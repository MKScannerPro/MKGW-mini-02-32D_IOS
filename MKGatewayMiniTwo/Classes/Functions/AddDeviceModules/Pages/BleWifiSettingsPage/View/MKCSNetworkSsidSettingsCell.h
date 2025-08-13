//
//  MKCSNetworkSsidSettingsCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/9/1.
//  Copyright © 2024 lovexiaoxia. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSNetworkSsidSettingsCellModel : NSObject

@property (nonatomic, copy)NSString *ssid;

@end

@protocol MKCSNetworkSsidSettingsCellDelegate <NSObject>

- (void)cs_networkSsidSettingsCell_ssidChanged:(NSString *)ssid;

- (void)cs_networkSsidSettingsCell_buttonPressed;

@end

@interface MKCSNetworkSsidSettingsCell : MKBaseCell

@property (nonatomic, strong)MKCSNetworkSsidSettingsCellModel *dataModel;

@property (nonatomic, weak)id <MKCSNetworkSsidSettingsCellDelegate>delegate;

+ (MKCSNetworkSsidSettingsCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
