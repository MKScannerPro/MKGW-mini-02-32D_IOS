//
//  MKCSImportServerController.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MKCSImportServerControllerDelegate <NSObject>

- (void)cs_selectedServerParams:(NSString *)fileName;

@end

@interface MKCSImportServerController : MKBaseViewController

@property (nonatomic, weak)id <MKCSImportServerControllerDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
