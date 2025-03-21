//
//  MKCSFilterByRawDataModel.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSFilterByRawDataModel.h"

#import "MKMacroDefines.h"

#import "MKCSDeviceModeManager.h"

#import "MKCSMQTTInterface.h"

@interface MKCSFilterByRawDataModel ()

@property (nonatomic, strong)dispatch_queue_t readQueue;

@property (nonatomic, strong)dispatch_semaphore_t semaphore;

@end

@implementation MKCSFilterByRawDataModel

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock {
    dispatch_async(self.readQueue, ^{
        if (![self readFilterByRawData]) {
            [self operationFailedBlockWithMsg:@"Read Datas Error" block:failedBlock];
            return;
        }
        moko_dispatch_main_safe(^{
            if (sucBlock) {
                sucBlock();
            }
        });
    });
}

#pragma mark - interface
- (BOOL)readFilterByRawData {
    __block BOOL success = NO;
    [MKCSMQTTInterface cs_readFilterByRawDataStatusWithMacAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        success = YES;
        self.iBeacon = ([returnData[@"data"][@"ibeacon"] integerValue] == 1);
        self.uid = ([returnData[@"data"][@"eddystone_uid"] integerValue] == 1);
        
        self.url = ([returnData[@"data"][@"eddystone_url"] integerValue] == 1);
        self.tlm = ([returnData[@"data"][@"eddystone_tlm"] integerValue] == 1);
        
        self.bxpDeviceInfo = ([returnData[@"data"][@"bxp_devinfo"] integerValue] == 1);
        self.bxpAcc = ([returnData[@"data"][@"bxp_acc"] integerValue] == 1);
        
        self.bxpTH = ([returnData[@"data"][@"bxp_th"] integerValue] == 1);
        
        self.bxpButton = ([returnData[@"data"][@"bxp_button"] integerValue] == 1);
        self.bxpTag = ([returnData[@"data"][@"bxp_tag"] integerValue] == 1);
        self.pirPresence = ([returnData[@"data"][@"pir"] integerValue] == 1);
        self.tof = ([returnData[@"data"][@"mk_tof"] integerValue] == 1);
        self.other = ([returnData[@"data"][@"other"] integerValue] == 1);
        dispatch_semaphore_signal(self.semaphore);
    } failedBlock:^(NSError * _Nonnull error) {
        dispatch_semaphore_signal(self.semaphore);
    }];
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    return success;
}

#pragma mark - private method
- (void)operationFailedBlockWithMsg:(NSString *)msg block:(void (^)(NSError *error))block {
    moko_dispatch_main_safe(^{
        NSError *error = [[NSError alloc] initWithDomain:@"filterRawParams"
                                                    code:-999
                                                userInfo:@{@"errorInfo":msg}];
        block(error);
    })
}

#pragma mark - getter
- (dispatch_semaphore_t)semaphore {
    if (!_semaphore) {
        _semaphore = dispatch_semaphore_create(0);
    }
    return _semaphore;
}

- (dispatch_queue_t)readQueue {
    if (!_readQueue) {
        _readQueue = dispatch_queue_create("filterRawQueue", DISPATCH_QUEUE_SERIAL);
    }
    return _readQueue;
}

@end
