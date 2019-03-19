//
//  QHAABTestStart.h
//  AnalyticsSdk
//
//  Created by sunyimin on 2017/10/30.
//  Copyright © 2017年 北京奇虎科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface QHAABTestSnapShot : NSObject


/**
 根据变量名称获取变量值
 
 @param name 测试变量名称
 @return 通过变量名称返回对应的值
 */
- (id _Nullable)getABTestVariable:(NSString *_Nonnull)name;

/**
 获取当前运行的实验信息
 
 @return 返回实验信息
 */
- (NSArray *_Nullable)getAllCurrentABTest;


/**
 上报ABTest指标数据
 
 @param eventName 指标名称
 @param value 变量值
 */
- (void)tracker:(NSString *_Nonnull)eventName withValue:(NSNumber *_Nullable)value;
- (void)tracker:(NSString *_Nonnull)eventName;


@end


@interface QHAABTestStart : NSObject

typedef void (^QHAABTestSnapShotBlock)(QHAABTestSnapShot * _Nullable object);

/**
 ABTest初始化方法

 @param appKey 在QDAS上注册app的key
 @param channelId 渠道名称,为nil或@""时,默认会被被当作@"App Store"渠道
 @return 初始化方法对象
 */
+ (QHAABTestStart *_Nullable)startWithAppkey:(NSString *_Nonnull)appKey channelId:(NSString *_Nullable)channelId;


/**
 设置上报数据的域名和获取测试参数接口以及云控接口

 @param report 上报数据的域名
 @param config 请求云控数据的域名
 @param abtestUrl 获取ABTest测试方案的域名
 */
- (void)setDomainForReporting:(NSString *_Nullable)report onlineConfig:(NSString *_Nullable)config getABTestsUrl:(NSString *_Nullable)abtestUrl;


/**
 设置用户id

 @param userId 用户ID
 */
- (void)setUserId:(NSString *_Nullable)userId;


/**
 设置是否打印sdk的log信息

 @param isEnabled 是否打印log，默认关闭
 */
//- (void)setLogEnabled:(BOOL)isEnabled;


/**
 设置精细化分流属性
 
 @param customProperties 自定义维度
 */
- (void)setABTestCustomProperties:(NSMutableDictionary *_Nonnull)customProperties;


/**
 获取快照实例化对象

 @param block 快照实例化对象，当获取不到时返回为空
 */
- (void)getSingleToSnapShotObj:(QHAABTestSnapShotBlock _Nullable) block;


/**
 更新本地ABTest方案
 */
- (void)updateABTestsPlan;


/**
 集成化测试
 *   如果您的AppDelegate中 实现了其中一个或者多个方法 请以在已实现的函数中 调用handleUrl
 *  - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation
 *  - (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
 *  - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options
 *  如果以上所有函数都未实现 则请实现 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation 方法并调用handleUrl
 注意：需要在调用完handleUrl后，调用一次getSingleToSnapShotObj，把回调对象赋值给全局对象。
 @param url url scheme
 @return 是否成功
 */
+ (BOOL)handleUrl:(NSURL *_Nonnull)url;

@end

