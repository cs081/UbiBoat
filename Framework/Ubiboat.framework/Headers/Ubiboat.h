//
//  UbiBoat.h
//  UbiBoat
//
//  Created by apple on 2021/7/30.
//

#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <BabyBluetooth/BabyBluetooth.h>
#import <AFNetworking/AFNetworking.h>

//#import "UbDelegate.h"
#import <CoreLocation/CLLocationManager.h>
//! Project version number for UbiBoat.
FOUNDATION_EXPORT double UbiBoatVersionNumber;

//! Project version string for UbiBoat.
FOUNDATION_EXPORT const unsigned char UbiBoatVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <UbiBoat/PublicHeader.h>
NS_ASSUME_NONNULL_BEGIN

#define UBSTARTSUCESS           @"UbiBoat启动成功"
#define UBLOCATIONAUTHERROR     @"定位权限异常"
#define UBBTAUTHERROR           @"蓝牙权限异常"
#define KEYERROR                @"秘钥系统不匹配"
#define NEEDKEY                 @"需要秘钥"
#define IPNOTINWHITELIST        @"访问IP不在白名单"
#define SYSTEMERROR             @"系统错误"
typedef NS_ENUM(NSInteger, ubiBoatStatus) {
//    1：启动成功
    ubiBoatStatusStartSucess = 1,
//    2：key没有值
    ubiBoatStatusKeyError,
//    3：UserId没有值
    ubiBoatStatusappUserIdError,
//    4：蓝牙关闭
    ubiBoatStatusBTPowerOff,
//    5：APP没有蓝牙权限
    ubiBoatStatusBTUnauthorized,
//    6：手机没有识别到蓝牙
    ubiBoatStatusBTUnsupported,
//    7：用户尚未决定是否允许定位权限
    ubiBoatStatusCLNotDetermined,
//    8：定位权限受限，用户没有权限打开
    ubiBoatStatusCLRestricted,
//    9：用户禁止APP使用定位
    ubiBoatStatusCLDenied,
//    10：用户禁止APP使用蜂窝网络
    ubiBoatStatusNetDenied,
//    11：key校验失败
    ubiBoatStatusKeyVerifyFailed,
//    12：没有查询到附近的人
    ubiBoatStatusNONearPerson,
//    13：没有查询到附近的人
    ubiBoatStatusCannotGetDistance,
//    14：系统错误
    ubiBoatStatusSystemError,
};
//#define UBLOCATIONAUTHERROR     @"定位权限异常"
typedef NS_ENUM(NSInteger, ubiBoatStartError) {
//默认从0开始
//UbiBoat 启动成功
    UBIBoatStartSucess = 1,
//已经启动，本次启动不执行
    UBIBoatStarted,
//用户第一次打开App的时候，用户没有决定是否使用定位服务,+2
    UBkCLAuthorizationStatusNotDetermined,
//定位服务授权状态是受限制的。可能是由于活动限制定位服务，用户不能改变。这个状态可能不是用户拒绝的定位服务
    UBkCLAuthorizationStatusRestricted,
//定位服务授权状态已经被用户明确禁止，或者在设置里的定位服务中关闭
    UBkCLAuthorizationStatusDenied,
//定位服务授权状态已经被用户允许在任何状态下获取位置信息。包括监测区域、访问区域、或者在有显著的位置变化的时候。
    UBkCLAuthorizationStatusAuthorizedAlways,
//定位服务授权状态仅在使用应用程序的时候被允许
    UBkCLAuthorizationStatusAuthorizedWhenInUse,
    
//手机没有识别到蓝牙+7
    UBCBManagerStateUnknown,
//手机蓝牙已断开连接，重置中...
    UBCBManagerStateResetting,
//手机不支持蓝牙功能
    UBCBManagerStateUnsupported,
//手机蓝牙功能没有权限,需前往设置
    UBCBManagerStateUnauthorized,
//手机蓝牙功能关闭，需前往设置打开蓝牙及控制中心打开蓝牙
    UBCBManagerStatePoweredOff,
//蓝牙开启且可用,+12
    UBCBManagerStatePoweredOn,
};
typedef NS_ENUM(NSInteger, UBiBoatRspMessage) {
    UBiBoatRspMessageGetDis,
    UBiBoatRspMessageGetNear,
    UBiBoatRspMessageScene,
    UBiBoatRspMessageStatus,
    UBiBoatRspMessageUploadAnchor,
};
typedef NS_ENUM(NSInteger, UBiBoatServerRspType) {
//    秘钥系统不匹配
    UBiBoatServerRspTypeKeyError = 401,
//    需要秘钥
    UBiBoatServerRspTypeKeyLost = 402,
//    访问IP不在白名单
    UBiBoatServerRspTypeIPRefused = 403,
//    系统错误
    UBiBoatServerRspTypeSystemError = 503,
};
@protocol UbNetDelegate <NSObject>

-(void)ub_onUbiboatResp:(NSMutableDictionary*)dataDic;
@end


@interface UbiboatManager : NSObject

@property (nonatomic, weak) id <UbNetDelegate> UbNetDelegate;
//@property (nonatomic, weak) id <UBLocationDelegate> UBLocationDelegate;
//- (void)start;
+ (UbiboatManager *)sharedManager;
- (void)initWithAppKey:(NSString *)appKey andWithUserID:(NSString*)appUserId;
- (void)start;
- (void)stop;
- (void)getNearPoi:(double)dis type:(int)type;
- (void)getDis:(NSString*)appUserId;
@end

NS_ASSUME_NONNULL_END


