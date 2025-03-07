#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTAutomationSupport_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import "Xcode_10_2_XCTLogArchiveRequesting.h"
#import <Foundation/Foundation.h>

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTLogArchiveRequest : NSObject <XCTLogArchiveRequesting>
{
    // Error parsing type: {atomic_flag="_Value"AB}, name: _hasExecuted
    NSDate *_startDate;
    NSString *_outputPath;
    NSXPCConnection *_connection;
}

+ (id)logArchiveCollectorConnection;
+ (id)requestWithStartDate:(id)arg1 outputPath:(id)arg2;
@property(readonly) NSXPCConnection *connection; // @synthesize connection=_connection;
@property(readonly, copy) NSString *outputPath; // @synthesize outputPath=_outputPath;
@property(readonly, copy) NSDate *startDate; // @synthesize startDate=_startDate;
- (void)executeWithCompletion:(CDUnknownBlockType)arg1;
- (id)initWithStartDate:(id)arg1 outputPath:(id)arg2;
- (id)initWithStartDate:(id)arg1 outputPath:(id)arg2 connection:(id)arg3;

// Remaining properties

@end

#endif