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
@property (nonatomic, assign) int id;
@property (nonatomic, retain) NSString *type;
@property (nonatomic, retain) NSString *templateType;
@property (nonatomic, retain) NSString *identifier;
@property (nonatomic, retain) NSString *title;
@property (nonatomic, retain) NSString *topbarTitle;
@property (nonatomic, retain) NSString *contentText;
@property (nonatomic, retain) NSString *contentBackgroundColor;
@property (nonatomic, retain) NSString *contentFontColor;
@property (nonatomic, retain) NSString *startDate;
@property (nonatomic, retain) NSString *endDate;
@property (nonatomic, retain) NSString *banner;
@property (nonatomic, retain) NSString *image;
@property (nonatomic, retain) NSString *webviewUrl;
@property (nonatomic, retain) NSString *topbarButton;
@property (nonatomic, retain) NSString *nbStamps;
@property (nonatomic, retain) NSString *media;

// Set programmatically
@property (nonatomic, retain) NSString *transmitterId;
@property (nonatomic, retain) NSString *favorite;
@property (nonatomic, retain) NSString *locked;
@property (nonatomic, retain) NSString *timeLeft;
@property (nonatomic, retain) NSString *userStamps;
@property (nonatomic, retain) NSString *backgroundFetch;

@property (nonatomic, retain) SCSDKPoi *poi;
@property (nonatomic, retain) SCSDKTransmitter *transmitter;

@end
