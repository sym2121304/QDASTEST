//
//  CustomEvent.h
//  AnalyticsSdkSource
//
//  Created by guanwei-fin on 15/8/4.
//  Copyright (c) 2015年 北京奇虎科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QHAConfiguration.h"

/**事件类型*/
typedef NS_ENUM(NSUInteger, QHACustomEventType){
    QHACustomEventTypeNormal,//普通事件
    QHACustomEventTypePush//推送事件
};


@interface QHACustomEvent : NSObject

@property (nonatomic,assign) QHACustomEventType type;//事件类型
@property (nonatomic,strong,nonnull) NSString *eventId;//事件ID
@property (nonatomic,assign) QHACustomEventSamplingType samplingType;//事件采样类型
@property (nonatomic,assign) unsigned long long timeValue;//事件发生次数
@property (nonatomic,strong,nullable) NSString *statusValue;//事件状态值
@property (nonatomic,strong,nullable) NSString *label;//用户自定义标签
@property (nonatomic,strong,nullable) NSDictionary *customAttributes;//用户自定义属性
@property (nonatomic,assign) QHADataLevel dataLevel;//数据优先级
@property (nonatomic,readonly) unsigned long long timestamp;//事件发生时间戳
@property (nonatomic,assign) QHAAbTestTag abTestValue;//用于做AB Test的标识
@property (nonatomic,strong,nullable) NSString *abTestName;
//=====

- (nonnull instancetype)initWithId:(nonnull NSString *)eventId;


/**
 *创建自定义事件实例
 *@param eventId 事件ID
 */
+ (nonnull QHACustomEvent *)eventWithId:(nonnull NSString *)eventId;


/**
 *创建自定义事件实例
 *@param eventId 事件ID
 */
+ (nullable QHACustomEvent *)timeEvent:(nonnull NSString *)eventId;


/**
 *自定义事件发生一次
 *@param event 自定义事件实例
 */
+ (void)onEvent:(nonnull QHACustomEvent *)event;


/**
 *数据优先级为L5的计数事件发生一次
 *@param eventId 事件ID
 */
+ (void)onTimeEvent:(nonnull NSString *)eventId;


/**
 * 远程推送事件
 * @param pushId 远程推送信息的标识
 * @param type 推送事件类型
 * @param label 用户自定义标签
 */
+ (void)onPushEvent:(nonnull NSString *)pushId type:(QHAPushType)type label:(nullable NSString *)label;


/**
 *  自定义事件，上传服务器组合参数
 *
 *  @return 可变字典类型
 */
- (nonnull NSMutableDictionary *)toDictionary;
@end
