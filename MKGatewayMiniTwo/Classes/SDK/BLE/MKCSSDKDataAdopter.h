//
//  MKCSSDKDataAdopter.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MKCSSDKNormalDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKCSSDKDataAdopter : NSObject

+ (NSString *)fetchWifiSecurity:(mk_cs_wifiSecurity)security;

+ (NSString *)fetchWifiEapType:(mk_cs_eapType)eapType;

+ (NSString *)fetchConnectModeString:(mk_cs_connectMode)mode;

+ (NSString *)fetchMqttServerQosMode:(mk_cs_mqttServerQosMode)mode;

+ (NSString *)fetchAsciiCode:(NSString *)value;

/// 4字节16进制转换成47.104.81.55
/// @param value 4字节16进制数据
+ (NSString *)parseIpAddress:(NSString *)value;

+ (BOOL)isIpAddress:(NSString *)ip;

/// 将ip地址转换成对应的4个字节的16进制命令
/// @param ip @"47.104.81.55"
+ (NSString *)ipAddressToHex:(NSString *)ip;

+ (NSArray <NSString *>*)parseFilterMacList:(NSString *)content;

+ (NSArray <NSString *>*)parseFilterAdvNameList:(NSArray <NSData *>*)contentList;

@end

NS_ASSUME_NONNULL_END
