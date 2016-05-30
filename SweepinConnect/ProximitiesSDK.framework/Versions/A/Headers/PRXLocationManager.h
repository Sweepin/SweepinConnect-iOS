//
//  PRXLocationManager.h
//  ExampleApp
//
//  Created by Johan Jégard on 09/02/2014.
//  Copyright (c) 2014 Johan Jégard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

@class PRXWebService;

@interface PRXLocationManager : NSObject <CLLocationManagerDelegate, UIAlertViewDelegate>{
    NSMutableArray *_beacons;
}
@property (nonatomic, readonly, strong) NSMutableArray *beacons;
@property (nonatomic,readonly,strong) CLLocation *lastKnownLocation;
@property (nonatomic,readonly,strong) CLLocation *lastAnimationDisplayLocation;

/***
 * Default proximity UUIDs to monitor, without any need of location updates.
 * Use this default UUIDs to improve beacons detection efficiency.
 **/
@property (nonatomic) NSArray *defaultProximityUUIDs;
@property(nonatomic, assign)BOOL localNotifIsFromPush;
@property(nonatomic, assign)BOOL localNotifIsFromMulti;

-(void) manageMultipleAnimationsDisplayWithDict:(NSDictionary *) PRXAnimationsInfos;
-(void) manageAnimationDisplayWithDict:(NSDictionary *) PRXAnimationInfo;
- (UIViewController *)topViewController;
- (void) initDefaultBeaconRegions;
- (void)showPopupForSimpleNotification:(NSDictionary*)simpleNotification;

@end
