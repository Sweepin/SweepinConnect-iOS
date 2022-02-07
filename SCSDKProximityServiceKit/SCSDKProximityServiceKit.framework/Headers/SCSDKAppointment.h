//
//  SCSDKAppointment.h
//  SCSDKProximityServiceKit
//
//  Created by Julien Goudet on 21/05/2019.
//  Copyright © 2019 Sweepin. All rights reserved.
//

@import SCSDKCoreKit;
#import "SCSDKIPSTriggerInfo.h"
#import "SCSDKContentTemplate.h"
#import "SCSDKTransmitter.h"
#import "SCSDKPoi.h"

@interface SCSDKAppointment: SCSDKBaseEntity

@property (nonatomic, assign) int id;
@property (nonatomic, strong, nonnull) NSString* startDate;
@property (nonatomic, strong, nonnull) NSString* endDate;
@property (nonatomic, strong, nonnull) NSString* appointmentId;
@property (nonatomic, strong, nonnull) NSString* with;
@property (nonatomic, strong, nonnull) NSString* email;
@property (nonatomic, strong, nonnull) NSString* phone;
@property (nonatomic, strong, nonnull) NSString* informations;
@property (nonatomic, strong, nonnull) NSString* state;
@property (nonatomic, strong, nonnull) NSString* created;
@property (nonatomic, strong, nonnull) NSString* updated;
@property (nonatomic, assign) int status;
@property (nonatomic, assign) int archive;
@property (nonatomic, assign) int eligible;
@property (nonatomic, strong, nonnull) NSString* _admissionStatus;

@property (nonatomic, strong, nonnull) SCSDKIPSTriggerInfo* ipsTriggerInfo;
@property (nonatomic, strong, nullable) SCSDKContentTemplate* contentTemplate;
@property (nonatomic, strong, nullable) SCSDKPoi* poi;
@property (nonatomic, strong, nonnull) NSArray<SCSDKTransmitter*>* transmitters;
@end
