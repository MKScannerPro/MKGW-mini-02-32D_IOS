//
//  MKCSDeviceMQTTParamsModel.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSDeviceMQTTParamsModel.h"

#import "MKCSDeviceModel.h"

static MKCSDeviceMQTTParamsModel *paramsModel = nil;
static dispatch_once_t onceToken;

@implementation MKCSDeviceMQTTParamsModel

+ (MKCSDeviceMQTTParamsModel *)shared {
    dispatch_once(&onceToken, ^{
        if (!paramsModel) {
            paramsModel = [MKCSDeviceMQTTParamsModel new];
        }
    });
    return paramsModel;
}

+ (void)sharedDealloc {
    paramsModel = nil;
    onceToken = 0;
}

#pragma mark - getter
- (MKCSDeviceModel *)deviceModel {
    if (!_deviceModel) {
        _deviceModel = [[MKCSDeviceModel alloc] init];
    }
    return _deviceModel;
}

@end
