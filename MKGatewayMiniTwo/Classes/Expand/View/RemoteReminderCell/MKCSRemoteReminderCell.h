//
//  MKCSRemoteReminderCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2025/1/20.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSRemoteReminderCellModel : NSObject

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, assign)NSInteger index;

@end

@protocol MKCSRemoteReminderCellDelegate <NSObject>

- (void)bxd_remindButtonPressed:(NSInteger)index;

@end

@interface MKCSRemoteReminderCell : MKBaseCell

@property (nonatomic, strong)MKCSRemoteReminderCellModel *dataModel;

@property (nonatomic, weak)id <MKCSRemoteReminderCellDelegate>delegate;

+ (MKCSRemoteReminderCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
