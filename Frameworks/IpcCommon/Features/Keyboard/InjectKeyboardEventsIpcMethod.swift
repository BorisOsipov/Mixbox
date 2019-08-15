#if MIXBOX_ENABLE_IN_APP_SERVICES

import MixboxIpc

public final class InjectKeyboardEventsIpcMethod: IpcMethod {
    public typealias Arguments = [KeyboardEvent]
    public typealias ReturnValue = IpcVoid
    
    public init() {
    }
}

#endif
