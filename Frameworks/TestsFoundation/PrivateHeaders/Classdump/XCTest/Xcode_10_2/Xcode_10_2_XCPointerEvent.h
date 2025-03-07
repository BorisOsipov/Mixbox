#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 120200 && __IPHONE_OS_VERSION_MAX_ALLOWED < 130000

#import "Xcode_10_2_XCTest_CDStructures.h"
#import "Xcode_10_2_SharedHeader.h"
#import <Foundation/Foundation.h>

//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@interface XCPointerEvent : NSObject <NSSecureCoding>
{
    _Bool _mergeModifierFlagsWithCurrentFlags;
    unsigned long long _eventType;
    unsigned long long _buttonType;
    double _pressure;
    double _offset;
    double _duration;
    long long _verticalLineScroll;
    unsigned long long _clickCount;
    unsigned long long _keyModifierFlags;
    NSString *_key;
    NSString *_string;
    unsigned long long _typingSpeed;
    unsigned long long _keyCode;
    unsigned long long _keyPhase;
    struct CGPoint _coordinate;
    struct CGPoint _destination;
    struct CGVector _deltaVector;
}

+ (CDUnknownBlockType)offsetComparator;
+ (id)keyboardEventForKeyCode:(unsigned long long)arg1 keyPhase:(unsigned long long)arg2 modifierFlags:(unsigned long long)arg3 offset:(double)arg4;
+ (id)textEventForString:(id)arg1 offset:(double)arg2 typingSpeed:(unsigned long long)arg3;
+ (id)textEventForKey:(id)arg1 withModifierFlags:(unsigned long long)arg2 offset:(double)arg3;
+ (id)textEventForModifierFlags:(unsigned long long)arg1 mergeWithCurrent:(_Bool)arg2 offset:(double)arg3;
+ (id)dragEventWithCoordinate:(struct CGPoint)arg1 destination:(struct CGPoint)arg2 offset:(double)arg3 duration:(double)arg4;
+ (id)scrollEventAtPoint:(struct CGPoint)arg1 lines:(long long)arg2 offset:(double)arg3;
+ (id)scrollEventWithDeltaVector:(struct CGVector)arg1 offset:(double)arg2 duration:(double)arg3;
+ (id)eventWithType:(unsigned long long)arg1 buttonType:(unsigned long long)arg2 coordinate:(struct CGPoint)arg3 pressure:(double)arg4 offset:(double)arg5 duration:(double)arg6 clickCount:(unsigned long long)arg7;
+ (id)eventWithType:(unsigned long long)arg1 buttonType:(unsigned long long)arg2 coordinate:(struct CGPoint)arg3 offset:(double)arg4 duration:(double)arg5 clickCount:(unsigned long long)arg6;
+ (id)eventWithType:(unsigned long long)arg1 buttonType:(unsigned long long)arg2 coordinate:(struct CGPoint)arg3 offset:(double)arg4 clickCount:(unsigned long long)arg5;
+ (_Bool)supportsSecureCoding;
@property unsigned long long keyPhase; // @synthesize keyPhase=_keyPhase;
@property unsigned long long keyCode; // @synthesize keyCode=_keyCode;
@property unsigned long long typingSpeed; // @synthesize typingSpeed=_typingSpeed;
@property(copy) NSString *string; // @synthesize string=_string;
@property(copy) NSString *key; // @synthesize key=_key;
@property _Bool mergeModifierFlagsWithCurrentFlags; // @synthesize mergeModifierFlagsWithCurrentFlags=_mergeModifierFlagsWithCurrentFlags;
@property unsigned long long keyModifierFlags; // @synthesize keyModifierFlags=_keyModifierFlags;
@property unsigned long long clickCount; // @synthesize clickCount=_clickCount;
@property long long verticalLineScroll; // @synthesize verticalLineScroll=_verticalLineScroll;
@property double duration; // @synthesize duration=_duration;
@property struct CGVector deltaVector; // @synthesize deltaVector=_deltaVector;
@property double offset; // @synthesize offset=_offset;
@property double pressure; // @synthesize pressure=_pressure;
@property struct CGPoint destination; // @synthesize destination=_destination;
@property struct CGPoint coordinate; // @synthesize coordinate=_coordinate;
@property unsigned long long buttonType; // @synthesize buttonType=_buttonType;
@property unsigned long long eventType; // @synthesize eventType=_eventType;
- (id)description;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

#endif