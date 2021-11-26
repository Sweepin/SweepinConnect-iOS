//
//  SCSDKProximityServiceCampaignDisplayManager.h
//  SCSDKProximityServiceKit
//
//  Created by Alex on 30/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#import "SCSDKProximityServiceDisplayDelegate.h"

@class SCSDKCampaign;
@class SCSDKProximityServiceNetworkManager;

@interface SCSDKProximityServiceManager : NSObject
@property (nonatomic, strong) SCSDKProximityServiceNetworkManager *networkManager;

/**
 * Set your home-made UIBarButtonItem here to customize our RightBarButtonItem in campaigns templates.
 **/
@property (strong, nonatomic) id<SCSDKProximityServiceCampaignUIDelegate> campaignsTopbarUIDelegate;

/**
 * Set your home-made array of UIBarButtonItem here to customize our toolbar in campaigns templates.
 **/
@property (strong, nonatomic) id<SCSDKProximityServiceCampaignToolbarUIDelegate> campaignsToolbarUIDelegate;

/**
 * Programmatically check if a campaign is actually displayed.
 * Can be used to avoid displaying another view above.
 **/
@property (nonatomic, assign) BOOL pendingCampaign;

/**
 * This boolean allows to totally prevent our campaign display.
 **/
@property (nonatomic, assign) BOOL preventCampaignDisplay;

/**
 * Check if  one or more campaigns can be displayed, according to :
 * - Current state of [[UIApplication sharedApplication] applicationState]
 * - pendingCampaign boolean
 * - preventCampaignDisplay boolean
 *
 * If Yes, send logs to our back-office and display them
 **/
-(void)manageCampaignsDisplay:(NSArray *)arrCampaigns;

-(void)manageLocalNotificationWithUserInfo:(NSDictionary *)userInfo;

/**
 * Displaying a campaign with our UI Management
 **/
-(void)displayCampaign:(SCSDKCampaign *)campaign;

/*to remove */
- (UIViewController *)topViewController;


@end
