
typedef NS_ENUM(NSInteger, mk_cs_serverOperationID) {
    mk_cs_defaultServerOperationID,
    
#pragma mark - Config
    mk_cs_server_taskRebootDeviceOperation,             //重启设备
    mk_cs_server_taskKeyResetTypeOperation,             //配置按键恢复出厂设置类型
    mk_cs_server_taskConfigNetworkStatusReportIntervalOperation,    //配置网络状态上报间隔
    mk_cs_server_taskConfigReconnectTimeoutOperation,           //配置网络重连超时时间
    mk_cs_server_taskConfigOTAHostOperation,                    //OTA
    mk_cs_server_taskConfigNTPServerOperation,                  //配置NTP服务器信息
    mk_cs_server_taskConfigDeviceTimeZoneOperation,             //配置设备的UTC时间
    mk_cs_server_taskConfigCommunicationTimeoutOperation,       //配置通信超时时间
    mk_cs_server_taskConfigIndicatorLightStatusOperation,       //配置指示灯开关
    mk_cs_server_taskResetDeviceOperation,              //恢复出厂设置
    mk_cs_server_taskConfigNpcOTAHostOperation,         //Npc Ota
    mk_cs_server_taskModifyWifiInfosOperation,          //配置wifi网络
    mk_cs_server_taskModifyNetworkInfoOperation,        //配置网络参数
    mk_cs_server_taskModifyWifiCertsOperation,          //配置EAP证书
    mk_cs_server_taskModifyMqttInfoOperation,           //配置MQTT参数
    mk_cs_server_taskModifyMqttCertsOperation,          //配置MQTT证书
    mk_cs_server_taskConfigScanSwitchStatusOperation,   //配置扫描开关状态
    mk_cs_server_taskConfigFilterRelationshipsOperation,  //配置过滤逻辑
    mk_cs_server_taskConfigFilterByRSSIOperation,         //配置过滤RSSI
    mk_cs_server_taskConfigFilterByMacAddressOperation,     //配置过滤mac
    mk_cs_server_taskConfigFilterByADVNameOperation,        //配置过滤ADV Name
    mk_cs_server_taskConfigFilterByBeaconOperation,         //配置过滤iBeacon信息
    mk_cs_server_taskConfigFilterByUIDOperation,            //配置过滤UID信息
    mk_cs_server_taskConfigFilterByUrlOperation,            //配置过滤Url信息
    mk_cs_server_taskConfigFilterByTLMOperation,            //配置过滤TLM信息
    mk_cs_server_taskConfigFilterBXPDeviceInfoOperation,    //配置bxp-deviceInfo过滤状态
    mk_cs_server_taskConfigFilterBXPAccOperation,           //配置bxp-acc过滤状态
    mk_cs_server_taskConfigFilterBXPTHOperation,            //配置bxp-th过滤状态
    mk_cs_server_taskConfigFilterBXPButtonOperation,        //配置过滤bxp-button信息
    mk_cs_server_taskConfigFilterByTagOperation,            //配置过滤bxp_tag信息
    mk_cs_server_taskConfigFilterByPirOperation,            //配置过滤PIR信息
    mk_cs_server_taskConfigFilterByOtherDatasOperation,     //配置过滤Other信息
    mk_cs_server_taskConfigDuplicateDataFilterOperation,    //配置扫描重复数据参数
    mk_cs_server_taskConfigDataReportTimeoutOperation,      //配置数据包上报超时时间
    mk_cs_server_taskConfigUploadDataOptionOperation,       //配置扫描数据上报内容选项
    
    mk_cs_server_taskConnectBXPButtonWithMacOperation,      //连接指定mac地址的BXP-Button设备
    
    mk_cs_server_taskDisconnectNormalBleDeviceWithMacOperation, //网关断开指定mac地址的蓝牙设备
    mk_cs_server_taskStartBXPButtonDfuWithMacOperation,         //指定BXP-Button设备DFU升级
    
    mk_cs_server_taskConnectNormalBleDeviceWithMacOperation,    //网关连接指定mac地址的蓝牙设备
    mk_cs_server_taskStartBXPDfuWithMacOperation,               //MKCS3 V2 dfu
    
#pragma mark - Read
    mk_cs_server_taskReadKeyResetTypeOperation,         //读取按键恢复出厂设置类型
    mk_cs_server_taskReadDeviceInfoOperation,           //读取设备信息
    mk_cs_server_taskReadNetworkStatusReportIntervalOperation,  //读取网络状态上报间隔
    mk_cs_server_taskReadNetworkReconnectTimeoutOperation,      //读取网络重连超时时间
    mk_cs_server_taskReadNTPServerOperation,                    //读取NTP服务器信息
    mk_cs_server_taskReadDeviceUTCTimeOperation,                //读取当前UTC时间
    mk_cs_server_taskReadCommunicateTimeoutOperation,           //读取通信超时时间
    mk_cs_server_taskReadIndicatorLightStatusOperation,         //读取指示灯开关
    mk_cs_server_taskReadOtaStatusOperation,                    //读取当前设备OTA状态
    mk_cs_server_taskReadWifiInfosOperation,                    //读取设备当前连接的wifi信息
    mk_cs_server_taskReadNetworkInfosOperation,                 //读取网络参数
    mk_cs_server_taskReadMQTTParamsOperation,                   //读取MQTT服务器信息
    mk_cs_server_taskReadScanSwitchStatusOperation,    //读取扫描开关状态
    mk_cs_server_taskReadFilterRelationshipsOperation,  //读取过滤逻辑
    mk_cs_server_taskReadFilterByRSSIOperation,         //读取过滤RSSI
    mk_cs_server_taskReadFilterByMacOperation,          //读取过滤MAC
    mk_cs_server_taskReadFilterADVNameRSSIOperation,    //读取过滤ADV Name
    mk_cs_server_taskReadFilterByRawDataStatusOperation,    //读取RAW类型过滤开关
    mk_cs_server_taskReadFilterByBeaconOperation,           //读取iBeacon过滤内容
    mk_cs_server_taskReadFilterByUIDOperation,              //读取UID过滤内容
    mk_cs_server_taskReadFilterByUrlOperation,              //读取Url过滤内容
    mk_cs_server_taskReadFilterByTLMOperation,              //读取TLM过滤内容
    mk_cs_server_taskReadFilterBXPDeviceInfoStatusOperation,    //读取bxp-deviceInfo过滤开关
    mk_cs_server_taskReadFilterBXPAccStatusOperation,           //读取bxp-acc过滤开关
    mk_cs_server_taskReadFilterBXPTHStatusOperation,            //读取bxp-th过滤开关
    mk_cs_server_taskReadFilterBXPButtonOperation,              //读取bxp-button过滤内容
    mk_cs_server_taskReadFilterBXPTagOperation,                 //读取bxp-tag过滤内容
    mk_cs_server_taskReadFilterByPirOperation,                  //读取pir过滤内容
    mk_cs_server_taskReadFilterOtherDatasOperation,             //读取过滤Other信息
    mk_cs_server_taskReadDuplicateDataFilterDatasOperation,     //读取扫描重复数据参数
    mk_cs_server_taskReadDataReportTimeoutOperation,            //读取数据上报超时时间
    mk_cs_server_taskReadUploadDataOptionOperation,             //读取扫描数据上报内容选项
    
    mk_cs_server_taskReadBXPButtonConnectedDeviceInfoOperation, //读取已连接BXP-Button设备信息
    mk_cs_server_taskReadBXPButtonStatusOperation,              //读取已连接BXP-Button的状态
    mk_cs_server_taskDismissAlarmStatusOperation,               //BXP-Button消警
    
    mk_cs_server_taskReadGatewayBleConnectStatusOperation,      //读取网关蓝牙连接的状态
    
    mk_cs_server_taskReadNormalConnectedDeviceInfoOperation,    //读取蓝牙网关连接的指定设备的服务和特征信息
    mk_cs_server_taskNotifyCharacteristicOperation,             //打开/关闭监听指定特征
    mk_cs_server_taskReadCharacteristicValueOperation,          //读取蓝牙网关连接的指定设备的特征值
    mk_cs_server_taskWriteCharacteristicValueOperation,         //向蓝牙网关连接的指定设备的指定特征写入值
    
    mk_cs_server_taskReadAdvertiseBeaconParamsOperation,    //读取iBeacon广播参数
    mk_cs_server_taskConfigAdvertiseBeaconParamsOperation,  //配置iBeacon广播参数
    
    mk_cs_server_taskClearTriggerEventCountOperation,       //删除触发记录
    
    mk_cs_server_taskReadFilterByTofOperation,              //读取MK-TOF过滤
    mk_cs_server_taskConfigFilterByTofOperation,            //配置MK-TOF过滤
    
    mk_cs_server_taskReadFilterByPhyOperation,              //读取Phy过滤
    mk_cs_server_taskConfigFilterByPhyOperation,            //配置Phy过滤
    
    mk_cs_server_taskBxpBtnLedRemoteReminderOperation,      //BXP-B-D led远程消警
    mk_cs_server_taskBxpBtnBuzzerRemoteReminderOperation,   //BXP-B-D buzzer远程消警
    mk_cs_server_taskBxpBtnNotifyAccDataOperation,          //BXP-B-D 监听三轴数据
    mk_cs_server_taskBxpBtnRemotePowerOffOperation,         //BXP-B-D 远程关机
    mk_cs_server_taskBxpBtnReadAdvParamsOperation,          //BXP-B-D 读取广播参数
    mk_cs_server_taskBxpBtnConfigAdvParamsOperation,        //BXP-B-D 配置广播参数
    
    
    mk_cs_server_taskConnectBXPButtonCRWithMacOperation,    //BXP-B-CR 连接设备
    mk_cs_server_taskReadBXPButtonCRConnectedDeviceInfoOperation,   //BXP-B-CR读取设备信息
    mk_cs_server_taskReadBXPButtonCRStatusOperation,                //BXP-B-CR获取当前状态
    mk_cs_server_taskDismissBXPBCRAlarmStatusOperation,             //BXP-B-CR消警
    mk_cs_server_taskBxpBtnCRLedRemoteReminderOperation,            //BXP-B-CR控制LED
    mk_cs_server_taskBxpBtnCRBuzzerRemoteReminderOperation,         //BXP-B-CR控制蜂鸣器
    mk_cs_server_taskClearBXPButtonCREventCountOperation,           //BXP-B-CR删除触发记录
    mk_cs_server_taskBxpBtnCRNotifyAccDataOperation,                //BXP-B-CR监听三轴数据开关
    mk_cs_server_taskBxpBtnCRRemotePowerOffOperation,               //BXP-B-CR 远程关机
    mk_cs_server_taskBxpBtnCRVibratingRemoteReminderOperation,      //BXP-B-CR控制马达
    mk_cs_server_taskBXPCRNotifyAlarmDataOperation,                 //BXP-B-CR控制监听触发记录
    mk_cs_server_taskBxpBtnCRReadAdvParamsOperation,                //BXP-B-CR读取广播参数
    mk_cs_server_taskBxpBtnCRConfigAdvParamsOperation,              //BXP-B-CR配置广播参数
    
    
    mk_cs_server_taskConnectBXPCWithMacOperation,           //BXP-C 连接设备
    mk_cs_server_taskReadBXPCConnectedDeviceInfoOperation,  //BXP-C 读取设备信息
    mk_cs_server_taskReadBXPCStatusOperation,               //BXP-C 获取当前状态
    mk_cs_server_taskNotifyBXPCNotifyRealTimeHTDataOperation,   //控制实时温湿度数据监听开关
    mk_cs_server_taskBXPCNotifyAccDataOperation,                //BXP-C 实时三轴数据监听开关
    mk_cs_server_taskNotifyBXPCNotifyHistoricalHTDataOperation, //控制历史温湿度数据监听开关
    mk_cs_server_taskDeleteBXPCHistoricalHTDataOperation,           //清除历史温湿度数据
    mk_cs_server_taskBxpCPowerOffOperation,                 //BXP-C 远程关机
    mk_cs_server_taskReadBXPCTHDataSampleRateOperation,     //BXP-C 读取温湿度采样率
    mk_cs_server_taskConfigBXPCSampleRateOperation,         //BXP-C 配置温湿度采样率
    mk_cs_server_taskReadBXPCAdvParamsOperation,            //BXP-C 读取广播参数
    mk_cs_server_taskConfigBXPCAdvParamsOperation,          //BXP-C 配置广播参数
    
    mk_cs_server_taskConnectBXPDWithMacOperation,           //BXP-D 连接设备
    mk_cs_server_taskReadBXPDConnectedDeviceInfoOperation,  //BXP-D 读取设备信息
    mk_cs_server_taskReadBXPDStatusOperation,               //BXP-D 获取当前状态
    mk_cs_server_taskReadBXPDAccParamsOperation,            //BXP-D 读取三轴参数
    mk_cs_server_taskConfigBXPDAccParamsOperation,          //BXP-D 配置三轴参数
    mk_cs_server_taskBXPDNotifyAccDataOperation,            //BXP-D 实时三轴监听开关
    mk_cs_server_taskBxpDPowerOffOperation,                 //BXP-D 远程关机
    mk_cs_server_taskReadBXPDAdvParamsOperation,            //BXP-D 读取广播参数
    mk_cs_server_taskConfigBXPDAdvParamsOperation,          //BXP-D 配置广播参数
    
    mk_cs_server_taskConnectBXPTWithMacOperation,           //BXP-T 连接设备
    mk_cs_server_taskReadBXPTConnectedDeviceInfoOperation,  //BXP-T 读取设备信息
    mk_cs_server_taskReadBXPTStatusOperation,               //BXP-T 获取当前状态
    mk_cs_server_taskReadBXPTAccParamsOperation,            //BXP-T 读取三轴参数
    mk_cs_server_taskConfigBXPTAccParamsOperation,          //BXP-T 配置三轴参数
    mk_cs_server_taskReadBXPTMotioEventCountOperation,      //BXP-T 读取移动触发次数
    mk_cs_server_taskClearBXPTMotioEventCountOperation,     //BXP-T 清除移动触发次数
    mk_cs_server_taskBXPTLedRemoteReminderOperation,        //BXP-T 远程控制LED
    mk_cs_server_taskBXPTNotifyAccDataOperation,            //BXP-T 实时三轴监听开关
    mk_cs_server_taskBxpTPowerOffOperation,                 //BXP-T 远程关机
    mk_cs_server_taskReadBXPTAdvParamsOperation,            //BXP-T 读取广播参数
    mk_cs_server_taskConfigBXPTAdvParamsOperation,          //BXP-T 配置广播参数
    
    mk_cs_server_taskConnectBXPSWithMacOperation,           //BXP-C 连接设备
    mk_cs_server_taskReadBXPSConnectedDeviceInfoOperation,  //BXP-C 读取设备信息
    mk_cs_server_taskReadBXPSStatusOperation,               //BXP-C 获取当前状态
    mk_cs_server_taskNotifyBXPSNotifyRealTimeHTDataOperation,   //控制实时温湿度数据监听开关
    mk_cs_server_taskBXPSNotifyAccDataOperation,                //BXP-C 实时三轴数据监听开关
    mk_cs_server_taskNotifyBXPSNotifyHistoricalHTDataOperation, //控制历史温湿度数据监听开关
    mk_cs_server_taskDeleteBXPSHistoricalHTDataOperation,           //清除历史温湿度数据
    mk_cs_server_taskReadBXPSTHDataSampleRateOperation,     //BXP-S 读取温湿度采样率
    mk_cs_server_taskConfigBXPSSampleRateOperation,         //BXP-S 配置温湿度采样率
    mk_cs_server_taskReadBXPSHallCountOperation,            //BXP-S 读取hall触发次数
    mk_cs_server_taskClearBXPSHallCountOperation,           //BXP-S 清除hall触发次数
    mk_cs_server_taskBXPSLedRemoteReminderOperation,        //BXP-S 远程控制LED
    mk_cs_server_taskBXPSPowerOffOperation,                 //BXP-S 远程关机
    mk_cs_server_taskReadBXPSAdvParamsOperation,            //BXP-S 读取通道广播参数
    mk_cs_server_taskConfigBXPSAdvParamsOperation,          //BXP-S 配置通道广播参数
    
    mk_cs_server_taskConnectMKPirWithMacOperation,          //MK Pir 连接设备
    mk_cs_server_taskReadMKPirConnectedDeviceInfoOperation, //MK Pir 读取设备信息
    mk_cs_server_taskReadMKPirStatusOperation,              //MK Pir 获取当前状态
    mk_cs_server_taskNotifyMKPirSensorDataOperation,        //MK Pir 监听传感器数据
    mk_cs_server_taskReadMKPirSensorSensitivityOperation,   //MK Pir 读取灵敏度
    mk_cs_server_taskConfigMKPirSensorSensitivityOperation, //MK Pir 配置灵敏度
    mk_cs_server_taskReadMKPirSensorDelayOperation,         //MK Pir 读取延时状态
    mk_cs_server_taskConfigMKPirSensorDelayOperation,       //MK Pir 配置延时状态
    mk_cs_server_taskMKPirPowerOffOperation,                //MK Pir 远程关机
    mk_cs_server_taskReadMKPirAdvParamsOperation,           //MK Pir 读取广播参数
    mk_cs_server_taskConfigMKPirAdvParamsOperation,         //MK Pir 配置广播参数
    
    mk_cs_server_taskConnectMKTofWithMacOperation,          //MK Tof 连接设备
    mk_cs_server_taskReadMKTofConnectedDeviceInfoOperation, //MK Tof 读取设备信息
    mk_cs_server_taskReadMKTofStatusOperation,              //MK Tof 获取当前状态
    mk_cs_server_taskNotifyMKTofAccDataOperation,           //MK Tof 监听三轴数据
    mk_cs_server_taskMKTofPowerOffOperation,                //MK Tof 远程关机
    mk_cs_server_taskReadMKTofAdvParamsOperation,           //MK Tof 读取广播参数
    mk_cs_server_taskConfigMKTofAdvParamsOperation,         //MK Tof 配置广播参数
    mk_cs_server_taskReadMKTofSensorParamsOperation,        //MK Tof 读取采样参数
    mk_cs_server_taskConfigMKTofSensorParamsOperation,      //MK Tof 配置采样参数
    mk_cs_server_taskReadMKTofRangingModeOperation,         //MK Tof 读取距离模式
    mk_cs_server_taskConfigMKTofRangingModeOperation,       //MK Tof 配置距离模式
    mk_cs_server_taskNotifyMKTofSensorDataOperation,        //MK Tof 监听数据开关
    
    mk_cs_server_taskReadUploadDataIntervalOperation,           //读取数据上报间隔
    mk_cs_server_taskConfigUploadDataIntervalOperation,     //配置数据上报间隔
    
    mk_cs_server_taskReadBleCommunicateTimeoutOperation,    //读取蓝牙连接通信超时时间
    mk_cs_server_taskConfigBleCommunicateTimeoutOperation,  //配置蓝牙连接通信超时时间
};
