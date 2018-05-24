//
//  RLMObject+PropertyArray.h
//  SCSDKCoreKit
//
//  Created by Alexis Barat on 21/08/2017.
//  Copyright © 2017 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Realm/Realm.h>

@interface RLMObject (NSDictionary)
- (NSDictionary*) dictionaryRepresentation;
@end
