//
//  MKCSTestController.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/1.
//  Copyright © 2024 lovexiaoxia. All rights reserved.
//

#import "MKCSTestController.h"

#import "Masonry.h"

#import "MKCustomUIAdopter.h"

#import "MKCSDeviceListController.h"

@interface MKCSTestController ()

@end

@implementation MKCSTestController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.defaultTitle = @"Remote gateway";
    self.leftButton.hidden = YES;
    UIButton *button = [MKCustomUIAdopter customButtonWithTitle:@"MKGW-mini-02-32D"
                                                         target:self
                                                         action:@selector(pushRemoteGatewayPage)];
    [self.view addSubview:button];
    [button mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.view.mas_centerX);
        make.width.mas_equalTo(180.f);
        make.centerY.mas_equalTo(self.view.mas_centerY);
        make.height.mas_equalTo(40.f);
    }];
}

- (void)pushRemoteGatewayPage {
    MKCSDeviceListController *vc = [[MKCSDeviceListController alloc] init];
    vc.connectServer = YES;
    [self.navigationController pushViewController:vc animated:YES];
}

@end
