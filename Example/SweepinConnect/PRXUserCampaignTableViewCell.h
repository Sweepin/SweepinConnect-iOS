//
//  PRXUserCampaignTableViewCell.h
//  SweepinConnect_Example
//
//  Created by Alexis Barat on 29/09/2017.
//  Copyright © 2017 Alexis Barat. All rights reserved.
//

#import <UIKit/UIKit.h>
@import SCSDKCoreKit;

@interface PRXUserCampaignTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *poiNameLabel;
@property (weak, nonatomic) IBOutlet UILabel *campaignTitleLabel;
@property (weak, nonatomic) IBOutlet SCAsyncImageView *campaignImageView;

@end
