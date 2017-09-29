//
//  PRXUserCampaignsTableViewController.m
//  SweepinConnect_Example
//
//  Created by Alexis Barat on 29/09/2017.
//  Copyright © 2017 Alexis Barat. All rights reserved.
//

#import "PRXUserCampaignsTableViewController.h"

#import "PRXUserCampaignTableViewCell.h"
@import SCSDKCoreKit;
@import SCSDKProximityServiceKit;
#import <SCSDKProximityServiceKit/SCSDKCampaign.h>


@interface PRXUserCampaignsTableViewController ()

@end

@implementation PRXUserCampaignsTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.tableView registerNib:[UINib nibWithNibName:@"PRXUserCampaignTableViewCell" bundle:nil] forCellReuseIdentifier:@"campaignCellIdentifier"];
    [self.tableView setDelegate:self];
    [self.tableView setDataSource:self];
    
}

-(void)setArrCampaigns:(NSMutableArray *)arrCampaigns{
    _arrCampaigns = arrCampaigns;
    [self.tableView reloadData];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [_arrCampaigns count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    PRXUserCampaignTableViewCell *cell = (PRXUserCampaignTableViewCell *)[tableView dequeueReusableCellWithIdentifier:@"campaignCellIdentifier" forIndexPath:indexPath];

    [cell.campaignImageView setImageURL:nil];
    [cell.campaignImageView setImage:nil];
    
    SCSDKCampaign *campaign = [[SCSDKCampaign alloc]initWithProperties:[_arrCampaigns objectAtIndex:indexPath.row]];
    [cell.campaignTitleLabel setText:[campaign title]];
    [cell.campaignImageView setImageURL:[NSURL URLWithString:concatString(@"https://sweepin.fr", campaign.image)]];
    
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    SCSDKCampaign *campaign = [[SCSDKCampaign alloc]initWithProperties:[_arrCampaigns objectAtIndex:indexPath.row]];
    [[SCSDKProximityService sharedInstance]displayCampaign:campaign];
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 70;
}

@end
