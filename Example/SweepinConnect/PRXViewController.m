//
//  PRXViewController.m
//  SweepinConnect
//
//  Created by Alexis Barat on 05/20/2016.
//  Copyright (c) 2016 Alexis Barat. All rights reserved.
//

#import "PRXViewController.h"
@import SCSDKProximityServiceKit;
#import <SCSDKProximityServiceKit/SCSDKQrCodeReaderViewController.h>
#import "PRXUserCampaignsTableViewController.h"

@interface PRXViewController ()<SCSDKProximityServiceDelegate, SCSDKProximityServiceCampaignUIDelegate, SCSDKProximityServiceCampaignToolbarUIDelegate>

@property (weak, nonatomic) IBOutlet UISwitch *doNotDisturbOnBackgroundSwitch;

@end

@implementation PRXViewController

- (void)viewDidLoad{
    [super viewDidLoad];
    [_doNotDisturbOnBackgroundSwitch setOn:[[SCSDKProximityService sharedInstance]deactivateNotificationWhenOnBackground]];
    
    [[SCSDKProximityService sharedInstance]setDelegate:self];
    [[SCSDKProximityService sharedInstance]setCampaignsToolbarUIDelegate:self];
    [[SCSDKProximityService sharedInstance]setCampaignsTopbarUIDelegate:self];
    
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)getUserCampaignsAction:(id)sender {
    [[SCSDKProximityService sharedInstance]getCampaignsByUserAction:kUserActionReceived withSuccessHandler:^(id object) {
        PRXUserCampaignsTableViewController *userCampaignsVC = [[PRXUserCampaignsTableViewController alloc]init];
        [userCampaignsVC setArrCampaigns:object];
        
        UINavigationController *navVC = [[UINavigationController alloc]initWithRootViewController:userCampaignsVC];
        UIBarButtonItem *closeButton = [[UIBarButtonItem alloc]initWithBarButtonSystemItem:UIBarButtonSystemItemStop target:self action:@selector(dismissUserCampaignsVC:)];
        navVC.navigationBar.topItem.leftBarButtonItem = closeButton;
        navVC.navigationBar.tintColor = [UIColor orangeColor];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self presentViewController:navVC animated:YES completion:nil];
        });
        
        NSLog(@"%@", [object description]);
    } andFailureHandler:^(NSError *error) {
        NSLog(@"Error getting user's campaign : %@", [error description]);
    }];
}

-(void)dismissUserCampaignsVC:(id)sender{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)showQrCodeReaderAction:(id)sender {
    SCSDKQrCodeReaderViewController *qrCodeReaderVC = [[SCSDKQrCodeReaderViewController alloc]init];
    
    qrCodeReaderVC.navigationBarBackgroundColor = [UIColor whiteColor];
    qrCodeReaderVC.navigationBarTintColor = [UIColor blueColor];
    
    [self.navigationController pushViewController:qrCodeReaderVC animated:YES];

}

- (IBAction)doNotDisturbOnBackgroundAction:(id)sender {
    [[SCSDKProximityService sharedInstance]setDeactivateNotificationWhenOnBackground:_doNotDisturbOnBackgroundSwitch.isOn];
}

#pragma mark SCSDKProximityServiceDelegate
-(void)didReceiveCampaigns:(NSArray *)campaigns{
    NSLog(@"\n\n DID RECEIVE CAMPAIGNS : %@ \n\n", [campaigns description]);
}

-(void)didDisplayCampaign:(SCSDKCampaign *)campaign firstTime:(BOOL)firstTime{
    NSLog(@"\n\n DID DISPLAY CAMPAIGN : %@ \n\n", campaign);
}

-(void)handleActionForCampaignIdentifier:(NSString *)identifier{
    NSLog(@"\n\n HANDLE ACTION FOR IDENTIFIER : %@ \n\n", identifier);
}

-(BOOL)shouldTapRightButtonWithCampaigns:(NSArray *)campaigns{
    NSLog(@"\n\n SHOULD TAP RIGHT BUTTON WITH CAMPAIGNS : %@ \n\n", [campaigns description]);
    return YES;
}

-(BOOL)shouldTapLeftButtonWithCampaigns:(NSArray *)campaigns{
    NSLog(@"\n\n SHOULD TAP LEFT BUTTON WITH CAMPAIGNS : %@ \n\n", [campaigns description]);
    return YES;
}

-(void)didTapRightButtonWithCampaigns:(NSArray *)campaigns{
    NSLog(@"\n\n DID TAP RIGHT BUTTON WITH CAMPAIGNS : %@ \n\n", [campaigns description]);
}

-(void)didTapLeftButtonWithCampaigns:(NSArray *)campaigns{
    NSLog(@"\n\n DID TAP LEFT BUTTON WITH CAMPAIGNS : %@ \n\n", [campaigns description]);
}

-(NSArray *)getRightBarButtonItemsForCampaign:(SCSDKCampaign *)campaign{
    NSArray *barButtonItems = @[
                                [[UIBarButtonItem alloc]initWithTitle:@"First" style:UIBarButtonItemStyleDone target:self action:@selector(didTapCustomBarButtonItem:)],
                                [[UIBarButtonItem alloc]initWithTitle:@"Second" style:UIBarButtonItemStyleDone target:self action:@selector(didTapCustomBarButtonItem:)],
                                ];
    
    return barButtonItems;
}

-(NSArray *)getToolbarItemsForCampaign:(SCSDKCampaign *)campaign{
    NSArray *barButtonItems = @[
                                [[UIBarButtonItem alloc]initWithTitle:@"First" style:UIBarButtonItemStyleDone target:self action:@selector(didTapCustomBarButtonItem:)],
                                [[UIBarButtonItem alloc]initWithTitle:@"Second" style:UIBarButtonItemStyleDone target:self action:@selector(didTapCustomBarButtonItem:)],
                                ];
    
    return barButtonItems;
}

-(void)didTapCustomBarButtonItem:(id)sender{
    UIBarButtonItem *btn = (UIBarButtonItem *)sender;
    if ([btn.title isEqualToString:@"First"]) {
        NSLog(@"\n\n DID TAP FIRST BUTTON \n\n");
    }else if ([btn.title isEqualToString:@"Second"]) {
        NSLog(@"\n\n DID TAP SECOND BUTTON \n\n");
    }
}

@end
