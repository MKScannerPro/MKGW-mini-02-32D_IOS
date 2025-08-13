//
//  MKCSManageBleDevicesTypeSelectedView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2025/1/18.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MKCSManageBleDevicesTypeSelectedViewType) {
    MKCSManageBleDevicesTypeSelectedViewTypeBXPBD,
    MKCSManageBleDevicesTypeSelectedViewTypeBXPBCR,
    MKCSManageBleDevicesTypeSelectedViewTypeBXPC,
    MKCSManageBleDevicesTypeSelectedViewTypeBXPD,
    MKCSManageBleDevicesTypeSelectedViewTypeBXPT,
    MKCSManageBleDevicesTypeSelectedViewTypeBXPS,
    MKCSManageBleDevicesTypeSelectedViewTypePIR,
    MKCSManageBleDevicesTypeSelectedViewTypeTOF,
    MKCSManageBleDevicesTypeSelectedViewTypeOther,
};

@interface MKCSManageBleDevicesTypeSelectedView : UIView

+ (void)showWithType:(MKCSManageBleDevicesTypeSelectedViewType)type
        selecteBlock:(void (^)(MKCSManageBleDevicesTypeSelectedViewType selectedType))selecteBlock;

@end

NS_ASSUME_NONNULL_END
