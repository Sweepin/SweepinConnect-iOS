//
//  SCSDKTransmitter.h
//  SCSDKProximityServiceKit
//
//  Created by Alex on 07/12/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

@import SCSDKCoreKit;

@interface SCSDKTransmitter : SCSDKBaseEntity
@property (nonatomic) int id;
@property (nonatomic) NSString *name;
@property (nonatomic) NSUUID *uuid;
@property (nonatomic) NSNumber *major;
@property (nonatomic) NSNumber *minor;
@property (nonatomic) NSString *type;
@property (nonatomic) NSString *url;
@property (nonatomic) int *poiId;

#warning @RENAME
@property (nonatomic) NSArray *animations;
//@property (nonatomic) NSArray *campaigns;

@property (nonatomic) NSArray *poi;

@end
