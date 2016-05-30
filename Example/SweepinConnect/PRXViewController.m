//
//  PRXViewController.m
//  SweepinConnect
//
//  Created by Alexis Barat on 05/20/2016.
//  Copyright (c) 2016 Alexis Barat. All rights reserved.
//

#import "PRXViewController.h"
#import <ProximitiesSDK/PRX.h>

@interface PRXViewController ()
@property (weak, nonatomic) IBOutlet UIButton *showInTableViewBtn;
@property (weak, nonatomic) IBOutlet UIButton *showInColViewBtn;
@end

@implementation PRXViewController

- (void)viewDidLoad{
    [super viewDidLoad];
    [_showInTableViewBtn.layer setCornerRadius:3];
    _showInTableViewBtn.titleLabel.textAlignment = NSTextAlignmentCenter;

    [_showInColViewBtn.layer setCornerRadius:3];
    _showInColViewBtn.titleLabel.textAlignment = NSTextAlignmentCenter;
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)presentTableViewAction:(id)sender {
    NSDictionary *dict = @{
                           @"noResultsMessage":@"No results",
                           @"failToRetrieveMessage":@"Network issue",
                           @"notifTitleColor":@"1a0dab",
                           @"noResultsMessageTitleColor":@"da4600",
                           @"failToRetrieveMessageTitleColor":@"da4600",
                           @"topBarTintColor":@"ffffff",
                           @"topBarBackgroundColor":@"da4600",
                           @"topBarTitle":@"Last received"
                           };
    [[PRX singleton] presentAnimationsTableViewControllerWithUIAttributes:dict forUserAction:@"anim_received"];
}

- (IBAction)presentColViewAction:(id)sender {
    NSDictionary *dict = @{
                           @"noResultsMessage":@"No results",
                           @"failToRetrieveMessage":@"Network issue",
                           @"notifTitleColor":@"1a0dab",
                           @"noResultsMessageTitleColor":@"da4600",
                           @"failToRetrieveMessageTitleColor":@"da4600",
                           @"topBarTintColor":@"ffffff",
                           @"topBarBackgroundColor":@"da4600",
                           @"topBarTitle":@"Last received"
                           };
    [[PRX singleton] presentAnimationsCollectionViewControllerWithUIAttributes:dict forUserAction:@"anim_received"];
}

- (IBAction)doNotDisturbAction:(id)sender {
    if([sender isOn]){
        [[PRX singleton]preventAnimations:YES];
    } else{
        [[PRX singleton]preventAnimations:NO];
    }
}

@end