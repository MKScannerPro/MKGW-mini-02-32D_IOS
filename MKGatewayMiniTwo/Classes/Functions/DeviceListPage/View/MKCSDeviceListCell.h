//
//  MKCSDeviceListCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MKCSDeviceListCellDelegate <NSObject>

/**
 删除
 
 @param index 所在index
 */
- (void)cs_cellDeleteButtonPressed:(NSInteger)index;

@end

@class MKCSDeviceListModel;
@interface MKCSDeviceListCell : MKBaseCell

@property (nonatomic, weak)id <MKCSDeviceListCellDelegate>delegate;

@property (nonatomic, strong)MKCSDeviceListModel *dataModel;

+ (MKCSDeviceListCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
