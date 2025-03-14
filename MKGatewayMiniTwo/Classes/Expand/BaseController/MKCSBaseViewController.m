//
//  MKCSBaseViewController.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSBaseViewController.h"

#import "MKMacroDefines.h"
#import "UIView+MKAdd.h"

#import "MKCSDeviceModeManager.h"
#import "MKCSDeviceModel.h"

#import "MKCSMQTTDataManager.h"

@interface MKCSBaseViewController ()

@end

@implementation MKCSBaseViewController

- (void)dealloc {
    NSLog(@"MKCSBaseViewController销毁");
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self addNotifications];
}

#pragma mark - note
- (void)deviceOffline:(NSNotification *)note {
    NSDictionary *user = note.userInfo;
    if (!ValidDict(user) || !ValidStr(user[@"macAddress"])) {
        return;
    }
    [self processOfflineWithMacAddress:user[@"macAddress"]];
}

- (void)receiveDeviceLwtMessage:(NSNotification *)note {
    NSDictionary *user = note.userInfo;
    if (!ValidDict(user) || !ValidStr(user[@"device_info"][@"mac"])) {
        return;
    }
    [self processOfflineWithMacAddress:user[@"device_info"][@"mac"]];
}

- (void)deviceResetByButton:(NSNotification *)note {
    NSDictionary *user = note.userInfo;
    if (!ValidDict(user) || !ValidStr(user[@"device_info"][@"mac"])) {
        return;
    }
    [self processOfflineWithMacAddress:user[@"device_info"][@"mac"]];
}

#pragma mark - Private method
- (void)addNotifications {
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(deviceOffline:)
                                                 name:MKCSDeviceModelOfflineNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(receiveDeviceLwtMessage:)
                                                 name:MKCSReceiveDeviceOfflineNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(deviceResetByButton:)
                                                 name:MKCSReceiveDeviceResetByButtonNotification
                                               object:nil];
}

- (void)processOfflineWithMacAddress:(NSString *)macAddress {
    if (![macAddress isEqualToString:[MKCSDeviceModeManager shared].macAddress]) {
        return;
    }
    if (![MKBaseViewController isCurrentViewControllerVisible:self]) {
        return;
    }
    //让setting页面推出的alert消失
    [[NSNotificationCenter defaultCenter] postNotificationName:@"mk_cs_needDismissAlert" object:nil];
    //让所有MKPickView消失
    [[NSNotificationCenter defaultCenter] postNotificationName:@"mk_customUIModule_dismissPickView" object:nil];
    [self.view showCentralToast:@"device is off-line"];
    [self performSelector:@selector(gobackToListView) withObject:nil afterDelay:1.f];
}

- (void)gobackToListView {
    [self popToViewControllerWithClassName:@"MKCSDeviceListController"];
}

@end
