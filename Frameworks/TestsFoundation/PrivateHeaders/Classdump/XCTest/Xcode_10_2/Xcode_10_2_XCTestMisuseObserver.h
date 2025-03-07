#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import <Foundation/Foundation.h>
#import <XCTest/XCTestObservation.h>

@class XCTestCase, XCTestSuite;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTestMisuseObserver : NSObject <XCTestObservation>
{
    CDUnknownBlockType _warningLogHandler;
    NSMutableArray *_testSuiteStack;
    XCTestCase *_currentTestCase;
}

@property(retain) XCTestCase *currentTestCase; // @synthesize currentTestCase=_currentTestCase;
@property(readonly) NSMutableArray *testSuiteStack; // @synthesize testSuiteStack=_testSuiteStack;
@property(readonly, copy) CDUnknownBlockType warningLogHandler; // @synthesize warningLogHandler=_warningLogHandler;
- (void)testCaseDidFinish:(id)arg1;
- (void)testCase:(id)arg1 didFailWithDescription:(id)arg2 inFile:(id)arg3 atLine:(unsigned long long)arg4;
- (void)testCaseWillStart:(id)arg1;
- (void)testSuiteDidFinish:(id)arg1;
- (void)testSuiteWillStart:(id)arg1;
- (_Bool)testSuiteStackContainsTestSuite:(id)arg1;
- (void)removeTestSuiteFromStack:(id)arg1;
- (void)popCurrentTestSuite;
- (void)pushTestSuite:(id)arg1;
@property(readonly) XCTestSuite *currentTestSuite;
- (void)emitWarningLog:(id)arg1;
- (id)initWithWarningLogHandler:(CDUnknownBlockType)arg1;

// Remaining properties

@end

#endif