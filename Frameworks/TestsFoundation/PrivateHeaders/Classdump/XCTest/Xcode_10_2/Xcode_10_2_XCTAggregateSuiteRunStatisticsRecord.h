#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import <Foundation/Foundation.h>

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTAggregateSuiteRunStatisticsRecord : NSObject <NSSecureCoding>
{
    NSString *_suiteName;
    unsigned long long _executionCount;
    unsigned long long _failureCount;
    unsigned long long _unexpectedExceptionCount;
}

+ (_Bool)supportsSecureCoding;
@property(readonly) unsigned long long unexpectedExceptionCount; // @synthesize unexpectedExceptionCount=_unexpectedExceptionCount;
@property(readonly) unsigned long long failureCount; // @synthesize failureCount=_failureCount;
@property(readonly) unsigned long long executionCount; // @synthesize executionCount=_executionCount;
@property(readonly) NSString *suiteName; // @synthesize suiteName=_suiteName;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (_Bool)isEqualToStatisticsRecord:(id)arg1;
- (_Bool)isEqual:(id)arg1;
- (id)initWithSuiteName:(id)arg1 executionCount:(unsigned long long)arg2 failureCount:(unsigned long long)arg3 unexpectedExceptionCount:(unsigned long long)arg4;

@end

#endif