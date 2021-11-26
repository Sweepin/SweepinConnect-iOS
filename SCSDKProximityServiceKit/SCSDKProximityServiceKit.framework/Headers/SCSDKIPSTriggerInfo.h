//
//  SCSDKIPSTriggerInfo.h
//  SCSDKProximityServiceKit
//
//  Created by Julien Goudet on 21/05/2019.
//  Copyright © 2019 Sweepin. All rights reserved.
//

@import SCSDKCoreKit;
#import "SCSDKIPSTrigger.h"

@interface SCSDKIPSTriggerInfo : SCSDKBaseEntity<NSSecureCoding>

@property (nonatomic, assign) int id;
@property (nonatomic, strong, nonnull) NSString* type;
@property (nonatomic, strong, nonnull) NSString* name;
@property (nonatomic, strong, nonnull) NSString* keywords;
@property (nonatomic, strong, nonnull) NSDictionary* properties;
@property (nonatomic, strong, nonnull) NSString* icon;
@property (nonatomic, strong, nullable) NSString* b64Icon;
@property (nonatomic, assign) int shortcut;
@property (nonatomic, strong, nonnull) NSArray<SCSDKIPSTrigger*>* ipsTriggers;

@end
