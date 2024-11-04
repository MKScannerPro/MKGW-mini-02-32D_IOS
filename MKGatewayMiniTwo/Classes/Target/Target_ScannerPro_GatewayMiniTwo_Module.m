//
//  Target_ScannerPro_GatewayMiniTwo_Module.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "Target_ScannerPro_GatewayMiniTwo_Module.h"

#import "MKCSDeviceListController.h"

@implementation Target_ScannerPro_GatewayMiniTwo_Module

- (UIViewController *)Action_MKScannerPro_GatewayMiniTwo_DeviceListPage:(NSDictionary *)params {
    MKCSDeviceListController *vc = [[MKCSDeviceListController alloc] init];
    vc.connectServer = YES;
    return vc;
}

@end
