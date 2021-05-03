/// ABBYY Mobile Capture © 2020 ABBYY Development, Inc.
/// ABBYY is a registered trademark or a trademark of ABBYY Software Ltd.

#import <Foundation/Foundation.h>
#import "AUIConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AUIImageCaptureSettings

/// Minimum document area relative to frame area - 0...1. Default 0.15.
@property (nonatomic, assign) CGFloat minimumDocumentToViewRatio;

/**
 * Sets the physical size of the document to be captured.
 * If the physical size of the document being captured is known, setting this parameter will help to improve document boundary detection accuracy,
 * allow to preserve aspect ratio after crop and to automatically calculate image resolution before export.
 *
 * The size of the document in millimeters.
 */
@property (nonatomic, assign) AUIDocumentSize documentSize;

/**
 * Minimum appropriate value of document's aspect ratio.
 * This will help to improve boundary detection accuracy.
 * Value is found by division maximum size to minimum size.
 * Value must be either greater than or equal to 1, or not set (property set to 0).
 * If only maximum is set, minimum will be set to 1.
 * Not set by default (property set to 0).
 *
 * If not set, the values will be calculated from documentSize setting.
 */
@property (nonatomic, assign) CGFloat aspectRatioMin;

/**
 * Maximum appropriate value of document's aspect ratio.
 * This will help to improve boundary detection accuracy.
 * Value is found by division maximum size to minimum size.
 * Value must be either greater than or equal to 1, or not set (property set to 0).
 * If only minimum is set, maximum will be set to CGFLOAT_MAX.
 * Not set by default (property set to 0).
 *
 * If not set, the values will be calculated from documentSize setting.
 */
@property (nonatomic, assign) CGFloat aspectRatioMax;

/// Maximum pixel size of max side of image picked from gallery. Default 4096.
@property (nonatomic, assign) NSInteger imageFromGalleryMaxSize;

/// If YES result image will be cropped and quadrangle result will be nil. Default YES .
@property (nonatomic, assign) BOOL cropEnabled;

@end

NS_ASSUME_NONNULL_END
