//
//  MKCSNormalConnectedController.m
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import "MKCSNormalConnectedController.h"

#import "Masonry.h"

#import "MKMacroDefines.h"
#import "MKBaseTableView.h"
#import "UIView+MKAdd.h"
#import "UITableView+MKAdd.h"

#import "MKHudManager.h"
#import "MKTableSectionLineHeader.h"
#import "MKAlertView.h"

#import "MKBLEBaseSDKAdopter.h"

#import "MKCSMQTTDataManager.h"
#import "MKCSMQTTInterface.h"

#import "MKCSDeviceModeManager.h"
#import "MKCSDeviceModel.h"

#import "MKCSNormalConnectedCell.h"
#import "MKCSConnectedDeviceWriteAlertView.h"

@interface MKCSNormalConnectedController ()<UITableViewDelegate,
UITableViewDataSource,
MKCSNormalConnectedCellDelegate>

@property (nonatomic, strong)MKBaseTableView *tableView;

@property (nonatomic, strong)NSMutableArray *sectionList;

/*
    @{
        @"180a":@{
            @"section":@"0",
            @"data":@{
                    @"1800":@"0",
                    @"1801":@"1"
            }
        }
        @"ffea":@{
            @"section":@"0",
            @"data":@{
                    @"1800":@"0",
                    @"1801":@"1"
            }
        }
 }
 */
@property (nonatomic, strong)NSMutableDictionary *sectionCache;

@property (nonatomic, strong)MKCSConnectedDeviceWriteAlertView *writeAlert;

@end

@implementation MKCSNormalConnectedController

- (void)dealloc {
    NSLog(@"MKCSNormalConnectedController销毁");
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    //本页面禁止右划退出手势
    self.navigationController.interactivePopGestureRecognizer.enabled = NO;
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    self.navigationController.interactivePopGestureRecognizer.enabled = YES;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self loadSubViews];
    [self parseTableDatas];
    [self addNotes];
}

#pragma mark - super method
- (void)rightButtonMethod {
    @weakify(self);
    MKAlertViewAction *cancelAction = [[MKAlertViewAction alloc] initWithTitle:@"Cancel" handler:^{
        
    }];
    
    MKAlertViewAction *confirmAction = [[MKAlertViewAction alloc] initWithTitle:@"Confirm" handler:^{
        @strongify(self);
        [self disconnect];
    }];
    NSString *msg = @"Please confirm agian whether to disconnect the gateway from BLE devices?";
    MKAlertView *alertView = [[MKAlertView alloc] init];
    [alertView addAction:cancelAction];
    [alertView addAction:confirmAction];
    [alertView showAlertWithTitle:@"" message:msg notificationName:@"mk_cs_needDismissAlert"];
}

- (void)leftButtonMethod {
    //用户点击左上角，则需要返回MKCSDeviceDataController
    [self popToViewControllerWithClassName:@"MKCSDeviceDataController"];
}

#pragma mark - UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *dic = self.sectionList[indexPath.section];
    NSArray *charList = dic[@"charList"];
    MKCSNormalConnectedCellModel *cellModel = charList[indexPath.row];
    return [cellModel cellHeightWithWidth:kViewWidth];
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    return 40.f;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section {
    NSDictionary *dic = self.sectionList[section];
    MKTableSectionLineHeader *header = [MKTableSectionLineHeader initHeaderViewWithTableView:tableView];
    header.headerModel = dic[@"sectionHeaderModel"];
    return header;
}

#pragma mark - UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return self.sectionList.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    NSDictionary *dic = self.sectionList[section];
    NSArray *charList = dic[@"charList"];
    return charList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    MKCSNormalConnectedCell *cell = [MKCSNormalConnectedCell initCellWithTableView:tableView];
    NSDictionary *dic = self.sectionList[indexPath.section];
    NSArray *charList = dic[@"charList"];
    cell.dataModel = charList[indexPath.row];
    cell.delegate  = self;
    return cell;
}

#pragma mark - MKCSNormalConnectedCellDelegate
- (void)cs_normalConnectedCell_writeButtonPressed:(NSInteger)section
                                              row:(NSInteger)row
                                       serverUUID:(NSString *)serverUUID
                                   characteristic:(NSString *)characteristic {
    @weakify(self);
    [self.writeAlert showAlertWithValue:@"" dismissNote:@"mk_cs_needDismissAlert" cancelAction:^{
        
    } confirmAction:^(NSString * _Nonnull textValue) {
        @strongify(self);
        [self writeData:textValue serviceUUID:serverUUID characteristic:characteristic];
    }];
}

- (void)cs_normalConnectedCell_readButtonPressed:(NSInteger)section
                                             row:(NSInteger)row
                                      serverUUID:(NSString *)serverUUID
                                  characteristic:(NSString *)characteristic {
    [self readDataWithServiceUUID:serverUUID
                   characteristic:characteristic
                          section:section
                              row:row];
}

- (void)cs_normalConnectedCell_notifyButtonPressed:(BOOL)notify
                                           section:(NSInteger)section
                                               row:(NSInteger)row
                                        serverUUID:(NSString *)serverUUID
                                    characteristic:(NSString *)characteristic {
    [self notify:notify serviceUUID:serverUUID characteristic:characteristic section:section row:row];
}

#pragma mark - notes
- (void)receiveDisconnect:(NSNotification *)note {
    NSDictionary *user = note.userInfo;
    if (!ValidDict(user) || !ValidStr(user[@"device_info"][@"mac"]) || ![[MKCSDeviceModeManager shared].macAddress isEqualToString:user[@"device_info"][@"mac"]]) {
        return;
    }
    NSDictionary *dataDic = user[@"data"];
    if (![dataDic[@"mac"] isEqualToString:self.deviceBleInfo[@"data"][@"mac"]]) {
        return;
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"mk_cs_needDismissAlert" object:nil];
    //返回上一级页面
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)receiveDeviceDatas:(NSNotification *)note {
    NSDictionary *user = note.userInfo;
    if (!ValidDict(user) || !ValidStr(user[@"device_info"][@"mac"]) || ![[MKCSDeviceModeManager shared].macAddress isEqualToString:user[@"device_info"][@"mac"]]) {
        return;
    }
    NSDictionary *dataDic = user[@"data"];
    if (![dataDic[@"mac"] isEqualToString:self.deviceBleInfo[@"data"][@"mac"]]) {
        return;
    }
    
    NSDictionary *tempDic = self.sectionCache[dataDic[@"service_uuid"]];
    NSInteger section = [tempDic[@"section"] integerValue];
    NSString *charUUID = dataDic[@"char_uuid"];
    NSInteger row = [tempDic[@"rowData"][charUUID] integerValue];
    NSDictionary *modelDic = self.sectionList[section];
    NSArray *charList = modelDic[@"charList"];
    MKCSNormalConnectedCellModel *cellModel = charList[row];
    cellModel.value = dataDic[@"payload"];
    [self.tableView mk_reloadRow:row inSection:section withRowAnimation:UITableViewRowAnimationNone];
}

#pragma mark - private method
- (void)addNotes {
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(receiveDisconnect:)
                                                 name:MKCSReceiveGatewayDisconnectDeviceNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(receiveDeviceDatas:)
                                                 name:MKCSReceiveGatewayConnectedDeviceDatasNotification
                                               object:nil];
}

- (void)parseTableDatas {
    if (!ValidDict(self.deviceBleInfo)) {
        return;
    }
    NSArray *serviceList = self.deviceBleInfo[@"data"][@"service_array"];
    if (!ValidArray(serviceList)) {
        return;
    }
    NSInteger count = serviceList.count;
    for (NSInteger i = 0; i < count; i ++) {
        NSDictionary *serviceDic = serviceList[i];
        MKTableSectionLineHeaderModel *headerModel = [[MKTableSectionLineHeaderModel alloc] init];
        headerModel.text = [NSString stringWithFormat:@"%@%@",@"Service UUID: 0x",[SafeStr(serviceDic[@"service_uuid"]) uppercaseString]];
        
        NSArray *tempCharList = serviceDic[@"char_array"];
        NSInteger charCount = tempCharList.count;
        NSMutableArray *charList = [NSMutableArray array];
        NSMutableDictionary *charPathDic = [NSMutableDictionary dictionary];
        for (NSInteger j = 0; j < charCount; j ++) {
            NSDictionary *charDic = tempCharList[j];
            MKCSNormalConnectedCellModel *cellModel = [[MKCSNormalConnectedCellModel alloc] init];
            cellModel.section = i;
            cellModel.row = j;
            cellModel.server = serviceDic[@"service_uuid"];
            cellModel.characteristic = charDic[@"char_uuid"];
            cellModel.properties = [MKBLEBaseSDKAdopter fetchHexValue:[charDic[@"properties"] longLongValue] byteLen:1];
            cellModel.notifyStatus = [serviceDic[@"notify_status"] integerValue];
            cellModel.value = @"";
            [charList addObject:cellModel];
            [charPathDic setObject:@(j) forKey:charDic[@"char_uuid"]];
        }
        NSDictionary *tableDic = @{
            @"sectionHeaderModel":headerModel,
            @"charList":charList,
        };
        NSDictionary *cacheDic = @{
            @"section":@(i),
            @"rowData":charPathDic
        };
        [self.sectionList addObject:tableDic];
        
        [self.sectionCache setObject:cacheDic forKey:SafeStr(serviceDic[@"service_uuid"])];
    }
    
    [self.tableView reloadData];
}

- (void)disconnect {
    [[MKHudManager share] showHUDWithTitle:@"Waiting..." inView:self.view isPenetration:NO];
    [MKCSMQTTInterface cs_disconnectNormalBleDeviceWithBleMac:self.deviceBleInfo[@"data"][@"mac"] macAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        [[MKHudManager share] hide];
        [self.navigationController popViewControllerAnimated:YES];
    } failedBlock:^(NSError * _Nonnull error) {
        [[MKHudManager share] hide];
        [self.view showCentralToast:error.userInfo[@"errorInfo"]];
    }];
}

- (void)writeData:(NSString *)data serviceUUID:(NSString *)serverUUID characteristic:(NSString *)characteristic {
    [[MKHudManager share] showHUDWithTitle:@"Writing..." inView:self.view isPenetration:NO];
    [MKCSMQTTInterface cs_writeValueToDeviceWithBleMacAddress:self.deviceBleInfo[@"data"][@"mac"] value:data serviceUUID:serverUUID characteristicUUID:characteristic macAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        [[MKHudManager share] hide];
        if ([returnData[@"data"][@"result_code"] integerValue] != 0) {
            [self.view showCentralToast:@"Write Failed"];
            return;
        }
        [self.view showCentralToast:@"Success"];
    } failedBlock:^(NSError * _Nonnull error) {
        [[MKHudManager share] hide];
        [self.view showCentralToast:error.userInfo[@"errorInfo"]];
    }];
}

- (void)readDataWithServiceUUID:(NSString *)serverUUID
                 characteristic:(NSString *)characteristic
                        section:(NSInteger)section
                            row:(NSInteger)row {
    [[MKHudManager share] showHUDWithTitle:@"Reading..." inView:self.view isPenetration:NO];
    [MKCSMQTTInterface cs_readCharacteristicValueWithBleMacAddress:self.deviceBleInfo[@"data"][@"mac"] serviceUUID:serverUUID characteristicUUID:characteristic macAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        [[MKHudManager share] hide];
        if ([returnData[@"data"][@"result_code"] integerValue] != 0) {
            [self.view showCentralToast:@"Read Failed"];
            return;
        }
        NSDictionary *dic = self.sectionList[section];
        NSArray *charList = dic[@"charList"];
        MKCSNormalConnectedCellModel *cellModel = charList[row];
        cellModel.value = returnData[@"data"][@"payload"];
        [self.tableView mk_reloadRow:row inSection:section withRowAnimation:UITableViewRowAnimationNone];
    } failedBlock:^(NSError * _Nonnull error) {
        [[MKHudManager share] hide];
        [self.view showCentralToast:error.userInfo[@"errorInfo"]];
    }];
}

- (void)notify:(BOOL)notify
   serviceUUID:(NSString *)serverUUID
characteristic:(NSString *)characteristic
       section:(NSInteger)section
           row:(NSInteger)row {
    [[MKHudManager share] showHUDWithTitle:@"Config..." inView:self.view isPenetration:NO];
    [MKCSMQTTInterface cs_notifyCharacteristic:notify bleMacAddress:self.deviceBleInfo[@"data"][@"mac"] serviceUUID:serverUUID characteristicUUID:characteristic macAddress:[MKCSDeviceModeManager shared].macAddress topic:[MKCSDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        [[MKHudManager share] hide];
        if ([returnData[@"data"][@"result_code"] integerValue] != 0) {
            [self.view showCentralToast:@"Read Failed"];
            return;
        }
        NSDictionary *dic = self.sectionList[section];
        NSArray *charList = dic[@"charList"];
        MKCSNormalConnectedCellModel *cellModel = charList[row];
        cellModel.notifyStatus = (notify ? 1 : 0);
        [self.tableView mk_reloadRow:row inSection:section withRowAnimation:UITableViewRowAnimationNone];
    } failedBlock:^(NSError * _Nonnull error) {
        [[MKHudManager share] hide];
        [self.view showCentralToast:error.userInfo[@"errorInfo"]];
    }];
}

#pragma mark - UI
- (void)loadSubViews {
    self.defaultTitle = [MKCSDeviceModeManager shared].deviceName;
    [self.rightButton setTitle:@"Disconnect" forState:UIControlStateNormal];
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(0.f);
        make.right.mas_equalTo(0.f);
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

- (NSMutableArray *)sectionList {
    if (!_sectionList) {
        _sectionList = [NSMutableArray array];
    }
    return _sectionList;
}

- (MKCSConnectedDeviceWriteAlertView *)writeAlert {
    if (!_writeAlert) {
        _writeAlert = [[MKCSConnectedDeviceWriteAlertView alloc] init];
    }
    return _writeAlert;
}

- (NSMutableDictionary *)sectionCache {
    if (!_sectionCache) {
        _sectionCache = [NSMutableDictionary dictionary];
    }
    return _sectionCache;
}

@end
