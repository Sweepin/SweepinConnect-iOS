//
//  SCSDKNetworkManager.h
//  SCSDKCoreKit
//
//  Created by Alex on 07/12/2016.
//  Copyright © 2016 Sweepin. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SCSDKNetworkManagerRequestHeadersDataSource <NSObject>

/**
 * Implement this method to set custom headers to the corresponding request before creating a dataTask
 **/
-(NSDictionary *)getAdditionalHeadersForRequest:(NSURLRequest *)request;

@end
@interface SCSDKNetworkManager : NSObject

@property (nonatomic, strong) id<SCSDKNetworkManagerRequestHeadersDataSource> requestHeadersDatasource;

@property (nonatomic, strong) NSString *baseUrl;

/**
 * Related session can be accessed or set.
 * Default is [NSURLSession sharedSession]
 **/
@property (nonatomic, strong) NSURLSession *session;

/**
 * Session headers
 **/
-(void)addHeaderToSessionWithValue:(NSString *)value forKey:(NSString *)key;

/**
 * REST HTTP Methods
 **/
-(void)postToUrlPath:(NSString *)urlPath options:(NSDictionary*)options data:(NSDictionary *)data successHandler:(void (^)(id object))success failureHandler:(void (^)(NSError *error))failure;

-(void)putToUrlPath:(NSString *)urlPath options:(NSDictionary*)options data:(NSDictionary *)data successHandler:(void (^)(id object))success failureHandler:(void (^)(NSError *error))failure;

-(void)getFromUrlPath:(NSString *)urlPath options:(NSDictionary*)options successHandler:(void (^)(id object))success failureHandler:(void (^)(NSError *error))failure;

-(void)deleteFromUrlPath:(NSString *)urlPath options:(NSDictionary*)options successHandler:(void (^)(id object))success failureHandler:(void (^)(NSError *error))failure;

/**
 * Utils
 **/
+(NSString*)jsonToString:(NSObject *)data;
-(void)cURLWithMethod:(NSString *)httpMethod URLPath:(NSString *)urlPath data:(NSDictionary *)data successHandler:(void (^)(id object))success failureHandler:(void (^)(NSError *error))failure;

@end
