//
//  SCSDKProximityService.h
//  SCSDKProximityServiceKit
//
//  Created by Alex on 28/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
#import "SCSDKProximityServiceDisplayDelegate.h"

#define kUserActionReceived @"received_background,received_foreground,anim_received"
#define kUserActionReceivedBackground @"received_background"
#define kUserActionReceivedForeground @"received_foreground"
#define kUserActionSaved @"saved"

@class SCSDKProximityServiceCampaignDisplayManager;
@class SCSDKCampaign;

@protocol SCSDKProximityServiceDelegate <NSObject>

@optional
-(void)didReceiveCampaigns:(NSArray *)campaigns;
-(void)didDisplayCampaign:(SCSDKCampaign *)campaign firstTime:(BOOL)firstTime;
-(void)handleActionForCampaignIdentifier:(NSString *)identifier;

-(BOOL)shouldTapRightButtonWithCampaigns:(NSArray *)campaigns;
-(BOOL)shouldTapLeftButtonWithCampaigns:(NSArray *)campaigns;
-(void)didTapRightButtonWithCampaigns:(NSArray *)campaigns;
-(void)didTapLeftButtonWithCampaigns:(NSArray *)campaigns;

@end

@interface SCSDKProximityService : NSObject

/**
 * The singleton used to access all methods from SCSDKProximityServiceKit
 */
+(SCSDKProximityService *)sharedInstance;

@property (nonatomic, strong) id<SCSDKProximityServiceDelegate> delegate;

#pragma mark AppId / AppSecret

/**
 * Call this method on your service instance to authenticate within our API.
 *
 * If you do not have your app id and secret -provided by the Sweepin registration process- please contact the Sweepin team.
 **/
-(void)initWithAppId:(NSString*) appId andSecret:(NSString*) secret;
    
#pragma mark Parameters

/**
 * The minimum distance (measured in meters) a device must move horizontally before an update event is generated.
 * The default value of this property is 10
 *
 * Example :
 * If you have 2 point of sells distant from 25 kilometers,
 * you dont need location update to be triggered every 10 meters.
 * In this case, you can set it to a lower value.
 **/
@property (nonatomic,assign) float distanceFilter;

/**
 * Set this boolean to YES if you want to prevent SweepinConnect's ProximityService to present notifications.
 * If so, our campaigns will only show if the app is in foreground.
 * Can be used as an user parameter.
 */
@property (nonatomic, assign) BOOL deactivateNotificationWhenOnBackground;

#pragma mark Utils

/**
 * The most recently retrieved user location.
 **/
@property (nonatomic,readonly,strong) CLLocation *location;

#pragma mark Start/Stop Methods

/**
 * Start SweepinConnect Proximity Service (Geofence and Beacons handling)
 **/
-(void)start;

/**
 * Stop SweepinConnect Proximity Service
 **/
-(void)stop;

/**
 * This boolean allows to totally prevent our campaign display.
 **/
@property (nonatomic, assign) BOOL preventCampaignDisplay;

/**
 * This boolean indicate that your app has access to the user ASIdentifier, and that our SDK is authorized to use it.
 **/
@property (nonatomic, assign) BOOL useASIdentifier;

#pragma mark CampaignsUIDelegate
/**
 * Implement the methods from this delegate to customize RightBarButtonItems of our campaigns templates
 **/
-(void)setCampaignsTopbarUIDelegate:(id<SCSDKProximityServiceCampaignUIDelegate>)campaignsTopbarUIDelegate;

#pragma mark CampaignsUIDelegate
/**
 * Implement the methods from this delegate to customize the ToolBarButtons of our campaigns templates
 **/
-(void)setCampaignsToolbarUIDelegate:(id<SCSDKProximityServiceCampaignToolbarUIDelegate>)campaignsToolbarUIDelegate;

/**
 * Register an user in our database.
 * Example of use: segmentation by user parameter on campaigns
 *
 * The NSDictionary "usersInfos" must contains an identifier key containing the unique value that identify your user,
 * and a parameters keys with all the informations you want to save.
 *
 * Example :
 @"myDict" : @{
 @"firstParam" : @"firstValue",
 @"secondParam" : @"secondValue",
 ...
 }
 };
 *
 *  [[SCSDKProximityService sharedInstance]registerIdentifier:@"myUniqueIdentifier" withUserInfos:myDict withSuccessHandler:^(id object) {
 *      // Success
 *  } andFailureHandler:^(NSError *error) {
 *      // Failure
 *  }];
 *
 **/
-(void)registerIdentifier:(NSString*)identifier withUserInfos:(NSDictionary*) userInfos withSuccessHandler:(void (^)(id object))success andFailureHandler:(void (^)(NSError *error))failure;

-(void)removeIdentifier;

/**
 * You need to call this in your AppDelegate's didReceiveLocalNotification method.
 **/
-(void)manageLocalNotificationWithUserInfo:(NSDictionary *)userInfo;

/**
 * Returns the ProximityService bundle resources
 **/
+(NSBundle *)resourcesBundle;

/**
 * Returns a localized version of a string in ProximityService bundle resources
 **/
+(NSString *)localizedString:(NSString *)key;

/**
 * Returns an UIImage contained in ProximityService resources
 **/
+(UIImage *)imageNamed:(NSString *)imageName;

/**
 * Use this method to check if our SDK can manage a QRCode
 **/
-(BOOL)canManageMetadataObjects:(NSArray *)metadataObjects;

/**
 * Use this method to manage the scan of a QRCode
 **/
-(void)manageMetadataObjects:(NSArray *)metadataObjects withSuccessHandler:(void (^)(id object))success andFailureHandler:(void (^)(NSError *error))failure;

/**
 * Use this method to get user's campaigns
 * Set the userAction parameter to @"saved" to get the campaigns the user put into their favorites, @"received_foreground" or @"received_background" for the campaigns they received last. You can combine multiple by separating them with a comma
 * Example : userAction = @"received_foreground,received_background"
 **/
-(void)getCampaignsByUserAction:(NSString *)userAction withSuccessHandler:(void (^)(id object))success andFailureHandler:(void (^)(NSError *error))failure;

/**
 * Displaying a campaign with our UI Management
 **/
-(void)displayCampaign:(SCSDKCampaign *)campaign;

/**
 * Returns the base url for accessing medias
 **/
@property (nonatomic,readonly,strong) NSString *mediaBaseUrl;

@end
