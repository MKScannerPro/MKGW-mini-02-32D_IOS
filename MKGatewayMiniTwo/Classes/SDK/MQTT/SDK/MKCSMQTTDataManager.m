//
//  MKCSMQTTDataManager.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSMQTTDataManager.h"

#import "MKMacroDefines.h"

#import "MKCSMQTTServerManager.h"

#import "MKCSMQTTOperation.h"

NSString *const MKCSMQTTSessionManagerStateChangedNotification = @"MKCSMQTTSessionManagerStateChangedNotification";

NSString *const MKCSReceiveDeviceOnlineNotification = @"MKCSReceiveDeviceOnlineNotification";
NSString *const MKCSReceiveDeviceNetStateNotification = @"MKCSReceiveDeviceNetStateNotification";
NSString *const MKCSReceiveDeviceOTAResultNotification = @"MKCSReceiveDeviceOTAResultNotification";
NSString *const MKCSReceiveDeviceNpcOTAResultNotification = @"MKCSReceiveDeviceNpcOTAResultNotification";
NSString *const MKCSReceiveDeviceResetByButtonNotification = @"MKCSReceiveDeviceResetByButtonNotification";
NSString *const MKCSReceiveDeviceUpdateEapCertsResultNotification = @"MKCSReceiveDeviceUpdateEapCertsResultNotification";
NSString *const MKCSReceiveDeviceUpdateMqttCertsResultNotification = @"MKCSReceiveDeviceUpdateMqttCertsResultNotification";

NSString *const MKCSReceiveDeviceDatasNotification = @"MKCSReceiveDeviceDatasNotification";
NSString *const MKCSReceiveGatewayDisconnectBXPButtonNotification = @"MKCSReceiveGatewayDisconnectBXPButtonNotification";
NSString *const MKCSReceiveGatewayDisconnectDeviceNotification = @"MKCSReceiveGatewayDisconnectDeviceNotification";
NSString *const MKCSReceiveGatewayConnectedDeviceDatasNotification = @"MKCSReceiveGatewayConnectedDeviceDatasNotification";

NSString *const MKCSReceiveBxpButtonDfuProgressNotification = @"MKCSReceiveBxpButtonDfuProgressNotification";
NSString *const MKCSReceiveBxpButtonDfuResultNotification = @"MKCSReceiveBxpButtonDfuResultNotification";

NSString *const MKCSReceiveDeviceOfflineNotification = @"MKCSReceiveDeviceOfflineNotification";


static MKCSMQTTDataManager *manager = nil;
static dispatch_once_t onceToken;

@interface MKCSMQTTDataManager ()

@property (nonatomic, strong)NSOperationQueue *operationQueue;

@end

@implementation MKCSMQTTDataManager

- (instancetype)init {
    if (self = [super init]) {
        [[MKCSMQTTServerManager shared] loadDataManager:self];
    }
    return self;
}

+ (MKCSMQTTDataManager *)shared {
    dispatch_once(&onceToken, ^{
        if (!manager) {
            manager = [MKCSMQTTDataManager new];
        }
    });
    return manager;
}

+ (void)singleDealloc {
    [[MKCSMQTTServerManager shared] removeDataManager:manager];
    onceToken = 0;
    manager = nil;
}

#pragma mark - MKCSServerManagerProtocol
- (void)cs_didReceiveMessage:(NSDictionary *)data onTopic:(NSString *)topic {
    if (!ValidDict(data) || !ValidNum(data[@"msg_id"]) || !ValidStr(data[@"device_info"][@"mac"])) {
        return;
    }
    NSInteger msgID = [data[@"msg_id"] integerValue];
    NSString *macAddress = data[@"device_info"][@"mac"];
    //无论是什么消息，都抛出该通知，证明设备在线
    [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceOnlineNotification
                                                        object:nil
                                                      userInfo:@{@"macAddress":macAddress}];
    if (msgID == 3004) {
        //上报的网络状态
        NSDictionary *resultDic = @{
            @"macAddress":macAddress,
            @"data":data[@"data"]
        };
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceNetStateNotification
                                                            object:nil
                                                          userInfo:resultDic];
        return;
    }
    if (msgID == 3007) {
        //固件升级结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceOTAResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3014) {
        //设备通过按键恢复出厂设置
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceResetByButtonNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3016) {
        //NCP固件升级结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceNpcOTAResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3022) {
        //EAP证书更新结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceUpdateEapCertsResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3032) {
        //MQTT证书更新结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceUpdateMqttCertsResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3070) {
        //扫描到的数据
        if ([self.dataDelegate respondsToSelector:@selector(mk_cs_receiveDeviceDatas:)]) {
            [self.dataDelegate mk_cs_receiveDeviceDatas:data];
        }
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceDatasNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3108) {
        //网关与已连接的BXP-Button设备断开了链接，非主动断开
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveGatewayDisconnectBXPButtonNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3203) {
        //BXP-Button升级进度
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveBxpButtonDfuProgressNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3204) {
        //BXP-Button升级结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveBxpButtonDfuResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3302) {
        //网关与已连接的蓝牙设备断开了链接，非主动断开
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveGatewayDisconnectDeviceNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3311) {
        //网关接收到已连接的蓝牙设备的数据
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveGatewayConnectedDeviceDatasNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3999) {
        //遗嘱，设备离线
        [[NSNotificationCenter defaultCenter] postNotificationName:MKCSReceiveDeviceOfflineNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    @synchronized(self.operationQueue) {
        NSArray *operations = [self.operationQueue.operations copy];
        for (NSOperation <MKCSMQTTOperationProtocol>*operation in operations) {
            if (operation.executing) {
                [operation didReceiveMessage:data onTopic:topic];
                break;
            }
        }
    }
}

- (void)cs_didChangeState:(MKCSMQTTSessionManagerState)newState {
    [[NSNotificationCenter defaultCenter] postNotificationName:MKCSMQTTSessionManagerStateChangedNotification object:nil];
}

#pragma mark - public method
- (NSString *)currentSubscribeTopic {
    return [MKCSMQTTServerManager shared].serverParams.subscribeTopic;
}

- (NSString *)currentPublishedTopic {
    return [MKCSMQTTServerManager shared].serverParams.publishTopic;
}

- (id<MKCSServerParamsProtocol>)currentServerParams {
    return [MKCSMQTTServerManager shared].currentServerParams;
}

- (BOOL)saveServerParams:(id <MKCSServerParamsProtocol>)protocol {
    return [[MKCSMQTTServerManager shared] saveServerParams:protocol];
}

- (BOOL)clearLocalData {
    return [[MKCSMQTTServerManager shared] clearLocalData];
}

- (BOOL)connect {
    return [[MKCSMQTTServerManager shared] connect];
}

- (void)disconnect {
    if (self.operationQueue.operations.count > 0) {
        [self.operationQueue cancelAllOperations];
    }
    [[MKCSMQTTServerManager shared] disconnect];
}

- (void)subscriptions:(NSArray <NSString *>*)topicList {
    [[MKCSMQTTServerManager shared] subscriptions:topicList];
}

- (void)unsubscriptions:(NSArray <NSString *>*)topicList {
    [[MKCSMQTTServerManager shared] unsubscriptions:topicList];
}

- (void)clearAllSubscriptions {
    [[MKCSMQTTServerManager shared] clearAllSubscriptions];
}

- (MKCSMQTTSessionManagerState)state {
    return [MKCSMQTTServerManager shared].state;
}

- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
      macAddress:(NSString *)macAddress
          taskID:(mk_cs_serverOperationID)taskID
        sucBlock:(void (^)(id returnData))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock {
    MKCSMQTTOperation *operation = [self generateOperationWithTaskID:taskID
                                                               topic:topic
                                                          macAddress:macAddress
                                                                data:data
                                                            sucBlock:sucBlock
                                                         failedBlock:failedBlock];
    if (!operation) {
        return;
    }
    [self.operationQueue addOperation:operation];
}

- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
      macAddress:(NSString *)macAddress
          taskID:(mk_cs_serverOperationID)taskID
         timeout:(NSInteger)timeout
        sucBlock:(void (^)(id returnData))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock {
    MKCSMQTTOperation *operation = [self generateOperationWithTaskID:taskID
                                                               topic:topic
                                                          macAddress:macAddress
                                                                data:data
                                                            sucBlock:sucBlock
                                                         failedBlock:failedBlock];
    if (!operation) {
        return;
    }
    operation.operationTimeout = timeout;
    [self.operationQueue addOperation:operation];
}

#pragma mark - private method

- (MKCSMQTTOperation *)generateOperationWithTaskID:(mk_cs_serverOperationID)taskID
                                              topic:(NSString *)topic
                                        macAddress:(NSString *)macAddress
                                               data:(NSDictionary *)data
                                           sucBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock {
    if (!ValidDict(data)) {
        [self operationFailedBlockWithMsg:@"The data sent to the device cannot be empty" failedBlock:failedBlock];
        return nil;
    }
    if (!ValidStr(topic) || topic.length > 128) {
        [self operationFailedBlockWithMsg:@"Topic error" failedBlock:failedBlock];
        return nil;
    }
    if ([MKMQTTServerManager shared].managerState != MKMQTTSessionManagerStateConnected) {
        [self operationFailedBlockWithMsg:@"MTQQ Server disconnect" failedBlock:failedBlock];
        return nil;
    }
    __weak typeof(self) weakSelf = self;
    MKCSMQTTOperation *operation = [[MKCSMQTTOperation alloc] initOperationWithID:taskID macAddress:macAddress commandBlock:^{
        [[MKCSMQTTServerManager shared] sendData:data topic:topic sucBlock:nil failedBlock:nil];
    } completeBlock:^(NSError * _Nonnull error, id  _Nonnull returnData) {
        __strong typeof(self) sself = weakSelf;
        if (error) {
            moko_dispatch_main_safe(^{
                if (failedBlock) {
                    failedBlock(error);
                }
            });
            return ;
        }
        if (!returnData) {
            [sself operationFailedBlockWithMsg:@"Request data error" failedBlock:failedBlock];
            return ;
        }
        moko_dispatch_main_safe(^{
            if (sucBlock) {
                sucBlock(returnData);
            }
        });
    }];
    return operation;
}

- (void)operationFailedBlockWithMsg:(NSString *)message failedBlock:(void (^)(NSError *error))failedBlock {
    NSError *error = [[NSError alloc] initWithDomain:@"com.moko.RGMQTTDataManager"
                                                code:-999
                                            userInfo:@{@"errorInfo":message}];
    moko_dispatch_main_safe(^{
        if (failedBlock) {
            failedBlock(error);
        }
    });
}

#pragma mark - getter
- (NSOperationQueue *)operationQueue{
    if (!_operationQueue) {
        _operationQueue = [[NSOperationQueue alloc] init];
        _operationQueue.maxConcurrentOperationCount = 1;
    }
    return _operationQueue;
}

@end
