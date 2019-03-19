//
//  Configration.h
//  AnalyticsSdkSource
//
//  Created by guanwei-fin on 15/8/6.
//  Copyright (c) 2015年 北京奇虎科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


/**报告策略*/
typedef NS_ENUM(NSUInteger, QHAReportPolicy){
    QHAReportPolicyBatch = 0,          //应用启动时发送(默认)
    QHAReportPolicyInterval = 1        //间隔发送
//    QHAReportPolicyRealtime = 2        //实时发送
};


/**上报数据优先级*/
typedef NS_ENUM(int, QHADataLevel) {//1，2，3，4，6，7，8为非标准级别
    QHADataLevel1 = 1, //默认24小时以后
    QHADataLevel5 = 5, //间隔时间
    QHADataLevel9 = 9//实时时间
};


/**统计项目*/
typedef NS_ENUM(NSUInteger, AnalyticsItem) {
    AnalyticsItemModuleName             =0,//model机型
    AnalyticsItemCarrier                =1,//operator 电信运营商
    AnalyticsItemLocaleCountryCode      =2,//country 国家
    AnalyticsItemBoard                  =3,//board 主版名称 IOS 没有这项
    AnalyticsItemBrand                  =4,//brand 商标名称 IOS 没有这项
    AnalyticsItemManufacturer           =5,//manufacturer 制造商 IOS 没有这项
    AnalyticsItemUid                    =6,//ip 已不使用该位，保留做其它用处
    AnalyticsItemMac                    =7,//mac IOS 没有这项
    AnalyticsItemTag                    =8,//tag 自定义标签
    AnalyticsItemImei                   =9,//imei IOS 没有这项
    AnalyticsItemLanguage               =10,//language 系统语言
    AnalyticsItemPage                   =11,//activity 页面信息
    AnalyticsItemSession                =12,//terminate 会话信息
    AnalyticsItemCpu                    =13,//cpu IOS 没有这项
    AnalyticsItemLongitude              =14,//longitude
    AnalyticsItemLatitude               =15,//latitude
    AnalyticsItemCustomEvent            =16,//event 自定义事件
    AnalyticsItemSocialEvent            =17,//social 社交行为
    AnalyticsItemBSSID                  =18,//Wifi BSSID
    AnalyticsItemEventBindings          =19,//是否支持无埋点
    AnalyticsItemAOP                    =20 //是否支持无埋点全量采集数据

};


//采样项目ID,一个ID对应一个采样值，可通过云控来设置
typedef NS_ENUM(int, SampledItemId){
    SampledItemIdPage,            //页面
    SampledItemIdCustomEventA,    //A类型事件
    SampledItemIdCustomEventB     //B类型事件
};


typedef NS_ENUM(NSUInteger, QHACustomEventSamplingType){
    QHACustomEventSamplingTypeA,    //A类型事件
    QHACustomEventSamplingTypeB     //B类型事件
};


/**数据类型*/
typedef NS_ENUM(NSUInteger, QHADataType) {
    QHADataTypeBasicInfo,
    QHADataTypeSession,
    QHADataTypePage,
    QHADataTypeCustomEvent,
    QHADataTypeBindingEvent,
    QHADataTypeAOPPage,
    QHADataTypeError
};


/**报告类型*/
typedef NS_ENUM(NSUInteger, QHADataReportType) {
    QHADataReportTypeNormal = 0,//正常报告
    QHADataReportTypeBackGround = 1,////wifi或者Extension启动
    QHADataReportTypeFileSystemFreeSizeIsLow = 2,//存储空间不足
    QHADataReportTypeOnSessionBegin = 3//应用启动报告
};


//1为收到远程推送，2为点击打开远程推送，3为远程推送已展示，4为触发下载
typedef NS_ENUM(NSUInteger, QHAPushType) {
    QHAPushTypeReceived = 1,//收到推送
    QHAPushTypeOpen     = 2,//用户打开推送
    QHAPushTypeShown    = 3,//推送信息打开并展示
    QHAPushTypeDownload = 4 //推送触发下载
};


/**A／B Test类型*/
typedef NS_ENUM(NSUInteger, QHAAbTestTag) {
    QHAAbTestTagA = 1,
    QHAAbTestTagB = 2,
    QHAAbTestTagC = 3,
    QHAAbTestTagD = 4,
    QHAAbTestTagE = 5
};


/**header中放入ext里的tag类型*/
typedef NS_ENUM(NSUInteger, QHAExtraTagIndex) {
    QHAExtraTagIndex1 = 1,
    QHAExtraTagIndex2 = 2,
    QHAExtraTagIndex3 = 3,
    QHAExtraTagIndex4 = 4,
    QHAExtraTagIndex5 = 5,
    QHAExtraTagIndex6 = 6,
    QHAExtraTagIndex7 = 7,
    QHAExtraTagIndex8 = 8,
    QHAExtraTagIndex9 = 9,
    QHAExtraTagIndex10 = 10,
};


typedef NS_OPTIONS(NSUInteger, QHADevLogType){
    QHADevLogTypeDataPersiser = 1<<0,
    QHADevLogTypeConfiguration = 1<<1,
    QHADevLogTypeSession = 1<<2,
    QHADevLogTypeEvent = 1<<3,
    QHADevLogTypePage = 1<<4,
    QHADevLogTypeActivity = 1<<5,
    QHADevLogTypeUpload = 1<<6,
    QHADevLogTypeRealtimeUpload = 1<<7,
    QHADevLogTypeAOPEvent = 1<<8,
    QHADevLogTypeAOPPage = 1<<9,
    QHADevLogTypeABTest = 1<<10,
    QHADevLogTypeDataAll = QHADevLogTypeDataPersiser|
    QHADevLogTypeConfiguration|QHADevLogTypeSession|
    QHADevLogTypeEvent|QHADevLogTypePage|
    QHADevLogTypeActivity|QHADevLogTypeUpload|
    QHADevLogTypeRealtimeUpload|QHADevLogTypeAOPEvent|
    QHADevLogTypeAOPPage|QHADevLogTypeABTest
    
};

////////////////////////////////////////////
#pragma mark -
#pragma mark 采样项目
@interface SampledItem : NSObject
@property (nonatomic,assign)SampledItemId itemId;
@property (nonatomic,assign,readonly) BOOL isSampled;//是否是取样设备，YES表示是取样设备，则采集信息，否则不采集信息
- (instancetype)initWithItemId:(SampledItemId)itemId;
- (void)updateWithSamplingRate:(unsigned int)rateValue;
@end


////////////////////////////////////////////
#pragma mark -
#pragma mark 云控对象
@interface QHAOnlineConfiguration : NSObject
@property (nonatomic,strong) NSString *appKey;
@property (nonatomic,strong) NSNumber *refreshInterval;//请求云控配置的间隔，单位为小时
@property (nonatomic,strong) NSNumber *reportPolicy;//上传策略，0为下次启动时，1为按间隔

@property (nonatomic,strong) NSNumber *reportInterval2G;//2G上传间隔
@property (nonatomic,strong) NSNumber *reportInterval3G;//3G上传间隔
@property (nonatomic,strong) NSNumber *reportInterval4G;//4G上传间隔
@property (nonatomic,strong) NSNumber *reportIntervalWiFi;//WIFI上传间隔

@property (nonatomic,strong) NSNumber *reportIntervalBg;//后台活跃上传间隔

@property (nonatomic,strong) NSNumber *reportInterval2GL1;//L1,2G上传间隔
@property (nonatomic,strong) NSNumber *reportInterval3GL1;//L1,3G上传间隔
@property (nonatomic,strong) NSNumber *reportInterval4GL1;//L1,4G上传间隔
@property (nonatomic,strong) NSNumber *reportIntervalWiFiL1;//L1,WIFI上传间隔

@property (nonatomic,strong) NSNumber *reportWhenNoDataRetryTimes; //读取上报数据并上传时，没有读取到数据时的重试次数
@property (nonatomic,strong) NSNumber *sessionFinishDelay;//会话持续时间，单位毫秒,这个字段IOS版本不会使用。
@property (nonatomic,strong) NSNumber *dataCacheItemSize;//上报时每个包的大小byte，超过此值就要分包。
@property (nonatomic,strong) NSNumber *dataCacheMaxFileSize;//本地缓存文件最大的大小bype，超过此大小就要删除一部分或全部
@property (nonatomic,strong) NSNumber *dataCacheMinFileSystemFreeSize;//文件系统最小可用空间，满足此项才会写缓存文件
@property (nonatomic,strong) NSNumber *transportProtocols;//上传协议顺序，1为Post、2为Get、3为TCP、4为UDP
@property (nonatomic,strong) NSNumber *intervalReportCancelTimeInterval;//间隔上传的最大时间间隔
@property (nonatomic,strong) NSNumber *maxErrorCountOneDay;//每天上报错误条数最大值

@property (nonatomic,strong) NSNumber *switchValue;//一个十进制的无符号64位数字，用来做采集项开关
@property (nonatomic,strong) NSNumber *sdkSwitchValue;//SDK排错用的开关。为开时会上传排错信息。

@property (nonatomic,strong) SampledItem *sampledItemPage;//页面路径的采样率
@property (nonatomic,strong) SampledItem *sampledItemCustomEventA;//自定义事件A的采样率
@property (nonatomic,strong) SampledItem *sampledItemCustomEventB;//自定义事件B的采样率


//=====
- (instancetype)initWithDic:(NSDictionary *)dic;
+ (void)loadOnlineConfigurationWithAppKey:(NSString *)appKey;
+ (QHAOnlineConfiguration *)readOnlineConfiguration;
+ (BOOL)isTimeToUpdateOnlineConfig;
@end

@interface QHAConfiguration : NSObject

@property(nonatomic,assign)BOOL reportEnabled;//是否上报统计数据
@property(nonatomic,assign)BOOL crashReportEnabled;//是否上报错误信息
@property(nonatomic,assign)BOOL crashReportAppleFormatEnabled;//是否上报苹果错误报告
@property(nonatomic,assign)BOOL autoLocationEnabled;//是否自动定位位置信息
@property(nonatomic,assign)BOOL loactionReportEnabled;//是否上报位置信息
@property(nonatomic,assign)BOOL logEnabled;//是否输出日志
@property(nonatomic,assign)BOOL useIdfvOnly;//是否只使用IDFV,不使用KEYCHAIN
@property(nonatomic,assign)BOOL debugMode;//测试模式会开启数据监听
@property(nonatomic,assign)QHAReportPolicy reportPolicy;
@property(nonatomic,assign)double onlineConfigUpdateTimeInterval;//云控的更新时间间隔
@property(nonatomic,assign)NSUInteger reportWhenNoDataRetryTimes;//读取上报数据并上传时，没有读取到数据时的重试次数
@property(nonatomic,assign)long long switchValue;//一个十进制的无符号64位数字，用来做采集项开关
@property(nonatomic,assign)unsigned long long dataCacheItemSize;   //每个包的大小，默认5KB
@property(nonatomic,assign)unsigned long long dataCacheMinFileSystemFreeSize;   //最小可用存储空间，默认50MB
@property(nonatomic,assign)unsigned long long dataCacheMaxFileSize;    //本地最多备份的数据大小，默认2MB
@property (nonatomic,assign) BOOL onlineConfigBeBetaVersion;//是否使用测试版本的云控
@property (nonatomic,assign) BOOL devLogEnable;
@property (nonatomic,assign) BOOL dataL1Enable;
@property (nonatomic,assign) BOOL isExtension;//是否Extension
@property (nonatomic,assign) BOOL isEventBinding;//是否开启无埋点功能

@property(nonatomic,assign,readonly) BOOL debugInfo;//是否上传排错信息，默认关闭
@property(nonatomic,assign,readonly) BOOL debugInfoPersistable;
@property(nonatomic,assign) BOOL sdkError;//是否上报SDKError
@property(nonatomic,strong) NSString *domainReport;//报告域名
@property(nonatomic,strong) NSString *domainConfig;//云控域名
@property(nonatomic,assign)NSUInteger intervalReportCancelTimeInterval;//间隔上传的最大时间间隔
@property(nonatomic,assign)NSUInteger maxErrorCountOneDay;//每天上报错误条数最大值
@property (atomic, strong) NSSet *eventBindings;//圈选事件集合
@property (nonatomic,strong) NSString *EBindingVersion;//圈选事件版本号
@property (nonatomic,strong) NSString *configVersion;//云控版本号
@property(nonatomic,strong) QHAOnlineConfiguration *onlineConfig;

//=====

+ (QHAConfiguration *)instance;
- (NSTimeInterval)reportTimeInervalWithDataLevel:(QHADataLevel)dataLevel;
- (BOOL)isAnalyticsItemEanble:(AnalyticsItem)item;
- (BOOL)isAnalyticsItemEanble:(AnalyticsItem)item samplingEffect:(BOOL)hasEffect;
- (BOOL)isAnalyticsItemEanble:(AnalyticsItem)item customEventSamplingType:(QHACustomEventSamplingType)samplingType samplingEffect:(BOOL)hasEffect;
- (void)syncUpdateOnlineConfiguration;
+ (QHADataLevel)ensureDataLevel:(QHADataLevel)dataLevel;
- (void)executeLocationEventBindings;
@end




