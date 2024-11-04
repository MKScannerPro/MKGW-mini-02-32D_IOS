
typedef NS_ENUM(NSInteger, mk_cs_centralConnectStatus) {
    mk_cs_centralConnectStatusUnknow,                                           //未知状态
    mk_cs_centralConnectStatusConnecting,                                       //正在连接
    mk_cs_centralConnectStatusConnected,                                        //连接成功
    mk_cs_centralConnectStatusConnectedFailed,                                  //连接失败
    mk_cs_centralConnectStatusDisconnect,
};

typedef NS_ENUM(NSInteger, mk_cs_centralManagerStatus) {
    mk_cs_centralManagerStatusUnable,                           //不可用
    mk_cs_centralManagerStatusEnable,                           //可用状态
};

typedef NS_ENUM(NSInteger, mk_cs_wifiSecurity) {
    mk_cs_wifiSecurity_personal,
    mk_cs_wifiSecurity_enterprise,
};

typedef NS_ENUM(NSInteger, mk_cs_eapType) {
    mk_cs_eapType_peap_mschapv2,
    mk_cs_eapType_ttls_mschapv2,
    mk_cs_eapType_tls,
};


typedef NS_ENUM(NSInteger, mk_cs_connectMode) {
    mk_cs_connectMode_TCP,                                          //TCP
    mk_cs_connectMode_CASignedServerCertificate,                    //SSL.Do not verify the server certificate.
    mk_cs_connectMode_CACertificate,                                //SSL.Verify the server's certificate
    mk_cs_connectMode_SelfSignedCertificates,                       //SSL.Two-way authentication
};

//Quality of MQQT service
typedef NS_ENUM(NSInteger, mk_cs_mqttServerQosMode) {
    mk_cs_mqttQosLevelAtMostOnce,      //At most once. The message sender to find ways to send messages, but an accident and will not try again.
    mk_cs_mqttQosLevelAtLeastOnce,     //At least once.If the message receiver does not know or the message itself is lost, the message sender sends it again to ensure that the message receiver will receive at least one, and of course, duplicate the message.
    mk_cs_mqttQosLevelExactlyOnce,     //Exactly once.Ensuring this semantics will reduce concurrency or increase latency, but level 2 is most appropriate when losing or duplicating messages is unacceptable.
};

typedef NS_ENUM(NSInteger, mk_cs_filterRelationship) {
    mk_cs_filterRelationship_null,
    mk_cs_filterRelationship_mac,
    mk_cs_filterRelationship_advName,
    mk_cs_filterRelationship_rawData,
    mk_cs_filterRelationship_advNameAndRawData,
    mk_cs_filterRelationship_macAndadvNameAndRawData,
    mk_cs_filterRelationship_advNameOrRawData,
    mk_cs_filterRelationship_advNameAndMacData,
};


@protocol mk_cs_centralManagerScanDelegate <NSObject>

/// Scan to new device.
/// @param deviceModel device
- (void)mk_cs_receiveDevice:(NSDictionary *)deviceModel;

@optional

/// Starts scanning equipment.
- (void)mk_cs_startScan;

/// Stops scanning equipment.
- (void)mk_cs_stopScan;

@end
