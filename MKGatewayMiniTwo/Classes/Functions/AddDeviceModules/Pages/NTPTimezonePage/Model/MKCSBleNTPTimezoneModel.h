//
//  MKCSBleNTPTimezoneModel.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSBleNTPTimezoneModel : NSObject

/// 0-64 Characters
@property (nonatomic, copy)NSString *ntpHost;

/// -24~28(半小时为单位)
@property (nonatomic, assign)NSInteger timeZone;

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
