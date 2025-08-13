//
//  MKCSBXPButtonCRAlarmEventHeader.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2025/3/27.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MKCSBXPButtonCRAlarmEventHeaderDelegate <NSObject>

- (void)cs_bxpButtonCRAlarmEventHeaderView_syncButtonPressed:(BOOL)isOn;

- (void)cs_bxpButtonCRAlarmEventHeaderView_exportButtonPressed;

@end

@interface MKCSBXPButtonCRAlarmEventHeader : UIView

@property (nonatomic, weak)id <MKCSBXPButtonCRAlarmEventHeaderDelegate>delegate;

- (void)updateSyncStatus:(BOOL)isOn;

@end

NS_ASSUME_NONNULL_END
