//
//  SCSDKMotionManager.h
//  SCSDKCoreKit
//
//  Created by Alex on 24/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

@class SCSDKMotionManager;

@protocol SCSDKMotionManagerIndoorPositioningSystemDataSource
@required
-(void)motionManager:(SCSDKMotionManager *)manager handlerForGyroUpdatesWithData:(CMGyroData *)gyroData error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForAccelerometerUpdatesWithData:(CMAccelerometerData *)accelerometerData error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForPedometerUpdatesWithData:(CMPedometerData *)pedometerData error:(NSError *)error;
@end

@interface SCSDKMotionManager : CMMotionManager
@property (strong) id<SCSDKMotionManagerIndoorPositioningSystemDataSource> indoorPositioningSystemDataSource;

-(void)startGyroscopeUpdates;
-(void)stopGyroscopeUpdates;

-(void)startAccelerometerUpdates;
// stopAccelerometerUpdates is the same than parent's

-(void)startPedometerUpdates;


@end
