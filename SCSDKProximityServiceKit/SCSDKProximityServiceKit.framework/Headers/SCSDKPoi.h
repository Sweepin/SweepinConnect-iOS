//
//  SCSDKPoi.h
//  SCSDKProximityServiceKit
//
//  Created by Alex on 29/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

@import SCSDKCoreKit;

@interface SCSDKPoi : SCSDKBaseEntity

@property (nonatomic) int id;
@property (nonatomic) NSString *name;
@property (nonatomic) NSString *type;
@property (nonatomic) NSString *city;
@property (nonatomic) NSString *zipcode;
@property (nonatomic) NSString *address;
@property (nonatomic) NSString *phone;
@property (nonatomic) float latitude;
@property (nonatomic) float longitude;
@property (nonatomic) NSString *backgroundFetch;
@property (nonatomic) NSDate *created;
@property (nonatomic) NSDate *updated;
@property (nonatomic) NSString *image;

@property (nonatomic) int partnerId;
@property (nonatomic) NSArray *transmitters;
@property (nonatomic) NSArray *campaigns;

@end
