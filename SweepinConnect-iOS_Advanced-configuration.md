<p align="center" >
  <img src="http://connect.sweepin.net/img/logo/sweepin-connect-850x300.png" alt="SweepinConnectLogo" title="SweepinConnectLogo">
</p>

# SweepinConnect-iOS : Advanced configuration
## Table of contents

<!-- - [SweepinConnect Example](#example)-->
- [The SCSDKProximityServiceDelegate protocol](#PRXAnimationViewControllerDelegate)
- [Retrieve user's campaigns](#getAnim)
- [Request campaigns from a QRCode](#qrCodeReader)
- [Store user information for segmented campaigns](#segUser)
- [Prevent and restart the display of campaigns](#preventCampaign)
- [General options](#generalOptions)
	- [Location manager distance filter](#generalOptionsDistanceFilter)
	- [Confirmation messages ](#generalOptionsLocalizable)
	- [Display Manager](#displayManager)
		- [SCSDKProximityServiceCampaignUIDelegate](#campaignUIDelegate)
		- [SCSDKProximityServiceCampaignToolbarUIDelegate](#campaignToolbarUIDelegate)
	- [Advertising Identifier](#generalOptionsIDFA)

<!-- <div id='example'/>

#SweepinConnect Example 

Because code is always more talking than words, we made an example project to show you how to use the SweepinConnect SDK methods.

To run it, clone the repo, and run `pod install` from the Example directory.
<br/><br/> -->

<div id='PRXAnimationViewControllerDelegate'/>
# The SCSDKProximityServiceDelegate protocol 
Our SDK provides a protocol that you can adopt to manage user interactions.

Adopt the protocol (for example in the AppDelegate.h): 
    
	@import SCSDKProximityServiceKit;
    @interface AppDelegate : UIResponder <UIApplicationDelegate, SCSDKProximityServiceDelegate>

Then in your AppDelegate.m: 

	[[SCSDKProximityService sharedInstance]setDelegate:self];

Here is the list of the methods available: 

	-(void)didReceiveCampaigns:(NSArray *)campaigns;
	-(void)didDisplayCampaign:(SCSDKCampaign *)campaign firstTime:(BOOL)firstTime;
	-(void)handleActionForCampaignIdentifier:(NSString *)identifier;
	
	-(BOOL)shouldTapRightButtonWithCampaigns:(NSArray *)campaigns;
	-(BOOL)shouldTapLeftButtonWithCampaigns:(NSArray *)campaigns;
	-(void)didTapRightButtonWithCampaigns:(NSArray *)campaigns;
	-(void)didTapLeftButtonWithCampaigns:(NSArray *)campaigns;

>**Note:** The **identifier** is an alpha-numeric string that you can use to identify a set of campaigns to associate a specific action. Let's say you want to open the fidelity card view controller, and you have 2 campaigns. When you create your campaigns, in the Sweepin Connect back-office, you'll give the same identifier for these two campaigns (ex : 'open-fidelity-vc').
In your delegate's method implementation, you can now handle a specific action for this set of campaigns.

<div id='getAnim'/>
# Retrieve user's campaigns
The SDK provide a convenient method to get user's campaigns.

The userAction parameter allow you to get campaigns sorted by user actions.
The available values are :

	kUserActionReceived
	kUserActionReceivedBackground
	kUserActionReceivedForeground
	kUserActionSaved

Example : 

	[[SCSDKProximityService sharedInstance]getCampaignsByUserAction:kUserActionReceived withSuccessHandler:^(id object) {
		
    } andFailureHandler:^(NSError *error) {
		
    }];

The object parameter in the successHandler contains an array with user's campaigns.

<div id='qrCodeReader'/>
# Request campaigns from a QRCode

We made a ViewController implementing a QRCode reader available in our SDK.

First, import the SCSDKQrCodeReaderViewController:

	#import <SCSDKProximityServiceKit/SCSDKQrCodeReaderViewController.h>

Then create and push it :

	SCSDKQrCodeReaderViewController *qrCodeReaderVC = [[SCSDKQrCodeReaderViewController alloc]init];
	    
	qrCodeReaderVC.navigationBarBackgroundColor = [UIColor whiteColor];
	qrCodeReaderVC.navigationBarTintColor = [UIColor blueColor];
	    
	[self.navigationController pushViewController:qrCodeReaderVC animated:YES];
	    
*Note: This controller also handle vcards reading.*

If you want to implement your custom QR Code solution in your app, it's also possible.
In the *captureOutput:didOutputMetadataObjects:fromConnection:* method, you can check if our SDK is able to handle the information contained in the scanned QRCode, then send the data to it : 

	-(void)captureOutput:(AVCaptureOutput *)captureOutput didOutputMetadataObjects:(NSArray *)metadataObjects fromConnection:(AVCaptureConnection *)connection{
	    if (metadataObjects != nil && [metadataObjects count] > 0) {
	        if([[SCSDKProximityService sharedInstance]canManageMetadataObjects:metadataObjects]){
	            [[SCSDKProximityService sharedInstance]manageMetadataObjects:metadataObjects withSuccessHandler:^(id object) {
	                dispatch_async(dispatch_get_main_queue(), ^{
	                    [self.navigationController popViewControllerAnimated:YES];
	                });
	            } andFailureHandler:^(NSError *error) {
	                
	            }];
	        }
	    }
	}

<div id='segUser'/>
# Store user information for segmented campaigns
At one point, your app's customer is going to login (or auto-login) to your app.
If you want the Sweepin Connect system to be aware of your users informations, you'll need to register this user to the Sweepin system. 
To achieve this, you can call the *registerIdentifier: withUserInfos:withSuccessHandler:andFailureHandler:* method on your login/autologin routine method.

Registering users is the way to send segmented campaigns to a specific group of users.

    NSDictionary* myDict = @{ @"parameters" : @{
                           		       @"age" : @"19",
                                       @"gender" : @"male",
                                       ...
                                };
                                 
    [[SCSDKApplicationDelegate sharedInstance]registerIdentifier:@"myUniqueIdentifier" withUserInfos:myDict withSuccessHandler:^(id object) {
        
    } andFailureHandler:^(NSError *error) {
        
    }];


<div id='preventCampaign'/>
# Prevent and restart the display of campaigns
In some cases, you'll want to prevent the display of animations. 
For example, if the user is on the payment view of your app, you don't want any other screen to interfere while the user is in the payment process.

    [[SCSDKProximityService sharedInstance]setPreventCampaignDisplay:(BOOL)];


<div id='generalOptions'/>
# General options

<div id='generalOptionsDistanceFilter'/>
### Location manager distance filter

The minimum distance (measured in meters) a device must move horizontally before an update event is generated.

The default value of this property is 10    

	[[SCSDKProximityService sharedInstance]setDistanceFilter:(CGFloat)];

<div id='generalOptionsLocalizable'/>
### Confirmation messages 

You can set messages to display alerts relative to the SDK. The keys/strings values can be set in the Localizable.strings files of SCSDKResourcesForProximityServiceKit.bundle.
Here is a complete list of all the configurable parameters:

#### SCSDKQrCodeReaderViewController
	"qrcode_reader-navigation_bar_title"
	"qrcode_reader-camera_disabled_alert_title"
	"qrcode_reader-camera_disabled_alert_message"
	"qrcode_reader-camera_disabled_alert_option_title_cancel"
	"qrcode_reader-camera_disabled_alert_option_title_settings"
	"qrcode_reader-vcard_add_contact_successful"

#### SCSDKMultipleCampaignsTableViewController
	"multi_campaign-view-controller-title"
	"multi_campaign-close_action_alert_title"
	"multi_campaign-close_action_alert_message"
	"multi_campaign-close_action_alert_title"
	"multi_campaign-close_action_alert_message"
	"multi_campaign-close_action_alert_option_title_validate"
	"multi_campaign-close_action_alert_option_title_cancel"

CHECK IF SET ON:
"multi_campaign-close_action_alert_title"
"multi_campaign-close_action_alert_message"
#### Bluetooth
	"bluetooth_error-disabled_from_app_alert_title"
	"bluetooth_error-disabled_from_app_alert_message"
	"bluetooth_error-disabled_from_app_alert_option_title_cancel"
	"bluetooth_error-disabled_from_app_alert_option_title_validate"

#### Notifications
	"notification-multi_campaign_title"
	
#### Simple notification in app
	"notification_in_app-agree-action"
	"notification_in_app-disagree-action"

#### Loyalty campaign
	"loyalty_campaign-full_stamp_view_reset_label_title"
	"loyalty_campaign-full_stamp_view_reset_sublabel_title"
	"loyalty_campaign-full_stamp_view_reset_option_title_cancel"
	"loyalty_campaign-full_stamp_view_reset_option_title_validate"
	"loyalty_campaign-full_stamp_view_confirm_alert_title"
	"loyalty_campaign-full_stamp_view_confirm_alert_message"
	"loyalty_campaign-full_stamp_view_reset_done_title"

<div id='displayManager'/>
### Display Manager
You can customize some parameters of our campaigns directly from your app. We created 2 protocols for this :

<div id='campaignUIDelegate'/>
### SCSDKProximityServiceCampaignUIDelegate
The CampaignTopbarUIDelegate allow you to customize the rightBarButtonItems parameter using the *getRightBarButtonItemsForCampaign:* method. 

Adopt the protocol (for example in the AppDelegate.h):

	@import SCSDKProximityServiceKit;
	@interface AppDelegate : UIResponder <UIApplicationDelegate, SCSDKProximityServiceCampaignUIDelegate>

Then in your AppDelegate.m:

	[[SCSDKProximityService sharedInstance]setCampaignsTopbarUIDelegate:self];
	
This method has to return a NSArray of UIBarButtonItems. The implementation is the same as setting the rightBarButtonItems in one or your UINavigationItem.

Example : 
	
	-(NSArray *)getRightBarButtonItemsForCampaign:(SCSDKCampaign *)campaign{
	    NSArray *barButtonItems = @[
	                                [[UIBarButtonItem alloc]initWithTitle:@"First" style:UIBarButtonItemStyleDone target:self action:@selector(didTapFirstCustomBarButtonItem:)],
	                                [[UIBarButtonItem alloc]initWithTitle:@"Second" style:UIBarButtonItemStyleDone target:self action:@selector(didTapSecondCustomBarButtonItem:)],
	                                ];
	    
	    return barButtonItems;
	}
	
<div id='campaignToolbarUIDelegate'/>
### SCSDKProximityServiceCampaignToolbarUIDelegate
We put an UIToolbar at the bottom of the rich template-type view controller.
We commonly use it to display share buttons allowing you users to share the campaign's content to their Facebook / Twitter account.

You can configure this UIToolbar by adopting the protocol (for example in the AppDelegate.h):

	@import SCSDKProximityServiceKit;
	@interface AppDelegate : UIResponder <UIApplicationDelegate, SCSDKProximityServiceCampaignUIDelegate>

Then in your AppDelegate.m:

	[[SCSDKProximityService sharedInstance]setCampaignsToolbarUIDelegate:self];
 
The CampaignToolbarUIDelegate allow you to customize the rightBarButtonItems parameter using the *getToolbarItemsForCampaign:* method. 

Adopt the protocol (for example in the AppDelegate.h):

	
This method has to return a NSArray of UIBarButtonItems. The implementation is the same as setting the items in one or your UIToolbar.

Example : 
	
	-(NSArray *)getToolbarItemsForCampaign:(SCSDKCampaign *)campaign{
	    NSArray *barButtonItems = @[
	                                [[UIBarButtonItem alloc]initWithTitle:@"Facebook" style:UIBarButtonItemStyleDone target:self action:@selector(didTapFacebookShareButton:)],
	                                [[UIBarButtonItem alloc]initWithTitle:@"Twitter" style:UIBarButtonItemStyleDone target:self action:@selector(didTapTwitterShareButton:)],
	                                ];
	    
	    return barButtonItems;
	}

<div id='generalOptionsIDFA'/>
### Advertising Identifier

If your app use IDFA, you can enable our SDK to use it. It will act like an anonymous identifier in our database.

To use it, just add in your AppDelegate's *didFinishLaunchingWithOptions* method: 

	[[SCSDKProximityService sharedInstance]setUseASIdentifier:YES];

**Be careful when adding this capability as Apple will reject your app if you do not include ad functionality**

## License

SweepinConnect is available under the MIT license. See the LICENSE file for more info.
