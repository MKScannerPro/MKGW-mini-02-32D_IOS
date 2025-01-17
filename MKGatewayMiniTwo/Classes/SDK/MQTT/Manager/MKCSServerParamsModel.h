//
//  MKCSServerParamsModel.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MKCSServerConfigDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKCSServerParamsModel : NSObject<MKCSServerParamsProtocol>

/// 1-64 Characters
@property (nonatomic, copy)NSString *host;

/// 0~65535
@property (nonatomic, copy)NSString *port;

/// 1-64 Characters
@property (nonatomic, copy)NSString *clientID;

/// 0-128 Characters
@property (nonatomic, copy)NSString *subscribeTopic;

/// 0-128 Characters
@property (nonatomic, copy)NSString *publishTopic;

@property (nonatomic, assign)BOOL cleanSession;

/// 0、1、2
@property (nonatomic, assign)NSInteger qos;

/// 10-120
@property (nonatomic, copy)NSString *keepAlive;

/// 0-256 Characters
@property (nonatomic, copy)NSString *userName;

/// 0-256 Characters
@property (nonatomic, copy)NSString *password;

@property (nonatomic, assign)BOOL sslIsOn;

/// 0:CA signed server certificate     1:CA certificate     2:Self signed certificates
@property (nonatomic, assign)NSInteger certificate;

/// 根证书
@property (nonatomic, copy)NSString *caFileName;

/// 对于app是.p12证书
@property (nonatomic, copy)NSString *clientFileName;








/// 将参数保存到本地，下次启动通过该参数连接服务器
/// @param protocol protocol
- (BOOL)saveServerParams:(id <MKCSServerParamsProtocol>)protocol;

/**
 清除本地记录的设置信息
 */
- (BOOL)clearLocalData;

/// 判断当前的服务器参数是否具备连接服务器的要求
- (BOOL)paramsCanConnectServer;

@end

NS_ASSUME_NONNULL_END
