#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import <Foundation/Foundation.h>

@class XCDeviceEvent;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@protocol XCUIDeviceEventAndStateInterface <NSObject>
- (void)getDeviceOrientationWithCompletion:(void (^)(long long, NSError *))arg1;
- (void)updateDeviceOrientation:(long long)arg1 completion:(void (^)(_Bool, NSError *))arg2;
- (void)performDeviceEvent:(XCDeviceEvent *)arg1 completion:(void (^)(_Bool, NSError *))arg2;
@end

#endif
