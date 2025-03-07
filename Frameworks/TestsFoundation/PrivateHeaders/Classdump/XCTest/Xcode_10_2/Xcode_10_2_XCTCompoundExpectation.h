#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import "Xcode_10_2_XCTestExpectationDelegate.h"
#import <XCTest/XCTestExpectation.h>

@class XCTCompoundExpectationImplementation, _XCTCompoundExpectationImplementation;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTCompoundExpectation : XCTestExpectation <XCTestExpectationDelegate>
{
    id _internalCompoundExpectation;
}

@property(readonly) _XCTCompoundExpectationImplementation *internalCompoundExpectation; // @synthesize internalCompoundExpectation=_internalCompoundExpectation;
- (void)didFulfillExpectation:(id)arg1;
- (void)cleanup;
- (_Bool)_queue_validateSubexpectationsFulfillment;
- (void)_updateFulfilledState;
@property(readonly, copy) NSArray *subexpectations;
@property(readonly) unsigned long long logicalType;
- (id)initWithLogicalType:(unsigned long long)arg1 subexpectations:(id)arg2;

// Remaining properties

@end

#endif