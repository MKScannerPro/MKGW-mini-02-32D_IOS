//
//  MKCSButtonFirmwareCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSButtonFirmwareCellModel : NSObject

/// cell唯一识别号
@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *leftMsg;

@property (nonatomic, copy)NSString *rightMsg;

@property (nonatomic, copy)NSString *rightButtonTitle;

@end

@protocol MKCSButtonFirmwareCellDelegate <NSObject>

- (void)cs_buttonFirmwareCell_buttonAction:(NSInteger)index;

@end

@interface MKCSButtonFirmwareCell : MKBaseCell

@property (nonatomic, strong)MKCSButtonFirmwareCellModel *dataModel;

@property (nonatomic, weak)id <MKCSButtonFirmwareCellDelegate>delegate;

+ (MKCSButtonFirmwareCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
