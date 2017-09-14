//
//  SCSDKProximityServiceDisplayDelegate.h
//  SCSDKProximityServiceKit
//
//  Created by Alexis Barat on 14/09/2017.
//  Copyright © 2017 Sweepin. All rights reserved.
//

#ifndef SCSDKProximityServiceDisplayDelegate_h
#define SCSDKProximityServiceDisplayDelegate_h


#endif /* SCSDKProximityServiceDisplayDelegate_h */
@class SCSDKCampaign;

@protocol SCSDKProximityServiceCampaignUIDelegate <NSObject>

/**
 * Return your home-made array of UIBarButtonItem here to customize the navigation bar in our campaigns templates.
 **/
-(NSArray *)getRightBarButtonItemsForCampaign:(SCSDKCampaign *)campaign;

@end

@protocol SCSDKProximityServiceCampaignToolbarUIDelegate <NSObject>

/**
 * Return your home-made array of UIBarButtonItem here to customize the toolbar bar in our campaigns templates.
 **/
-(NSArray *)getToolbarItemsForCampaign:(SCSDKCampaign *)campaign;

@end
