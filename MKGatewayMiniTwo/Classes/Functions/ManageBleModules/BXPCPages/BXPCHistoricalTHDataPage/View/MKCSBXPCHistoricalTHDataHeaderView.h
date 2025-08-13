//
//  MKCSBXPCHistoricalTHDataHeaderView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2025/2/11.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MKCSBXPCHistoricalTHDataHeaderViewDelegate <NSObject>

- (void)cs_bxpcHistoricalHTDataHeaderView_syncButtonPressed:(BOOL)isOn;

- (void)cs_bxpcHistoricalHTDataHeaderView_deleteButtonPressed;

- (void)cs_bxpcHistoricalHTDataHeaderView_exportButtonPressed;

@end

@interface MKCSBXPCHistoricalTHDataHeaderView : UIView

@property (nonatomic, weak)id <MKCSBXPCHistoricalTHDataHeaderViewDelegate>delegate;

- (void)updateSyncStatus:(BOOL)isOn;

@end

NS_ASSUME_NONNULL_END
