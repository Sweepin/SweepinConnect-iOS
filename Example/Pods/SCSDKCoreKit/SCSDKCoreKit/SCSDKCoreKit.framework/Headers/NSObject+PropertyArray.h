//
//  NSObject+PropertyArray.h
//  SCSDKCoreKit
//
//  Created by Alex on 21/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (PropertyArray)
- (NSArray *) allKeys;
- (id)customClassWithProperties:(NSDictionary *)properties;
- (id)initWithProperties:(NSDictionary *)properties;
- (id)valueForUndefinedKey:(NSString *)key;
- (NSDictionary *) dictionaryWithPropertiesOfObject:(id)obj;
@end
