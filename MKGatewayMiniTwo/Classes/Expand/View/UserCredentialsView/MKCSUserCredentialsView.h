//
//  MKCSUserCredentialsView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSUserCredentialsViewModel : NSObject

@property (nonatomic, copy)NSString *userName;

@property (nonatomic, copy)NSString *password;

@end

@protocol MKCSUserCredentialsViewDelegate <NSObject>

- (void)cs_mqtt_userCredentials_userNameChanged:(NSString *)userName;

- (void)cs_mqtt_userCredentials_passwordChanged:(NSString *)password;

@end

@interface MKCSUserCredentialsView : UIView

@property (nonatomic, strong)MKCSUserCredentialsViewModel *dataModel;

@property (nonatomic, weak)id <MKCSUserCredentialsViewDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
