//
//  MKCSMQTTServerManager.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MKBaseMQTTModule/MKMQTTServerManager.h>

#import "MKCSServerConfigDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKCSMQTTServerManager : NSObject<MKMQTTServerProtocol>

@property (nonatomic, assign, readonly)MKCSMQTTSessionManagerState state;

@property (nonatomic, strong, readonly, getter=currentServerParams)id <MKCSServerParamsProtocol>serverParams;

@property (nonatomic, strong, readonly)NSMutableArray <id <MKCSServerManagerProtocol>>*managerList;

+ (MKCSMQTTServerManager *)shared;

/// 销毁单例
+ (void)singleDealloc;

/// 将一个满足MKCSServerManagerProtocol的对象加入到管理列表
/// @param dataManager MKCSServerManagerProtocol
- (void)loadDataManager:(nonnull id <MKCSServerManagerProtocol>)dataManager;

/// 将满足MKCSServerManagerProtocol的对象移除管理列表
/// @param dataManager MKCSServerManagerProtocol的对象
- (BOOL)removeDataManager:(nonnull id <MKCSServerManagerProtocol>)dataManager;

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

/// 如果是从壳工程进入的设备列表页面，接收不到需要网络改变导致需要联网的通知，所以需要走网络改变的流程
- (void)startWork;

- (void)disconnect;

/**
 Subscribe the topic

 @param topicList topicList
 */
- (void)subscriptions:(NSArray <NSString *>*)topicList;

- (void)clearAllSubscriptions;

/**
 Unsubscribe the topic
 
 @param topicList topicList
 */
- (void)unsubscriptions:(NSArray <NSString *>*)topicList;

- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
        sucBlock:(void (^)(void))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
