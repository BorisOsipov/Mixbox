#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import <Foundation/Foundation.h>

@class Bool, XCAccessibilityElement;

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCUIRecorderUtilities : NSObject
{
    unsigned long long _language;
    unsigned long long _platform;
    unsigned long long _compareSnapshotsLikePlatform;
    XCAccessibilityElement *_previousFocusedAccessibilityElement;
    NSMutableString *_previousTyping;
}

+ (id)applicationNodeForLanguage:(unsigned long long)arg1;
+ (unsigned long long)currentPlatform;
@property(retain) NSMutableString *previousTyping; // @synthesize previousTyping=_previousTyping;
@property(retain) XCAccessibilityElement *previousFocusedAccessibilityElement; // @synthesize previousFocusedAccessibilityElement=_previousFocusedAccessibilityElement;
@property unsigned long long _compareSnapshotsLikePlatform; // @synthesize _compareSnapshotsLikePlatform;
@property unsigned long long language; // @synthesize language=_language;
- (id)performWithKeyModifiersAndBlockNodeForModifierFlags:(unsigned long long)arg1;
- (id)gestureNodesForKeyDownEventWithCharacters:(id)arg1 charactersIgnoringModifiers:(id)arg2 modifierFlags:(unsigned long long)arg3 focusedAccessibilityElement:(id)arg4 didAppendToPreviousString:(_Bool *)arg5;
- (id)_stringConstantForString:(id)arg1;
- (void)clearPreviousTyping;
- (id)nodeToFindElementForSnapshots:(id)arg1;
- (id)typeKeyNodeForKey:(id)arg1 modifierFlags:(unsigned long long)arg2;
- (id)typeStringNodeForString:(id)arg1;
- (id)stringForKeyModifierFlags:(unsigned long long)arg1;
- (id)simpleGestureNodeForMethodName:(id)arg1;
- (id)assertHasFocusNode;
- (id)remoteNodeWithButtonSymbolName:(id)arg1;
- (id)commentNodeWithString:(id)arg1;
- (id)applicationNode;
- (id)adjustedSnapshotForApplicationSnapshot:(id)arg1;
- (id)focusedAccessibilityElementForApplicationSnapshot:(id)arg1;
- (id)snapshotsForAccessibilityElement:(id)arg1 applicationSnapshot:(id)arg2;
- (id)snapshotInTreeStartingWithSnapshot:(id)arg1 forElement:(id)arg2;
- (id)_snapshotInTreeStartingWithSnapshot:(id)arg1 passingPredicateBlock:(CDUnknownBlockType)arg2;
- (id)nodeForOrientationChangeWithSymbolName:(id)arg1;
@property unsigned long long platform; // @synthesize platform=_platform;

@end

#endif