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

#import "SCSDKApiManagerNetworkManager.h"
#import "SCSDKApiManagerPoiTableViewCell.h"
#import "SCSDKAudioCampaignViewController.h"
#import "SCSDKAudioPlayerView.h"
#import "SCSDKCampaign.h"
#import "SCSDKCustomWebViewController.h"
#import "SCSDKFullscreenCampaignViewController.h"
#import "SCSDKLoyaltyCampaignViewController.h"
#import "SCSDKMultipleCampaignsTableViewCell.h"
#import "SCSDKMultipleCampaignsTableViewController.h"
#import "SCSDKPartner.h"
#import "SCSDKPoi.h"
#import "SCSDKProximityService.h"
#import "SCSDKProximityServiceBeaconManager.h"
#import "SCSDKProximityServiceCampaignActionManager.h"
#import "SCSDKProximityServiceCampaignDisplayManager.h"
#import "SCSDKProximityServiceDisplayDelegate.h"
#import "SCSDKProximityServiceGeofenceManager.h"
#import "SCSDKProximityServiceKit.h"
#import "SCSDKProximityServiceLogsManager.h"
#import "SCSDKProximityServiceNetworkManager.h"
#import "SCSDKProximityServiceQRCodeManager.h"
#import "SCSDKQrCodeReaderViewController.h"
#import "SCSDKRealmCampaign.h"
#import "SCSDKRealmCampaignLog.h"
#import "SCSDKRealmPoi.h"
#import "SCSDKRealmTransmitter.h"
#import "SCSDKRealmTransmitterLog.h"
#import "SCSDKRichCampaignViewController.h"
#import "SCSDKTransmitter.h"
#import "SCSDKWebviewCampaignViewController.h"
#import "Urls.h"

FOUNDATION_EXPORT double SCSDKProximityServiceKitVersionNumber;
FOUNDATION_EXPORT const unsigned char SCSDKProximityServiceKitVersionString[];

