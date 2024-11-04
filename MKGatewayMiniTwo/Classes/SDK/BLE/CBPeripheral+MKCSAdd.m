//
//  CBPeripheral+MKCSAdd.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "CBPeripheral+MKCSAdd.h"

#import <objc/runtime.h>

static const char *cs_manufacturerKey = "cs_manufacturerKey";
static const char *cs_deviceModelKey = "cs_deviceModelKey";
static const char *cs_hardwareKey = "cs_hardwareKey";
static const char *cs_softwareKey = "cs_softwareKey";
static const char *cs_firmwareKey = "cs_firmwareKey";

static const char *cs_passwordKey = "cs_passwordKey";
static const char *cs_disconnectTypeKey = "cs_disconnectTypeKey";
static const char *cs_customKey = "cs_customKey";

static const char *cs_passwordNotifySuccessKey = "cs_passwordNotifySuccessKey";
static const char *cs_disconnectTypeNotifySuccessKey = "cs_disconnectTypeNotifySuccessKey";
static const char *cs_customNotifySuccessKey = "cs_customNotifySuccessKey";

@implementation CBPeripheral (MKCSAdd)

- (void)cs_updateCharacterWithService:(CBService *)service {
    NSArray *characteristicList = service.characteristics;
    if ([service.UUID isEqual:[CBUUID UUIDWithString:@"180A"]]) {
        //设备信息
        for (CBCharacteristic *characteristic in characteristicList) {
            if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A24"]]) {
                objc_setAssociatedObject(self, &cs_deviceModelKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A26"]]) {
                objc_setAssociatedObject(self, &cs_firmwareKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A27"]]) {
                objc_setAssociatedObject(self, &cs_hardwareKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A28"]]) {
                objc_setAssociatedObject(self, &cs_softwareKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A29"]]) {
                objc_setAssociatedObject(self, &cs_manufacturerKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }
        }
        return;
    }
    if ([service.UUID isEqual:[CBUUID UUIDWithString:@"AA00"]]) {
        //自定义
        for (CBCharacteristic *characteristic in characteristicList) {
            if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA00"]]) {
                objc_setAssociatedObject(self, &cs_passwordKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA01"]]) {
                objc_setAssociatedObject(self, &cs_disconnectTypeKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA03"]]) {
                objc_setAssociatedObject(self, &cs_customKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }
            [self setNotifyValue:YES forCharacteristic:characteristic];
        }
        return;
    }
}

- (void)cs_updateCurrentNotifySuccess:(CBCharacteristic *)characteristic {
    if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA00"]]) {
        objc_setAssociatedObject(self, &cs_passwordNotifySuccessKey, @(YES), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        return;
    }
    if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA01"]]) {
        objc_setAssociatedObject(self, &cs_disconnectTypeNotifySuccessKey, @(YES), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        return;
    }
    if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA03"]]) {
        objc_setAssociatedObject(self, &cs_customNotifySuccessKey, @(YES), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        return;
    }
}

- (BOOL)cs_connectSuccess {
    if (![objc_getAssociatedObject(self, &cs_customNotifySuccessKey) boolValue] || ![objc_getAssociatedObject(self, &cs_passwordNotifySuccessKey) boolValue] || ![objc_getAssociatedObject(self, &cs_disconnectTypeNotifySuccessKey) boolValue]) {
        return NO;
    }
    if (!self.cs_hardware || !self.cs_firmware) {
        return NO;
    }
    if (!self.cs_password || !self.cs_disconnectType || !self.cs_custom) {
        return NO;
    }
    return YES;
}

- (void)cs_setNil {
    objc_setAssociatedObject(self, &cs_manufacturerKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &cs_deviceModelKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &cs_hardwareKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &cs_softwareKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &cs_firmwareKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    objc_setAssociatedObject(self, &cs_passwordKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &cs_disconnectTypeKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &cs_customKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    objc_setAssociatedObject(self, &cs_passwordNotifySuccessKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &cs_disconnectTypeNotifySuccessKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &cs_customNotifySuccessKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

#pragma mark - getter

- (CBCharacteristic *)cs_manufacturer {
    return objc_getAssociatedObject(self, &cs_manufacturerKey);
}

- (CBCharacteristic *)cs_deviceModel {
    return objc_getAssociatedObject(self, &cs_deviceModelKey);
}

- (CBCharacteristic *)cs_hardware {
    return objc_getAssociatedObject(self, &cs_hardwareKey);
}

- (CBCharacteristic *)cs_software {
    return objc_getAssociatedObject(self, &cs_softwareKey);
}

- (CBCharacteristic *)cs_firmware {
    return objc_getAssociatedObject(self, &cs_firmwareKey);
}

- (CBCharacteristic *)cs_password {
    return objc_getAssociatedObject(self, &cs_passwordKey);
}

- (CBCharacteristic *)cs_disconnectType {
    return objc_getAssociatedObject(self, &cs_disconnectTypeKey);
}

- (CBCharacteristic *)cs_custom {
    return objc_getAssociatedObject(self, &cs_customKey);
}

@end
