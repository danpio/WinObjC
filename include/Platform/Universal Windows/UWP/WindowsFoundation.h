//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsFoundation.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WFPropertyValue, WFDeferral, WFWwwFormUrlDecoder, WFUri, WFWwwFormUrlDecoderEntry, WFMemoryBuffer;
@class WFPoint, WFSize, WFRect, WFDateTime, WFTimeSpan;
@class RTArray_C_RTObject_WFIWwwFormUrlDecoderEntry;
@protocol WFIClosable, WFIPropertyValue, WFIPropertyValueStatics, WFIStringable, WFIDeferral, WFIDeferralFactory, WFIAsyncInfo, WFIAsyncAction, WFIAsyncOperationWithProgress, WFIAsyncOperation, WFIAsyncActionWithProgress, WFIReference, WFIReferenceArray, WFIUriRuntimeClass, WFIUriRuntimeClassWithAbsoluteCanonicalUri, WFIUriEscapeStatics, WFIUriRuntimeClassFactory, WFIWwwFormUrlDecoderEntry, WFIWwwFormUrlDecoderRuntimeClass, WFIWwwFormUrlDecoderRuntimeClassFactory, WFIGetActivationFactory, WFIMemoryBufferReference, WFIMemoryBuffer, WFIMemoryBufferFactory;

// Windows.Foundation.PropertyType
enum _WFPropertyType {
	WFPropertyTypeEmpty = 0,
	WFPropertyTypeUInt8 = 1,
	WFPropertyTypeInt16 = 2,
	WFPropertyTypeUInt16 = 3,
	WFPropertyTypeInt32 = 4,
	WFPropertyTypeUInt32 = 5,
	WFPropertyTypeInt64 = 6,
	WFPropertyTypeUInt64 = 7,
	WFPropertyTypeSingle = 8,
	WFPropertyTypeDouble = 9,
	WFPropertyTypeChar16 = 10,
	WFPropertyTypeBoolean = 11,
	WFPropertyTypeString = 12,
	WFPropertyTypeInspectable = 13,
	WFPropertyTypeDateTime = 14,
	WFPropertyTypeTimeSpan = 15,
	WFPropertyTypeGuid = 16,
	WFPropertyTypePoint = 17,
	WFPropertyTypeSize = 18,
	WFPropertyTypeRect = 19,
	WFPropertyTypeOtherType = 20,
	WFPropertyTypeUInt8Array = 1025,
	WFPropertyTypeInt16Array = 1026,
	WFPropertyTypeUInt16Array = 1027,
	WFPropertyTypeInt32Array = 1028,
	WFPropertyTypeUInt32Array = 1029,
	WFPropertyTypeInt64Array = 1030,
	WFPropertyTypeUInt64Array = 1031,
	WFPropertyTypeSingleArray = 1032,
	WFPropertyTypeDoubleArray = 1033,
	WFPropertyTypeChar16Array = 1034,
	WFPropertyTypeBooleanArray = 1035,
	WFPropertyTypeStringArray = 1036,
	WFPropertyTypeInspectableArray = 1037,
	WFPropertyTypeDateTimeArray = 1038,
	WFPropertyTypeTimeSpanArray = 1039,
	WFPropertyTypeGuidArray = 1040,
	WFPropertyTypePointArray = 1041,
	WFPropertyTypeSizeArray = 1042,
	WFPropertyTypeRectArray = 1043,
	WFPropertyTypeOtherTypeArray = 1044,
};
typedef unsigned WFPropertyType;

#include "WindowsFoundationCollections.h"
// Windows.Foundation.AsyncActionCompletedHandler
#ifndef __WFAsyncActionCompletedHandler__DEFINED
#define __WFAsyncActionCompletedHandler__DEFINED
typedef void(^WFAsyncActionCompletedHandler)(RTObject<WFIAsyncAction>* asyncInfo, WFAsyncStatus asyncStatus);
#endif // __WFAsyncActionCompletedHandler__DEFINED

// Windows.Foundation.DeferralCompletedHandler
#ifndef __WFDeferralCompletedHandler__DEFINED
#define __WFDeferralCompletedHandler__DEFINED
typedef void(^WFDeferralCompletedHandler)();
#endif // __WFDeferralCompletedHandler__DEFINED


#import <Foundation/Foundation.h>

// [struct] Windows.Foundation.Point
WINRT_EXPORT
@interface WFPoint : NSObject
+ (instancetype)new;
@property float x;
@property float y;
@end

// [struct] Windows.Foundation.Size
WINRT_EXPORT
@interface WFSize : NSObject
+ (instancetype)new;
@property float width;
@property float height;
@end

// [struct] Windows.Foundation.Rect
WINRT_EXPORT
@interface WFRect : NSObject
+ (instancetype)new;
@property float x;
@property float y;
@property float width;
@property float height;
@end

// [struct] Windows.Foundation.DateTime
WINRT_EXPORT
@interface WFDateTime : NSObject
+ (instancetype)new;
@property int64_t universalTime;
@end

// [struct] Windows.Foundation.TimeSpan
WINRT_EXPORT
@interface WFTimeSpan : NSObject
+ (instancetype)new;
@property int64_t duration;
@end

// Windows.Foundation.AsyncActionCompletedHandler
#ifndef __WFAsyncActionCompletedHandler__DEFINED
#define __WFAsyncActionCompletedHandler__DEFINED
typedef void(^WFAsyncActionCompletedHandler)(RTObject<WFIAsyncAction>* asyncInfo, WFAsyncStatus asyncStatus);
#endif // __WFAsyncActionCompletedHandler__DEFINED

// Windows.Foundation.DeferralCompletedHandler
#ifndef __WFDeferralCompletedHandler__DEFINED
#define __WFDeferralCompletedHandler__DEFINED
typedef void(^WFDeferralCompletedHandler)();
#endif // __WFDeferralCompletedHandler__DEFINED

// Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2
 // Could not generate delegate: Can't marshal Windows.Foundation.IAsyncOperationWithProgress`2<0,1>
// Windows.Foundation.AsyncOperationCompletedHandler`1
 // Could not generate delegate: Can't marshal Windows.Foundation.IAsyncOperation`1<0>
// Windows.Foundation.AsyncActionWithProgressCompletedHandler`1
 // Could not generate delegate: Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<0>
// Windows.Foundation.AsyncOperationProgressHandler`2
 // Could not generate delegate: Can't marshal Windows.Foundation.IAsyncOperationWithProgress`2<0,1>
// Windows.Foundation.AsyncActionProgressHandler`1
 // Could not generate delegate: Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<0>
// Windows.Foundation.TypedEventHandler`2
 // Could not generate delegate: Can't marshal 0
// Windows.Foundation.EventHandler`1
 // Could not generate delegate: Can't marshal 0
// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Foundation.IPropertyValue
#ifndef __WFIPropertyValue_DEFINED__
#define __WFIPropertyValue_DEFINED__

@protocol WFIPropertyValue
@property (readonly) BOOL isNumericScalar;
@property (readonly) WFPropertyType type;
- (uint8_t)getUInt8;
- (int16_t)getInt16;
- (unsigned short)getUInt16;
- (int)getInt32;
- (unsigned int)getUInt32;
- (int64_t)getInt64;
- (uint64_t)getUInt64;
- (float)getSingle;
- (double)getDouble;
- (WCHAR)getChar16;
- (BOOL)getBoolean;
- (NSString *)getString;
- (WFGUID*)getGuid;
- (WFDateTime*)getDateTime;
- (WFTimeSpan*)getTimeSpan;
- (WFPoint*)getPoint;
- (WFSize*)getSize;
- (WFRect*)getRect;
- (void)getUInt8Array:(id<NSFastEnumeration> /* uint8_t */*)value;
- (void)getInt16Array:(id<NSFastEnumeration> /* int16_t */*)value;
- (void)getUInt16Array:(id<NSFastEnumeration> /* unsigned short */*)value;
- (void)getInt32Array:(id<NSFastEnumeration> /* int */*)value;
- (void)getUInt32Array:(id<NSFastEnumeration> /* unsigned int */*)value;
- (void)getInt64Array:(id<NSFastEnumeration> /* int64_t */*)value;
- (void)getUInt64Array:(id<NSFastEnumeration> /* uint64_t */*)value;
- (void)getSingleArray:(id<NSFastEnumeration> /* float */*)value;
- (void)getDoubleArray:(id<NSFastEnumeration> /* double */*)value;
- (void)getChar16Array:(id<NSFastEnumeration> /* WCHAR */*)value;
- (void)getBooleanArray:(id<NSFastEnumeration> /* BOOL */*)value;
- (void)getStringArray:(id<NSFastEnumeration> /* NSString * */*)value;
- (void)getInspectableArray:(id<NSFastEnumeration> /* RTObject* */*)value;
- (void)getGuidArray:(id<NSFastEnumeration> /* WFGUID* */*)value;
- (void)getDateTimeArray:(id<NSFastEnumeration> /* WFDateTime* */*)value;
- (void)getTimeSpanArray:(id<NSFastEnumeration> /* WFTimeSpan* */*)value;
- (void)getPointArray:(id<NSFastEnumeration> /* WFPoint* */*)value;
- (void)getSizeArray:(id<NSFastEnumeration> /* WFSize* */*)value;
- (void)getRectArray:(id<NSFastEnumeration> /* WFRect* */*)value;
@end

#endif // __WFIPropertyValue_DEFINED__

// Windows.Foundation.IStringable
#ifndef __WFIStringable_DEFINED__
#define __WFIStringable_DEFINED__

@protocol WFIStringable
- (NSString *)toString;
@end

#endif // __WFIStringable_DEFINED__

// Windows.Foundation.IAsyncInfo
#ifndef __WFIAsyncInfo_DEFINED__
#define __WFIAsyncInfo_DEFINED__

@protocol WFIAsyncInfo
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
- (void)cancel;
- (void)close;
@end

#endif // __WFIAsyncInfo_DEFINED__

// Windows.Foundation.IAsyncAction
#ifndef __WFIAsyncAction_DEFINED__
#define __WFIAsyncAction_DEFINED__

@protocol WFIAsyncAction <WFIAsyncInfo>
@property (copy) WFAsyncActionCompletedHandler completed;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WFIAsyncAction_DEFINED__

// Windows.Foundation.IWwwFormUrlDecoderEntry
#ifndef __WFIWwwFormUrlDecoderEntry_DEFINED__
#define __WFIWwwFormUrlDecoderEntry_DEFINED__

@protocol WFIWwwFormUrlDecoderEntry
@property (readonly) NSString * name;
@property (readonly) NSString * value;
@end

#endif // __WFIWwwFormUrlDecoderEntry_DEFINED__

// Windows.Foundation.IGetActivationFactory
#ifndef __WFIGetActivationFactory_DEFINED__
#define __WFIGetActivationFactory_DEFINED__

@protocol WFIGetActivationFactory
- (RTObject*)getActivationFactory:(NSString *)activatableClassId;
@end

#endif // __WFIGetActivationFactory_DEFINED__

// Windows.Foundation.IMemoryBufferReference
#ifndef __WFIMemoryBufferReference_DEFINED__
#define __WFIMemoryBufferReference_DEFINED__

@protocol WFIMemoryBufferReference <WFIClosable>
@property (readonly) unsigned int capacity;
- (EventRegistrationToken)addClosedEvent:(void(^)(RTObject<WFIMemoryBufferReference>*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (void)close;
@end

#endif // __WFIMemoryBufferReference_DEFINED__

// Windows.Foundation.IMemoryBuffer
#ifndef __WFIMemoryBuffer_DEFINED__
#define __WFIMemoryBuffer_DEFINED__

@protocol WFIMemoryBuffer <WFIClosable>
- (RTObject<WFIMemoryBufferReference>*)createReference;
- (void)close;
@end

#endif // __WFIMemoryBuffer_DEFINED__

// Windows.Foundation.PropertyValue
#ifndef __WFPropertyValue_DEFINED__
#define __WFPropertyValue_DEFINED__

WINRT_EXPORT
@interface WFPropertyValue : RTObject
+ (RTObject*)createEmpty;
+ (RTObject*)createUInt8:(uint8_t)value;
+ (RTObject*)createInt16:(int16_t)value;
+ (RTObject*)createUInt16:(unsigned short)value;
+ (RTObject*)createInt32:(int)value;
+ (RTObject*)createUInt32:(unsigned int)value;
+ (RTObject*)createInt64:(int64_t)value;
+ (RTObject*)createUInt64:(uint64_t)value;
+ (RTObject*)createSingle:(float)value;
+ (RTObject*)createDouble:(double)value;
+ (RTObject*)createChar16:(WCHAR)value;
+ (RTObject*)createBoolean:(BOOL)value;
+ (RTObject*)createString:(NSString *)value;
+ (RTObject*)createInspectable:(RTObject*)value;
+ (RTObject*)createGuid:(WFGUID*)value;
+ (RTObject*)createDateTime:(WFDateTime*)value;
+ (RTObject*)createTimeSpan:(WFTimeSpan*)value;
+ (RTObject*)createPoint:(WFPoint*)value;
+ (RTObject*)createSize:(WFSize*)value;
+ (RTObject*)createRect:(WFRect*)value;
+ (RTObject*)createUInt8Array:(id<NSFastEnumeration> /* uint8_t */)value;
+ (RTObject*)createInt16Array:(id<NSFastEnumeration> /* int16_t */)value;
+ (RTObject*)createUInt16Array:(id<NSFastEnumeration> /* unsigned short */)value;
+ (RTObject*)createInt32Array:(id<NSFastEnumeration> /* int */)value;
+ (RTObject*)createUInt32Array:(id<NSFastEnumeration> /* unsigned int */)value;
+ (RTObject*)createInt64Array:(id<NSFastEnumeration> /* int64_t */)value;
+ (RTObject*)createUInt64Array:(id<NSFastEnumeration> /* uint64_t */)value;
+ (RTObject*)createSingleArray:(id<NSFastEnumeration> /* float */)value;
+ (RTObject*)createDoubleArray:(id<NSFastEnumeration> /* double */)value;
+ (RTObject*)createChar16Array:(id<NSFastEnumeration> /* WCHAR */)value;
+ (RTObject*)createBooleanArray:(id<NSFastEnumeration> /* BOOL */)value;
+ (RTObject*)createStringArray:(id<NSFastEnumeration> /* NSString * */)value;
+ (RTObject*)createInspectableArray:(id<NSFastEnumeration> /* RTObject* */)value;
+ (RTObject*)createGuidArray:(id<NSFastEnumeration> /* WFGUID* */)value;
+ (RTObject*)createDateTimeArray:(id<NSFastEnumeration> /* WFDateTime* */)value;
+ (RTObject*)createTimeSpanArray:(id<NSFastEnumeration> /* WFTimeSpan* */)value;
+ (RTObject*)createPointArray:(id<NSFastEnumeration> /* WFPoint* */)value;
+ (RTObject*)createSizeArray:(id<NSFastEnumeration> /* WFSize* */)value;
+ (RTObject*)createRectArray:(id<NSFastEnumeration> /* WFRect* */)value;
@end

#endif // __WFPropertyValue_DEFINED__

// Windows.Foundation.Deferral
#ifndef __WFDeferral_DEFINED__
#define __WFDeferral_DEFINED__

WINRT_EXPORT
@interface WFDeferral : RTObject <WFIClosable>
+ (WFDeferral*)create:(WFDeferralCompletedHandler)handler ACTIVATOR;
- (void)complete;
- (void)close;
@end

#endif // __WFDeferral_DEFINED__

// Windows.Foundation.WwwFormUrlDecoder
#ifndef __WFWwwFormUrlDecoder_DEFINED__
#define __WFWwwFormUrlDecoder_DEFINED__

WINRT_EXPORT
@interface WFWwwFormUrlDecoder : RTObject
+ (WFWwwFormUrlDecoder*)createWwwFormUrlDecoder:(NSString *)query ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (NSString *)getFirstValueByName:(NSString *)name;
@end

#endif // __WFWwwFormUrlDecoder_DEFINED__

// Windows.Foundation.Uri
#ifndef __WFUri_DEFINED__
#define __WFUri_DEFINED__

WINRT_EXPORT
@interface WFUri : RTObject <WFIStringable>
+ (NSString *)unescapeComponent:(NSString *)toUnescape;
+ (NSString *)escapeComponent:(NSString *)toEscape;
+ (WFUri*)createUri:(NSString *)uri ACTIVATOR;
+ (WFUri*)createWithRelativeUri:(NSString *)baseUri relativeUri:(NSString *)relativeUri ACTIVATOR;
@property (readonly) NSString * absoluteUri;
@property (readonly) NSString * displayUri;
@property (readonly) NSString * domain;
@property (readonly) NSString * extension;
@property (readonly) NSString * fragment;
@property (readonly) NSString * host;
@property (readonly) NSString * password;
@property (readonly) NSString * path;
@property (readonly) int port;
@property (readonly) NSString * query;
@property (readonly) WFWwwFormUrlDecoder* queryParsed;
@property (readonly) NSString * rawUri;
@property (readonly) NSString * schemeName;
@property (readonly) BOOL suspicious;
@property (readonly) NSString * userName;
@property (readonly) NSString * absoluteCanonicalUri;
@property (readonly) NSString * displayIri;
- (BOOL)equals:(WFUri*)pUri;
- (WFUri*)combineUri:(NSString *)relativeUri;
- (NSString *)toString;
@end

#endif // __WFUri_DEFINED__

// Windows.Foundation.WwwFormUrlDecoderEntry
#ifndef __WFWwwFormUrlDecoderEntry_DEFINED__
#define __WFWwwFormUrlDecoderEntry_DEFINED__

WINRT_EXPORT
@interface WFWwwFormUrlDecoderEntry : RTObject <WFIWwwFormUrlDecoderEntry>
@property (readonly) NSString * name;
@property (readonly) NSString * value;
@end

#endif // __WFWwwFormUrlDecoderEntry_DEFINED__

// Windows.Foundation.MemoryBuffer
#ifndef __WFMemoryBuffer_DEFINED__
#define __WFMemoryBuffer_DEFINED__

WINRT_EXPORT
@interface WFMemoryBuffer : RTObject <WFIMemoryBuffer, WFIClosable>
+ (WFMemoryBuffer*)create:(unsigned int)capacity ACTIVATOR;
- (RTObject<WFIMemoryBufferReference>*)createReference;
- (void)close;
@end

#endif // __WFMemoryBuffer_DEFINED__

