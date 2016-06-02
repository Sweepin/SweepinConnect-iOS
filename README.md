![Image of SweepinConnect](Images/logoSweepinConnect.png =500x)

[![CI Status](http://img.shields.io/travis/Alexis Barat/SweepinConnect.svg?style=flat)](https://travis-ci.org/Alexis Barat/SweepinConnect)
[![Version](https://img.shields.io/cocoapods/v/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)
[![License](https://img.shields.io/cocoapods/l/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)
[![Platform](https://img.shields.io/cocoapods/p/SweepinConnect.svg?style=flat)](http://cocoapods.org/pods/SweepinConnect)

SweepinConnect is a location-based marketing tool for iOS. By integrating our system in your application, you are quickly ready to go with the **iBeacon technology**, along with the geofencing system.

Our solution is linked to an intuitive back-office interface, <a href='http://manager.sweepin.fr/admin/login/?ref=/'>Sweepin Manager</a>. It let you create your campaigns online in no time and broadcast to your audience.
Watch the analytics data on our charts, and get the visitor's traffic in real time.

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
___
To run the example project, clone the repo, and run `pod install` from the Example directory first.
-->
<br/>
#Get Started

##Installation with Cocoapods
___

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like SweepinConnect in your projects. See the "Getting Started" guide for more information. You can install it with the following command:

	$ gem install cocoapods

* CocoaPods 0.39.0+ is required to build SweepinConnect 0.1.0

###Podfile
To integrate SweepinConnect into your Xcode project using CocoaPods, specify it in your Podfile by simply adding the following line :

```
pod "SweepinConnect"
```

##Manual installation
___
Download the **ProximitiesSDK.framework** and **ProximitiesSDK.bundle** files.

Two simple steps to integrate :

- Simply drag the **ProximitiesSDK.framework** file into your Frameworks project's folder in XCode. Don't choose the "copy items into destination's group folder" option, as you may want to only use references.  
- Then drag the ProximitiesSDK.bundle in your project. In your project's target settings, open the build phase tab, and add the ProximitiesSDK.bundle file in the Copy Bundle Resources section (in most case, the bundle will automatically be added). This bundle contains the nibs and images.


## Requirements
___

For use with beacons technology, devices must support Bluetooth LE 4.0 : 

- iPhones 4S and later.
- iPad 3 and later.
- iPod 5 and later.

The iPhone 4 is only compatible with the geofencing technology.

Finally, devices must have at least iOS 7.0 installed.

#App configuration
___
In order to make our SDK working in your app, you have to link some popular frameworks. 

If you're using **Cocoapods**, these frameworkds are included automatically. 

If not, you need to add them manually in your target's "Linked Frameworks and Libraries" section.

###SweepinConnect SDK requirements:
 
- CoreBluetooth.framework
- CoreLocation.framework
- SystemConfiguration.framework
- UIKit.framework
- Foundation.framework
- AVKit.framework
- CoreMedia.framework
- AVFoundation.framework
- libsqlite3.0.tbd

###YourApp-Info.plist

Since iOS 8 SDK, the key **NSLocationAlwaysUsageDescription** is required for the use of localisation in an app.

Open the Info.plist file, then add a new string key *NSLocationAlwaysUsageDescription*. In the value, set the message you want to display to users to request their permission for background localisation updates :

    <key>NSLocationAlwaysUsageDescription</key>
    <string>Your message goes here</string>

And since iOS 9 SDK, you need to describe your app’s intended HTTP connection behavior, including for Sweepin servers.

Since our SDK can integrate webviews that are pointing to other servers than ours, every http loads should be authorized.

	<key>NSAppTransportSecurity</key>
	<dict>
		<key>NSAllowsArbitraryLoads</key>
		<true/>
	</dict>
	


<br/>
#Usage

You're now two steps away from receiving your first animation in your app. But before it, a quick explanation on the heart of our SDK. Let me introduce you :
###The PRX Singleton
___
The SweepinConnect SDK provides a unique singleton to access all methods. 

You just need to import the PRX.h header file :

    #import <ProximitiesSDK/PRX.h>

And then you can call the singleton: 

    [[PRX singleton] anySDKMethod]


###1/ Initialize the SDK
___

To authenticate within our API, use the PRX singleton with the *initWithAppId:andSecret:* method in your AppDelegate's *didFinishLaunchingWithOptions* method: 

    [[PRX singleton] initWithAppId:@"YOUR-APP-ID" andSecret:@"YOUR-APP-SECRET"];

*If you do not have your app id and secret -provided by the Sweepin registration process- please contact the [Sweepin team][1].*
    
#####/!\ Be careful to keep your app secret for yourself.
<br/>

###2/ Suscribe to local notifications and animation display
___

You just need to call *manageLocalNotificationForUserInfo:* on your AppDelegate's *didReceiveLocalNotification:* method.

    - (void)application:(UIApplication *)application didReceiveLocalNotification:( UILocalNotification *)notification{
    	[[PRX singleton] manageLocalNotificationForUserInfo:notification.userInfo];
    }

###Congratulations, your app is now ready to go ! 
#####Go to <a href='http://manager.sweepin.fr/admin/login/?ref=/'>The Sweepin Manager interface</a> to create your first animation !

###For more options, see [SweepinConnect iOS : Advanced configuration](SweepinConnect-iOS_Advanced-configuration.md)
*A bunch of methods are available to customize our SDK to fit your needs :*

- *Show animations in UITableView / UICollectionView*
- *Create custom actions on reception* 
- *Integrate a QRCode reader in your app*
- *Register your users' properties to send segmented animations on specific groups*
- *...and lot more !*


<br/>	
## License
___
SweepinConnect is available under the MIT license. See the LICENSE file for more info.

  [1]: http://www.sweepin.fr/contact