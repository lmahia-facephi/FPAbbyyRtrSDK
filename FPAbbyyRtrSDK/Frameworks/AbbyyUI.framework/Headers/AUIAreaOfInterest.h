/// ABBYY Mobile Capture © 2020 ABBYY Development, Inc.
/// ABBYY is a registered trademark or a trademark of ABBYY Software Ltd.

#import <UIKit/UIKit.h>
#import "AUIDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

ABBYYUI_EXTERN
@interface AUIAreaOfInterest : NSObject <NSCopying>

/// Area of interest for a document made up of one line.
@property (class, nonatomic, copy, readonly) AUIAreaOfInterest* oneLine;

/// Area of interest that uses maximum are of camera frame excluding margins.
@property (class, nonatomic, copy, readonly) AUIAreaOfInterest* fill;

/// The ratio between the width and height.
+ (AUIAreaOfInterest*)areaOfInterestWithPortraitAspectRatio:(CGFloat)portraitAspectRatio
	landscapeAspectRatio:(CGFloat)landscapeAspectRatio;
+ (AUIAreaOfInterest*)areaOfInterestWithAspectRatio:(CGFloat)aspectRatio;
+ (instancetype)new __unavailable;

/// The ratio between the width and height.
- (AUIAreaOfInterest*)initWithAspectRatio:(CGFloat)aspectRatio;
- (instancetype)initWithPortraitAspectRatio:(CGFloat)portraitAspectRatio
	landscapeAspectRatio:(CGFloat)landscapeAspectRatio;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
