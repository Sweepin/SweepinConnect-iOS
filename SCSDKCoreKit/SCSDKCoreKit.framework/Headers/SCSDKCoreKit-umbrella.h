#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "AsyncImageView.h"
#import "Constants.h"
#import "Macros.h"
#import "NSData+GZIP.h"
#import "NSObject+KezRemoveNulls.h"
#import "NSObject+PropertyArray.h"
#import "NSURLRequest+cURL.h"
#import "Resources.h"
#import "RLMObject+PropertyArray.h"
#import "SCAsyncImageView.h"
#import "SCSDKApplicationDelegate.h"
#import "SCSDKBaseEntity.h"
#import "SCSDKCoreKit.h"
#import "SCSDKLocationManager.h"
#import "SCSDKMotionManager.h"
#import "SCSDKNetworkManager.h"
#import "SCSDKRealmEntity.h"
#import "UIColor+Hexa.h"

FOUNDATION_EXPORT double SCSDKCoreKitVersionNumber;
FOUNDATION_EXPORT const unsigned char SCSDKCoreKitVersionString[];

