//
//  NSURLRequest+cURL.h
//  SCSDKCoreKit
//
//  Created by Alex on 22/02/2017.
//  Copyright © 2017 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURLRequest (cURL)
- (NSString *)cURLCommandString;
- (NSString *)cURLCommandStringWithSession:(NSURLSession *)session;
@end
