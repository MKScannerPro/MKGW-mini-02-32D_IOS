//
//  MKCSResetByButtonCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSResetByButtonCellModel : NSObject

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, assign)BOOL selected;

@end

@protocol MKCSResetByButtonCellDelegate <NSObject>

- (void)cs_resetByButtonCellAction:(NSInteger)index;

@end

@interface MKCSResetByButtonCell : MKBaseCell

@property (nonatomic, weak)id <MKCSResetByButtonCellDelegate>delegate;

@property (nonatomic, strong)MKCSResetByButtonCellModel *dataModel;

+ (MKCSResetByButtonCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
