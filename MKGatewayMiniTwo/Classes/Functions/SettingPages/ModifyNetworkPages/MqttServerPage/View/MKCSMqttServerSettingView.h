//
//  MKCSMqttServerSettingView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MKCSMqttServerSettingViewDelegate <NSObject>

/// 底部按钮
/// @param index 0:Export Demo File   1:Import Config File  2:Clear All Configurations
- (void)cs_mqtt_deviecSetting_fileButtonPressed:(NSInteger)index;

@end

@interface MKCSMqttServerSettingView : UIView

@property (nonatomic, weak)id <MKCSMqttServerSettingViewDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
