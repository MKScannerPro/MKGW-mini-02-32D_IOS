//
//  MKCSMQTTInterface.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MKCSMQTTConfigDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKCSMQTTInterface : NSObject

#pragma mark *********************Config************************

/// Reboot.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_rebootDeviceWithMacAddress:(NSString *)macAddress
                                topic:(NSString *)topic
                             sucBlock:(void (^)(id returnData))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;

/// Reset device by button.
/// @param type type
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configKeyResetType:(mk_cs_keyResetType)type
                   macAddress:(NSString *)macAddress
                        topic:(NSString *)topic
                     sucBlock:(void (^)(id returnData))sucBlock
                  failedBlock:(void (^)(NSError *error))failedBlock;

/// The reporting interval of the device's network status.
/// @param interval 0s or 30s ~ 86400s
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configNetworkStatusReportInterval:(NSInteger)interval
                                  macAddress:(NSString *)macAddress
                                       topic:(NSString *)topic
                                    sucBlock:(void (^)(id returnData))sucBlock
                                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Reconnect timeout.
/// @param timeout 0~1440 Mins.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configReconnectTimeout:(NSInteger)timeout
                       macAddress:(NSString *)macAddress
                            topic:(NSString *)topic
                         sucBlock:(void (^)(id returnData))sucBlock
                      failedBlock:(void (^)(NSError *error))failedBlock;

/// WIFI OTA.
/// @param filePath 1-256 Characters
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configOTAWithFilePath:(NSString *)filePath
                      macAddress:(NSString *)macAddress
                           topic:(NSString *)topic
                        sucBlock:(void (^)(id returnData))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the NTP server.
/// @param isOn isOn
/// @param host 0-64 Characters
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configNTPServer:(BOOL)isOn
                      host:(NSString *)host
                macAddress:(NSString *)macAddress
                     topic:(NSString *)topic
                  sucBlock:(void (^)(id returnData))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the UTC time zone of the device, and the device will reset the time according to the time zone.
/// @param timeZone Time Zone(-24~28,Unit:0.5)
/// @param timestamp timestamp
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configDeviceTimeZone:(NSInteger)timeZone
                      timestamp:(NSTimeInterval)timestamp
                     macAddress:(NSString *)macAddress
                          topic:(NSString *)topic
                       sucBlock:(void (^)(id returnData))sucBlock
                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Communication timeout.
/// @param timeout 0~60 Mins.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configCommunicationTimeout:(NSInteger)timeout
                           macAddress:(NSString *)macAddress
                                topic:(NSString *)topic
                             sucBlock:(void (^)(id returnData))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure indicator status.
/// @param protocol protocol.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configIndicatorLightStatus:(id <cs_indicatorLightStatusProtocol>)protocol
                           macAddress:(NSString *)macAddress
                                topic:(NSString *)topic
                             sucBlock:(void (^)(id returnData))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;

/// Reset.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_resetDeviceWithMacAddress:(NSString *)macAddress
                               topic:(NSString *)topic
                            sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

/// NPC OTA.
/// @param filePath 1-256 Characters
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configNpcOTAWithFilePath:(NSString *)filePath
                         macAddress:(NSString *)macAddress
                              topic:(NSString *)topic
                           sucBlock:(void (^)(id returnData))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Modify Wifi.
/// @param protocol protocol
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_modifyWifiInfos:(id <mk_cs_mqttModifyWifiProtocol>)protocol
                macAddress:(NSString *)macAddress
                     topic:(NSString *)topic
                  sucBlock:(void (^)(id returnData))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

/// EAP certificate update.
/// @param protocol protocol
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_modifyWifiCerts:(id <mk_cs_mqttModifyWifiEapCertProtocol>)protocol
                macAddress:(NSString *)macAddress
                     topic:(NSString *)topic
                  sucBlock:(void (^)(id returnData))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

/// Network Settings.
/// @param protocol protocol
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_modifyNetworkInfos:(id <mk_cs_mqttModifyNetworkProtocol>)protocol
                   macAddress:(NSString *)macAddress
                        topic:(NSString *)topic
                     sucBlock:(void (^)(id returnData))sucBlock
                  failedBlock:(void (^)(NSError *error))failedBlock;

/// MQTT Settings.
/// @param protocol protocol
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_modifyMqttInfos:(id <mk_cs_modifyMqttServerProtocol>)protocol
                macAddress:(NSString *)macAddress
                     topic:(NSString *)topic
                  sucBlock:(void (^)(id returnData))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

/// MQTT certificate update.
/// @param protocol protocol
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_modifyMqttCerts:(id <mk_cs_modifyMqttServerCertsProtocol>)protocol
                macAddress:(NSString *)macAddress
                     topic:(NSString *)topic
                  sucBlock:(void (^)(id returnData))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;

/// Config scan status.
/// @param isOn isOn
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configScanSwitchStatus:(BOOL)isOn
                       macAddress:(NSString *)macAddress
                            topic:(NSString *)topic
                         sucBlock:(void (^)(id returnData))sucBlock
                      failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure the filter relationship.
/// @param relationship relationship
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterRelationship:(mk_cs_filterRelationship)relationship
                         macAddress:(NSString *)macAddress
                              topic:(NSString *)topic
                           sucBlock:(void (^)(id returnData))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by RSSI
/// @param rssi -127dBm~0dBm
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByRSSI:(NSInteger)rssi
                   macAddress:(NSString *)macAddress
                        topic:(NSString *)topic
                     sucBlock:(void (^)(id returnData))sucBlock
                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by MAC Address.
/// @param macList The filtered mac address list contains up to 10 filtering options, and the length of each option should be 1 to 6 bytes of hexadecimal data.If the number is 0, it means that the historical configuration data is cleared.
/// @param preciseMatch Precise Match is On.
/// @param reverseFilter Reverse Filter is On.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByMacAddress:(nonnull NSArray <NSString *>*)macList
                       preciseMatch:(BOOL)preciseMatch
                      reverseFilter:(BOOL)reverseFilter
                         macAddress:(NSString *)macAddress
                              topic:(NSString *)topic
                           sucBlock:(void (^)(id returnData))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by ADV Name.
/// @param nameList The list of filtered device broadcast names contains up to 10 filtering options, and each option should be 1-20 characters in length. If the incoming number is zero, it means that the filter options are cleared.
/// @param preciseMatch Precise Match is On.
/// @param reverseFilter Reverse Filter is On.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByADVName:(nonnull NSArray <NSString *>*)nameList
                    preciseMatch:(BOOL)preciseMatch
                   reverseFilter:(BOOL)reverseFilter
                      macAddress:(NSString *)macAddress
                           topic:(NSString *)topic
                        sucBlock:(void (^)(id returnData))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by iBeacon.
/// @param isOn isOn
/// @param minMinor 0~65535
/// @param maxMinor minMinor <= maxMinor < 65535
/// @param minMajor 0~65535
/// @param maxMajor minMajor <= maxMajor < 65535
/// @param uuid 0~16 Bytes.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByBeacon:(BOOL)isOn
                       minMinor:(NSInteger)minMinor
                       maxMinor:(NSInteger)maxMinor
                       minMajor:(NSInteger)minMajor
                       maxMajor:(NSInteger)maxMajor
                           uuid:(NSString *)uuid
                     macAddress:(NSString *)macAddress
                          topic:(NSString *)topic
                       sucBlock:(void (^)(id returnData))sucBlock
                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by UID Data.
/// @param isOn isOn
/// @param namespaceID 0~10 Bytes.
/// @param instanceID 0~6 Bytes.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByUID:(BOOL)isOn
                 namespaceID:(NSString *)namespaceID
                  instanceID:(NSString *)instanceID
                  macAddress:(NSString *)macAddress
                       topic:(NSString *)topic
                    sucBlock:(void (^)(id returnData))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by URL Data.
/// @param isOn isOn
/// @param url 0-37 Characters
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByURL:(BOOL)isOn
                         url:(NSString *)url
                  macAddress:(NSString *)macAddress
                       topic:(NSString *)topic
                    sucBlock:(void (^)(id returnData))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by TLM Data.
/// @param isOn isOn
/// @param tlm tlm
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByTLM:(BOOL)isOn
                         tlm:(mk_cs_filterByTLM)tlm
                  macAddress:(NSString *)macAddress
                       topic:(NSString *)topic
                    sucBlock:(void (^)(id returnData))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter switch status of BXP-DeviceInfo.
/// @param isOn isOn
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterFilterBXPDeviceInfo:(BOOL)isOn
                                macAddress:(NSString *)macAddress
                                     topic:(NSString *)topic
                                  sucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter switch status of BXP-ACC.
/// @param isOn isOn
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterBXPAcc:(BOOL)isOn
                   macAddress:(NSString *)macAddress
                        topic:(NSString *)topic
                     sucBlock:(void (^)(id returnData))sucBlock
                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter switch status of BXP-TH.
/// @param isOn isOn
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterBXPTH:(BOOL)isOn
                  macAddress:(NSString *)macAddress
                       topic:(NSString *)topic
                    sucBlock:(void (^)(id returnData))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter By BXP-Button.
/// @param protocol protocol
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterBXPButton:(id <mk_cs_BLEFilterBXPButtonProtocol>)protocol
                      macAddress:(NSString *)macAddress
                           topic:(NSString *)topic
                        sucBlock:(void (^)(id returnData))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by BXP-Tag.
/// @param isOn isOn
/// @param preciseMatch Precise Match is On.
/// @param reverseFilter Reverse Filter is On.
/// @param tagIDList The filtered tag ID list contains up to 10 filtering options, and the length of each option should be 1 to 6 bytes of hexadecimal data.If the number is 0, it means that the historical configuration data is cleared.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByTag:(BOOL)isOn
                preciseMatch:(BOOL)preciseMatch
               reverseFilter:(BOOL)reverseFilter
                   tagIDList:(NSArray <NSString *>*)tagIDList
                  macAddress:(NSString *)macAddress
                       topic:(NSString *)topic
                    sucBlock:(void (^)(id returnData))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter By PIR Presence.
/// @param protocol protocol
/// @param minMinor 0~65535
/// @param maxMinor minMinor <= maxMinor < 65535
/// @param minMajor 0~65535
/// @param maxMajor minMajor <= maxMajor < 65535
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByPir:(id <mk_cs_BLEFilterPirProtocol>)protocol
                    minMinor:(NSInteger)minMinor
                    maxMinor:(NSInteger)maxMinor
                    minMajor:(NSInteger)minMajor
                    maxMajor:(NSInteger)maxMajor
                  macAddress:(NSString *)macAddress
                       topic:(NSString *)topic
                    sucBlock:(void (^)(id returnData))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by Other Raw Data.
/// @param isOn isOn
/// @param relationship The relationship changes with the original filter condition. If the original filter condition is empty, the relationship does not take effect; if the filter condition is 1, the relationship can only fill in mk_cs_filterByOther_A; if the filter condition is 2, you can choose mk_cs_filterByOther_AB/mk_cs_filterByOther_AOrB; If there are 3, select mk_cs_filterByOther_ABC/mk_cs_filterByOther_ABOrC/mk_cs_filterByOther_AOrBOrC.
/// @param rawDataList rawDataList
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByOtherDatas:(BOOL)isOn
                       relationship:(mk_cs_filterByOther)relationship
                        rawDataList:(NSArray <mk_cs_BLEFilterRawDataProtocol>*)rawDataList
                         macAddress:(NSString *)macAddress
                              topic:(NSString *)topic
                           sucBlock:(void (^)(id returnData))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure scan duplicate data parameters.(V1 version)
/// @param filter filter
/// @param strategy strategy
/// @param period 1s~86400s
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configDuplicateDataFilter:(mk_cs_duplicateDataFilter)filter
                            strategy:(mk_cs_duplicateDataFilterStrategy)strategy
                              period:(long long)period
                          macAddress:(NSString *)macAddress
                               topic:(NSString *)topic
                            sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Data report timeout.
/// @param timeout 100ms ~ 3000ms
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configDataReportTimeout:(NSInteger)timeout
                        macAddress:(NSString *)macAddress
                             topic:(NSString *)topic
                          sucBlock:(void (^)(id returnData))sucBlock
                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure scan data report content options.
/// @param protocol protocol
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configUploadDataOption:(id <cs_uploadDataOptionProtocol>)protocol
                       macAddress:(NSString *)macAddress
                            topic:(NSString *)topic
                         sucBlock:(void (^)(id returnData))sucBlock
                      failedBlock:(void (^)(NSError *error))failedBlock;

/// The gateway connects to the BXP-Button with the specified MAC address.
/// @param password 0-16 Characters
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectBXPButtonWithPassword:(NSString *)password
                                 bleMac:(NSString *)bleMacAddress
                             macAddress:(NSString *)macAddress
                                  topic:(NSString *)topic
                               sucBlock:(void (^)(id returnData))sucBlock
                            failedBlock:(void (^)(NSError *error))failedBlock;

/// The gateway disconnect the Bluetooth device with the specified MAC address.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_disconnectNormalBleDeviceWithBleMac:(NSString *)bleMacAddress
                                    macAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-Button DFU.
/// @param firmwareUrl Firmware file URL.1- 256 Characters.
/// @param dataUrl Init data file URL.1- 256 Characters.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_startBXPButtonDfuWithFirmwareUrl:(NSString *)firmwareUrl
                                    dataUrl:(NSString *)dataUrl
                                     bleMac:(NSString *)bleMacAddress
                                 macAddress:(NSString *)macAddress
                                      topic:(NSString *)topic
                                   sucBlock:(void (^)(id returnData))sucBlock
                                failedBlock:(void (^)(NSError *error))failedBlock;


/// The gateway connects to the Bluetooth device with the specified MAC address.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectNormalBleDeviceWithBleMac:(NSString *)bleMacAddress
                                 macAddress:(NSString *)macAddress
                                      topic:(NSString *)topic
                                   sucBlock:(void (^)(id returnData))sucBlock
                                failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP DFU(V2).
/// @param type 1:BXP-B-D   2:BXP-B-CR  3:BXP-C 4:BXP-D 5:BXP-TAG   6:BXP-S 7:PIR   8:TOF
/// @param firmwareUrl Firmware file URL.1- 256 Characters.
/// @param dataUrl Init data file URL.1- 256 Characters.
/// @param dfuList @[@{@"mac":"aabbccddeeff",@"password":@"xxxx"}]
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_startBXPDfuWithBeaconType:(NSInteger)type
                         firmwareUrl:(NSString *)firmwareUrl
                             dataUrl:(NSString *)dataUrl
                             dfuList:(NSArray <NSDictionary *>*)dfuList
                          macAddress:(NSString *)macAddress
                               topic:(NSString *)topic
                            sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************Read************************

/// Reset device by button.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readKeyResetTypeWithMacAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// Reset device Infomation.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readDeviceInfoWithMacAddress:(NSString *)macAddress
                                  topic:(NSString *)topic
                               sucBlock:(void (^)(id returnData))sucBlock
                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the reporting interval of the device's network status.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readNetworkStatusReportIntervalWithMacAddress:(NSString *)macAddress
                                                   topic:(NSString *)topic
                                                sucBlock:(void (^)(id returnData))sucBlock
                                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Reconnect Timeout.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readNetworkReconnectTimeoutWithMacAddress:(NSString *)macAddress
                                               topic:(NSString *)topic
                                            sucBlock:(void (^)(id returnData))sucBlock
                                         failedBlock:(void (^)(NSError *error))failedBlock;
/// NTP Server.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readNTPServerWithMacAddress:(NSString *)macAddress
                                 topic:(NSString *)topic
                              sucBlock:(void (^)(id returnData))sucBlock
                           failedBlock:(void (^)(NSError *error))failedBlock;

/// UTC Time.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readDeviceUTCTimeWithMacAddress:(NSString *)macAddress
                                     topic:(NSString *)topic
                                  sucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

/// Communicate Timeout.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readCommunicateTimeoutWithMacAddress:(NSString *)macAddress
                                          topic:(NSString *)topic
                                       sucBlock:(void (^)(id returnData))sucBlock
                                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Indicator Status
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readIndicatorLightStatusWithMacAddress:(NSString *)macAddress
                                            topic:(NSString *)topic
                                         sucBlock:(void (^)(id returnData))sucBlock
                                      failedBlock:(void (^)(NSError *error))failedBlock;

/// Query whether the device can perform OTA upgrade.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readOtaStatusWithMacAddress:(NSString *)macAddress
                                 topic:(NSString *)topic
                              sucBlock:(void (^)(id returnData))sucBlock
                           failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the wifi information that the device is currently connected to.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readWifiInfosWithMacAddress:(NSString *)macAddress
                                 topic:(NSString *)topic
                              sucBlock:(void (^)(id returnData))sucBlock
                           failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the network information that the device is currently connected to.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readNetworkInfosWithMacAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the MQTT Params.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMQTTParamsWithMacAddress:(NSString *)macAddress
                                  topic:(NSString *)topic
                               sucBlock:(void (^)(id returnData))sucBlock
                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Read scan status.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readScanSwitchStatusWithMacAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter Relationship.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterRelationshipWithMacAddress:(NSString *)macAddress
                                          topic:(NSString *)topic
                                       sucBlock:(void (^)(id returnData))sucBlock
                                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by Mac.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByRSSIWithMacAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by MAC Address.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByMacWithMacAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by ADV Name.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByADVNameWithMacAddress:(NSString *)macAddress
                                       topic:(NSString *)topic
                                    sucBlock:(void (^)(id returnData))sucBlock
                                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by Raw Data Status.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByRawDataStatusWithMacAddress:(NSString *)macAddress
                                             topic:(NSString *)topic
                                          sucBlock:(void (^)(id returnData))sucBlock
                                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by iBeacon.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByBeaconWithMacAddress:(NSString *)macAddress
                                      topic:(NSString *)topic
                                   sucBlock:(void (^)(id returnData))sucBlock
                                failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by UID.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByUIDWithMacAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by Url.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByUrlWithMacAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by TLM.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByTLMWithMacAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter switch status of BXP-DeviceInfo.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterBXPDeviceInfoStatusWithMacAddress:(NSString *)macAddress
                                                 topic:(NSString *)topic
                                              sucBlock:(void (^)(id returnData))sucBlock
                                           failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter switch status of BXP-Acc.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterBXPAccStatusWithMacAddress:(NSString *)macAddress
                                          topic:(NSString *)topic
                                       sucBlock:(void (^)(id returnData))sucBlock
                                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter switch status of BXP-TH.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterBXPTHStatusWithMacAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter By BXP-Button.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterBXPButtonWithMacAddress:(NSString *)macAddress
                                       topic:(NSString *)topic
                                    sucBlock:(void (^)(id returnData))sucBlock
                                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter By BXP-Tag.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterBXPTagWithMacAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter By PIR Presence.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByPirWithMacAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by Other Raw Data.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterOtherDatasWithMacAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Read scan duplicate data parameters.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readDuplicateDataFilterDatasWithMacAddress:(NSString *)macAddress
                                                topic:(NSString *)topic
                                             sucBlock:(void (^)(id returnData))sucBlock
                                          failedBlock:(void (^)(NSError *error))failedBlock;

/// Data report timeout.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readDataReportTimeoutWithMacAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// Read scan data report content option.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readUploadDataOptionWithMacAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by MK-TOF.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByTofWithMacAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Filtered list of TOF List.
/// @param codeList You can set up to 10 filters.2 Bytes.
/// @param isOn Filter Status.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByTofList:(NSArray <NSString *>*)codeList
                            isOn:(BOOL)isOn
                      macAddress:(NSString *)macAddress
                           topic:(NSString *)topic
                        sucBlock:(void (^)(id returnData))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by PHY.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readFilterByPhyWithMacAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Filter by PHY.
/// @param phy phy.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configFilterByPhy:(mk_cs_PHYMode)phy
                  macAddress:(NSString *)macAddress
                       topic:(NSString *)topic
                    sucBlock:(void (^)(id returnData))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Data Upload Interval.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readUploadDataIntervalWithMacAddress:(NSString *)macAddress
                                          topic:(NSString *)topic
                                       sucBlock:(void (^)(id returnData))sucBlock
                                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Data Upload Interval.
/// @param interval 0~86400s
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configUploadDataInterval:(NSInteger)interval
                         macAddress:(NSString *)macAddress
                              topic:(NSString *)topic
                           sucBlock:(void (^)(id returnData))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Configure scan duplicate data parameters.(V2 version)
/// @param filter filter
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configDuplicateDataFilter:(mk_cs_duplicateDataFilter)filter
                          macAddress:(NSString *)macAddress
                               topic:(NSString *)topic
                            sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************  BXP-B-D  ************************

/// Read the service and feature information of the specified BXP-Button connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPButtonConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                                  macAddress:(NSString *)macAddress
                                                       topic:(NSString *)topic
                                                    sucBlock:(void (^)(id returnData))sucBlock
                                                 failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-Button's status that connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPButtonConnectedStatusWithBleMacAddress:(NSString *)bleMacAddress
                                              macAddress:(NSString *)macAddress
                                                   topic:(NSString *)topic
                                                sucBlock:(void (^)(id returnData))sucBlock
                                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Dismiss Alarm Status.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_dismissBXPButtonAlarmStatusWithBleMacAddress:(NSString *)bleMacAddress
                                             macAddress:(NSString *)macAddress
                                                  topic:(NSString *)topic
                                               sucBlock:(void (^)(id returnData))sucBlock
                                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Query whether the Bluetooth gateway is connected to the device.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readGatewayBleConnectStatusWithMacAddress:(NSString *)macAddress
                                               topic:(NSString *)topic
                                            sucBlock:(void (^)(id returnData))sucBlock
                                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the service and feature information of the specified device connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readNormalConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                               macAddress:(NSString *)macAddress
                                                    topic:(NSString *)topic
                                                 sucBlock:(void (^)(id returnData))sucBlock
                                              failedBlock:(void (^)(NSError *error))failedBlock;
/// Whether to open the characteristic's monitoring.
/// @param notify notify
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param serviceUUID serviceUUID
/// @param characteristicUUID characteristicUUID
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_notifyCharacteristic:(BOOL)notify
                  bleMacAddress:(NSString *)bleMacAddress
                    serviceUUID:(NSString *)serviceUUID
             characteristicUUID:(NSString *)characteristicUUID
                     macAddress:(NSString *)macAddress
                          topic:(NSString *)topic
                       sucBlock:(void (^)(id returnData))sucBlock
                    failedBlock:(void (^)(NSError *error))failedBlock;


/// Read the characteristic value of the connected device with the specified mac address.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param serviceUUID serviceUUID
/// @param characteristicUUID characteristicUUID
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readCharacteristicValueWithBleMacAddress:(NSString *)bleMacAddress
                                        serviceUUID:(NSString *)serviceUUID
                                 characteristicUUID:(NSString *)characteristicUUID
                                         macAddress:(NSString *)macAddress
                                              topic:(NSString *)topic
                                           sucBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Writes a value to the characteristic of the connected device for the specified mac address.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param value value(Byte)
/// @param serviceUUID serviceUUID
/// @param characteristicUUID characteristicUUID
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_writeValueToDeviceWithBleMacAddress:(NSString *)bleMacAddress
                                         value:(NSString *)value
                                   serviceUUID:(NSString *)serviceUUID
                            characteristicUUID:(NSString *)characteristicUUID
                                    macAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;




/// Advertise iBeacon.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readAdvertiseBeaconParamsWithMacAddress:(NSString *)macAddress
                                             topic:(NSString *)topic
                                          sucBlock:(void (^)(id returnData))sucBlock
                                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Advertise iBeacon.
/// @param protocol protocol.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configAdvertiseBeaconParams:(id <cs_advertiseBeaconProtocol>)protocol
                            macAddress:(NSString *)macAddress
                                 topic:(NSString *)topic
                              sucBlock:(void (^)(id returnData))sucBlock
                           failedBlock:(void (^)(NSError *error))failedBlock;

/// Advertise iBeacon for V2.
/// @param protocol protocol.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configV2AdvertiseBeaconParams:(id <cs_advertiseBeaconV2Protocol>)protocol
                              macAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Clear trigger event count.
/// @param eventType eventType.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_clearTriggerEventCount:(mk_cs_triggerEventType)eventType
                           bleMac:(NSString *)bleMacAddress
                       macAddress:(NSString *)macAddress
                            topic:(NSString *)topic
                         sucBlock:(void (^)(id returnData))sucBlock
                      failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-D LED Remote Reminder.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param blinkingTime flash time, 1 x 100ms ~ 6000 x 100ms.
/// @param blinkingInterval flash interval, 0 x 100ms ~ 100 x 100ms.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnLedRemoteReminderWithBleMac:(NSString *)bleMacAddress
                                blinkingTime:(NSInteger)blinkingTime
                            blinkingInterval:(NSInteger)blinkingInterval
                                  macAddress:(NSString *)macAddress
                                       topic:(NSString *)topic
                                    sucBlock:(void (^)(id returnData))sucBlock
                                 failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-D Buzzer Remote Reminder.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param ringTime ring time, 1 x 100ms ~ 6000 x 100ms.
/// @param ringInterval ring interval, 0 x 100ms ~ 100 x 100ms.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnBuzzerRemoteReminderWithBleMac:(NSString *)bleMacAddress
                                       ringTime:(NSInteger)ringTime
                                   ringInterval:(NSInteger)ringInterval
                                     macAddress:(NSString *)macAddress
                                          topic:(NSString *)topic
                                       sucBlock:(void (^)(id returnData))sucBlock
                                    failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-D notify Acc Data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnNotifyAccDataWithBleMac:(NSString *)bleMacAddress
                                  notify:(BOOL)notify
                              macAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-D remote power off.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnRemotePowerOffWithBleMac:(NSString *)bleMacAddress
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-D Advertisement parameters.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnReadAdvParamsWithBleMac:(NSString *)bleMacAddress
                              macAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-D Advertisement parameters.
/// @param params Adv Params.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnConfigAdvParamsWithParams:(NSDictionary *)params
                                    bleMac:(NSString *)bleMacAddress
                                macAddress:(NSString *)macAddress
                                     topic:(NSString *)topic
                                  sucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************  BXP-B-CR  ************************

/// The gateway connects to the BXP-Button-CR with the specified MAC address.
/// @param password 0-16 Characters
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectBXPButtonCRWithPassword:(NSString *)password
                                   bleMac:(NSString *)bleMacAddress
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the service and feature information of the specified BXP-Button-CR connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPButtonCRConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                                    macAddress:(NSString *)macAddress
                                                         topic:(NSString *)topic
                                                      sucBlock:(void (^)(id returnData))sucBlock
                                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-Button-CR's status that connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPButtonCRConnectedStatusWithBleMacAddress:(NSString *)bleMacAddress
                                                macAddress:(NSString *)macAddress
                                                     topic:(NSString *)topic
                                                  sucBlock:(void (^)(id returnData))sucBlock
                                               failedBlock:(void (^)(NSError *error))failedBlock;

/// Dismiss BXP-B-CR Alarm Status.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_dismissBXPButtonCRAlarmStatusWithBleMacAddress:(NSString *)bleMacAddress
                                               macAddress:(NSString *)macAddress
                                                    topic:(NSString *)topic
                                                 sucBlock:(void (^)(id returnData))sucBlock
                                              failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-CR LED Remote Reminder.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param blinkingTime flash time, 1 x 100ms ~ 6000 x 100ms.
/// @param blinkingInterval flash interval, 0 x 100ms ~ 100 x 100ms.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnCRLedRemoteReminderWithBleMac:(NSString *)bleMacAddress
                                  blinkingTime:(NSInteger)blinkingTime
                              blinkingInterval:(NSInteger)blinkingInterval
                                    macAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-CR Buzzer Remote Reminder.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param ringTime ring time, 1 x 100ms ~ 6000 x 100ms.
/// @param ringInterval ring interval, 0 x 100ms ~ 100 x 100ms.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnCRBuzzerRemoteReminderWithBleMac:(NSString *)bleMacAddress
                                         ringTime:(NSInteger)ringTime
                                     ringInterval:(NSInteger)ringInterval
                                       macAddress:(NSString *)macAddress
                                            topic:(NSString *)topic
                                         sucBlock:(void (^)(id returnData))sucBlock
                                      failedBlock:(void (^)(NSError *error))failedBlock;

/// Clear the  BXP-Button-CR's event counts that connected to the current gateway.
/// @param type 0:clear the single press event count    1:clear the double press event count    2:clear the long press event count
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_clearBXPButtonCREventCountWithType:(mk_cs_triggerEventType)type
                                bleMacAddress:(NSString *)bleMacAddress
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-CR notify Acc Data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnCRNotifyAccDataWithBleMac:(NSString *)bleMacAddress
                                    notify:(BOOL)notify
                                macAddress:(NSString *)macAddress
                                     topic:(NSString *)topic
                                  sucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-CR remote power off.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnCRRemotePowerOffWithBleMac:(NSString *)bleMacAddress
                                 macAddress:(NSString *)macAddress
                                      topic:(NSString *)topic
                                   sucBlock:(void (^)(id returnData))sucBlock
                                failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-CR Vibrating Remote Reminder.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param vibratingTime vibrating time, 1 x 100ms ~ 6000 x 100ms.
/// @param vibratingInterval vibrating interval, 0 x 100ms ~ 100 x 100ms.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnCRVibratingRemoteReminderWithBleMac:(NSString *)bleMacAddress
                                       vibratingTime:(NSInteger)vibratingTime
                                   vibratingInterval:(NSInteger)vibratingInterval
                                          macAddress:(NSString *)macAddress
                                               topic:(NSString *)topic
                                            sucBlock:(void (^)(id returnData))sucBlock
                                         failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-CR notify Alarm Event Data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param alarmEventType  mk_cs_bxpcrAlarmEventType
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_BXPCRNotifyAlarmDataWithBleMac:(NSString *)bleMacAddress
                           alarmEventType:(mk_cs_bxpcrAlarmEventType)alarmEventType
                                   notify:(BOOL)notify
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-CR Advertisement parameters.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnCRReadAdvParamsWithBleMac:(NSString *)bleMacAddress
                                macAddress:(NSString *)macAddress
                                     topic:(NSString *)topic
                                  sucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-B-CR Advertisement parameters.
/// @param params Adv Params.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBtnCRConfigAdvParamsWithParams:(NSDictionary *)params
                                      bleMac:(NSString *)bleMacAddress
                                  macAddress:(NSString *)macAddress
                                       topic:(NSString *)topic
                                    sucBlock:(void (^)(id returnData))sucBlock
                                 failedBlock:(void (^)(NSError *error))failedBlock;


#pragma mark *********************  BXP-C  ************************
/// The gateway connects to the BXP-C with the specified MAC address.
/// @param password 0-16 Characters
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectBXPCWithPassword:(NSString *)password
                            bleMac:(NSString *)bleMacAddress
                        macAddress:(NSString *)macAddress
                             topic:(NSString *)topic
                          sucBlock:(void (^)(id returnData))sucBlock
                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the service and feature information of the specified BXP-C connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPCConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                             macAddress:(NSString *)macAddress
                                                  topic:(NSString *)topic
                                               sucBlock:(void (^)(id returnData))sucBlock
                                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-C's status that connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPCConnectedStatusWithBleMacAddress:(NSString *)bleMacAddress
                                         macAddress:(NSString *)macAddress
                                              topic:(NSString *)topic
                                           sucBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-C notify Real Time HT Datas.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPCNotifyRealTimeHTDataWithBleMac:(NSString *)bleMacAddress
                                          notify:(BOOL)notify
                                      macAddress:(NSString *)macAddress
                                           topic:(NSString *)topic
                                        sucBlock:(void (^)(id returnData))sucBlock
                                     failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-C notify Acc Data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPCNotifyAccDataWithBleMac:(NSString *)bleMacAddress
                                   notify:(BOOL)notify
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-D notify Historical HT Datas.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPCNotifyHistoricalHTDataWithBleMac:(NSString *)bleMacAddress
                                            notify:(BOOL)notify
                                        macAddress:(NSString *)macAddress
                                             topic:(NSString *)topic
                                          sucBlock:(void (^)(id returnData))sucBlock
                                       failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-D delete Historical HT Datas.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPCDeleteHistoricalHTDataWithBleMac:(NSString *)bleMacAddress
                                        macAddress:(NSString *)macAddress
                                             topic:(NSString *)topic
                                          sucBlock:(void (^)(id returnData))sucBlock
                                       failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-C remote power off.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPCPowerOffWithBleMac:(NSString *)bleMacAddress
                          macAddress:(NSString *)macAddress
                               topic:(NSString *)topic
                            sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-C's H&T datas sample rate.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPCTHDataSampleRateWithBleMacAddress:(NSString *)bleMacAddress
                                          macAddress:(NSString *)macAddress
                                               topic:(NSString *)topic
                                            sucBlock:(void (^)(id returnData))sucBlock
                                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Config the  BXP-C's H&T datas sample rate.
/// @param sampleRate 1s~65535s
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBXPCSampleRate:(NSInteger)sampleRate
                         bleMac:(NSString *)bleMacAddress
                     macAddress:(NSString *)macAddress
                          topic:(NSString *)topic
                       sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-C's advertising paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPCAdvParamsWithBleMacAddress:(NSString *)bleMacAddress
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-C Advertisement parameters.
/// @param channel 0~5.
/// @param interval advterisment interval. 1 x 100ms ~ 100 x 100ms.
/// @param txPower 0~9:
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBXPCAdvParamsWithChannel:(NSInteger)channel
                                 interval:(NSInteger)interval
                                  txPower:(NSInteger)txPower
                                   bleMac:(NSString *)bleMacAddress
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************  BXP-D  ************************
/// The gateway connects to the BXP-D with the specified MAC address.
/// @param password 0-16 Characters
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectBXPDWithPassword:(NSString *)password
                            bleMac:(NSString *)bleMacAddress
                        macAddress:(NSString *)macAddress
                             topic:(NSString *)topic
                          sucBlock:(void (^)(id returnData))sucBlock
                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the service and feature information of the specified BXP-D connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPDConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                             macAddress:(NSString *)macAddress
                                                  topic:(NSString *)topic
                                               sucBlock:(void (^)(id returnData))sucBlock
                                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-D's status that connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPDConnectedStatusWithBleMacAddress:(NSString *)bleMacAddress
                                         macAddress:(NSString *)macAddress
                                              topic:(NSString *)topic
                                           sucBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-D's Accelerometer paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPDAccParamsWithBleMacAddress:(NSString *)bleMacAddress
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Config the  BXP-D's Accelerometer paramters which is connected by the current gateway.
/// @param scale scale
/// @param sampleRate sampleRate
/// @param sensitivity If the scale is mk_cs_threeAxisDataAG0, the range is 1~20.If the scale is mk_cs_threeAxisDataAG1, the range is 1~40.If the scale is mk_cs_threeAxisDataAG2, the range is 1~80.If the scale is mk_cs_threeAxisDataAG3, the range is 1~160.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBXPDAccParamsWithScale:(mk_cs_threeAxisDataAG)scale
                             sampleRate:(mk_cs_threeAxisDataRate)sampleRate
                            sensitivity:(NSInteger)sensitivity
                                 bleMac:(NSString *)bleMacAddress
                             macAddress:(NSString *)macAddress
                                  topic:(NSString *)topic
                               sucBlock:(void (^)(id returnData))sucBlock
                            failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-D notify Acc Data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPDNotifyAccDataWithBleMac:(NSString *)bleMacAddress
                                   notify:(BOOL)notify
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-D remote power off.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPDPowerOffWithBleMac:(NSString *)bleMacAddress
                          macAddress:(NSString *)macAddress
                               topic:(NSString *)topic
                            sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-D's advertising paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPDAdvParamsWithBleMacAddress:(NSString *)bleMacAddress
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-D Advertisement parameters.
/// @param channel 0~5.
/// @param interval advterisment interval. 1 x 100ms ~ 100 x 100ms.
/// @param txPower 0~9:
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBXPDAdvParamsWithChannel:(NSInteger)channel
                                 interval:(NSInteger)interval
                                  txPower:(NSInteger)txPower
                                   bleMac:(NSString *)bleMacAddress
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************  BXP-T  ************************
/// The gateway connects to the BXP-T with the specified MAC address.
/// @param password 0-16 Characters
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectBXPTWithPassword:(NSString *)password
                            bleMac:(NSString *)bleMacAddress
                        macAddress:(NSString *)macAddress
                             topic:(NSString *)topic
                          sucBlock:(void (^)(id returnData))sucBlock
                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the service and feature information of the specified BXP-T connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPTConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                             macAddress:(NSString *)macAddress
                                                  topic:(NSString *)topic
                                               sucBlock:(void (^)(id returnData))sucBlock
                                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-T's status that connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPTConnectedStatusWithBleMacAddress:(NSString *)bleMacAddress
                                         macAddress:(NSString *)macAddress
                                              topic:(NSString *)topic
                                           sucBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-T's Accelerometer paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPTAccParamsWithBleMacAddress:(NSString *)bleMacAddress
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Config the  BXP-T's Accelerometer paramters which is connected by the current gateway.
/// @param scale scale
/// @param sampleRate sampleRate
/// @param sensitivity 1~255. If the scale is mk_cs_threeAxisDataAG0, the unit is 3.91mg.If the scale is mk_cs_threeAxisDataAG1, the unit is 7.81mg.If the scale is mk_cs_threeAxisDataAG2, the unit is 15.63mg.If the scale is mk_cs_threeAxisDataAG3, the unit is 31.25mg.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBXPTAccParamsWithScale:(mk_cs_threeAxisDataAG)scale
                             sampleRate:(mk_cs_threeAxisDataRate)sampleRate
                            sensitivity:(NSInteger)sensitivity
                                 bleMac:(NSString *)bleMacAddress
                             macAddress:(NSString *)macAddress
                                  topic:(NSString *)topic
                               sucBlock:(void (^)(id returnData))sucBlock
                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-T's Motion event count which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPTMotioEventCountWithBleMacAddress:(NSString *)bleMacAddress
                                         macAddress:(NSString *)macAddress
                                              topic:(NSString *)topic
                                           sucBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Clear the  BXP-T's Motion event count which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_clearBXPTMotioEventCountWithBleMacAddress:(NSString *)bleMacAddress
                                          macAddress:(NSString *)macAddress
                                               topic:(NSString *)topic
                                            sucBlock:(void (^)(id returnData))sucBlock
                                         failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-T LED Remote Reminder.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param color LED color
/// @param blinkingTime flash time, 1s ~ 600s.
/// @param blinkingInterval flash interval, 1 x 100ms ~ 100 x 100ms.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPTLedRemoteReminderWithBleMac:(NSString *)bleMacAddress
                                        color:(mk_cs_bxptLedColor)color
                                 blinkingTime:(NSInteger)blinkingTime
                             blinkingInterval:(NSInteger)blinkingInterval
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-T notify Acc Data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPTNotifyAccDataWithBleMac:(NSString *)bleMacAddress
                                   notify:(BOOL)notify
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-T remote power off.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPTPowerOffWithBleMac:(NSString *)bleMacAddress
                          macAddress:(NSString *)macAddress
                               topic:(NSString *)topic
                            sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-T's advertising paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPTAdvParamsWithBleMacAddress:(NSString *)bleMacAddress
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-T Advertisement parameters.
/// @param channel 0~5.
/// @param interval advterisment interval. 1 x 100ms ~ 100 x 100ms.
/// @param txPower 0~9:
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBXPTAdvParamsWithChannel:(NSInteger)channel
                                 interval:(NSInteger)interval
                                  txPower:(NSInteger)txPower
                                   bleMac:(NSString *)bleMacAddress
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************  BXP-S  ************************
/// The gateway connects to the BXP-S with the specified MAC address.
/// @param password 0-16 Characters
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectBXPSWithPassword:(NSString *)password
                            bleMac:(NSString *)bleMacAddress
                        macAddress:(NSString *)macAddress
                             topic:(NSString *)topic
                          sucBlock:(void (^)(id returnData))sucBlock
                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the service and feature information of the specified BXP-S connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPSConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                             macAddress:(NSString *)macAddress
                                                  topic:(NSString *)topic
                                               sucBlock:(void (^)(id returnData))sucBlock
                                            failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-S's status that connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPSConnectedStatusWithBleMacAddress:(NSString *)bleMacAddress
                                         macAddress:(NSString *)macAddress
                                              topic:(NSString *)topic
                                           sucBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-S notify Real Time HT Datas.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPSNotifyRealTimeHTDataWithBleMac:(NSString *)bleMacAddress
                                          notify:(BOOL)notify
                                      macAddress:(NSString *)macAddress
                                           topic:(NSString *)topic
                                        sucBlock:(void (^)(id returnData))sucBlock
                                     failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-S notify Acc Data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPSNotifyAccDataWithBleMac:(NSString *)bleMacAddress
                                   notify:(BOOL)notify
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-S notify Historical HT Datas.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPSNotifyHistoricalHTDataWithBleMac:(NSString *)bleMacAddress
                                            notify:(BOOL)notify
                                        macAddress:(NSString *)macAddress
                                             topic:(NSString *)topic
                                          sucBlock:(void (^)(id returnData))sucBlock
                                       failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-S delete Historical HT Datas.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPSDeleteHistoricalHTDataWithBleMac:(NSString *)bleMacAddress
                                        macAddress:(NSString *)macAddress
                                             topic:(NSString *)topic
                                          sucBlock:(void (^)(id returnData))sucBlock
                                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-S's H&T datas sample rate.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPSTHDataSampleRateWithBleMacAddress:(NSString *)bleMacAddress
                                          macAddress:(NSString *)macAddress
                                               topic:(NSString *)topic
                                            sucBlock:(void (^)(id returnData))sucBlock
                                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Config the  BXP-S's H&T datas sample rate.
/// @param sampleRate 1s~65535s
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBXPSSampleRate:(NSInteger)sampleRate
                         bleMac:(NSString *)bleMacAddress
                     macAddress:(NSString *)macAddress
                          topic:(NSString *)topic
                       sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-S's Hall Sensor count which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPSHallCountWithBleMacAddress:(NSString *)bleMacAddress
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// Clear the  BXP-S's Hall Sensor count which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_clearBXPSHallCountWithBleMacAddress:(NSString *)bleMacAddress
                                    macAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-S LED Remote Reminder.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param color LED color
/// @param blinkingTime flash time, 1s ~ 600s.
/// @param blinkingInterval flash interval, 1 x 100ms ~ 100 x 100ms.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPSLedRemoteReminderWithBleMac:(NSString *)bleMacAddress
                                        color:(mk_cs_bxptLedColor)color
                                 blinkingTime:(NSInteger)blinkingTime
                             blinkingInterval:(NSInteger)blinkingInterval
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-S remote power off.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpBXPSPowerOffWithBleMac:(NSString *)bleMacAddress
                          macAddress:(NSString *)macAddress
                               topic:(NSString *)topic
                            sucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  BXP-S's advertising paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBXPSAdvParamsWithBleMacAddress:(NSString *)bleMacAddress
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/// BXP-S Advertisement parameters.
/// @param params Adv Params.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBXPSAdvParamsWithParams:(NSDictionary *)params
                                  bleMac:(NSString *)bleMacAddress
                              macAddress:(NSString *)macAddress
                                   topic:(NSString *)topic
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************  MK Pir  ************************
/// The gateway connects to the MK Pir with the specified MAC address.
/// @param password 0-16 Characters
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectMKPirWithPassword:(NSString *)password
                             bleMac:(NSString *)bleMacAddress
                         macAddress:(NSString *)macAddress
                              topic:(NSString *)topic
                           sucBlock:(void (^)(id returnData))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the service and feature information of the specified MK Pir connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKPirConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                              macAddress:(NSString *)macAddress
                                                   topic:(NSString *)topic
                                                sucBlock:(void (^)(id returnData))sucBlock
                                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  MK Pir's status that connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKPirConnectedStatusWithBleMacAddress:(NSString *)bleMacAddress
                                          macAddress:(NSString *)macAddress
                                               topic:(NSString *)topic
                                            sucBlock:(void (^)(id returnData))sucBlock
                                         failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Pir notify Sensor Datas.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_notifyMKPirSensorDataWithBleMac:(NSString *)bleMacAddress
                                    notify:(BOOL)notify
                                macAddress:(NSString *)macAddress
                                     topic:(NSString *)topic
                                  sucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the Pir sensor sensitivity.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKPirSensorSensitivityWithBleMac:(NSString *)bleMacAddress
                                     macAddress:(NSString *)macAddress
                                          topic:(NSString *)topic
                                       sucBlock:(void (^)(id returnData))sucBlock
                                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Config the Pir sensor sensitivity.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param sensitivity sensitivity
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configMKPirSensorSensitivityWithBleMac:(NSString *)bleMacAddress
                                      sensitivity:(mk_cs_pirSensorParamType)sensitivity
                                     macAddress:(NSString *)macAddress
                                          topic:(NSString *)topic
                                       sucBlock:(void (^)(id returnData))sucBlock
                                    failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the Pir sensor delay.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKPirSensorDelayWithBleMac:(NSString *)bleMacAddress
                               macAddress:(NSString *)macAddress
                                    topic:(NSString *)topic
                                 sucBlock:(void (^)(id returnData))sucBlock
                              failedBlock:(void (^)(NSError *error))failedBlock;

/// Config the Pir sensor delay.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param delay delay
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configMKPirSensorDelayWithBleMac:(NSString *)bleMacAddress
                                      delay:(mk_cs_pirSensorParamType)delay
                                 macAddress:(NSString *)macAddress
                                      topic:(NSString *)topic
                                   sucBlock:(void (^)(id returnData))sucBlock
                                failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Pir remote power off.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpMKPirPowerOffWithBleMac:(NSString *)bleMacAddress
                           macAddress:(NSString *)macAddress
                                topic:(NSString *)topic
                             sucBlock:(void (^)(id returnData))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  MK Pir's advertising paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKPirAdvParamsWithBleMacAddress:(NSString *)bleMacAddress
                                    macAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Pir Advertisement parameters.
/// @param interval advterisment interval. 1 x 100ms ~ 100 x 100ms.
/// @param txPower 0~7:(-40,-20,-16,-12,-8,-4,0,4)
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configMKPirAdvParamsWithInterval:(NSInteger)interval
                                    txPower:(NSInteger)txPower
                                     bleMac:(NSString *)bleMacAddress
                                 macAddress:(NSString *)macAddress
                                      topic:(NSString *)topic
                                   sucBlock:(void (^)(id returnData))sucBlock
                                failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************  MK Tof  ************************
/// The gateway connects to the MK Tof with the specified MAC address.
/// @param password 0-16 Characters
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_connectMKTofWithPassword:(NSString *)password
                             bleMac:(NSString *)bleMacAddress
                         macAddress:(NSString *)macAddress
                              topic:(NSString *)topic
                           sucBlock:(void (^)(id returnData))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the service and feature information of the specified MK Tof connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKTofConnectedDeviceInfoWithBleMacAddress:(NSString *)bleMacAddress
                                              macAddress:(NSString *)macAddress
                                                   topic:(NSString *)topic
                                                sucBlock:(void (^)(id returnData))sucBlock
                                             failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  MK Tof's status that connected to the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKTofConnectedStatusWithBleMacAddress:(NSString *)bleMacAddress
                                          macAddress:(NSString *)macAddress
                                               topic:(NSString *)topic
                                            sucBlock:(void (^)(id returnData))sucBlock
                                         failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Tof notify Acc Data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpMKTofNotifyAccDataWithBleMac:(NSString *)bleMacAddress
                                    notify:(BOOL)notify
                                macAddress:(NSString *)macAddress
                                     topic:(NSString *)topic
                                  sucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Tof remote power off.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpMKTofPowerOffWithBleMac:(NSString *)bleMacAddress
                           macAddress:(NSString *)macAddress
                                topic:(NSString *)topic
                             sucBlock:(void (^)(id returnData))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  MK Tof's advertising paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKTofAdvParamsWithBleMacAddress:(NSString *)bleMacAddress
                                    macAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Tof Advertisement parameters.
/// @param interval advterisment interval. 1s~86400s.
/// @param txPower 0~8:(-40,-20,-16,-12,-8,-4,0,3,4)
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configMKTofAdvParamsWithInterval:(NSInteger)interval
                                    txPower:(NSInteger)txPower
                                     bleMac:(NSString *)bleMacAddress
                                 macAddress:(NSString *)macAddress
                                      topic:(NSString *)topic
                                   sucBlock:(void (^)(id returnData))sucBlock
                                failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  MK Tof's sensor paramters which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKTofSensorParamsWithBleMacAddress:(NSString *)bleMacAddress
                                       macAddress:(NSString *)macAddress
                                            topic:(NSString *)topic
                                         sucBlock:(void (^)(id returnData))sucBlock
                                      failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Tof sensor parameters.
/// @param sampleInterval sample interval. 1s~86400s.(sampleCount + 1) *sampleTime <= sampleInterval
/// @param sampleCount sample count. 2~255
/// @param sampleTime sample time.8ms~140ms.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configMKTofSensorParamsWithInterval:(NSInteger)sampleInterval
                                   sampleCount:(NSInteger)sampleCount
                                    sampleTime:(NSInteger)sampleTime
                                        bleMac:(NSString *)bleMacAddress
                                    macAddress:(NSString *)macAddress
                                         topic:(NSString *)topic
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/// Read the  MK Tof's ranging mode which is connected by the current gateway.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readMKTofRangingModeWithBleMacAddress:(NSString *)bleMacAddress
                                      macAddress:(NSString *)macAddress
                                           topic:(NSString *)topic
                                        sucBlock:(void (^)(id returnData))sucBlock
                                     failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Tof ranging mode.
/// @param mode mode.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configMKTofRangingMode:(mk_cs_tofRangingMode)mode
                           bleMac:(NSString *)bleMacAddress
                       macAddress:(NSString *)macAddress
                            topic:(NSString *)topic
                         sucBlock:(void (^)(id returnData))sucBlock
                      failedBlock:(void (^)(NSError *error))failedBlock;

/// MK Tof notify sensor data.
/// @param bleMacAddress The mac address of the target bluetooth device.(e.g.AABBCCDDEEFF)
/// @param notify notify
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_bxpMKTofNotifySensorDataWithBleMac:(NSString *)bleMacAddress
                                       notify:(BOOL)notify
                                   macAddress:(NSString *)macAddress
                                        topic:(NSString *)topic
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark *********************  Normal Ble  ************************
/// Bluetooth communicate timeout.
/// @param macAddress WIFI_STA Mac address of the device.(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_readBleCommunicateTimeoutWithMacAddress:(NSString *)macAddress
                                             topic:(NSString *)topic
                                          sucBlock:(void (^)(id returnData))sucBlock
                                       failedBlock:(void (^)(NSError *error))failedBlock;

/// Bluetooth communicate timeout.
/// @param timeout 0min~60mins.
/// @param macAddress WIFI_STA Mac address of the device(e.g.AABBCCDDEEFF)
/// @param topic topic 1-128 Characters
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
+ (void)cs_configBleCommunicateTimeout:(NSInteger)timeout
                            macAddress:(NSString *)macAddress
                                 topic:(NSString *)topic
                              sucBlock:(void (^)(id returnData))sucBlock
                           failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
