<p align="center" >
  <img src="http://connect.sweepin.net/img/logo/sweepin-connect-850x300.png" alt="SweepinConnectLogo" title="SweepinConnectLogo">
</p>

[![Version](https://img.shields.io/cocoapods/v/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)
[![License](https://img.shields.io/cocoapods/l/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)
[![Platform](https://img.shields.io/cocoapods/p/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)

SweepinConnect is a location-based marketing tool for iOS. By integrating our system in your application, you are quickly ready to go with the **iBeacon technology**, along with the geofencing system.

Our solution is linked to an intuitive back-office interface, <a href='https://connect.sweepin.fr/admin/login'>Sweepin Connect</a>. It let you create your campaigns online in no time and broadcast to your audience.
Watch the analytics data on our charts, and get the visitor's traffic in real time.

# Get Started

## Requirements

- To use our Proximity Service SDK, devices must have at least **iOS 8.1** installed

- We are using Realm to create a local database into our application.

## Installation with Cocoapods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like SweepinConnect in your projects. See the "Getting Started" guide for more information. You can install it with the following command:

	$ gem install cocoapods

* CocoaPods 0.39.0+ is required to build SweepinConnect 0.1.0

### Podfile
To integrate our ProximityService solution into your Xcode project using CocoaPods, specify it in your Podfile by simply adding the following packages :

```
pod 'SCSDKCoreKit'
pod 'SCSDKProximityServiceKit'
```

## Manual installation

Download the **SCSDKCoreKit.framework**, **SCSDKProximityServiceKit.framework** and **SCSDKResourcesForProximityServiceKit.bundle** files.

Two simple steps to integrate :

- Drag the **SCSDKCoreKit.framework** and **SCSDKProximityServiceKit.framework** files into your Frameworks project's folder in XCode. Don't choose the "copy items into destination's group folder" option, as you may want to only use references.  
- Then drag the **SCSDKResourcesForProximityServiceKit.bundle** in your project. In your project's target settings, open the build phase tab, and add the **SCSDKResourcesForProximityServiceKit.bundle** file in the Copy Bundle Resources section (in most case, the bundle will automatically be added). This bundle contains the nibs and images.

You also have to add to install Realm manually, please refer to <a href='https://realm.io/docs/objc/latest/#installation'>their documentation</a>.

# App configuration


### Info.plist
	
Open your Info.plist file, then add these three new string key : *NSLocationAlwaysUsageDescription*, *NSLocationAlwaysAndWhenInUseUsageDescription* and *NSLocationWhenInUseUsageDescription*. In the values, set the messages you want to display to users to request their permission for localisation updates :

	<key>NSLocationAlwaysUsageDescription</key>
		<string>Your message goes here</string>
	<key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
		<string>Your message goes here</string>
	<key>NSLocationWhenInUseUsageDescription</key>
		<string>Your message goes here</string>

For devices running iOS 9.0+, you need to describe your app’s intended HTTP connection behavior, including for Sweepin servers, by adding the **NSAppTransportSecurity** key

Since our SDK can integrate webviews that are pointing to other servers than ours, every http loads should be authorized. You do this by setting the **NSAllowsArbitraryLoads** key to true.

	<key>NSAppTransportSecurity</key>
	<dict>
		<key>NSAllowsArbitraryLoads</key>
		<true/>
	</dict>
	

# Usage

You are now two steps away from receiving your first campaign in your app. But before it, a quick explanation on the heart of our SDK. Let me introduce you :
### The [SCSDKProximityService sharedInstance]

The SweepinConnect SDK provides a unique singleton to access all methods. 
To use it, you just need to import the SDK into your controller:

	@import SCSDKProximityServiceKit;

Then you can call it: 

    [[SCSDKProximityService sharedInstance] anyMethod]


### 1/ Initialize the SDK


To authenticate within our API, use the SDK's singleton with the *initWithAppId:andSecret:* method in your AppDelegate's *didFinishLaunchingWithOptions* method: 

    [[SCSDKProximityService sharedInstance] initWithAppId:@"YOUR-APP-ID" andSecret:@"YOUR-APP-SECRET"];

*If you do not have your app id and secret -provided by the Sweepin registration process- please contact the [Sweepin team][1].*
    
##### /!\ Be careful to keep your app secret for yourself.

### 2/ Suscribe to local notifications and campaign display


You just need to call *manageLocalNotificationForUserInfo:* on your AppDelegate's *didReceiveLocalNotification:* method.

	- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification{
	    [[SCSDKProximityService sharedInstance]manageLocalNotificationWithUserInfo:notification.userInfo];
	}

### 3/ Start the services

Now it's time to start all the services. Just call:

	[[SCSDKProximityService sharedInstance]start];

### Congratulations, your app is now ready to go ! 
##### Go to <a href='https://connect.sweepin.fr/admin/login'>the Sweepin Connect interface</a> to create your first campaign !

### For more options, see [SweepinConnect iOS : Advanced configuration](SweepinConnect-iOS_Advanced-configuration.md)
*A bunch of methods are available to customize our SDK to fit your needs :*

- *Get the latest campaigns received*
- *Create custom actions on reception / display /close*
- *Integrate a QRCode reader in your app and call our API to get related campaigns*
- *Register your users' properties to send segmented campaigns to specific groups*
- *...and lot more !*


<br/>	

## License

SweepinConnect is available under the MIT license. See the LICENSE file for more info.

  [1]: http://www.sweepin.fr/contact


<!--
The Sweepin platform currently lets you choose from 6 types of animations: 

1) Simple: simple notification that will be triggered when detecting the associated beacon, and will simply open the app. You can then handle what to do, like deep linking the push (ex: open a specific view controller)

2) Rich: notification that opens the app and displays a rich animation (custom images, colors, texts in the web manager). 

3) Webview : A notification that opens the app and displays an UIWebview object loading the url you choose inside an UIViewController.

4) Audio : notification that opens the app and displays an audio animation (containing an image in background, an audio file and texts in the web manager). 

5) Video : notification that opens the app and displays a video animation, containing a video file and texts in the web manager.

6) Loyalty : notification that opens the app and displays a loyalty animation. On each connection with the related transmitter, the loyalty template receive one more stamp.

All these animations include a custom delegate to handle user interactions.
-->

<!--## Example project

To run the example project, clone the repo, and run `pod install` from the Example directory first.
-->
