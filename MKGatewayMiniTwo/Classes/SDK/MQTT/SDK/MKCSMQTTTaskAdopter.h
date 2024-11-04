//
//  MKCSMQTTTaskAdopter.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSMQTTTaskAdopter : NSObject

+ (NSDictionary *)parseDataWithJson:(NSDictionary *)json topic:(NSString *)topic;

@end

NS_ASSUME_NONNULL_END
