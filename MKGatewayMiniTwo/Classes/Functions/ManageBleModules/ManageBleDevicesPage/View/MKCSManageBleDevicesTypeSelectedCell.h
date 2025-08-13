//
//  MKCSManageBleDevicesTypeSelectedCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2025/1/18.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSManageBleDevicesTypeSelectedCellModel : NSObject

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, assign)BOOL selected;

@property (nonatomic, copy)NSString *msg;

@end

@protocol MKCSManageBleDevicesTypeSelectedCellDelegate <NSObject>

- (void)cs_manageBleDevicesTypeSelectedCell_selected:(BOOL)selected index:(NSInteger)index;

@end

@interface MKCSManageBleDevicesTypeSelectedCell : UITableViewCell

@property (nonatomic, weak)id <MKCSManageBleDevicesTypeSelectedCellDelegate>delegate;

@property (nonatomic, strong)MKCSManageBleDevicesTypeSelectedCellModel *dataModel;

+ (MKCSManageBleDevicesTypeSelectedCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
