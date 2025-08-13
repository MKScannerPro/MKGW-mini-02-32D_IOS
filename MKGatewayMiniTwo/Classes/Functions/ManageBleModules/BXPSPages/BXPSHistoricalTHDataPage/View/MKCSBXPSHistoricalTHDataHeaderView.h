//
//  MKCSBXPSHistoricalTHDataHeaderView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2025/2/11.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MKCSBXPSHistoricalTHDataHeaderViewDelegate <NSObject>

- (void)cs_BXPSHistoricalHTDataHeaderView_syncButtonPressed:(BOOL)isOn;

- (void)cs_BXPSHistoricalHTDataHeaderView_deleteButtonPressed;

- (void)cs_BXPSHistoricalHTDataHeaderView_exportButtonPressed;

@end

@interface MKCSBXPSHistoricalTHDataHeaderView : UIView

@property (nonatomic, weak)id <MKCSBXPSHistoricalTHDataHeaderViewDelegate>delegate;

- (void)updateSyncStatus:(BOOL)isOn;

@end

NS_ASSUME_NONNULL_END
