//
//  MKCSTaskAdopter.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const mk_cs_totalNumKey;
extern NSString *const mk_cs_totalIndexKey;
extern NSString *const mk_cs_contentKey;

@class CBCharacteristic;
@interface MKCSTaskAdopter : NSObject

+ (NSDictionary *)parseReadDataWithCharacteristic:(CBCharacteristic *)characteristic;

+ (NSDictionary *)parseWriteDataWithCharacteristic:(CBCharacteristic *)characteristic;

@end

NS_ASSUME_NONNULL_END
