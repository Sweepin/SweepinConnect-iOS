# SweepinConnect

[![CI Status](http://img.shields.io/travis/Alexis Barat/SweepinConnect.svg?style=flat)](https://travis-ci.org/Alexis Barat/SweepinConnect)
[![Version](https://img.shields.io/cocoapods/v/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)
[![License](https://img.shields.io/cocoapods/l/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)
[![Platform](https://img.shields.io/cocoapods/p/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)

## Introduction
**SweepinConnect SDK** is a tool to get started with the **iBeacon technology**, along with the geofencing system.

The Sweepin platform currently lets you choose from 6 types of animations: 

1) Simple: simple notification that will be triggered when detecting the associated beacon, and will simply open the app. You can then handle what to do, like deep linking the push (ex: open a specific view controller)

2) Rich: notification that opens the app and displays a rich animation (custom images, colors, texts in the web manager). 

3) Webview : A notification that opens the app and displays an UIWebview object loading the url you choose inside an UIViewController.

4) Audio : notification that opens the app and displays an audio animation (containing an image in background, an audio file and texts in the web manager). 

5) Video : notification that opens the app and displays a video animation, containing a video file and texts in the web manager.

6) Loyalty : notification that opens the app and displays a loyalty animation. On each connection with the related transmitter, the loyalty template receive one more stamp.

All these animations include a custom delegate to handle user interactions.

######More information is available in the Sweepin manager interface:
<http://manager.sweepin.fr/>


## Requirements
Any of the iOS devices with Bluetooth LE 4.0 support : 
>- iPhones 4S and later.
>- iPad 3 and later.
>- iPod 5 and later.

All devices must have at least iOS 7.0 installed.


## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.


##Installation
###Cocoapods
SweepinConnect is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```
pod "SweepinConnect"
```

###Manual installation

Download the **ProximitiesSDK.framework** and **ProximitiesSDK.bundle** files.

Two simple steps to integrate :

- Simply drag the **ProximitiesSDK.framework** file into your Frameworks project's folder in XCode. Don't choose the "copy items into destination's group folder" option, as you may want to only use references.  
- Then drag the ProximitiesSDK.bundle in your project. In your project's target settings, open the build phase tab, and add the ProximitiesSDK.bundle file in the Copy Bundle Resources section (in most case, the bundle will automatically be added). This bundle contains the nibs and images.

<a name="updateiOS"></a>
**iOS 8 update :**
You need to add a new property to your project's Info.plist file. Open the Info.plist file, then add a new string key **NSLocationAlwaysUsageDescription**. In the value, set the message you want to display to users to request their permission for background localisation updates.

    <key>NSLocationAlwaysUsageDescription</key>
    <string>Your message goes here</string>


Next, you just need to import the PRX.h header file like this:

    #import <ProximitiesSDK/PRX.h>
    
**iOS 9 update :**
With the new App Transport Security feature implemented in iOS9, you now need to describe your app’s intended HTTP connection behavior, including Sweepin servers. Since our SDK can integrate webviews that are pointing to other servers than ours, every http loads should be authorized.

<!--If you're integrating our SDK on our test environment, simply add these parameters to your info.plist file. 

	<key>NSAppTransportSecurity</key>
	<dict>
		<key>NSExceptionDomains</key>
		<dict>
			<key>sweepin.fr</key>
			<dict>
				<key>NSIncludesSubdomains</key>
				<true/>
				<key>NSExceptionAllowsInsecureHTTPLoads</key>
				<true/>
			</dict>
		</dict>
	</dict>-->


	<key>NSAppTransportSecurity</key>
	<dict>
		<key>NSAllowsArbitraryLoads</key>
		<true/>
	</dict>
	
Then make sure to add the correct frameworks to meet the following requirements: 

> **SweepinConnect SDK requirements:**
> 
>- CoreBluetooth.framework
>- CoreLocation.framework
>- SystemConfiguration.framework
>- UIKit.framework
>- Foundation.framework
>- AVKit.framework
>- CoreMedia.framework
>- AVFoundation.framework
>- libsqlite3.0.tbd


>**Note:**
> You need to activate background mode for your app.
In your target's capabilities tab, enter the following UIBackgroundModes: 

>- Uses Bluetooth LE accessories


Make sure to implement the didReceiveLocalNotification method on you AppDelegate

    - (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification{
    }


######Congratulations, you are ready to go!
  
---------
#Getting started
---------
First of all, you'll need to use the app id and secret provided by the Sweepin registration process. If you do not have your app id and secret, please contact the [Sweepin team][1].

#####Be careful to keep the app secret for yourself.

----------

##.PRX Singleton
The Sweepin SDK provides a unique singleton to access all methods. You'll need to import the PRX.h header file if you didn't already. In your AppDelegate.m: 

    #import <ProximitiesSDK/PRX.h>

And then you can call the singleton: 

    [[PRX singleton] anySDKMethod]

----------

##.Init the SDK
To authenticate within the API, you need to use the PRX singleton with the *initWithAppId:andSecret:* method in your AppDelegate's *didFinishLaunchingWithOptions* method: 

    [[PRX singleton] initWithAppId:@"YOUR-APP-ID" andSecret:@"YOUR-APP-SECRET"];
    
<!--This method also ask for user persmissions to access its location and send local notification. If you want to ask these authorizations elsewhere, you can use separates methods:

    [[[PRX singleton]locationManager]requestLocationAuthorization];
	[[[PRX singleton]locationManager]requestUIUserNotifications];
-->

----------
##.Subscribe to local notifications and animation display.
You just need to call *manageLocalNotificationForUserInfo:* on your AppDelegate's *didReceiveLocalNotification:* method.

    - (void)application:(UIApplication *)application didReceiveLocalNotification:( UILocalNotification *)notification{
    	[[PRX singleton] manageLocalNotificationForUserInfo:notification.userInfo];
    }

###.Push in app
 To manage the case of a simple notification with push in app, you have to declare a block and call *setSimpleNotificationActionBlock:* on your AppDelegate's *willFinishLaunchingWithOptions:* method.

    void(^simpleNotificationCallback)() = ^(NSString* identifier) {
        if ( [identifier isEqualToString:@"open-specific-vc"] ){
            // Manage the opening of a specific view controller here
        }
        // Multiple parameters example: open product controller with product id
        // Ex identifier: controller=ProductViewController&id=10
        NSDictionary * params = [[PRX singleton] parametersFromQueryString:identifier];
        if ( [params valueForKey:@"controller"] && NSClassFromString([params valueForKey:@"controller"]) ){
            
            UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
            id viewController = [storyboard instantiateViewControllerWithIdentifier:[params valueForKey:@"controller"]];
            [self.window.rootViewController presentViewController:viewController animated:YES completion:nil];
        }
    };
    
    [[PRX singleton]setSimpleNotificationActionBlock:simpleNotificationCallback];
    
When the app is running, simple notifications will appear in a pop-up view. You can personalize this view by calling *setSimpleAnimationPopupProperties:* 

    NSDictionary *popupProperties = @{
                                      @"popupTextColor":[UIColor cyanColor],
                                      @"popupColor":[UIColor purpleColor]
                                      };
    [[PRX singleton]setSimpleAnimationPopupProperties:popupProperties];


>**Note:** The *simpleNotificationActionBlock* is executed in the main thread.

<a name="qrCode"></a>
##Get animation from QR Code
If you want to implement our QR Code solution in your app, simply use :

	-(void)showQrCodeReader{
    	PRXQrCodeReaderViewController *rootViewController =	[[PRXQrCodeReaderViewController alloc]init];
	    [rootViewController setNavigationBarBackgroundColor:[UIColor yourColor]];
    	[rootViewController setNavigationBarTintColor:[UIColor yourColor]];
	    [self.navigationController pushViewController:rootViewController animated:YES];
	}

This controller can display Sweepin's animations, handle web-url and vCards.

----------
<a name="showFavorites"></a>
##.Showing user's animations
Registered and non-registered users can receive and archive animations. The Sweepin SDK provides a built-in way to show animations for a user, in a customizable pop-in.

The **userAction** parameter allow you to get users favorites (userAction = @"saved") or received (userAction = @"anim_received") animations.

####.Nice preview collectionViewController with curved layout


You can for example add a UIButton somewhere in your app's user interface.
Here is an example of a possible IBAction: 

    - (IBAction)showFavoritesAction:(id)sender {
    NSDictionary *dict = @{
                           @"topbarTitle":@"Mes favoris",
                           @"topbarTextColor":[UIColor blackColor],
                           @"tintColor":[UIColor blackColor],
                           @"textColor":[UIColor brownColor],
                           @"topbarTintColor":[UIColor whiteColor],
                           @"emptyCaseTitle" : @"Aucun élément disponible actuellement"
                           };
    [[PRX singleton] presentAnimationsCollectionViewControllerWithUIAttributes:dict forUserAction:userAction];
    }


>**Note:**
This is the complete list of attributes. No need to explain each one of them as they speak for themselves.  

If your app is embedded in a navigation controller, you can also display that list of animations by pushing the favorites view controller :

    [[PRX singleton] pushAnimationsCollectionViewControllerWithUIAttributes:dict fromCurrentViewController:self forUserAction:userAction];
 
    
####.Simple preview in UITableView
Another template to show user's animations use an UITableView.
You can customize the view. Here is an example how to use this method :

    [[PRX singleton]presentAnimationsTableViewControllerWithUIAttributes:@{
	    @"noResultsMessage":@"Pas de résultats",
		@"failToRetrieveMessage":@"Pas de réseau",
		@"notifTitleColor":@"1a0dab",
		@"noResultsMessageTitleColor":@"fa99cc",
		@"failToRetrieveMessageTitleColor":@"b90d75",
		@"topBarTintColor":@"ffffff",
		@"topBarBackgroundColor":@"d54586",
		@"topBarTitle":@"Notifications"
	forUserAction:@"saved"];
   
Or if your app is embedded in a navigation controller : 

     [[PRX singleton] pushAnimationsTableViewControllerWithUIAttributes:attributes   
  		 fromCurrentViewController:(UIViewController *)viewController 
	     forUserAction:(NSString *)userAction{

####. Custom UITableView
The UIViewController **PRXAnimationsTableViewControllerDelegate** implement all the necessary methods to get user's animations and display them into an UITableView.
By this way, you can create your own UITableView inside your controllers and use it to display the animations.
Here is an example how to use :

1) Import the header :

	#import <ProximitiesSDK/PRXAnimationsTableViewControllerDelegate.h>
2) Declare an instance :

	@property (nonatomic, strong) PRXAnimationsTableViewControllerDelegate *prxTableViewDelegate;
	
3) Configure your UITableView this way :

	_prxTableViewDelegate = [[PRXAnimationsTableViewControllerDelegate 	alloc]initWithUIAttributes:(NSDictionary *)attributes andUserAction:(NSString *) userAction];
    [_prxTableViewDelegate setFromVC:self];
    [_prxTableViewDelegate setTableView:_notifsTableView];
    
    [_notifsTableView setDelegate:_prxTableViewDelegate];
    [_notifsTableView setDataSource:_prxTableViewDelegate];

----------
<a name="getAnimationsByUserAction"></a>
##.Get the user's archived animations
The SDK provide a convenient method to get user's animations.

The userAction parameter allow you to get users favorites (userAction = @"saved") or received (userAction = @"anim_received") animations.

	[[PRX singleton]getAnimationsByUserAction:@"saved" withSuccessHandler:^(NSArray *animations) {
        if ([animations count] == 0) {
        	// Result is empty 
        }else{
        	// Handle success
        }
    } andFailureHandler:^(NSError *error) {
		// Handle error
    }];


This method return a NSArray object with user's animations.

----------

##.Prevent and restart the display of animations
####.In your methods

In some cases, you'll want to prevent the display of animations. 
For example, if the user is on the payment view of your app, you don't want any other screen to interfere while the user is in the payment process.

To prevent the display, use:

    - (void)stopAnimationsDisplay;

To restart the display after, use:
    
    - (void)restartAnimationsDisplay;



####.By user choice

You can also give to your users the possibility to prevent all animations to be displayed. Here is an example of a possible IBAction: 

    - (IBAction)switchAction:(id)sender {
	    if([sender isOn]){
	        [[PRX singleton]preventAnimations:YES];
	    } else{
        	[[PRX singleton]preventAnimations:NO];
    	}
	}

----------
##.The PRXAnimationViewControllerDelegate protocol (optional)
For non-simple notification cases, the SDK provides a delegate that you can adopt to manage user interactions.

Adopt the protocol (in the AppDelegate.h for example): 
    
    #import <ProximitiesSDK/PRXAnimationViewControllerDelegate.h>
    @interface AppDelegate : UIResponder <UIApplicationDelegate,PRXAnimationViewControllerDelegate>

Then in your AppDelegate.m: 

    [[PRX singleton] setAnimationViewControllersDelegate:self]

Here is the list of delegate methods that you can implement: 

	- (BOOL) shouldTapRightButtonWithAnimation:(PRXAnimation*)animation;
	- (BOOL) shouldTapLeftButtonWithAnimation:(PRXAnimation*)animation;
	- (void) didTapRightButtonWithAnimation:(PRXAnimation*)animation;
	- (void) didTapLeftButtonWithAnimation:(PRXAnimation*)animation;

Theses delegate are triggered the first time an user sees an animation (no delegates when displaying from the favorites view).

>**Note:** The **identifier** is an alpha-numeric string that you can use to identify a set of animations to associate a specific action. Let's say you want to open the fidelity card view controller, and you have 2 animations. When you create your animations, in the Sweepin administration, you'll give the same identifier for these two animations (ex : 'open-fidelity-vc').
In your delegate's method implementation, you can now handle a specific action for this set of animations.

----------

##.Store user infos for segmented animations (optional)
At one point, your app's customer is going to login (or auto-login) to your app.
If you want the Sweepin system to be aware of your users informations, you'll need to register this user to the Sweepin system. 
For example, you can call the *registerIdentifier:withUserInfos:* method on your login/autologin routine method to.
Registering users is the way to send segmented animations on a specific group of users.

    NSDictionary* myDict = @{ @"parameters" : @{
                           		       @"age" : @"19",
                                       @"gender" : @"male",
                                       ...
                                };
                                 
    [[PRX singleton]registerIdentifier:@"myUniqueIdentifier" withUserInfos:myDict withSuccessHandler:^(id object) {
        
    } andFailureHandler:^(NSError *error) {
        
    }];



#.SDK Options

###.Location manager distance filter
The location manager distance filter for geofencing animations.
    
    [[PRX singleton] setLocationManagerDistanceFilter:10];

----------


###.Confirmation messages 
You can set messages to display alerts relative to the SDK. The keys/strings values can be set in the Localizable.strings files of ProximitiesSDK.bundle.
Here is a complete list of all the configurable parameters:

----------

>- Alert when your user delete an animation from its favorites:
 	- "prx.delete-favorite-alert-title" 
 	- "prx.delete-favorite-alert-message"
>- Alert on first launch, to inform the user that its bluetooth is disabled:
 	- "prx.bluetooth-disabled-alert-title"
 	- "prx.bluetooth-disabled-alert-message"
>- Alert when your user dismiss the multi-animations list:
 	- "prx-multi-animations-list.close-alert-title"
 	- "prx-multi-animations-list.close-alert-message"
>- Message shown in favorites' view if user's animations' list is empty:
 	- "prx-favorites-list.empty-case-title"
>- Favorites view title:
 	- "prx-favorites-list.topbar-title" 
 	
>- On loyalty-type animation, when the user unlocked all stamps, a message is shown above the animation, to invite him to present the animation to the related POI manager, and to reset the stamps.
 	- "prx-loyalty-animation-full-stamp.label-title"
>- On loyalty-type animation, when the user choose to reset its stamps, an UIAlertController / UIAlertView is shown, to notify him that this action can’t be undone. If the first two keys are empty, no alert is displayed.
 	- "prx-loyalty-animation-full-stamp-confirm-reset.alert-title"
 	- "prx-loyalty-animation-full-stamp-confirm-reset.alert-message"
	- "prx-loyalty-animation-full-stamp.agree-button-title"
	-"prx-loyalty-animation-full-stamp.disagree-button-title"
>- On loyalty-type animation, when user reset its stamps and if the value isn't empty, a PRXAlertView is shown to confirm the action.
	- "prx-loyalty-animation-full-stamp.reset-done"
>- A trad key used in the SDK when a webservice call failed. If empty, no PRXAlertView shows.
 	- "prx-no-network.prx-alert-title"




>**Notes**
If you don't specify a title, the corresponding alert won't show.
The last two keys will not be used if you call *presentFavoritesListViewControllerWithUIAttributes:* or *pushFavoritesListViewControllerWithUIAttributes:* methods.


----------
###.Manage in-app urls from animations

Animations can contain html code, which can lead to a deep link into your app. Our SDK manage the link opening and provides you the ability to add your rules. 
Let's say the user press a html button in an animation, the method *webView:(UIWebView \*)inWeb shouldStartLoadWithRequest:(NSURLRequest \*)* gets called. 
You can define a block in your AppDelegate's *didFinishLaunchingWithOptions:* method, which will be executed. For example, you can test url's scheme and do the right action according to the case.


    BOOL (^customUrlManagementBlock)(NSURL*, UIViewController*);
    customUrlManagementBlock = ^BOOL (NSURL* url, UIViewController* vc){
        if ([[url scheme] isEqualToString:@"customUrlScheme"]) {
            UIViewController *customViewController = [[UIViewController alloc]init];
            [vc presentViewController:customViewController animated:YES completion:^{
                
            }];
            // Return no because we manage this case
            return NO;
        }
        // Return yes because we do not manage this case
        return YES;
    };
    
    [[PRX singleton]setCustomUrlManagementBlock:customUrlManagementBlock];

###.Custom right bar button in animations
The heart icon and all associated actions are fully configurable. You can create your own *UIBarButtonItem* in your AppDelegate's *didFinishLaunchingWithOptions:* method.

    UIBarButtonItem *customBarButtonItem = [[UIBarButtonItem alloc]initWithImage:[UIImage imageNamed:@"customImage"] style:UIBarButtonItemStylePlain target:self action:@selector(customAction:)];
    [[PRX singleton]setAnimationsCustomRightBarButtonItem:customBarButtonItem];
    
###.Application Icon Badge
Our SDK show by default an appIcon badge when it receive a notification. If you need to disable this option, you can set a boolean after your *initWithAppId:* method.

    [[PRX singleton]setShowIconBadgeNumber:NO];


  [1]: http://www.sweepin.fr/contact


## License

SweepinConnect is available under the MIT license. See the LICENSE file for more info.
