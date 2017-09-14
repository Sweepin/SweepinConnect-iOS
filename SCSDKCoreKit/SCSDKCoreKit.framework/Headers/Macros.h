//
//  Macros.h
//  SCSDKCoreKit
//
//  Created by Alex on 22/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#ifndef Macros_h
#define Macros_h

#import "UIColor+Hexa.h"

#define concatString(A,B) [(A) stringByAppendingString:(B)]

//- (NSData *)loadDataFromURL:(NSString *)dataURL
//{
//    START_TIMER;
//    NSData *data = [self doSomeStuff:dataURL];
//    END_TIMER(@"loadDataFromURL");
//    return data;
//}
#   define START_TIMER NSTimeInterval start = [NSDate timeIntervalSinceReferenceDate];
#   define END_TIMER(msg) 	NSTimeInterval stop = [NSDate timeIntervalSinceReferenceDate]; dlog([NSString stringWithFormat:@"%@ Time = %f", msg, stop-start]);

#ifdef DEBUG

// Pretty NSLog
#   define dlog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#   define cleanDlog(FORMAT, ...) fprintf(stderr,"%s\n", [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);

#define TICK   [[NSUserDefaults standardUserDefaults]setObject:[NSNumber numberWithDouble:CACurrentMediaTime()] forKey:@"TICK"];dlog(@"TICK");
#define TOCK   dlog(@"TOCK : %f", CACurrentMediaTime() - [[[NSUserDefaults standardUserDefaults] objectForKey:@"TICK"]doubleValue]);

#else

#   define dlog(...)
#   define cleanDlog(...)
#define TICK
#define TOCK

#endif


#endif /* Macros_h */
