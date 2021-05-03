/// ABBYY Mobile Capture © 2020 ABBYY Development, Inc.
/// ABBYY is a registered trademark or a trademark of ABBYY Software Ltd.

#import "AUICaptureScenario.h"
#import "AUIImageCaptureSettings.h"
#import "AUIConstants.h"
#import <AbbyyRtrSDK/AbbyyRtrSDK.h>

NS_ASSUME_NONNULL_BEGIN

ABBYYUI_EXTERN
@interface AUIImageCaptureResult : NSObject

/// Cropped image, or captured image, if no documentBoundary was detected.
@property (nonatomic, strong) UIImage* image;

/// Boundary for document. NSValue contains CGPoint.
/// You can modify boundary by manual tunning.
@property (nonatomic, strong, nullable) NSArray<NSValue*>* documentBoundary;

/// Captured image.
@property (nonatomic, strong) UIImage* originalImage;

@end

@protocol AUIImageCaptureScenarioDelegate;

@class AUIImageCaptureScenario;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@protocol AUIImageCaptureScenarioDelegate <AUICaptureScenarioDelegate>

- (void)captureScenarioDidCancel:(AUICaptureScenario*)scenario;

- (void)captureScenario:(AUIImageCaptureScenario*)captureScenario didCaptureImageWithResult:(AUIImageCaptureResult*)result;

- (void)captureScenario:(AUIImageCaptureScenario*)scenario didFailWithError:(NSError*)error;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ABBYYUI_EXTERN
@interface AUIImageCaptureScenario : AUICaptureScenario<AUIImageCaptureSettings>

@property (nonatomic, weak, nullable) id<AUIImageCaptureScenarioDelegate> delegate;

/// If NO automatic image capturing is disabled. Default YES. After each capture is set to NO.
@property (nonatomic, assign) BOOL active;

- (void)setActive:(BOOL)active animated:(BOOL)animated;

/// Cancel scenario.
- (void)cancel;

- (instancetype)initWithEngine:(RTREngine*)engine;

/// Capture image immediately.
- (void)captureImageManually;
/// Pick Image from gallery.
- (void)pickImageFromGallery;

@end

NS_ASSUME_NONNULL_END
