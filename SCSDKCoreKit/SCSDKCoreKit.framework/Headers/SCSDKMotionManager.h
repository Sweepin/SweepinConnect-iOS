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

@protocol SCSDKMotionManagerIndoorPositioningSystemDataSource <NSObject>
@required
-(void)motionManager:(SCSDKMotionManager *)manager handlerForDeviceMotionUpdatesWithData:(CMDeviceMotion *)deviceMotion error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForAccelerometerUpdatesWithData:(CMAccelerometerData *)accelerometerData error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForLinearAccelerometerUpdatesWithData:(CMAccelerometerData *)accelerometerData error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForMagnetometerUpdatesWithData:(CMMagnetometerData *)magnetometerData error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForAltimeterUpdatesWithData:(CMAltitudeData *)altitudeData error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForGyroscopeUpdatesWithData:(CMGyroData *)gyroData error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForPedometerUpdatesWithData:(CMPedometerData *)pedometerData error:(NSError *)error;
-(void)motionManager:(SCSDKMotionManager *)manager handlerForPedometerEventUpdatesWithEvent:(CMPedometerEvent *)pedometerEvent error:(NSError *)error API_AVAILABLE(ios(10.0));

@end

@interface SCSDKMotionManager : CMMotionManager
@property (strong) id<SCSDKMotionManagerIndoorPositioningSystemDataSource> indoorPositioningSystemDataSource;

-(void)startDeviceMotion;
-(void)stopDeviceMotion;

-(void)startGyroscope;
-(void)stopGyroscope;

//-(void)startAccelerometer;
//-(void)stopAccelerometer;

-(void)startPedometer;
-(void)stopPedometer;

-(void)startMagnetometer;
-(void)stopMagnetometer;

-(void)startAltimeter;
-(void)stopAltimeter;

-(void)startAccelerometer;
-(void)stopAccelerometer;

// Queue
@property (nonatomic, strong) NSOperationQueue *queue;

@end
