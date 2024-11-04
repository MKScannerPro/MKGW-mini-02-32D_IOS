//
//  MKCSMQTTDataManager.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MKCSServerConfigDefines.h"

#import "MKCSMQTTTaskID.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const MKCSMQTTSessionManagerStateChangedNotification;

extern NSString *const MKCSReceiveDeviceOnlineNotification;

extern NSString *const MKCSReceiveDeviceOTAResultNotification;

extern NSString *const MKCSReceiveDeviceNpcOTAResultNotification;

extern NSString *const MKCSReceiveDeviceResetByButtonNotification;

extern NSString *const MKCSReceiveDeviceUpdateMqttCertsResultNotification;

extern NSString *const MKCSReceiveDeviceNetStateNotification;

extern NSString *const MKCSReceiveDeviceDatasNotification;

extern NSString *const MKCSReceiveGatewayDisconnectBXPButtonNotification;

extern NSString *const MKCSReceiveGatewayDisconnectDeviceNotification;

extern NSString *const MKCSReceiveGatewayConnectedDeviceDatasNotification;

extern NSString *const MKCSReceiveBxpButtonDfuProgressNotification;

extern NSString *const MKCSReceiveBxpButtonDfuResultNotification;


extern NSString *const MKCSReceiveDeviceOfflineNotification;

@protocol MKCSReceiveDeviceDatasDelegate <NSObject>

- (void)mk_cs_receiveDeviceDatas:(NSDictionary *)data;

@end

@interface MKCSMQTTDataManager : NSObject<MKCSServerManagerProtocol>

@property (nonatomic, weak)id <MKCSReceiveDeviceDatasDelegate>dataDelegate;

@property (nonatomic, assign, readonly)MKCSMQTTSessionManagerState state;

+ (MKCSMQTTDataManager *)shared;

+ (void)singleDealloc;

/// 当前app连接服务器参数
@property (nonatomic, strong, readonly, getter=currentServerParams)id <MKCSServerParamsProtocol>serverParams;

/// 当前用户有没有设置MQTT的订阅topic，如果设置了，则只能定于这个topic，如果没有设置，则订阅添加的设备的topic
@property (nonatomic, copy, readonly, getter=currentSubscribeTopic)NSString *subscribeTopic;

/// 当前用户有没有设置MQTT的订阅topic，如果设置了，则只能定于这个topic，如果没有设置，则订阅添加的设备的topic
@property (nonatomic, copy, readonly, getter=currentPublishedTopic)NSString *publishedTopic;

/// 将参数保存到本地，下次启动通过该参数连接服务器
/// @param protocol protocol
- (BOOL)saveServerParams:(id <MKCSServerParamsProtocol>)protocol;

/**
 清除本地记录的设置信息
 */
- (BOOL)clearLocalData;

#pragma mark - *****************************服务器交互部分******************************

/// 开始连接服务器，前提是必须服务器参数不能为空
- (BOOL)connect;

- (void)disconnect;

/**
 Subscribe the topic

 @param topicList topicList
 */
- (void)subscriptions:(NSArray <NSString *>*)topicList;

/**
 Unsubscribe the topic
 
 @param topicList topicList
 */
- (void)unsubscriptions:(NSArray <NSString *>*)topicList;

- (void)clearAllSubscriptions;

/// Send Data
/// @param data json
/// @param topic topic,1-128 Characters
/// @param macAddress macAddress,6字节16进制，不包含任何符号AABBCCDDEEFF
/// @param taskID taskID
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
      macAddress:(NSString *)macAddress
          taskID:(mk_cs_serverOperationID)taskID
        sucBlock:(void (^)(id returnData))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock;

/// Send Data
/// @param data json
/// @param topic topic,1-128 Characters
/// @param macAddress macAddress,6字节16进制，不包含任何符号AABBCCDDEEFF
/// @param taskID taskID
/// @param timeout 任务超时时间
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
      macAddress:(NSString *)macAddress
          taskID:(mk_cs_serverOperationID)taskID
         timeout:(NSInteger)timeout
        sucBlock:(void (^)(id returnData))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
