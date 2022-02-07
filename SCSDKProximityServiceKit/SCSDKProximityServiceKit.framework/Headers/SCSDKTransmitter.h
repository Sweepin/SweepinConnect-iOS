//
//  SCSDKTransmitter.h
//  SCSDKProximityServiceKit
//
//  Created by Alex on 07/12/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

@import SCSDKCoreKit;

@interface SCSDKTransmitter : SCSDKBaseEntity<NSSecureCoding>

@property (nonatomic, assign) int id;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *role;
//@property (nonatomic, retain) NSString *description;
@property (nonatomic, retain) NSString *type;
@property (nonatomic, retain) NSString *location;
@property (nonatomic, retain) NSUUID *uuid;
@property (nonatomic, retain) NSString *installationDate;
@property (nonatomic, retain) NSString *revisionDate;
@property (nonatomic, retain) NSString *brand;
@property (nonatomic, retain) NSString *model;
@property (nonatomic, retain) NSString *serialNumber;
@property (nonatomic, retain) NSNumber *major;
@property (nonatomic, retain) NSNumber *minor;
@property (nonatomic, retain) NSString *instance;
//@property (nonatomic, retain) NSString *namespace;
@property (nonatomic, retain) NSString *url;
@property (nonatomic, retain) NSString *inApp;
@property (nonatomic, retain) NSString *created;
@property (nonatomic, retain) NSString *updated;
@property (nonatomic, retain) NSString *archive;
@property (nonatomic, retain) NSString *createdBy;
@property (nonatomic, retain) NSString *isCreatedByAdmin;
@property (nonatomic, retain) NSString *batteryLife;
@property (nonatomic, retain) NSString *batteryLeft;
@property (nonatomic, retain) NSString *batteryWarning;
@property (nonatomic, retain) NSString *status;

@property (nonatomic, assign) int poiId;

@property (nonatomic, retain) NSArray<NSDictionary*> *campaigns;
@property (nonatomic, retain) NSArray<NSDictionary*> *poi;

@end
