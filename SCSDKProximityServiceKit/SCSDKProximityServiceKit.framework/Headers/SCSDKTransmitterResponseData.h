//
//  SCSDKTransmitterResponseData.h
//  SCSDKProximityServiceKit
//
//  Created by Julien Goudet on 21/05/2019.
//  Copyright © 2019 Sweepin. All rights reserved.
//

//@import SCSDKCoreKit;
#import "SCSDKTransmitter.h"

@class SCSDKAppointment;

@interface SCSDKTransmitterResponseData : SCSDKBaseEntity
@property (nonatomic, nonnull) NSArray<SCSDKTransmitter *> *transmitters;
@property (nonatomic, nonnull) NSArray<SCSDKAppointment *> *appointments;
@property (nonatomic, nonnull) NSArray<SCSDKAppointment *> *allAppointments;
@end
