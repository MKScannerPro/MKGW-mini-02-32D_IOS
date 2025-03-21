//
//  MKCSBleScannerFilterModel.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSBleScannerFilterModel : NSObject

@property (nonatomic, assign)NSInteger rssi;

/// 0~6 Bytes
@property (nonatomic, copy)NSString *macAddress;

/// 0~20 Characters
@property (nonatomic, copy)NSString *advName;

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
