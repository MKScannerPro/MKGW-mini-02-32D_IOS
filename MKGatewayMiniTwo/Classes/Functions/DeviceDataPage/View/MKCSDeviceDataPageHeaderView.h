//
//  MKCSDeviceDataPageHeaderView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSDeviceDataPageHeaderViewModel : NSObject

@property (nonatomic, assign)BOOL isOn;

@end

@protocol MKCSDeviceDataPageHeaderViewDelegate <NSObject>

- (void)cs_updateLoadButtonAction;

- (void)cs_powerButtonAction;

- (void)cs_scannerStatusChanged:(BOOL)isOn;

- (void)cs_manageBleDeviceAction;

@end

@interface MKCSDeviceDataPageHeaderView : UIView

@property (nonatomic, strong)MKCSDeviceDataPageHeaderViewModel *dataModel;

@property (nonatomic, weak)id <MKCSDeviceDataPageHeaderViewDelegate>delegate;

- (void)updateTotalNumbers:(NSInteger)numbers;

@end

NS_ASSUME_NONNULL_END
