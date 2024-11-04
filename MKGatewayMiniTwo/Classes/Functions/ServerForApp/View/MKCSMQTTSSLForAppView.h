//
//  MKCSMQTTSSLForAppView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSMQTTSSLForAppViewModel : NSObject

@property (nonatomic, assign)BOOL sslIsOn;

/// 0:CA certificate     1:Self signed certificates
@property (nonatomic, assign)NSInteger certificate;

@property (nonatomic, copy)NSString *caFileName;

/// P12证书
@property (nonatomic, copy)NSString *clientFileName;

@end

@protocol MKCSMQTTSSLForAppViewDelegate <NSObject>

- (void)cs_mqtt_sslParams_app_sslStatusChanged:(BOOL)isOn;

/// 用户选择了加密方式
/// @param certificate 0:CA certificate     1:Self signed certificates
- (void)cs_mqtt_sslParams_app_certificateChanged:(NSInteger)certificate;

/// 用户点击选择了caFaile按钮
- (void)cs_mqtt_sslParams_app_caFilePressed;

/// 用户点击选择了P12证书按钮
- (void)cs_mqtt_sslParams_app_clientFilePressed;

@end

@interface MKCSMQTTSSLForAppView : UIView

@property (nonatomic, strong)MKCSMQTTSSLForAppViewModel *dataModel;

@property (nonatomic, weak)id <MKCSMQTTSSLForAppViewDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
