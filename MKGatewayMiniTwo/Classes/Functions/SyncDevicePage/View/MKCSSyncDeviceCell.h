//
//  MKCSSyncDeviceCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2025/3/7.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

#import "MKCSDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKCSSyncDeviceCellModel : MKCSDeviceModel

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, assign)BOOL selected;

@end

@protocol MKCSSyncDeviceCellDelegate <NSObject>

- (void)cs_syncDeviceCell_selected:(BOOL)selected index:(NSInteger)index;

@end

@interface MKCSSyncDeviceCell : MKBaseCell

@property (nonatomic, strong)MKCSSyncDeviceCellModel *dataModel;

@property (nonatomic, weak)id <MKCSSyncDeviceCellDelegate>delegate;

+ (MKCSSyncDeviceCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
