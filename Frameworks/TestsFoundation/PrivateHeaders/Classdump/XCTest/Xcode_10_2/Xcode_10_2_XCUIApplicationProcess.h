#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import "Xcode_10_2_XCTElementSnapshotAttributeDataSource.h"
#import <Foundation/Foundation.h>

@protocol XCTRunnerAutomationSession, XCUIDevice;

@class XCAccessibilityElement, XCElementSnapshot, XCUIApplicationProcess;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCUIApplicationProcess : NSObject <XCTElementSnapshotAttributeDataSource>
{
    NSObject *_queue;
    _Bool _accessibilityActive;
    unsigned long long _applicationState;
    int _processID;
    id _token;
    int _exitCode;
    _Bool _eventLoopHasIdled;
    _Bool _animationsHaveFinished;
    _Bool _hasExitCode;
    _Bool _hasCrashReport;
    _Bool _bridged;
    unsigned long long _alertCount;
    NSString *_bundleID;
    id <XCTRunnerAutomationSession> _automationSession;
    XCElementSnapshot *_lastSnapshot;
    XCUIApplicationProcess *_bridgedProcess;
    id <XCUIDevice> _device;
}

+ (id)keyPathsForValuesAffectingIsQuiescent;
+ (_Bool)automaticallyNotifiesObserversForKey:(id)arg1;
+ (id)keyPathsForValuesAffectingHasBridgedProcess;
+ (id)keyPathsForValuesAffectingIsProcessIDValid;
+ (id)keyPathsForValuesAffectingForeground;
+ (id)keyPathsForValuesAffectingBackground;
+ (id)keyPathsForValuesAffectingSuspended;
+ (id)keyPathsForValuesAffectingRunning;
+ (id)keyPathsForValuesAffectingIsApplicationStateKnown;
@property(readonly) id <XCUIDevice> device; // @synthesize device=_device;
@property(retain, nonatomic) XCUIApplicationProcess *bridgedProcess; // @synthesize bridgedProcess=_bridgedProcess;
@property(retain) XCElementSnapshot *lastSnapshot; // @synthesize lastSnapshot=_lastSnapshot;
@property(retain) id <XCTRunnerAutomationSession> automationSession; // @synthesize automationSession=_automationSession;
@property(getter=isBridged) _Bool bridged; // @synthesize bridged=_bridged;
@property _Bool hasCrashReport; // @synthesize hasCrashReport=_hasCrashReport;
@property _Bool hasExitCode; // @synthesize hasExitCode=_hasExitCode;
@property(readonly, copy, nonatomic) NSString *bundleID; // @synthesize bundleID=_bundleID;
@property(readonly) _Bool usePointTransformationsForFrameConversions;
@property(readonly) _Bool supportsHostedViewCoordinateTransformations;
- (id)parameterizedAttribute:(id)arg1 forElement:(id)arg2 parameter:(id)arg3 error:(id *)arg4;
- (id)attributesForElement:(id)arg1 attributes:(id)arg2 error:(id *)arg3;
@property(readonly) _Bool allowsRemoteAccess;
- (id)_underlyingDataSourceForElement:(id)arg1;
- (_Bool)terminate:(id *)arg1;
- (_Bool)waitForViewControllerViewDidDisappearWithTimeout:(double)arg1 error:(id *)arg2;
- (void)acquireBackgroundAssertion;
- (void)waitForFutureAutomationSession:(id)arg1;
- (id)futureAutomationSession;
- (void)waitForAutomationSession;
@property(readonly, getter=isQuiescent) _Bool quiescent;
- (void)_initiateQuiescenceChecksIncludingAnimationsIdle:(_Bool)arg1;
- (void)waitForQuiescenceIncludingAnimationsIdle:(_Bool)arg1;
- (id)_makeQuiescenceExpectation;
- (void)_notifyWhenAnimationsAreIdle:(CDUnknownBlockType)arg1;
- (_Bool)_supportsAnimationsIdleNotifications;
- (void)_notifyWhenMainRunLoopIsIdle:(CDUnknownBlockType)arg1;
- (void)resetAlertCount;
- (void)incrementAlertCount;
@property(readonly) unsigned long long alertCount; // @synthesize alertCount=_alertCount;
@property _Bool animationsHaveFinished;
@property _Bool eventLoopHasIdled;
@property int exitCode;
@property(retain) id token;
- (_Bool)hasBridgedProcess;
@property(nonatomic) int processID;
@property(readonly, getter=isProcessIDValid) _Bool processIDValid;
@property(readonly) _Bool foreground;
@property(readonly) _Bool background;
@property(readonly) _Bool suspended;
@property(readonly) _Bool running;
- (_Bool)isApplicationStateKnown;
- (void)_awaitKnownApplicationState;
@property(nonatomic) unsigned long long applicationState;
@property(nonatomic) _Bool accessibilityActive;
@property(readonly, copy) XCAccessibilityElement *accessibilityElement;
@property(readonly, copy) NSString *shortDescription;
- (id)_queue_description;
- (id)initWithBundleID:(id)arg1 device:(id)arg2;

// Remaining properties

@end

#endif