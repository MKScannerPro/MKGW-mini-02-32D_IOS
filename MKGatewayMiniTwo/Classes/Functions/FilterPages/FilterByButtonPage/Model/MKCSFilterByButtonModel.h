//
//  MKCSFilterByButtonModel.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MKCSMQTTConfigDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKCSFilterByButtonModel : NSObject<mk_cs_BLEFilterBXPButtonProtocol>

@property (nonatomic, assign)BOOL isOn;

@property (nonatomic, assign)BOOL singlePressIsOn;

@property (nonatomic, assign)BOOL doublePressIsOn;

@property (nonatomic, assign)BOOL longPressIsOn;

@property (nonatomic, assign)BOOL abnormalInactivityIsOn;

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
