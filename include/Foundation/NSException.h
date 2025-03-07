/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSEXCEPTION_H_
#define _NSEXCEPTION_H_

#import <Foundation/NSObject.h>
#import <setjmp.h>

@class NSDictionary,NSArray;

FOUNDATION_EXPORT NSString * const NSGenericException;
FOUNDATION_EXPORT NSString * const NSInvalidArgumentException;
FOUNDATION_EXPORT NSString * const NSRangeException;

FOUNDATION_EXPORT NSString * const NSInternalInconsistencyException;
FOUNDATION_EXPORT NSString * const NSMallocException;

FOUNDATION_EXPORT NSString * const NSParseErrorException;
FOUNDATION_EXPORT NSString * const NSInconsistentArchiveException;

FOUNDATION_EXPORT NSString * const NSGenericException;
FOUNDATION_EXPORT NSString * const NSRangeException;
FOUNDATION_EXPORT NSString * const NSInvalidArgumentException;
FOUNDATION_EXPORT NSString * const NSInternalInconsistencyException;
FOUNDATION_EXPORT NSString * const NSMallocException;
FOUNDATION_EXPORT NSString * const NSObjectInaccessibleException;
FOUNDATION_EXPORT NSString * const NSObjectNotAvailableException;
FOUNDATION_EXPORT NSString * const NSDestinationInvalidException;
FOUNDATION_EXPORT NSString * const NSPortTimeoutException;
FOUNDATION_EXPORT NSString * const NSInvalidSendPortException;
FOUNDATION_EXPORT NSString * const NSInvalidReceivePortException;
FOUNDATION_EXPORT NSString * const NSPortSendException;
FOUNDATION_EXPORT NSString * const NSPortReceiveException;
FOUNDATION_EXPORT NSString * const NSOldStyleException;

FOUNDATION_EXPORT_CLASS
@interface NSException:NSObject <NSCoding, NSCopying>

+(void)raise:(NSString *)name format:(NSString *)format,...;
+(void)raise:(NSString *)name format:(NSString *)format arguments:(va_list)arguments;

-initWithName:(NSString *)name reason:(NSString *)reason userInfo:(NSDictionary *)userInfo;

+(NSException *)exceptionWithName:(NSString *)name reason:(NSString *)reason userInfo:(NSDictionary *)userInfo;

-(void)raise;

-(NSString *)name;
-(NSString *)reason;
-(NSDictionary *)userInfo;

-(NSArray *)callStackReturnAddresses;

@end

@interface NSException(WinObjC)
+ (void)raiseWithLogging:(NSString *)name format : (NSString *)format, ...;
@end

typedef void NSUncaughtExceptionHandler(NSException *exception);

FOUNDATION_EXPORT NSUncaughtExceptionHandler *NSGetUncaughtExceptionHandler(void);
FOUNDATION_EXPORT void NSSetUncaughtExceptionHandler(NSUncaughtExceptionHandler *);

typedef struct NSExceptionFrame {
   jmp_buf                  state;
   struct NSExceptionFrame *parent;
   __unsafe_unretained NSException             *exception;
} NSExceptionFrame;

FOUNDATION_EXPORT void __NSPushExceptionFrame(NSExceptionFrame *frame);
FOUNDATION_EXPORT void __NSPopExceptionFrame(NSExceptionFrame *frame);

#define NS_DURING \
  { \
   NSExceptionFrame __exceptionFrame; \
   __NSPushExceptionFrame(&__exceptionFrame); \
   if(setjmp(__exceptionFrame.state)==0){

#define NS_HANDLER \
    __NSPopExceptionFrame(&__exceptionFrame); \
   } \
   else{ \
    NSException *localException=__exceptionFrame.exception;

#define NS_ENDHANDLER \
   } \
  }

#define NS_VALUERETURN(val,type) \
  { __NSPopExceptionFrame(&__exceptionFrame); return val; }

#define NS_VOIDRETURN \
  { __NSPopExceptionFrame(&__exceptionFrame); return; }


#import <Foundation/NSAssertionHandler.h>

#endif /* _NSEXCEPTION_H_ */