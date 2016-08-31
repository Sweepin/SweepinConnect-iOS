//
//  PRX.h
//  Proximity
//
//  Created by Johan Jégard on 11/11/2013.
//  Copyright (c) 2013 Johan Jégard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PRXAnimationViewControllerDelegate.h"

@class PRXLocationManager;
@class PRXWebService;
@class PRXAppUser;

@interface PRX : NSObject{
    PRXLocationManager *_locationManager;
    PRXWebService *_WSManager;
    NSString *_appId;
    NSString *_appSecret;
}
/* @todo :  put locationmanager on readonly for SDK  */
@property (nonatomic,strong) PRXLocationManager *locationManager;
@property (nonatomic,strong) PRXWebService *WSManager;
@property (nonatomic,assign) float minDistanceForPoiAnimationsUpdates;
@property (nonatomic,readonly) NSString *appId;
@property (nonatomic,readonly) NSString *appSecret;
@property (nonatomic,readonly) PRXAppUser *user;
@property (nonatomic,readonly) BOOL animationIsPending;
@property (nonatomic,assign) BOOL appMightBeKilled;
@property (nonatomic,strong) id<PRXAnimationViewControllerDelegate> animationDelegate;

@property (nonatomic, strong) NSDictionary* multipleAnimationsScreenProperties;
@property (nonatomic, copy) void (^simpleNotificationActionBlock)(NSString*);
@property (nonatomic, strong) NSDictionary* simpleAnimationPopupProperties;
@property (nonatomic, assign) BOOL disableFavoriteOption;

@property (nonatomic, copy) BOOL (^customUrlManagementBlock)(NSURL*, UIViewController*);

@property (strong, nonatomic) UIBarButtonItem *animationsCustomRightBarButtonItem;

@property (nonatomic, assign) BOOL showIconBadgeNumber;
@property (nonatomic, assign) BOOL enableAdvertisingIdentifier;
/**
 * Enable the intrusive mode. When intrusive mode is enabled
 * every active zone the user crosses with his phone on his pocket, a notification will be triggered.
 * Example for enableIntrusiveMode = YES  : you cross 3 active beacons with your phone in your pocket, you'll get 3 notifications
 * Example for enableIntrusiveMode = NO  : you cross 3 active beacons with your phone in your pocket, you'll get ONLY the first notification, you'll not get the 2 others until you click on the first notification 
 * Default to YES
 */
@property (nonatomic,assign) BOOL enableIntrusiveMode;

/**
 * Mininum distance that will trigger update of beacons list by geolocating the device.
 * This is the distanceFilter property of CLLocationManager class
 * Example :
 * If you have 2 point of sells distant from 25 kilometers,
 * you dont need location update to be triggered every 10 meters.
 * In this case, you can set it to a lower value.
 * Default : 10 meters
 **/
@property (nonatomic,assign) float locationManagerDistanceFilter;

/**
* Return the PRX shared instance.
* Call this each time you want to call any PRX method.
**/
+ (PRX *)singleton;

/**
 * Use this method to init the Proximities SDK
 * Provide a valid appId and secret and you're good to go.
 **/
- (void) initWithAppId:(NSString*) appId andSecret:(NSString*) secret;

/**
 * You need to call this in the AppDelegate's didReceiveLocalNotification function.
 **/

- (void) manageLocalNotificationForUserInfo:(NSDictionary  *)userInfo;

/**
 * Get a list of all Proximities partners
 */
-(NSArray*) getPartners;
-(NSArray*) getCategories;

/**
 * Get the current proximities bundle
 */
+ (NSBundle *)bundle;

/**
 * Return a dictionnary of key/value parameters
 * based on the http URI parameters.
 * Ex: name=test&value=3
 */
-(NSDictionary*)parametersFromQueryString:(NSString*)query;

/**
 * With this method, you can set the PRXAnimationViewControllerDelegate delegate to a class that conforms to the protocol.
 **/
-(void) setAnimationViewControllersDelegate:(id<PRXAnimationViewControllerDelegate>) object;

/**
 * Present the list of favorites campaigns/animations added by the current user
 * Currently displayed in a nice preview collectionViewController with curved layout.
 * List of customizable attributes :
 *   @{
        @"topbarTitle":@"My favorites",
        @"topbarTextColor":[UIColor orangeColor],
        @"tintColor":[UIColor orangeColor],
        @"textColor":[UIColor brownColor],
        @"topbarTintColor":[UIColor whiteColor],
        @"emptyCaseTitle" : @"Aucun élément disponible actuellement"
    };
 *
 */
-(void) presentAnimationsCollectionViewControllerWithUIAttributes:(NSDictionary *)attributes forUserAction:(NSString *)userAction;

/**
 * Push the list of favorites campaigns/animations added by the current user
 * Currently displayed in a nice preview collectionViewController with curved layout.
 * List of customizable attributes :
 *   @{
        @"topbarTitle":@"My favorites",
        @"topbarTextColor":[UIColor orangeColor],
        @"tintColor":[UIColor orangeColor],
        @"textColor":[UIColor brownColor],
        @"topbarTintColor":[UIColor whiteColor],
        @"emptyCaseTitle" : @"Aucun élément disponible actuellement"
    };
 *
 */
-(void) pushAnimationsCollectionViewControllerWithUIAttributes:(NSDictionary *)attributes fromCurrentViewController:(UIViewController *)viewController forUserAction:(NSString *)userAction;

/**
 * Present the current user's list of animations (put in favorites or received)
 * Displayed in a simple UITableView.
 * UserAction value can be @"saved" or @"anim_received"
 * Example of customized attributes :
 *   @{
 @"noResultsMessage":@"Pas de résultats",
 @"failToRetrieveMessage":@"Pas de réseau",
 @"notifTitleColor":@"1a0dab",
 @"noResultsMessageTitleColor":@"fa99cc",
 @"failToRetrieveMessageTitleColor":@"b90d75",
 @"topBarTintColor":@"ffffff",
 @"topBarBackgroundColor":@"d54586",
 @"topBarTitle":@"Notifications",
 @"topBarTitleFont":[UIFont myFont]
 };
 *
 */
-(void) presentAnimationsTableViewControllerWithUIAttributes:(NSDictionary *)attributes forUserAction:(NSString *)userAction;

/**
 * Push the current user's list of animations (put in favorites or received)
 * Displayed in a simple UITableView.
 * UserAction value can be @"saved" or @"anim_received"
 * Example of customized attributes :
 *   @{
 @"noResultsMessage":@"Pas de résultats",
 @"failToRetrieveMessage":@"Pas de réseau",
 @"notifTitleColor":@"1a0dab",
 @"noResultsMessageTitleColor":@"fa99cc",
 @"failToRetrieveMessageTitleColor":@"b90d75",
 @"topBarTintColor":@"ffffff",
 @"topBarBackgroundColor":@"d54586",
 @"topBarTitle":@"Notifications",
 @"topBarTitleFont":[UIFont myFont]
 };
 *
 */
-(void) pushAnimationsTableViewControllerWithUIAttributes:(NSDictionary *)attributes fromCurrentViewController:(UIViewController *)viewController forUserAction:(NSString *)userAction;

/**
 * Get the top most VC
 */
-(UIViewController *)topViewController;

/**
 * In some cases, you'll want to prevent the SDK
 * to display things.
 * This prevent / restart display of animations (campaigns)
 */
- (void)stopAnimationsDisplay;
- (void)restartAnimationsDisplay;


/**
 * Register an user in the database
 * Example of use: segmentation on animations
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
 *  [[PRX singleton]registerIdentifier:@"myUniqueIdentifier" withUserInfos:myDict withSuccessHandler:^(id object) {
 *      // Success
 *  } andFailureHandler:^(NSError *error) {
 *      // Failure
 *  }];
 *
 */

- (void) registerIdentifier:(NSString*)identifier withUserInfos:(NSDictionary*) userInfos withSuccessHandler:(void (^)(id object))success andFailureHandler:(void (^)(NSError *error))failure;

/**
 * Return an UIImage stored in PRX resources bundle
 */
-(UIImage*)bundleImageFrom:(NSString*)name;

/**
 * Get a NSArray object containing the current user's campaigns/animations by userAction (@"saved" to get the animations the user put into their favorites or @"anim_received" if you want the animations they received last).
 */
-(void) getAnimationsByUserAction:(NSString *)userAction withSuccessHandler:(void (^)(NSArray * animations))success
                andFailureHandler:(void (^)(NSError *error))failure;

/**
 * Prevent all animations to be displayed.
 * This method can be used as a user's parameter.
 * Default to NO.
 */
-(void)preventAnimations:(BOOL)userChoice;

/**
 * Your app has been opened after scanning a QRCode with another app.
 * This method send the QRCode url to our SDK, that check if a campaign has to be displayed.
 */
-(void)manageNotificationFromQrCodeUrl:(NSURL *)url;

@end
