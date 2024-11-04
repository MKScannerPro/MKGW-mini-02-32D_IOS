

typedef NS_ENUM(NSInteger, mk_cs_taskOperationID) {
    mk_cs_defaultTaskOperationID,
    
#pragma mark - Read
    mk_cs_taskReadDeviceModelOperation,        //读取产品型号
    mk_cs_taskReadFirmwareOperation,           //读取固件版本
    mk_cs_taskReadHardwareOperation,           //读取硬件类型
    mk_cs_taskReadSoftwareOperation,           //读取软件版本
    mk_cs_taskReadManufacturerOperation,       //读取厂商信息
    
#pragma mark - 自定义协议读取
    mk_cs_taskReadDeviceNameOperation,         //读取设备名称
    mk_cs_taskReadDeviceMacAddressOperation,    //读取MAC地址
    mk_cs_taskReadDeviceWifiSTAMacAddressOperation, //读取WIFI STA MAC地址
    mk_cs_taskReadNTPServerHostOperation,       //读取NTP服务器域名
    mk_cs_taskReadTimeZoneOperation,            //读取时区
    
#pragma mark - Wifi Params
    mk_cs_taskReadWIFISecurityOperation,        //读取设备当前wifi的加密模式
    mk_cs_taskReadWIFISSIDOperation,            //读取设备当前的wifi ssid
    mk_cs_taskReadWIFIPasswordOperation,        //读取设备当前的wifi密码
    mk_cs_taskReadWIFIEAPTypeOperation,         //读取设备当前的wifi EAP类型
    mk_cs_taskReadWIFIEAPUsernameOperation,     //读取设备当前的wifi EAP用户名
    mk_cs_taskReadWIFIEAPPasswordOperation,     //读取设备当前的wifi EAP密码
    mk_cs_taskReadWIFIEAPDomainIDOperation,     //读取设备当前的wifi EAP域名ID
    mk_cs_taskReadWIFIVerifyServerStatusOperation,  //读取是否校验服务器
    mk_cs_taskReadWIFIDHCPStatusOperation,              //读取Wifi DHCP开关
    mk_cs_taskReadWIFINetworkIpInfosOperation,          //读取Wifi IP信息
    
#pragma mark - MQTT Params
    mk_cs_taskReadServerHostOperation,          //读取MQTT服务器域名
    mk_cs_taskReadServerPortOperation,          //读取MQTT服务器端口
    mk_cs_taskReadClientIDOperation,            //读取Client ID
    mk_cs_taskReadServerUserNameOperation,      //读取服务器登录用户名
    mk_cs_taskReadServerPasswordOperation,      //读取服务器登录密码
    mk_cs_taskReadServerCleanSessionOperation,  //读取MQTT Clean Session
    mk_cs_taskReadServerKeepAliveOperation,     //读取MQTT KeepAlive
    mk_cs_taskReadServerQosOperation,           //读取MQTT Qos
    mk_cs_taskReadSubscibeTopicOperation,       //读取Subscribe topic
    mk_cs_taskReadPublishTopicOperation,        //读取Publish topic
    mk_cs_taskReadLWTStatusOperation,           //读取LWT开关状态
    mk_cs_taskReadLWTQosOperation,              //读取LWT Qos
    mk_cs_taskReadLWTRetainOperation,           //读取LWT Retain
    mk_cs_taskReadLWTTopicOperation,            //读取LWT topic
    mk_cs_taskReadLWTPayloadOperation,          //读取LWT Payload
    mk_cs_taskReadConnectModeOperation,         //读取MTQQ服务器通信加密方式
    
#pragma mark - Filter Params
    mk_cs_taskReadRssiFilterValueOperation,             //读取扫描RSSI过滤
    mk_cs_taskReadFilterRelationshipOperation,          //读取扫描过滤逻辑
    mk_cs_taskReadFilterMACAddressListOperation,        //读取MAC过滤列表
    mk_cs_taskReadFilterAdvNameListOperation,           //读取ADV Name过滤列表
    
#pragma mark - iBeacon Params
    mk_cs_taskReadAdvertiseBeaconStatusOperation,       //读取iBeacon开关
    mk_cs_taskReadBeaconMajorOperation,                 //读取iBeacon major
    mk_cs_taskReadBeaconMinorOperation,                 //读取iBeacon minor
    mk_cs_taskReadBeaconUUIDOperation,                  //读取iBeacon UUID
    mk_cs_taskReadBeaconAdvIntervalOperation,           //读取Adv interval
    mk_cs_taskReadBeaconTxPowerOperation,               //读取Tx Power
    mk_cs_taskReadBeaconRssiOperation,                      //读取RSSI@1m
    
#pragma mark - 计电量参数
    mk_cs_taskReadMeteringSwitchOperation,              //读取计量数据上报开关
    mk_cs_taskReadPowerReportIntervalOperation,         //读取电量数据上报间隔
    mk_cs_taskReadEnergyReportIntervalOperation,        //读取电能数据上报间隔
    mk_cs_taskReadLoadDetectionNotificationStatusOperation, //读取负载检测通知开关
    
    
#pragma mark - 密码特征
    mk_cs_connectPasswordOperation,             //连接设备时候发送密码
    
#pragma mark - 配置
    mk_cs_taskEnterSTAModeOperation,                //设备重启进入STA模式
    mk_cs_taskConfigNTPServerHostOperation,         //配置NTP服务器域名
    mk_cs_taskConfigTimeZoneOperation,              //配置时区
    
#pragma mark - Wifi Params
    
    mk_cs_taskConfigWIFISecurityOperation,      //配置wifi的加密模式
    mk_cs_taskConfigWIFISSIDOperation,          //配置wifi的ssid
    mk_cs_taskConfigWIFIPasswordOperation,      //配置wifi的密码
    mk_cs_taskConfigWIFIEAPTypeOperation,       //配置wifi的EAP类型
    mk_cs_taskConfigWIFIEAPUsernameOperation,   //配置wifi的EAP用户名
    mk_cs_taskConfigWIFIEAPPasswordOperation,   //配置wifi的EAP密码
    mk_cs_taskConfigWIFIEAPDomainIDOperation,   //配置wifi的EAP域名ID
    mk_cs_taskConfigWIFIVerifyServerStatusOperation,    //配置wifi是否校验服务器
    mk_cs_taskConfigWIFICAFileOperation,                //配置WIFI CA证书
    mk_cs_taskConfigWIFIClientCertOperation,            //配置WIFI设备证书
    mk_cs_taskConfigWIFIClientPrivateKeyOperation,      //配置WIFI私钥
    mk_cs_taskConfigWIFIDHCPStatusOperation,                //配置Wifi DHCP开关
    mk_cs_taskConfigWIFIIpInfoOperation,                    //配置Wifi IP地址相关信息
    mk_cs_taskConfigNetworkTypeOperation,                   //配置网络接口类型
    mk_cs_taskConfigEthernetDHCPStatusOperation,            //配置Ethernet DHCP开关
    mk_cs_taskConfigEthernetIpInfoOperation,                //配置Ethernet IP地址相关信息
    
#pragma mark - MQTT Params
    mk_cs_taskConfigServerHostOperation,        //配置MQTT服务器域名
    mk_cs_taskConfigServerPortOperation,        //配置MQTT服务器端口
    mk_cs_taskConfigClientIDOperation,              //配置ClientID
    mk_cs_taskConfigServerUserNameOperation,        //配置服务器的登录用户名
    mk_cs_taskConfigServerPasswordOperation,        //配置服务器的登录密码
    mk_cs_taskConfigServerCleanSessionOperation,    //配置MQTT Clean Session
    mk_cs_taskConfigServerKeepAliveOperation,       //配置MQTT KeepAlive
    mk_cs_taskConfigServerQosOperation,             //配置MQTT Qos
    mk_cs_taskConfigSubscibeTopicOperation,         //配置Subscribe topic
    mk_cs_taskConfigPublishTopicOperation,          //配置Publish topic
    mk_cs_taskConfigLWTStatusOperation,             //配置LWT开关
    mk_cs_taskConfigLWTQosOperation,                //配置LWT Qos
    mk_cs_taskConfigLWTRetainOperation,             //配置LWT Retain
    mk_cs_taskConfigLWTTopicOperation,              //配置LWT topic
    mk_cs_taskConfigLWTPayloadOperation,            //配置LWT payload
    mk_cs_taskConfigConnectModeOperation,           //配置MTQQ服务器通信加密方式
    mk_cs_taskConfigCAFileOperation,                //配置CA证书
    mk_cs_taskConfigClientCertOperation,            //配置设备证书
    mk_cs_taskConfigClientPrivateKeyOperation,      //配置私钥
        
#pragma mark - 过滤参数
    mk_cs_taskConfigRssiFilterValueOperation,                   //配置扫描RSSI过滤
    mk_cs_taskConfigFilterRelationshipOperation,                //配置扫描过滤逻辑
    mk_cs_taskConfigFilterMACAddressListOperation,           //配置MAC过滤规则
    mk_cs_taskConfigFilterAdvNameListOperation,             //配置Adv Name过滤规则
    
#pragma mark - 蓝牙广播参数
    mk_cs_taskConfigAdvertiseBeaconStatusOperation,         //配置iBeacon开关
    mk_cs_taskConfigBeaconMajorOperation,                   //配置iBeacon major
    mk_cs_taskConfigBeaconMinorOperation,                   //配置iBeacon minor
    mk_cs_taskConfigBeaconUUIDOperation,                    //配置iBeacon UUID
    mk_cs_taskConfigAdvIntervalOperation,                   //配置广播频率
    mk_cs_taskConfigTxPowerOperation,                       //配置Tx Power
    mk_cs_taskConfigBeaconRssiOperation,                        //配置Beacon Rssi@1m
    
#pragma mark - 计电量参数
    mk_cs_taskConfigMeteringSwitchOperation,                //配置计量数据上报开关
    mk_cs_taskConfigPowerReportIntervalOperation,           //配置电量数据上报间隔
    mk_cs_taskConfigEnergyReportIntervalOperation,          //配置电能数据上报间隔
    mk_cs_taskConfigLoadDetectionNotificationStatusOperation,   //配置负载检测通知开关
};

