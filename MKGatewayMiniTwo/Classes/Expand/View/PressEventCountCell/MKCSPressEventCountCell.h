//
//  MKCSPressEventCountCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2025/1/19.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSPressEventCountCellModel : NSObject

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, copy)NSString *count;

@end

@protocol MKCSPressEventCountCellDelegate <NSObject>

- (void)cs_pressEventCountCell_clearButtonPressed:(NSInteger)index;

@end

@interface MKCSPressEventCountCell : MKBaseCell

@property (nonatomic, weak)id <MKCSPressEventCountCellDelegate>delegate;

@property (nonatomic, strong)MKCSPressEventCountCellModel *dataModel;

+ (MKCSPressEventCountCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
