//
//  MKCSFilterCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSFilterCellModel : NSObject

/// cell标识符
@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, assign)NSInteger dataListIndex;

@property (nonatomic, strong)NSArray <NSString *>*dataList;

@end

@protocol MKCSFilterCellDelegate <NSObject>

- (void)cs_filterValueChanged:(NSInteger)dataListIndex index:(NSInteger)index;

@end

@interface MKCSFilterCell : MKBaseCell

@property (nonatomic, strong)MKCSFilterCellModel *dataModel;

@property (nonatomic, weak)id <MKCSFilterCellDelegate>delegate;

+ (MKCSFilterCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
