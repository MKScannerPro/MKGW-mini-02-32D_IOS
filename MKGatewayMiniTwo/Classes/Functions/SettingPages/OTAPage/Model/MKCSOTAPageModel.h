//
//  MKCSOTAPageModel.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSOTAPageModel : NSObject

/// 0:Wifi OTA   1:NCP OTA
@property (nonatomic, assign)NSInteger otaType;

@property (nonatomic, copy)NSString *filePath;

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
