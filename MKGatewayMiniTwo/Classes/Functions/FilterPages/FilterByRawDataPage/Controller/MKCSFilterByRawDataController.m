//
//  MKCSFilterByRawDataController.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSFilterByRawDataController.h"

#import "Masonry.h"

#import "MKMacroDefines.h"
#import "MKBaseTableView.h"
#import "UIView+MKAdd.h"
#import "UITableView+MKAdd.h"

#import "MKHudManager.h"
#import "MKNormalTextCell.h"
#import "MKTextSwitchCell.h"

#import "MKCSDeviceModeManager.h"
#import "MKCSDeviceModel.h"

#import "MKCSMQTTInterface.h"

#import "MKCSFilterByRawDataModel.h"

#import "MKCSFilterByBeaconController.h"
#import "MKCSFilterByUIDController.h"
#import "MKCSFilterByURLController.h"
#import "MKCSFilterByTLMController.h"
#import "MKCSFilterByButtonController.h"
#import "MKCSFilterByTagController.h"
#import "MKCSFilterByPirController.h"
#import "MKCSFilterByTofController.h"
#import "MKCSFilterByOtherController.h"

@interface MKCSFilterByRawDataController ()<UITableViewDelegate,
UITableViewDataSource,
mk_textSwitchCellDelegate>

@property (nonatomic, strong)MKBaseTableView *tableView;

@property (nonatomic, strong)NSMutableArray *section0List;

@property (nonatomic, strong)NSMutableArray *section1List;

@property (nonatomic, strong)NSMutableArray *section2List;

@property (nonatomic, strong)MKCSFilterByRawDataModel *dataModel;

@end

@implementation MKCSFilterByRawDataController

- (void)dealloc {
    NSLog(@"MKCSFilterByRawDataController销毁");
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self readDataFromDevice];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self loadSubViews];
    [self loadSectionDatas];
}

#pragma mark - UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 44.f;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.section == 0 && indexPath.row == 0) {
        //iBeacon
        MKCSFilterByBeaconController *vc = [[MKCSFilterByBeaconController alloc] init];
        vc.pageType = mk_cs_filterByBeaconPageType_beacon;
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
    if (indexPath.section == 0 && indexPath.row == 1) {
        //Eddystone-UID
        MKCSFilterByUIDController *vc = [[MKCSFilterByUIDController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
    if (indexPath.section == 0 && indexPath.row == 2) {
        //Eddystone-URL
        MKCSFilterByURLController *vc = [[MKCSFilterByURLController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
    if (indexPath.section == 0 && indexPath.row == 3) {
        //Eddystone-TLM
        MKCSFilterByTLMController *vc = [[MKCSFilterByTLMController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
    if (indexPath.section == 2 && indexPath.row == 0) {
        //BXP-Button
        MKCSFilterByButtonController *vc = [[MKCSFilterByButtonController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
    if (indexPath.section == 2 && indexPath.row == 1) {
        //BXP-Tag
        MKCSFilterByTagController *vc = [[MKCSFilterByTagController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
    if (indexPath.section == 2 && indexPath.row == 2) {
        //PIR
        MKCSFilterByPirController *vc = [[MKCSFilterByPirController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
    if (indexPath.section == 2 && indexPath.row == 3) {
        //MK TOF
        MKCSFilterByTofController *vc = [[MKCSFilterByTofController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
    if (indexPath.section == 2 && indexPath.row == 4) {
        //Other
        MKCSFilterByOtherController *vc = [[MKCSFilterByOtherController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        return;
    }
}

#pragma mark - UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 3;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    if (section == 0) {
        return self.section0List.count;
    }
    if (section == 1) {
        return self.section1List.count;
    }
    if (section == 2) {
        return self.section2List.count;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.section == 0) {
        MKNormalTextCell *cell = [MKNormalTextCell initCellWithTableView:tableView];
        cell.dataModel = self.section0List[indexPath.row];
        return cell;
    }
    if (indexPath.section == 1) {
        MKTextSwitchCell *cell = [MKTextSwitchCell initCellWithTableView:tableView];
        cell.dataModel = self.section1List[indexPath.row];
        cell.delegate = self;
        return cell;
    }
    MKNormalTextCell *cell = [MKNormalTextCell initCellWithTableView:tableView];
    cell.dataModel = self.section2List[indexPath.row];
    return cell;
}

#pragma mark - mk_textSwitchCellDelegate
/// 开关状态发生改变了
/// @param isOn 当前开关状态
/// @param index 当前cell所在的index
- (void)mk_textSwitchCellStatusChanged:(BOOL)isOn index:(NSInteger)index {
    if (index == 0) {
        //BeaconX Pro – Device info
        [self configFilterBXPDeviceInfo:isOn];
        return;
    }
    if (index == 1) {
        //BeaconX Pro – ACC
        [self configFilterBXPACC:isOn];
        return;
    }
    if (index == 2) {
        //BeaconX Pro – T&H
        [self configFilterBXPTH:isOn];
        return;
    }
}

#pragma mark - interface
- (void)readDataFromDevice {
    [[MKHudManager share] showHUDWithTitle:@"Reading..." inView:self.view isPenetration:NO];
    @weakify(self);
    [self.dataModel readDataWithSucBlock:^{
        @strongify(self);
        [[MKHudManager share] hide];
        [self updateCellStatus];
    } failedBlock:^(NSError * _Nonnull error) {
        @strongify(self);
        [[MKHudManager share] hide];
        [self.view showCentralToast:error.userInfo[@"errorInfo"]];
    }];
}

- (void)configFilterBXPDeviceInfo:(BOOL)isOn {
    [[MKHudManager share] showHUDWithTitle:@"Config..." inView:self.view isPenetration:NO];
    [MKCSMQTTInterface cs_configFilterFilterBXPDeviceInfo:isOn macAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        [[MKHudManager share] hide];
        MKTextSwitchCellModel *cellModel = self.section1List[0];
        cellModel.isOn = isOn;
        self.dataModel.bxpDeviceInfo = isOn;
    } failedBlock:^(NSError * _Nonnull error) {
        [[MKHudManager share] hide];
        [self.view showCentralToast:error.userInfo[@"errorInfo"]];
        [self.tableView mk_reloadRow:0 inSection:1 withRowAnimation:UITableViewRowAnimationNone];
    }];
}

- (void)configFilterBXPACC:(BOOL)isOn {
    [[MKHudManager share] showHUDWithTitle:@"Config..." inView:self.view isPenetration:NO];
    [MKCSMQTTInterface cs_configFilterBXPAcc:isOn macAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        [[MKHudManager share] hide];
        MKTextSwitchCellModel *cellModel = self.section1List[1];
        cellModel.isOn = isOn;
        self.dataModel.bxpAcc = isOn;
    } failedBlock:^(NSError * _Nonnull error) {
        [[MKHudManager share] hide];
        [self.view showCentralToast:error.userInfo[@"errorInfo"]];
        [self.tableView mk_reloadRow:0 inSection:1 withRowAnimation:UITableViewRowAnimationNone];
    }];
}

- (void)configFilterBXPTH:(BOOL)isOn {
    [[MKHudManager share] showHUDWithTitle:@"Config..." inView:self.view isPenetration:NO];
    [MKCSMQTTInterface cs_configFilterBXPTH:isOn macAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        [[MKHudManager share] hide];
        MKTextSwitchCellModel *cellModel = self.section1List[2];
        cellModel.isOn = isOn;
        self.dataModel.bxpTH = isOn;
    } failedBlock:^(NSError * _Nonnull error) {
        [[MKHudManager share] hide];
        [self.view showCentralToast:error.userInfo[@"errorInfo"]];
        [self.tableView mk_reloadRow:0 inSection:1 withRowAnimation:UITableViewRowAnimationNone];
    }];
}

#pragma mark - loadSectionDatas
- (void)loadSectionDatas {
    [self loadSection0Datas];
    [self loadSection1Datas];
    [self loadSection2Datas];
    
    [self.tableView reloadData];
}

- (void)updateCellStatus {
    MKNormalTextCellModel *cellModel1 = self.section0List[0];
    cellModel1.rightMsg = (self.dataModel.iBeacon ? @"ON" : @"OFF");
    
    MKNormalTextCellModel *cellModel2 = self.section0List[1];
    cellModel2.rightMsg = (self.dataModel.uid ? @"ON" : @"OFF");
    
    MKNormalTextCellModel *cellModel3 = self.section0List[2];
    cellModel3.rightMsg = (self.dataModel.url ? @"ON" : @"OFF");
    
    MKNormalTextCellModel *cellModel4 = self.section0List[3];
    cellModel4.rightMsg = (self.dataModel.tlm ? @"ON" : @"OFF");
    
    MKTextSwitchCellModel *cellModel5 = self.section1List[0];
    cellModel5.isOn = self.dataModel.bxpDeviceInfo;
    
    MKTextSwitchCellModel *cellModel6 = self.section1List[1];
    cellModel6.isOn = self.dataModel.bxpAcc;
    
    MKTextSwitchCellModel *cellModel7 = self.section1List[2];
    cellModel7.isOn = self.dataModel.bxpTH;
    
    MKNormalTextCellModel *cellModel8 = self.section2List[0];
    cellModel8.rightMsg = (self.dataModel.bxpButton ? @"ON" : @"OFF");
    
    MKNormalTextCellModel *cellModel9 = self.section2List[1];
    cellModel9.rightMsg = (self.dataModel.bxpTag ? @"ON" : @"OFF");
    
    MKNormalTextCellModel *cellModel10 = self.section2List[2];
    cellModel10.rightMsg = (self.dataModel.pirPresence ? @"ON" : @"OFF");
    
    MKNormalTextCellModel *cellModel11 = self.section2List[3];
    cellModel11.rightMsg = (self.dataModel.tof ? @"ON" : @"OFF");
    
    MKNormalTextCellModel *cellModel12 = self.section2List[4];
    cellModel12.rightMsg = (self.dataModel.other ? @"ON" : @"OFF");
    
    [self.tableView reloadData];
}

- (void)loadSection0Datas {
    MKNormalTextCellModel *cellModel1 = [[MKNormalTextCellModel alloc] init];
    cellModel1.showRightIcon = YES;
    cellModel1.leftMsg = @"iBeacon";
    [self.section0List addObject:cellModel1];
    
    MKNormalTextCellModel *cellModel2 = [[MKNormalTextCellModel alloc] init];
    cellModel2.showRightIcon = YES;
    cellModel2.leftMsg = @"Eddystone-UID";
    [self.section0List addObject:cellModel2];
    
    MKNormalTextCellModel *cellModel3 = [[MKNormalTextCellModel alloc] init];
    cellModel3.showRightIcon = YES;
    cellModel3.leftMsg = @"Eddystone-URL";
    [self.section0List addObject:cellModel3];
    
    MKNormalTextCellModel *cellModel4 = [[MKNormalTextCellModel alloc] init];
    cellModel4.showRightIcon = YES;
    cellModel4.leftMsg = @"Eddystone-TLM";
    [self.section0List addObject:cellModel4];
}

- (void)loadSection1Datas {
    MKTextSwitchCellModel *cellModel1 = [[MKTextSwitchCellModel alloc] init];
    cellModel1.index = 0;
    cellModel1.msg = @"BXP - Device info";
    [self.section1List addObject:cellModel1];
    
    MKTextSwitchCellModel *cellModel2 = [[MKTextSwitchCellModel alloc] init];
    cellModel2.index = 1;
    cellModel2.msg = @"BXP – ACC";
    [self.section1List addObject:cellModel2];
    
    MKTextSwitchCellModel *cellModel3 = [[MKTextSwitchCellModel alloc] init];
    cellModel3.index = 2;
    cellModel3.msg = @"BXP – T&H";
    [self.section1List addObject:cellModel3];
}

- (void)loadSection2Datas {
    MKNormalTextCellModel *cellModel1 = [[MKNormalTextCellModel alloc] init];
    cellModel1.showRightIcon = YES;
    cellModel1.leftMsg = @"BXP-Button";
    [self.section2List addObject:cellModel1];
    
    MKNormalTextCellModel *cellModel2 = [[MKNormalTextCellModel alloc] init];
    cellModel2.showRightIcon = YES;
    cellModel2.leftMsg = @"BXP-Tag";
    [self.section2List addObject:cellModel2];
    
    MKNormalTextCellModel *cellModel3 = [[MKNormalTextCellModel alloc] init];
    cellModel3.showRightIcon = YES;
    cellModel3.leftMsg = @"PIR Presence";
    [self.section2List addObject:cellModel3];
    
    MKNormalTextCellModel *cellModel4 = [[MKNormalTextCellModel alloc] init];
    cellModel4.showRightIcon = YES;
    cellModel4.leftMsg = @"MK TOF";
    [self.section2List addObject:cellModel4];
    
    MKNormalTextCellModel *cellModel5 = [[MKNormalTextCellModel alloc] init];
    cellModel5.showRightIcon = YES;
    cellModel5.leftMsg = @"Other";
    [self.section2List addObject:cellModel5];
}

#pragma mark - UI
- (void)loadSubViews {
    self.defaultTitle = @"Filter by Raw Data";
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(0);
        make.right.mas_equalTo(0);
        make.top.mas_equalTo(self.view.mas_safeAreaLayoutGuideTop);
        make.bottom.mas_equalTo(self.view.mas_safeAreaLayoutGuideBottom);
    }];
}

#pragma mark - getter
- (MKBaseTableView *)tableView {
    if (!_tableView) {
        _tableView = [[MKBaseTableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
    }
    return _tableView;
}

- (NSMutableArray *)section0List {
    if (!_section0List) {
        _section0List = [NSMutableArray array];
    }
    return _section0List;
}

- (NSMutableArray *)section1List {
    if (!_section1List) {
        _section1List = [NSMutableArray array];
    }
    return _section1List;
}

- (NSMutableArray *)section2List {
    if (!_section2List) {
        _section2List = [NSMutableArray array];
    }
    return _section2List;
}

- (MKCSFilterByRawDataModel *)dataModel {
    if (!_dataModel) {
        _dataModel = [[MKCSFilterByRawDataModel alloc] init];
    }
    return _dataModel;
}

@end
