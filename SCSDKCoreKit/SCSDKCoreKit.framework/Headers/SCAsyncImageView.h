//
//  SCAsyncImageView.h
//  SCSDKCoreKit
//
//  Created by Alex on 21/11/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import "AsyncImageView.h"

@interface SCAsyncImageView : AsyncImageView

@property (nonatomic, strong) UIImage *defaultImage;
@property (nonatomic,strong) NSDictionary *userInfos;
@property (nonatomic, assign) CGFloat cornerRadius;

- (void)showDefaultImage;

@end
