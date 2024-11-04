//
//  CBPeripheral+MKCSAdd.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface CBPeripheral (MKCSAdd)

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *cs_manufacturer;

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *cs_deviceModel;

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *cs_hardware;

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *cs_software;

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *cs_firmware;

#pragma mark - custom

/// W/N
@property (nonatomic, strong, readonly)CBCharacteristic *cs_password;

/// N
@property (nonatomic, strong, readonly)CBCharacteristic *cs_disconnectType;

/// W/N
@property (nonatomic, strong, readonly)CBCharacteristic *cs_custom;

- (void)cs_updateCharacterWithService:(CBService *)service;

- (void)cs_updateCurrentNotifySuccess:(CBCharacteristic *)characteristic;

- (BOOL)cs_connectSuccess;

- (void)cs_setNil;

@end

NS_ASSUME_NONNULL_END
