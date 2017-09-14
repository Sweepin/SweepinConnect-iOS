//
//  SCSDKLocationManager.h
//  SCSDKCoreKit
//
//  Created by Alex on 21/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol SCSDKLocationManagerProximityServiceDataSource
@required
-(void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations;

-(void)locationManager:(CLLocationManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;
-(void)locationManager:(CLLocationManager *)manager didEnterRegion:(CLRegion *)region;
-(void)locationManager:(CLLocationManager *)manager didExitRegion:(CLRegion *)region;
-(void)locationManager:(CLLocationManager *)manager didStartMonitoringForRegion:(CLRegion *)region;
-(void)locationManager:(CLLocationManager *)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region;
@end

@protocol SCSDKLocationManagerIndoorPositioningSystemDataSource
@required
-(void)locationManager:(CLLocationManager *)manager didUpdateHeading:(CLHeading *)heading;

-(void)locationManager:(CLLocationManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;
-(void)locationManager:(CLLocationManager *)manager didEnterRegion:(CLRegion *)region;
-(void)locationManager:(CLLocationManager *)manager didExitRegion:(CLRegion *)region;
-(void)locationManager:(CLLocationManager *)manager didStartMonitoringForRegion:(CLRegion *)region;
-(void)locationManager:(CLLocationManager *)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region;

@end

@interface SCSDKLocationManager : CLLocationManager
@property (strong) id <SCSDKLocationManagerProximityServiceDataSource> proximityServiceDataSource;
@property (strong) id <SCSDKLocationManagerIndoorPositioningSystemDataSource> indoorPositioningSystemDataSource;

@end
