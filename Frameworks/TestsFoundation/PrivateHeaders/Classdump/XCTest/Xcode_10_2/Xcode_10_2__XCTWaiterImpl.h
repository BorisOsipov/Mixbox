#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import <Foundation/Foundation.h>

@protocol XCTWaiterDelegate;

@class CFRunLoop, XCTWaiterManager;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface _XCTWaiterImpl : NSObject
{
    id <XCTWaiterDelegate> _delegate;
    XCTWaiterManager *_manager;
    NSArray *_waitCallStackReturnAddresses;
    NSObject *_delegateQueue;
    NSArray *_expectations;
    NSMutableArray *_fulfilledExpectations;
    struct __CFRunLoop *_waitingRunLoop;
    long long _state;
    double _timeout;
    long long _result;
    _Bool _enforceOrderOfFulfillment;
}

@property _Bool enforceOrderOfFulfillment; // @synthesize enforceOrderOfFulfillment=_enforceOrderOfFulfillment;
@property long long result; // @synthesize result=_result;
@property long long state; // @synthesize state=_state;
@property(readonly, nonatomic) NSMutableArray *fulfilledExpectations; // @synthesize fulfilledExpectations=_fulfilledExpectations;
@property(copy, nonatomic) NSArray *expectations; // @synthesize expectations=_expectations;
@property(readonly, nonatomic) NSObject *delegateQueue; // @synthesize delegateQueue=_delegateQueue;
@property XCTWaiterManager *manager; // @synthesize manager=_manager;
@property id <XCTWaiterDelegate> delegate; // @synthesize delegate=_delegate;
@property double timeout; // @synthesize timeout=_timeout;
@property struct __CFRunLoop *waitingRunLoop; // @synthesize waitingRunLoop=_waitingRunLoop;
@property(copy) NSArray *waitCallStackReturnAddresses; // @synthesize waitCallStackReturnAddresses=_waitCallStackReturnAddresses;
- (void)dealloc;
- (id)init;

@end

#endif