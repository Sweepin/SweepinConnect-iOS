//
//  SCSDKProximityServiceNetworkManager.h
//  SCSDKProximityServiceKit
//
//  Created by Alex on 08/12/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import <SCSDKCoreKit/SCSDKNetworkManager.h>


@interface SCSDKProximityServiceNetworkManager : SCSDKNetworkManager

-(id)initWithAppId:(NSString*) appId andSecret:(NSString*) appSecret;

-(void)postCampaignLogs:(NSArray *)arrLogs withSuccessHandler:(void (^)(id object))success andFailureHandler:(void (^)(NSError *error))failure;

-(void)postTransmitterLogs:(NSArray *)arrLogs withSuccessHandler:(void (^)(id object))success andFailureHandler:(void (^)(NSError *error))failure;

@property (nonatomic, assign) BOOL useASIdentifier;

@property (nonatomic, strong, readonly) NSString *appVersion;

@property (nonatomic, strong, readonly) NSString *mediaBaseUrl;
@end
