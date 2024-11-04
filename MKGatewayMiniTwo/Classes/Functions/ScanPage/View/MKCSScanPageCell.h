//
//  MKCSScanPageCell.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@class MKCSScanPageModel;
@interface MKCSScanPageCell : MKBaseCell

@property (nonatomic, strong)MKCSScanPageModel *dataModel;

+ (MKCSScanPageCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
