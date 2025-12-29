//
//  MKCSUploadDataOptionModel.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MKCSMQTTConfigDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKCSUploadDataOptionModel : NSObject<cs_uploadDataOptionProtocol>

/// V2版本固件
@property (nonatomic, assign)BOOL isV2;

@property (nonatomic, assign)BOOL timestamp;

@property (nonatomic, assign)BOOL rawData_advertising;

/// V2中无此参数
@property (nonatomic, assign)BOOL rawData_response;

/// V2中有此参数
@property (nonatomic, assign)BOOL parsed_data;

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
