#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import <Foundation/Foundation.h>

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCTBlockingQueue : NSObject
{
    _Bool _finalized;
    NSObject *_mutex;
    NSObject *_sema;
    NSMutableArray *_objects;
}

@property _Bool finalized; // @synthesize finalized=_finalized;
@property(readonly) NSMutableArray *objects; // @synthesize objects=_objects;
@property(readonly) NSObject *sema; // @synthesize sema=_sema;
@property(readonly) NSObject *mutex; // @synthesize mutex=_mutex;
- (void)finalize;
- (id)dequeueObject;
- (void)enqueueObject:(id)arg1;
- (void)enqueueObjects:(id)arg1;
- (id)init;

@end

#endif