/// ABBYY Mobile Capture © 2020 ABBYY Development, Inc.
/// ABBYY is a registered trademark or a trademark of ABBYY Software Ltd.

#import "RTREngine.h"
#import "RTRConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RTRDataCaptureService;
@protocol RTRDataCaptureServiceDelegate;

@class RTRDataScheme;
@class RTRExtendedSettings;

#pragma mark - RTREngine

@interface RTREngine (DataCapture)

/**
 * Creates a background recognition DataCapture service.
 *
 * @param delegate The delegate object used to interact with the service.
 * @param profile The selected profile for DataCapture service.
 *
 * @return Data capture service that conforms to RTRDataCaptureService protocol.
 */
- (nullable id<RTRDataCaptureService>)createDataCaptureServiceWithDelegate:(id<RTRDataCaptureServiceDelegate>)delegate profile:(nullable NSString*)profile;

/**
 * Creates a background recognition DataCapture service.
 *
 * @param delegate The delegate object used to interact with the service.
 * @param profile The selected profile for DataCapture service.
 * @param settings The settings used to configure background recognition service.
 *
 * @return Data capture service that conforms to RTRDataCaptureService protocol.
 */
- (nullable id<RTRDataCaptureService>)createDataCaptureServiceWithDelegate:(id<RTRDataCaptureServiceDelegate>)delegate profile:(nullable NSString*)profile settings:(nullable RTRExtendedSettings*)settings;

/**
 * Examines bundle directories and returns the list of languages available for business card recognition.
 *
 * @return A set of strings with internal language names.
 */
- (NSSet<RTRLanguageName>*)languagesAvailableForBCR;

/**
* A list of supported schemes for the specifed profile.
*/
- (nullable NSArray<RTRDataScheme*>*)dataSchemesForProfile:(NSString*)profile error:(NSError**)error;

@end

NS_ASSUME_NONNULL_END
