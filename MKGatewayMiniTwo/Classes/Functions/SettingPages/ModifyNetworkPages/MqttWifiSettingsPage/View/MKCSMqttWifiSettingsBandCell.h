//
//  MKCSMqttWifiSettingsBandCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 lovexiaoxia. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSMqttWifiSettingsBandCellModel : NSObject

@property (nonatomic, assign)NSInteger country;

@end

@protocol MKCSMqttWifiSettingsBandCellDelegate <NSObject>

- (void)cs_mqttWifiSettingsBandCell_countryChanged:(NSInteger)country;

@end

@interface MKCSMqttWifiSettingsBandCell : MKBaseCell

@property (nonatomic, strong)MKCSMqttWifiSettingsBandCellModel *dataModel;

@property (nonatomic, weak)id <MKCSMqttWifiSettingsBandCellDelegate>delegate;

+ (MKCSMqttWifiSettingsBandCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
