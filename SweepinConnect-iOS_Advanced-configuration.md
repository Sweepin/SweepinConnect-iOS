![Image of SweepinConnect](http://staging.sweepin.fr/img/sweepinconnect-logo.png =300x)
___
#SweepinConnect-iOS : Advanced configuration
##Table of contents

- [SweepinConnect Example](#example)
- [Showing user's animations](#showAnim)
     - [Nice preview collectionViewController with curved layout](#showAnimColView)
     - [Simple preview in UITableView](#showAnimTableView)
     - [Custom UITableView](#showAnimCustomTableView)
- [Get the user's archived animations](#getAnim)
- [Implement PRXQRCodeReader](#qrCodeReader)
- [The PRXAnimationViewControllerDelegate protocol](#PRXAnimationViewControllerDelegate)
- [Store user infos for segmented animations](#segUser)
- [Prevent and restart the display of animations](#preventAnim)
	- [By user choice](#preventAnimUserChoice)
	- [In your methods](#preventAnimDeveloperChoice)
- [Push in app](#pushInApp)
- [General options](#generalOptions)
	- [Location manager distance filter](#generalOptionsDistanceFilter)
	- [Confirmation messages ](#generalOptionsLocalizable)
	- [Manage in-app urls from animations](#generalOptionsInAppUrl)
	- [Custom right bar button in animations](#generalOptionsRightBarButton)
	- [Application Icon Badge](#generalOptionsAppIcon)
	- [Advertising Identifier](#generalOptionsIDFA)
<br/><br/>
<div id='example'/>
# SweepinConnect Example 
___
Because code is always more talking than words, we made an example project to show you how to use the SweepinConnect SDK methods.

To run it, clone the repo, and run `pod install` from the Example directory.
<br/><br/>
<div id='showAnim'/>
#Showing user's animations
___
Registered and non-registered users can receive and archive animations. The Sweepin SDK provides a built-in way to show animations for a user, in a customizable pop-in.

The **userAction** parameter allow you to get users favorites (userAction = @"saved") or received (userAction = @"anim_received") animations.

<div id='showAnimColView'/>
###Nice preview collectionViewController with curved layout
___
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
 
<div id='showAnimTableView'/>
###Simple preview in UITableView
___
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

<div id='showAnimCustomTableView'/>
###Custom UITableView
___
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

<div id='getAnim'/>
#Get the user's archived animations
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

<div id='qrCodeReader'/>
#Implement PRXQRCodeReader
___
If you want to implement our QR Code solution in your app, simply use :

	-(void)showQrCodeReader{
    	PRXQrCodeReaderViewController *rootViewController =	[[PRXQrCodeReaderViewController alloc]init];
	    [rootViewController setNavigationBarBackgroundColor:[UIColor yourColor]];
    	[rootViewController setNavigationBarTintColor:[UIColor yourColor]];
	    [self.navigationController pushViewController:rootViewController animated:YES];
	}

This controller can display Sweepin's animations, handle web-url and vCards.

<div id='PRXAnimationViewControllerDelegate'/>
#The PRXAnimationViewControllerDelegate protocol 
___
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

<div id='segUser'/>
#Store user infos for segmented animations
___
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


<div id='preventAnim'/>
#Prevent and restart the display of animations
___
<div id='preventAnimDeveloperChoice'/>
###In your methods
___
In some cases, you'll want to prevent the display of animations. 
For example, if the user is on the payment view of your app, you don't want any other screen to interfere while the user is in the payment process.

To prevent the display, use:

    - (void)stopAnimationsDisplay;

To restart the display after, use:
    
    - (void)restartAnimationsDisplay;


<div id='preventAnimUserChoice'/>
###By user choice
___
You can also give to your users the possibility to prevent all animations to be displayed. Here is an example of a possible IBAction: 

    - (IBAction)switchAction:(id)sender {
	    if([sender isOn]){
	        [[PRX singleton]preventAnimations:YES];
	    } else{
        	[[PRX singleton]preventAnimations:NO];
    	}
	}




<div id='pushInApp'/>
#Push in app
___
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

<div id='generalOptions'/>
#General options
___

<div id='generalOptionsDistanceFilter'/>
###Location manager distance filter
___
The location manager distance filter for geofencing animations.
    
    [[PRX singleton] setLocationManagerDistanceFilter:10];

----------

<div id='generalOptionsLocalizable'/>
###Confirmation messages 
___
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

<div id='generalOptionsInAppUrl'/>
###Manage in-app urls from animations
___

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

<div id='generalOptionsRightBarButton'/>
###Custom right bar button in animations
___
The heart icon and all associated actions are fully configurable. You can create your own *UIBarButtonItem* in your AppDelegate's *didFinishLaunchingWithOptions:* method.

    UIBarButtonItem *customBarButtonItem = [[UIBarButtonItem alloc]initWithImage:[UIImage imageNamed:@"customImage"] style:UIBarButtonItemStylePlain target:self action:@selector(customAction:)];
    [[PRX singleton]setAnimationsCustomRightBarButtonItem:customBarButtonItem];

<div id='generalOptionsAppIcon'/>
###Application Icon Badge
___
Our SDK show by default an appIcon badge when it receive a notification. If you need to disable this option, you can set a boolean after your *initWithAppId:* method.

    [[PRX singleton]setShowIconBadgeNumber:NO];



<div id='generalOptionsIDFA'/>
###Advertising Identifier
___

If your app use IDFA, you can enable our SDK to use it. It will act like an anonymous identifier in our database.

To use it, just add in your AppDelegate's *didFinishLaunchingWithOptions* method: 

	[[PRX singleton]setEnableAdvertisingIdentifier:YES];


## License
___

SweepinConnect is available under the MIT license. See the LICENSE file for more info.
