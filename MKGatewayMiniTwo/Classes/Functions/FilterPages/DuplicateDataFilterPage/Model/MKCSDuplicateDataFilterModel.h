//
//  MKCSDuplicateDataFilterModel.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSDuplicateDataFilterModel : NSObject

/// 0:None    1:MAC   2:MAC+Data  type  3:MAC+Raw data
@property (nonatomic, assign)NSInteger rule;

/// 0:strategy1 1:strategy2
@property (nonatomic, assign)NSInteger strategy;

@property (nonatomic, copy)NSString *time;

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
