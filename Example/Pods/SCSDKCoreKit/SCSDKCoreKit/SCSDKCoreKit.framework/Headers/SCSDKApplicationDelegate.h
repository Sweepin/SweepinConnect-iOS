//
//  SCSDKApplicationDelegate.h
//  SCSDKCoreKit
//
//  Created by Alex on 21/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SCSDKLocationManager.h"

@interface SCSDKApplicationDelegate : NSObject{
SCSDKLocationManager *locationManager;
}

@property (nonatomic, strong) SCSDKLocationManager *locationManager;

/**
 * Return the SCSDKApplicationDelegate shared instance.
 * Call this each time you want to call any SCSDKApplicationDelegate method.
 **/
+(SCSDKApplicationDelegate *)sharedInstance;

@end
