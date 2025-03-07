#if MIXBOX_ENABLE_IN_APP_SERVICES

import MixboxIpc
import MixboxIpcCommon
import MixboxFoundation
import MixboxTestability

public final class InAppServicesDependenciesFactoryImpl: InAppServicesDependenciesFactory {
    public let ipcStarter: IpcStarter
    public let assertingSwizzler: AssertingSwizzler
    public let assertionFailureRecorder: AssertionFailureRecorder
    public let swizzler: Swizzler
    public let swizzlingSynchronization: SwizzlingSynchronization
    public let accessibilityEnhancer: AccessibilityEnhancer
    public let accessibilityValueSwizzler: AccessibilityValueSwizzler
    public let fakeCellsSwizzling: FakeCellsSwizzling
    public let collectionViewCellSwizzler: CollectionViewCellSwizzler
    public let collectionViewSwizzler: CollectionViewSwizzler
    public let fakeCellManager: FakeCellManager
    
    private let networkMockingBootstrappingType: NetworkMockingBootstrappingType
    
    public init?(environment: [String: String]) {
        // TODO: Fail tests instead of crashing app
        assertionFailureRecorder = StandardLibraryAssertionFailureRecorder()
        swizzler = SwizzlerImpl()
        swizzlingSynchronization = SwizzlingSynchronizationImpl()
        
        assertingSwizzler = AssertingSwizzlerImpl(
            swizzler: swizzler,
            swizzlingSynchronization: swizzlingSynchronization,
            assertionFailureRecorder: assertionFailureRecorder
        )
        
        let ipcStarterOrNil: IpcStarter?
        let ipcStarterType = InAppServicesDependenciesFactoryImpl.ipcStarterType(
            environment: environment
        )
        
        switch ipcStarterType {
        case .blackbox?:
            if let testRunnerHost = environment["MIXBOX_HOST"],
                let testRunnerPort = environment["MIXBOX_PORT"].flatMap({ UInt($0) })
            {
                ipcStarterOrNil = BuiltinIpcStarter(
                    testRunnerHost: testRunnerHost,
                    testRunnerPort: testRunnerPort
                )
                
                networkMockingBootstrappingType = .ipc
            } else {
                ipcStarterOrNil = nil
                networkMockingBootstrappingType = .disabled
            }
        case .sbtui?:
            ipcStarterOrNil = SbtuiIpcStarter(
                reregisterMethodHandlersAutomatically: environment["MIXBOX_REREGISTER_SBTUI_IPC_METHOD_HANDLERS_AUTOMATICALLY"] == "true"
            )
            networkMockingBootstrappingType = .disabled
        case .graybox?:
            ipcStarterOrNil = GrayBoxIpcStarter()
            networkMockingBootstrappingType = .inProcess
        case nil:
            ipcStarterOrNil = nil
            networkMockingBootstrappingType = .disabled
        }
        
        guard let ipcStarter = ipcStarterOrNil else {
            assertionFailure("Failed to start IPC")
            return nil
        }
        
        self.ipcStarter = ipcStarter
        
        let shouldEnhanceAccessibilityValue = ipcStarterType != IpcStarterType.graybox // TODO: Wrong place for this logic
        let shouldAddAssertionForCallingIsHiddenOnFakeCell
            = environment["MIXBOX_SHOULD_ADD_ASSERTION_FOR_CALLING_IS_HIDDEN_ON_FAKE_CELL"] == "true"
        
        let shouldEnableFakeCells = (environment["MIXBOX_SHOULD_ENABLE_FAKE_CELLS"] ?? "true") == "true"
        
        accessibilityValueSwizzler = AccessibilityValueSwizzlerImpl()
        
        collectionViewCellSwizzler = CollectionViewCellSwizzlerImpl(
            assertingSwizzler: assertingSwizzler,
            shouldAddAssertionForCallingIsHiddenOnFakeCell: shouldAddAssertionForCallingIsHiddenOnFakeCell
        )
        
        collectionViewSwizzler = CollectionViewSwizzlerImpl(
            assertingSwizzler: assertingSwizzler
        )
        
        fakeCellsSwizzling = FakeCellsSwizzlingImpl(
            collectionViewCellSwizzler: collectionViewCellSwizzler,
            collectionViewSwizzler: collectionViewSwizzler
        )
        
        fakeCellManager = FakeCellManagerImpl()
        
        accessibilityEnhancer = AccessibilityEnhancerImpl(
            accessibilityValueSwizzler: accessibilityValueSwizzler,
            fakeCellsSwizzling: fakeCellsSwizzling,
            shouldEnableFakeCells: shouldEnableFakeCells,
            shouldEnhanceAccessibilityValue: shouldEnhanceAccessibilityValue,
            fakeCellManager: fakeCellManager
        )
    }
    
    private static func ipcStarterType(environment: [String: String]) -> IpcStarterType? {
        if let typeString = environment["MIXBOX_IPC_STARTER_TYPE"], !typeString.isEmpty {
            guard let type = IpcStarterType(rawValue: typeString) else {
                assertionFailure("Unknown IpcStarterType: \(typeString) in MIXBOX_IPC_STARTER_TYPE environment variable")
                return nil
            }
            
            return type
        }
        
        // Fallback for earlier version. TODO: Remove on Oct 2019.
        
        if environment["MIXBOX_USE_BUILTIN_IPC"] == "true" {
            return .blackbox
        } else {
            return .sbtui
        }
    }
    
    public func mixboxUrlProtocolBootstrapper(ipcRouter: IpcRouter, ipcClient: IpcClient) -> MixboxUrlProtocolBootstrapper? {
        return mixboxUrlProtocolDependenciesFactory(ipcClient: ipcClient).map { ipcMixboxUrlProtocolDependenciesFactory in
            MixboxUrlProtocolBootstrapperImpl(
                assertingSwizzler: assertingSwizzler,
                mixboxUrlProtocolDependenciesFactory: ipcMixboxUrlProtocolDependenciesFactory,
                mixboxUrlProtocolSpecificIpcMethodHandlersRegisterer: ipcMixboxUrlProtocolDependenciesFactory,
                ipcRouter: ipcRouter
            )
        }
    }
    
    private func mixboxUrlProtocolDependenciesFactory(ipcClient: IpcClient) -> IpcMixboxUrlProtocolDependenciesFactory? {
        switch networkMockingBootstrappingType {
        case .disabled:
            return nil
        case .inProcess:
            // In-process URLProtocol is currently implemented via fake IPC (see `SameProcessIpcClientServer`).
            //
            // Usage of fake IpcClient (IPC without "IP") adds some little overhead, but no additional code is needed.
            // My attempt to implement solution with no overhead wasn't successful, because it required substantial time
            // investments at the moment I was implementing this feature.
            //
            return IpcMixboxUrlProtocolDependenciesFactory(
                ipcClient: ipcClient,
                foundationNetworkModelsBridgingFactory: FoundationNetworkModelsBridgingFactoryImpl(),
                assertionFailureRecorder: assertionFailureRecorder
            )
        case .ipc:
            return IpcMixboxUrlProtocolDependenciesFactory(
                ipcClient: ipcClient,
                foundationNetworkModelsBridgingFactory: FoundationNetworkModelsBridgingFactoryImpl(),
                assertionFailureRecorder: assertionFailureRecorder
            )
        }
    }
}

#endif
