//
//  PRXAnimationsTableViewControllerDelegate.h
//  ProximitiesSDK
//
//  Created by Alex on 01/04/2016.
//  Copyright © 2016 Johan Jégard. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PRXAnimationsTableViewControllerDelegate : UIViewController<UINavigationBarDelegate, UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) id fromVC;

@property (nonatomic, strong) NSString *userAction;
@property (weak, nonatomic) IBOutlet UITableView *tableView;

/*
 UIAttributes keys :
 
 @{@"noResultsMessage":@"Pas de résultats",
 @"failToRetrieveMessage":@"Pas de réseau",
 @"notifTitleColor":@"1a0dab",
 @"noResultsMessageTitleColor":@"fa99cc",
 @"failToRetrieveMessageTitleColor":@"b90d75",
 @"topBarTintColor":@"b90d75",
 @"topBarBackgroundColor":@"fa99cc",
 @"topBarTitle":@"Notifications"
*/
@property (nonatomic, strong) NSDictionary *UIAttributes;

-(instancetype)initWithUIAttributes:(NSDictionary *)attributes andUserAction:(NSString *)userAction;

@end