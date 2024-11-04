//
//  MKCSSystemTimeCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSSystemTimeCellModel : NSObject

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, copy)NSString *buttonTitle;

@end

@protocol MKCSSystemTimeCellDelegate <NSObject>

- (void)cs_systemTimeButtonPressed:(NSInteger)index;

@end

@interface MKCSSystemTimeCell : MKBaseCell

@property (nonatomic, strong)MKCSSystemTimeCellModel *dataModel;

@property (nonatomic, weak)id <MKCSSystemTimeCellDelegate>delegate;

+ (MKCSSystemTimeCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
