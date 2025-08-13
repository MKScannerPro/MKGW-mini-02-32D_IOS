//
//  MKCSNearbyWifiController.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/9/5.
//  Copyright © 2024 lovexiaoxia. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MKCSNearbyWifiControllerDelegate <NSObject>

- (void)cs_nearbyWifiController_selectedWifi:(NSString *)ssid;

@end

@interface MKCSNearbyWifiController : MKBaseViewController

@property (nonatomic, weak)id <MKCSNearbyWifiControllerDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
