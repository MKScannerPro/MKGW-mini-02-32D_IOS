//
//  MKCSFilterCell.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSFilterCell.h"

#import "Masonry.h"

#import "MKMacroDefines.h"

#import "MKCustomUIAdopter.h"
#import "MKPickerView.h"

@implementation MKCSFilterCellModel
@end

@interface MKCSFilterCell ()

@property (nonatomic, strong)UILabel *msgLabel;

@property (nonatomic, strong)UIButton *rightButton;

@end

@implementation MKCSFilterCell

+ (MKCSFilterCell *)initCellWithTableView:(UITableView *)tableView {
    MKCSFilterCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MKCSFilterCellIdenty"];
    if (!cell) {
        cell = [[MKCSFilterCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MKCSFilterCellIdenty"];
    }
    return cell;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        [self.contentView addSubview:self.msgLabel];
        [self.contentView addSubview:self.rightButton];
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self.msgLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(15.f);
        make.width.mas_equalTo(125.f);
        make.centerY.mas_equalTo(self.contentView.mas_centerY);
        make.height.mas_equalTo(MKFont(15.f).lineHeight);
    }];
    [self.rightButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(self.msgLabel.mas_right).mas_offset(10.f);
        make.right.mas_equalTo(-15.f);
        make.centerY.mas_equalTo(self.contentView.mas_centerY);
        make.height.mas_equalTo(30.f);
    }];
}

#pragma mark - event method
- (void)rightButtonPressed {
    NSInteger row = 0;
    for (NSInteger i = 0; i < self.dataModel.dataList.count; i ++) {
        if ([self.rightButton.titleLabel.text isEqualToString:self.dataModel.dataList[i]]) {
            row = i;
            break;
        }
    }
    
    MKPickerView *pickView = [[MKPickerView alloc] init];
    [pickView showPickViewWithDataList:self.dataModel.dataList selectedRow:row block:^(NSInteger currentRow) {
        [self.rightButton setTitle:self.dataModel.dataList[currentRow] forState:UIControlStateNormal];
        if ([self.delegate respondsToSelector:@selector(cs_filterValueChanged:index:)]) {
            [self.delegate cs_filterValueChanged:currentRow index:self.dataModel.index];
        }
    }];
}

#pragma mark - setter
- (void)setDataModel:(MKCSFilterCellModel *)dataModel {
    _dataModel = nil;
    _dataModel = dataModel;
    if (!_dataModel || ![_dataModel isKindOfClass:MKCSFilterCellModel.class]) {
        return;
    }
    self.msgLabel.text = SafeStr(_dataModel.msg);
    [self.rightButton setTitle:self.dataModel.dataList[_dataModel.dataListIndex] forState:UIControlStateNormal];
}

#pragma mark - getter
- (UILabel *)msgLabel {
    if (!_msgLabel) {
        _msgLabel = [[UILabel alloc] init];
        _msgLabel.textColor = DEFAULT_TEXT_COLOR;
        _msgLabel.textAlignment = NSTextAlignmentLeft;
        _msgLabel.font = MKFont(13.f);
    }
    return _msgLabel;
}

- (UIButton *)rightButton {
    if (!_rightButton) {
        _rightButton = [MKCustomUIAdopter customButtonWithTitle:@""
                                                         target:self
                                                         action:@selector(rightButtonPressed)];
        _rightButton.titleLabel.font = MKFont(13.f);
    }
    return _rightButton;
}

@end
