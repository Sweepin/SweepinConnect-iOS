//
//  PRXAnimationViewControllerDelegate.h
//  ProximitiesSDK
//
//  Created by Johan Jégard on 22/04/2015.
//  Copyright (c) 2015 Johan Jégard. All rights reserved.
//


#ifndef ProximitiesSDK_PRXAnimationViewControllerDelegate_h
#define ProximitiesSDK_PRXAnimationViewControllerDelegate_h

@class PRXAnimation;
@protocol PRXAnimationViewControllerDelegate <NSObject>
@optional
- (BOOL) shouldTapRightButtonWithAnimation:(PRXAnimation*)animation;
- (BOOL) shouldTapLeftButtonWithAnimation:(PRXAnimation*)animation;
- (void) didTapRightButtonWithAnimation:(PRXAnimation*)animation;
- (void) didTapLeftButtonWithAnimation:(PRXAnimation*)animation;
- (void) didReceivePRXAnimation:(PRXAnimation*)animation;
- (void) didReceiveMultiplePRXAnimations:(NSDictionary*)animationsDict;
@end

#endif