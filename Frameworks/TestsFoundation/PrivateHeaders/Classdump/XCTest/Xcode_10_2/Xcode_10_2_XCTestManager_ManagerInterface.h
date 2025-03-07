#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"

@class XCAccessibilityElement, XCDeviceEvent, XCElementSnapshot, XCSynthesizedEventRecord, XCTSerializedTransportWrapper, XCTSpindumpRequestSpecification;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@protocol XCTestManager_ManagerInterface
- (void)_XCT_requestBundleIDForPID:(int)arg1 reply:(void (^)(NSString *, NSError *))arg2;
- (void)_XCT_injectVoiceRecognitionAudioInputPaths:(NSArray *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)_XCT_injectAssistantRecognitionStrings:(NSArray *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)_XCT_startSiriUIRequestWithAudioFileURL:(NSURL *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)_XCT_startSiriUIRequestWithText:(NSString *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)_XCT_requestSiriEnabledStatus:(void (^)(_Bool, NSError *))arg1;
- (void)_XCT_enableFauxCollectionViewCells:(void (^)(_Bool, NSError *))arg1;
- (void)_XCT_setLocalizableStringsDataGatheringEnabled:(_Bool)arg1 reply:(void (^)(_Bool, NSError *))arg2;
- (void)_XCT_loadAccessibilityWithTimeout:(double)arg1 reply:(void (^)(_Bool, NSError *))arg2;
- (void)_XCT_setAXTimeout:(double)arg1 reply:(void (^)(int))arg2;
- (void)_XCT_requestScreenshotWithReply:(void (^)(NSData *, NSError *))arg1;
- (void)_XCT_sendString:(NSString *)arg1 maximumFrequency:(unsigned long long)arg2 completion:(void (^)(NSError *))arg3;
- (void)_XCT_getDeviceOrientationWithCompletion:(void (^)(NSNumber *, NSError *))arg1;
- (void)_XCT_updateDeviceOrientation:(long long)arg1 completion:(void (^)(NSError *))arg2;
- (void)_XCT_performDeviceEvent:(XCDeviceEvent *)arg1 completion:(void (^)(NSError *))arg2;
- (void)_XCT_synthesizeEvent:(XCSynthesizedEventRecord *)arg1 completion:(void (^)(NSError *))arg2;
- (void)_XCT_requestElementAtPoint:(struct CGPoint)arg1 reply:(void (^)(XCAccessibilityElement *, NSError *))arg2;
- (void)_XCT_fetchParameterizedAttribute:(NSString *)arg1 forElement:(XCAccessibilityElement *)arg2 parameter:(id)arg3 reply:(void (^)(id, NSError *))arg4;
- (void)_XCT_fetchParameterizedAttributeForElement:(XCAccessibilityElement *)arg1 attributes:(NSNumber *)arg2 parameter:(id)arg3 reply:(void (^)(id, NSError *))arg4;
- (void)_XCT_setAttribute:(NSNumber *)arg1 value:(id)arg2 element:(XCAccessibilityElement *)arg3 reply:(void (^)(_Bool, NSError *))arg4;
- (void)_XCT_fetchAttributes:(NSArray *)arg1 forElement:(XCAccessibilityElement *)arg2 reply:(void (^)(NSDictionary *, NSError *))arg3;
- (void)_XCT_fetchAttributesForElement:(XCAccessibilityElement *)arg1 attributes:(NSArray *)arg2 reply:(void (^)(NSDictionary *, NSError *))arg3;
- (void)_XCT_requestSnapshotForElement:(XCAccessibilityElement *)arg1 attributes:(NSArray *)arg2 parameters:(NSDictionary *)arg3 reply:(void (^)(XCElementSnapshot *, NSError *))arg4;
- (void)_XCT_snapshotForElement:(XCAccessibilityElement *)arg1 attributes:(NSArray *)arg2 parameters:(NSDictionary *)arg3 reply:(void (^)(XCElementSnapshot *, NSError *))arg4;
- (void)_XCT_terminateApplicationWithBundleID:(NSString *)arg1 completion:(void (^)(NSError *))arg2;
- (void)_XCT_performAccessibilityAction:(int)arg1 onElement:(XCAccessibilityElement *)arg2 withValue:(id)arg3 reply:(void (^)(NSError *))arg4;
- (void)_XCT_unregisterForAccessibilityNotification:(long long)arg1 withRegistrationToken:(NSNumber *)arg2 reply:(void (^)(NSError *))arg3;
- (void)_XCT_registerForAccessibilityNotification:(long long)arg1 reply:(void (^)(NSNumber *, NSError *))arg2;
- (void)_XCT_launchApplicationWithBundleID:(NSString *)arg1 arguments:(NSArray *)arg2 environment:(NSDictionary *)arg3 completion:(void (^)(NSError *))arg4;
- (void)_XCT_startMonitoringApplicationWithBundleID:(NSString *)arg1;
- (void)_XCT_requestBackgroundAssertionWithReply:(void (^)(void))arg1;
- (void)_XCT_requestBackgroundAssertionForPID:(int)arg1 reply:(void (^)(_Bool))arg2;
- (void)_XCT_requestScreenshotOfScreenWithID:(unsigned int)arg1 withRect:(struct CGRect)arg2 uti:(NSString *)arg3 compressionQuality:(double)arg4 withReply:(void (^)(NSData *, NSError *))arg5;
- (void)_XCT_requestSpindumpWithSpecification:(XCTSpindumpRequestSpecification *)arg1 completion:(void (^)(NSData *, NSError *))arg2;
- (void)_XCT_requestEndpointForTestTargetWithPID:(int)arg1 preferredBackendPath:(NSString *)arg2 reply:(void (^)(NSXPCListenerEndpoint *, NSError *))arg3;
- (void)_XCT_requestSerializedTransportWrapperForIDESessionWithIdentifier:(NSUUID *)arg1 reply:(void (^)(XCTSerializedTransportWrapper *))arg2;
- (void)_XCT_requestSocketForSessionIdentifier:(NSUUID *)arg1 reply:(void (^)(NSFileHandle *))arg2;
- (void)_XCT_exchangeProtocolVersion:(unsigned long long)arg1 reply:(void (^)(unsigned long long))arg2;
@end

#endif
