//
//  MKCSMQTTLWTForDeviceView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSMQTTLWTForDeviceViewModel : NSObject

@property (nonatomic, assign)BOOL lwtStatus;

@property (nonatomic, assign)BOOL lwtRetain;

@property (nonatomic, assign)NSInteger lwtQos;

@property (nonatomic, copy)NSString *lwtTopic;

@property (nonatomic, copy)NSString *lwtPayload;

@end

@protocol MKCSMQTTLWTForDeviceViewDelegate <NSObject>

- (void)cs_lwt_statusChanged:(BOOL)isOn;

- (void)cs_lwt_retainChanged:(BOOL)isOn;

- (void)cs_lwt_qosChanged:(NSInteger)qos;

- (void)cs_lwt_topicChanged:(NSString *)text;

- (void)cs_lwt_payloadChanged:(NSString *)text;

@end

@interface MKCSMQTTLWTForDeviceView : UIView

@property (nonatomic, strong)MKCSMQTTLWTForDeviceViewModel *dataModel;

@property (nonatomic, weak)id <MKCSMQTTLWTForDeviceViewDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
