//
//  SCSDKCampaign.h
//  SCSDKProximityServiceKit
//
//  Created by Alex on 30/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//


@import SCSDKCoreKit;
#import "SCSDKPoi.h"
#import "SCSDKTransmitter.h"

@interface SCSDKCampaign : SCSDKBaseEntity
//#warning @TODO Check if int is more reliable than NSString on args like favorites (faster comparison?)
@property (nonatomic) int id;
@property (nonatomic) NSString *type;
@property (nonatomic) NSString *templateType;
@property (nonatomic) NSString *identifier;
@property (nonatomic) NSString *title;
@property (nonatomic) NSString *topbarTitle;
@property (nonatomic) NSString *contentText;
@property (nonatomic) NSString *contentBackgroundColor;
@property (nonatomic) NSString *contentFontColor;
@property (nonatomic) NSString *startDate;
@property (nonatomic) NSString *endDate;
@property (nonatomic) NSString *banner;
@property (nonatomic) NSString *image;
@property (nonatomic) NSString *webviewUrl;
@property (nonatomic) NSString *topbarButton;
@property (nonatomic) NSString *nbStamps;
@property (nonatomic) NSString *media;

// Set programmatically
@property (nonatomic) NSString *transmitterId;
@property (nonatomic) NSString *favorite;
@property (nonatomic) NSString *locked;
@property (nonatomic) NSString *timeLeft;
@property (nonatomic) NSString *userStamps;
@property (nonatomic) NSString *backgroundFetch;

@property (nonatomic) SCSDKPoi *poi;
@property (nonatomic) SCSDKTransmitter *transmitter;

@end
