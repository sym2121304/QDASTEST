//
//  QHStatAgent.h
//  AnalyticsSdkSource
//
//  Created by guanwei-fin on 15/8/6.
//  Copyright (c) 2015年 北京奇虎科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QHAConfiguration.h"
#import "QHACustomEvent.h"


@interface QHStatAgent : NSObject


///---------------------------------------------------------------------------------------
/// @name  设置
///---------------------------------------------------------------------------------------

/**
 *  设置上报错误信息
 *
 *  @param isEnabled BOOL类型 默认 NO
 */
+ (void)setCrashReportEnabled:(BOOL)isEnabled;


/**
 *  设置启用苹果崩溃日志采集
 *
 *  @param isEnabled BOOL类型 默认 NO
 */
+ (void)setCrashReportAppleFormatEnabled:(BOOL)isEnabled;


/**
 *  设置是否打印sdk的log信息
 *
 *  @param isEnabled BOOL类型 默认 NO 设置为YES,SDK 会输出log信息,记得release产品时要设置回NO.
 */
+ (void)setLogEnabled:(BOOL)isEnabled;


/**
 *  设置打印数据监控信息
 *
 *  @param debug BOOL类型 默认 NO
 */
+ (void)setDebugMode:(BOOL)debug;


/**
 允许输出指定类型的log日志
 
 @param types 多个类型log
 */
+ (void)setAllowPrinftLog:(QHADevLogType)types;


/**
 *  设置圈选功能
 *
 *   如果您的AppDelegate中 实现了其中一个或者多个方法 请以在已实现的函数中 调用handleUrl
 *  - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation
 *  - (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
 *  - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options
 *  如果以上所有函数都未实现 则请实现 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation 方法并调用handleUrl
 */
+ (BOOL)handleUrl:(NSURL *_Nonnull)url;


///---------------------------------------------------------------------------------------
/// @name  开启统计
///---------------------------------------------------------------------------------------

/**
 *  开启sdk统计，默认以下次启动方式发送log
 *
 *  @param appKey    在QDAS上注册app的key
 *  @param policy    发送策略
 *  @param channelId 渠道名称,为nil或@""时,默认会被被当作@"App Store"渠道
 */
+ (void)startWithAppkey:(nonnull NSString *)appKey reportPolicy:(QHAReportPolicy)policy channelId:(nullable NSString *)channelId;


/**
 插件版调用

 @param appKey 在QDAS上注册app的key
 @param policy 发送策略
 @param channedId 渠道名称,为nil或@""时,默认会被被当作@"App Store"渠道
 @param extension 是否是插件端调用
 */
+(void)startWithAppkey:(nonnull NSString *)appKey reportPolicy:(QHAReportPolicy)policy channelId:(nullable NSString *)channedId isExtension:(BOOL)extension;


/**
 *  获取m2值，只生成一次uuid存入keychain中，下次直接从keychain中获取。
 *
 *  @return  返回keychain中读取的uuid
 */
+ (nullable NSString *)getM2;


/**
 获取SDK当前版本号

 @return  返回SDK当前版本号。
 */
+(nonnull NSString *)getSDKVersion;


/**
 * 手动设置app当前版本信息
 *
 *  @param appVersion app当前版本信息
 */
+ (void)setappVersion:(nonnull NSString *)appVersion;


/**
 *  为了更精确的统计用户地理位置，可以调用此方法传入经纬度信息
 需要链接 CoreLocation.framework 并且 #import <CoreLocation/CoreLocation.h>
 *
 *  @param latitude  纬度
 *  @param longitude 经度
 */
+ (void)setLocationWithLatitude:(double)latitude longitude:(double)longitude;


/**
 *  设置用户id
 *
 *  @param userId 字符串类型
 */
+ (void)setUserId:(nullable NSString *)userId;


/**
 *  设置tag值
 *
 *  @param tag 字符串类型
 */
+ (void)setTag:(nullable NSString *)tag;


/**
 *  设置多个tag值在header.ext里存放
 *
 *  @param tagValue  tag值  如果传空值则将把之前的赋值删除
 *  @param tagIndex  tag的key
 */
+ (void)setExtraTag:(nullable NSString *)tagValue index:(QHAExtraTagIndex)tagIndex;

/**
 *  设置发送策略
 *
 *  @param reportPolicy 发送策略
 */
+ (void)setReportPolicy:(QHAReportPolicy)reportPolicy;


/**
 *  设置上报当前用户位置信息
 *
 *  @param isEnabled BOOL类型 默认 NO
 */
+ (void)setLocationReportEnabled:(BOOL)isEnabled;


/**
 *  设置是否开启无埋点功能
 *
 *  @param isEnabled BOOL类型 默认 YES
 */
+ (void)setEventBindingsEnabled:(BOOL)isEnabled;


/**
 *  设置自动定位位置信息
 *
 *  @param isEnabled BOOL类型 默认 NO
 */
+ (void)setAutoLocationEnabled:(BOOL)isEnabled;


/**
 *  设置使用测试版本的云控（使用时注意）
 *
 *  @param isBeta BOOL类型 默认 NO 记得release产品时要设置回NO.
 */
+ (void)setOnlineConfigBeBetaVersion:(BOOL)isBeta;


/**
 *  设置A/B Test：本次test设置名字，然后通过设置不同tag值。
 *
 *  @param name 标示
 *  @param tag  类型
 */
+ (void)setABTestName:(nullable NSString *)name andValue:(QHAAbTestTag)tag;

/**
 *  设置域名，包括前缀部分，比如“https://abc.com”
 *
 *  @param report  上报数据的域名
 *  @param config  请求云控数据的域名
 */
+ (void)setDomainForReporting:(nullable NSString *)report onlineConfig:(nullable NSString *)config;


///---------------------------------------------------------------------------------------
/// @name  页面计时
///---------------------------------------------------------------------------------------


/**
 *  页面时长统计,记录某个view被打开多长时间,可以自己计时也可以调用onPageBegin,onPageEnd自动计时
 *
 *  @param pageName 需要记录时长的view名称.
 */
+ (void)onPageBegin:(nonnull NSString *)pageName;
+ (void)onPageEnd:(nonnull NSString *)pageName;


+ (void)onPageBegin:(nonnull NSString *)pageName label:(nullable NSString *)label;
+ (void)onPageBegin:(nonnull NSString *)pageName dataLevel:(QHADataLevel)dataLevel;
+ (void)onPageBegin:(nonnull NSString *)pageName dataLevel:(QHADataLevel)dataLevel  label:(nullable NSString *)label;
+ (void)onPageBegin:(nonnull NSString *)pageName ABTestName:(nullable NSString *)ABTestName ABTestValue:(QHAAbTestTag )abTestTag;
+ (void)onPageBegin:(nonnull NSString *)pageName dataLevel:(QHADataLevel)dataLevel ABTestName:(nullable NSString *)ABTestName ABTestValue:(QHAAbTestTag )abTestTag;


/**
 *  页面时长统计,记录某个view被打开多长时间
 *
 *  @param pageName   需要记录时长的view名称.
 *  @param dataLevel  上传数据优先级
 *  @param label      拓展
 *  @param ABTestName A／B Test 名称
 *  @param abTestTag  A／B Test 类型
 */
+ (void)onPageBegin:(nonnull NSString *)pageName dataLevel:(QHADataLevel)dataLevel label:(nullable NSString *)label ABTestName:(nullable NSString *)ABTestName ABTestValue:(QHAAbTestTag )abTestTag;


///---------------------------------------------------------------------------------------
/// @name  自定义事件统计
///---------------------------------------------------------------------------------------


/**
 *  使用前，请先到友盟App管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
 *  @param event 自定义事件实例
 */
+ (void)onEvent:(nonnull QHACustomEvent *)event;


/**
 *  数据优先级为L5，采样类型是A的计数事件发生一次
 *  使用前，请先到友盟App管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
 *  @param eventId 事件ID
 */
+ (void)onTimeEvent:(nonnull NSString *)eventId;


/**
 * 远程推送事件
 * @param pushId 远程推送信息的标识
 * @param type 推送事件类型
 * @param label 分类标签。不同的标签会分别进行统计，方便同一事件的不同标签的对比,为nil或空字符串时后台会生成和pushId同名的标签.
 */
+ (void)onPushEvent:(nonnull NSString *)pushId type:(QHAPushType)type label:(nullable NSString *)label;
 

@end
