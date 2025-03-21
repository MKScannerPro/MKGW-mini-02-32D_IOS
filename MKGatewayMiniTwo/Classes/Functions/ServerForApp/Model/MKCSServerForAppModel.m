//
//  MKCSServerForAppModel.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSServerForAppModel.h"

#import "MKMacroDefines.h"
#import "NSString+MKAdd.h"

#import "MKCSMQTTDataManager.h"

@implementation MKCSServerForAppModel

- (instancetype)init {
    if (self = [super init]) {
        [self loadServerParams];
    }
    return self;
}

- (void)clearAllParams {
    _host = @"";
    _port = @"";
    _clientID = @"";
    _subscribeTopic = @"";
    _publishTopic = @"";
    _cleanSession = YES;
    _qos = 0;
    _keepAlive = @"";
    _userName = @"";
    _password = @"";
    _sslIsOn = NO;
    _certificate = 0;
    _caFileName = @"";
    _clientFileName = @"";
}

- (NSString *)checkParams {
    if (!ValidStr(self.host) || self.host.length > 64 || ![self.host isAsciiString]) {
        return @"Host error";
    }
    if (!ValidStr(self.port) || [self.port integerValue] < 1 || [self.port integerValue] > 65535) {
        return @"Port error";
    }
    if (!ValidStr(self.clientID) || self.clientID.length > 64 || ![self.clientID isAsciiString]) {
        return @"ClientID error";
    }
    if (self.publishTopic.length > 128 || (ValidStr(self.publishTopic) && ![self.publishTopic isAsciiString])) {
        return @"PublishTopic error";
    }
    if (self.subscribeTopic.length > 128 || (ValidStr(self.subscribeTopic) && ![self.subscribeTopic isAsciiString])) {
        return @"SubscribeTopic error";
    }
    if (self.qos < 0 || self.qos > 2) {
        return @"Qos error";
    }
    if (!ValidStr(self.keepAlive) || [self.keepAlive integerValue] < 10 || [self.keepAlive integerValue] > 120) {
        return @"KeepAlive error";
    }
    if (self.userName.length > 256 || (ValidStr(self.userName) && ![self.userName isAsciiString])) {
        return @"UserName error";
    }
    if (self.password.length > 256 || (ValidStr(self.password) && ![self.password isAsciiString])) {
        return @"Password error";
    }
    if (self.sslIsOn) {
        if (self.certificate < 0 || self.certificate > 2) {
            return @"Certificate error";
        }
        if (self.certificate == 0) {
            return @"";
        }
        if (!ValidStr(self.caFileName)) {
            return @"CA File cannot be empty.";
        }
        if (self.certificate == 2 && !ValidStr(self.clientFileName)) {
            return @"Client File cannot be empty.";
        }
    }
    return @"";
}

- (void)updateValue:(MKCSServerForAppModel *)model {
    if (!model || ![model isKindOfClass:MKCSServerForAppModel.class]) {
        return;
    }
    self.host = model.host;
    self.port = model.port;
    self.clientID = model.clientID;
    self.subscribeTopic = model.subscribeTopic;
    self.publishTopic = model.publishTopic;
    self.cleanSession = model.cleanSession;
    
    self.qos = model.qos;
    self.keepAlive = model.keepAlive;
    self.userName = model.userName;
    self.password = model.password;
    self.sslIsOn = model.sslIsOn;
    self.certificate = model.certificate;
}

#pragma mark - private method
- (void)loadServerParams {
    if (!ValidStr([MKCSMQTTDataManager shared].serverParams.host)) {
        //本地没有服务器参数
        self.host = @"47.104.81.55";
        self.port = @"1883";
        NSString *tempID = [NSString stringWithFormat:@"%ld",(long)((1000000 + (arc4random() % 90000000)))];
        self.clientID = [@"MK_" stringByAppendingString:tempID];
        self.cleanSession = YES;
        self.keepAlive = @"60";
        self.qos = 0;
        return;
    }
    self.host = [MKCSMQTTDataManager shared].serverParams.host;
    self.port = [MKCSMQTTDataManager shared].serverParams.port;
    self.clientID = [MKCSMQTTDataManager shared].serverParams.clientID;
    self.subscribeTopic = [MKCSMQTTDataManager shared].serverParams.subscribeTopic;
    self.publishTopic = [MKCSMQTTDataManager shared].serverParams.publishTopic;
    self.cleanSession = [MKCSMQTTDataManager shared].serverParams.cleanSession;
    
    self.qos = [MKCSMQTTDataManager shared].serverParams.qos;
    self.keepAlive = [MKCSMQTTDataManager shared].serverParams.keepAlive;
    self.userName = [MKCSMQTTDataManager shared].serverParams.userName;
    self.password = [MKCSMQTTDataManager shared].serverParams.password;
    self.sslIsOn = [MKCSMQTTDataManager shared].serverParams.sslIsOn;
    self.certificate = [MKCSMQTTDataManager shared].serverParams.certificate;
    self.caFileName = [MKCSMQTTDataManager shared].serverParams.caFileName;
    self.clientFileName = [MKCSMQTTDataManager shared].serverParams.clientFileName;
}

- (NSString *)fetchClientID {
    NSString *valueString = [NSString stringWithFormat:@"%1lx",((1000000 + (arc4random() % 90000000)))];
    NSInteger needLen = 8 - valueString.length;
    for (NSInteger i = 0; i < needLen; i ++) {
        valueString = [@"0" stringByAppendingString:valueString];
    }
    return [@"MK_" stringByAppendingString:valueString];
}

@end
