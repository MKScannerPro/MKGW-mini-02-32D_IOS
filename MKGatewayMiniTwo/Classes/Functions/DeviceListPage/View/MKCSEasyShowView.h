//
//  MKCSEasyShowView.h
//  MKGatewayMiniTwo_Example
//
//  Created by aa on 2024/11/01.
//  Copyright © 2024 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKCSEasyShowView : UIView

- (void)showText:(NSString *)text
       superView:(UIView *)superView
        animated:(BOOL)animated;

- (void)hidden;

@end

NS_ASSUME_NONNULL_END
