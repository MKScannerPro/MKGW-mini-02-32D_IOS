//
//  MKCSBleWifiSettingsCertCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/1.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSBleWifiSettingsCertCellModel : NSObject

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *fileName;

@end

@protocol MKCSBleWifiSettingsCertCellDelegate <NSObject>

- (void)cs_bleWifiSettingsCertPressed:(NSInteger)index;

@end

@interface MKCSBleWifiSettingsCertCell : MKBaseCell

@property (nonatomic, strong)MKCSBleWifiSettingsCertCellModel *dataModel;

@property (nonatomic, weak)id <MKCSBleWifiSettingsCertCellDelegate>delegate;

+ (MKCSBleWifiSettingsCertCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
