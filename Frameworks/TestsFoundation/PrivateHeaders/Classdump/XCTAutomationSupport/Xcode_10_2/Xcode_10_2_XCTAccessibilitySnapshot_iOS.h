#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTAutomationSupport_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import <Foundation/Foundation.h>

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTAccessibilitySnapshot_iOS : NSObject <NSCopying>
{
    NSDictionary *_userTestingSnapshot;
    NSDictionary *_snapshotOptions;
    /* unknown type (struct __AXUIElement) */ void *_mainWindowRef;
    long long _appOrientation;
    struct CGRect _mainWindowFrame;
}

@property(readonly) long long appOrientation; // @synthesize appOrientation=_appOrientation;
@property(readonly) struct CGRect mainWindowFrame; // @synthesize mainWindowFrame=_mainWindowFrame;
@property(readonly) /* unknown type (struct __AXUIElement) */ void *mainWindowRef; // @synthesize mainWindowRef=_mainWindowRef;
@property(readonly) NSDictionary *snapshotOptions; // @synthesize snapshotOptions=_snapshotOptions;
@property(readonly) NSDictionary *userTestingSnapshot; // @synthesize userTestingSnapshot=_userTestingSnapshot;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)initWithUserTestingSnapshot:(id)arg1 snapshotOptions:(id)arg2 mainWindowRef:(/* unknown type (struct __AXUIElement) */ void *)arg3 mainWindowFrame:(struct CGRect)arg4 appOrientation:(long long)arg5;

@end

#endif