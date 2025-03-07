/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSCALENDAR_H_
#define _NSCALENDAR_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <CoreFoundation/CFCalendar.h>
#import <Foundation/NSDate.h>
#import <Foundation/FoundationExport.h>

@class NSDateComponents, NSTimeZone, NSLocale, NSDate;

enum {
    NSEraCalendarUnit = kCFCalendarUnitEra,
    NSYearCalendarUnit = kCFCalendarUnitYear,
    NSMonthCalendarUnit = kCFCalendarUnitMonth,
    NSDayCalendarUnit = kCFCalendarUnitDay,
    NSHourCalendarUnit = kCFCalendarUnitHour,
    NSMinuteCalendarUnit = kCFCalendarUnitMinute,
    NSSecondCalendarUnit = kCFCalendarUnitSecond,
    NSWeekCalendarUnit = kCFCalendarUnitWeek,
    NSWeekdayCalendarUnit = kCFCalendarUnitWeekday,
    NSWeekdayOrdinalCalendarUnit = kCFCalendarUnitWeekdayOrdinal,
    NSQuarterCalendarUnit = kCFCalendarUnitQuarter,
    NSWeekOfMonthCalendarUnit = kCFCalendarUnitWeekOfMonth,
    NSWeekOfYearCalendarUnit = kCFCalendarUnitWeekOfYear,
    NSYearForWeekOfYearCalendarUnit = kCFCalendarUnitYearForWeekOfYear,
    NSCalendarCalendarUnit = (1 << 20),
    NSTimeZoneCalendarUnit = (1 << 21),
};
typedef uint32_t NSCalendarUnit;

SB_EXPORT NSString * const NSGregorianCalendar;

FOUNDATION_EXPORT_CLASS
@interface NSCalendar : NSObject <NSCopying> 

+ currentCalendar;
+ (id)autoupdatingCurrentCalendar;

- initWithCalendarIdentifier:(NSString *)identifier;

- (NSString *)calendarIdentifier;
- (NSUInteger)firstWeekday;
- (NSUInteger)minimumDaysInFirstWeek;
- (NSTimeZone *)timeZone;
- (NSLocale *)locale;

- (void)setFirstWeekday:(NSUInteger)weekday;
- (void)setMinimumDaysInFirstWeek:(NSUInteger)days;
- (void)setTimeZone:(NSTimeZone *)timeZone;
- (void)setLocale:(NSLocale *)locale;

- (NSRange)minimumRangeOfUnit:(NSCalendarUnit)unit;
- (NSRange)maximumRangeOfUnit:(NSCalendarUnit)unit;
- (NSRange)rangeOfUnit:(NSCalendarUnit)unit inUnit:(NSCalendarUnit)inUnit forDate:(NSDate *)date;
- (NSUInteger)ordinalityOfUnit:(NSCalendarUnit)unit inUnit:(NSCalendarUnit)inUnit forDate:(NSDate *)date;

- (NSDateComponents *)components:(NSUInteger)flags fromDate:(NSDate *)date;
- (NSDateComponents *)components:(NSUInteger)flags fromDate:(NSDate *)fromDate toDate:(NSDate *)toDate options:(NSUInteger)options;

- (NSDate *)dateByAddingComponents:(NSDateComponents *)components toDate:(NSDate *)date options:(NSUInteger)options;
- (NSDate *)dateFromComponents:(NSDateComponents *)components;
- (BOOL)rangeOfUnit:(NSCalendarUnit)unit startDate:(NSDate **)datep interval:(NSTimeInterval *)tip forDate:(NSDate *)date;
 
@end

#endif /* _NSCALENDAR_H_ */