//
//  MKCSDuplicateDataFilterModel.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSDuplicateDataFilterModel.h"

#import "MKMacroDefines.h"

#import "MKCSDeviceModeManager.h"

#import "MKCSMQTTInterface.h"

@interface MKCSDuplicateDataFilterModel ()

@property (nonatomic, strong)dispatch_queue_t readQueue;

@property (nonatomic, strong)dispatch_semaphore_t semaphore;

@end

@implementation MKCSDuplicateDataFilterModel

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock {
    dispatch_async(self.readQueue, ^{
        if (![self readDuplicateDataFilter]) {
            [self operationFailedBlockWithMsg:@"Read Duplicate Data Filter Error" block:failedBlock];
            return;
        }
        moko_dispatch_main_safe(^{
            if (sucBlock) {
                sucBlock();
            }
        });
    });
}

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock {
    dispatch_async(self.readQueue, ^{
        NSString *msg = [self checkMsg];
        if (ValidStr(msg)) {
            [self operationFailedBlockWithMsg:msg block:failedBlock];
            return;
        }
        if (![self configDuplicateDataFilter]) {
            [self operationFailedBlockWithMsg:@"Setup failed!" block:failedBlock];
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
- (BOOL)readDuplicateDataFilter {
    __block BOOL success = NO;
    [MKCSMQTTInterface cs_readDuplicateDataFilterDatasWithMacAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        success = YES;
        self.rule = [returnData[@"data"][@"rule"] integerValue];
        self.strategy = [returnData[@"data"][@"mode"] integerValue];
        self.time = [NSString stringWithFormat:@"%@",returnData[@"data"][@"timeout"]];
        dispatch_semaphore_signal(self.semaphore);
    } failedBlock:^(NSError * _Nonnull error) {
        dispatch_semaphore_signal(self.semaphore);
    }];
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    return success;
}

- (BOOL)configDuplicateDataFilter {
    __block BOOL success = NO;
    [MKCSMQTTInterface cs_configDuplicateDataFilter:self.rule strategy:self.strategy period:[self.time longLongValue] macAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        success = YES;
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
        NSError *error = [[NSError alloc] initWithDomain:@"filterUIDParams"
                                                    code:-999
                                                userInfo:@{@"errorInfo":msg}];
        block(error);
    })
}

- (NSString *)checkMsg {
    if (self.rule == 0) {
        return @"";
    }
    if (!ValidStr(self.time) || [self.time integerValue] < 1 || [self.time integerValue] > 86400) {
        return @"Params error";
    }
    return @"";
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
        _readQueue = dispatch_queue_create("filterUIDQueue", DISPATCH_QUEUE_SERIAL);
    }
    return _readQueue;
}

@end
