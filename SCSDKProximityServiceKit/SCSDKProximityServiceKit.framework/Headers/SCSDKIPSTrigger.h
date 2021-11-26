//
//  SCSDKIPSTrigger.h
//  SCSDKProximityServiceKit
//
//  Created by Julien Goudet on 21/05/2019.
//  Copyright © 2019 Sweepin. All rights reserved.
//

@import SCSDKCoreKit;

@interface SCSDKIPSTrigger : SCSDKBaseEntity<NSSecureCoding>

@property (nonatomic, assign) int id;
@property (nonatomic, strong, nonnull) NSString* idMapping;
@property (nonatomic, strong, nonnull) NSString* ipsId;
@property (nonatomic, strong, nonnull) NSString* type;
@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double longitude;
@property (nonatomic, assign) double displayLatitude;
@property (nonatomic, assign) double displayLongitude;
@property (nonatomic, strong, nonnull) NSString* level;

@end
