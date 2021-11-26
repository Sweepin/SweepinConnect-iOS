//
//  SCSDKContentTemplate.h
//  SCSDKProximityServiceKit
//
//  Created by Julien Goudet on 21/05/2019.
//  Copyright © 2019 Sweepin. All rights reserved.
//

@import SCSDKCoreKit;


@interface SCSDKContentTemplate : SCSDKBaseEntity

@property (nonatomic, assign) int id;
@property (nonatomic, strong, nonnull) NSString* identifier;
@property (nonatomic, strong, nonnull) NSString* type;
@property (nonatomic, strong, nonnull) NSString* name;
@property (nonatomic, strong, nonnull) NSString* title;
@property (nonatomic, strong, nonnull) NSString* contentText;
@property (nonatomic, strong, nonnull) NSString* created;
@property (nonatomic, strong, nonnull) NSString* updated;
@property (nonatomic, assign) int status;
@property (nonatomic, assign) int archive;


@end
