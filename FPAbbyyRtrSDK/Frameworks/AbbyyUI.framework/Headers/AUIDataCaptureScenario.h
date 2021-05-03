/// ABBYY Mobile Capture © 2020 ABBYY Development, Inc.
/// ABBYY is a registered trademark or a trademark of ABBYY Software Ltd.

#import <Foundation/Foundation.h>
#import "AUICaptureScenario.h"
#import "AUIAreaOfInterest.h"
#import "AUIDataCaptureScenarioResult.h"
#import "AUIImageCaptureSettings.h"
#import "AUIConstants.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Signature for a field validation callback.
 */
typedef BOOL (^AUIFieldPredicateBlock)(NSString* value);

ABBYYUI_EXTERN
/**
 * Describes a field which should be extracted by the data capture scenario.
 */
@interface AUICustomDataCaptureField : NSObject

/**
 * The field name, that will be returned by the callback delegate methods.
 */
@property (nonatomic, readonly) NSString* name;
/**
 * A regular expression according to which the field should be validated in the custom data capture scenario.
 */
@property (nonatomic, readonly) NSString* regEx;
/**
 * Sets a user-defined validation block which will be used to verify the recognized field data.
 *
 * The validation block is called only after the data passes the regular expression check.
 * If no validation block is specified, the field is captured on the basis of the regular
 * expression only.
 */
@property (nonatomic, copy, nullable) AUIFieldPredicateBlock predicateBlock;

- (instancetype)initWithName:(NSString*)name
	regEx:(NSString*)regEx
	predicateBlock:(nullable AUIFieldPredicateBlock)predicateBlock;

@end


ABBYYUI_EXTERN
/**
 * Describes a scheme \ data \ document which should be caputred by the data capture scenario.
 */
@interface AUICustomDataCaptureScheme : NSObject
/**
 * The scheme name, that will be returned by the callback delegate methods.
 */
@property (nonatomic, readonly) NSString* name;
/**
 * The fields of the scheme.
 */
@property (nonatomic, readonly) NSArray<AUICustomDataCaptureField*>* fields;

- (instancetype)initWithName:(NSString*)name field:(AUICustomDataCaptureField*)field;

@end

#pragma mark -

@class AUIDataCaptureScenario;

#pragma mark -

typedef NS_ENUM(NSUInteger, AUIDataCaptureHint) {
	AUIDataCaptureHintStart,
	AUIDataCaptureHintTextTooSmall,
	AUIDataCaptureHintLookingForDocument,
	AUIDataCaptureHintComplete,
	AUIDataCaptureHintCropDocument,
};

/**
 Additional settings for a data capture process.
 */
@protocol AUIDataCaptureUISettings <NSObject>

@optional

/**
 Returns a text for the specific hint, that will be shown to the end-user.

 @param captureScenario Capture scenario informing delegate.
 @param hintType Specific event.
 @return Returns a text for the specific hint, that will be shown to the end-user, or nil to display default text.
 */
- (nullable NSString*)captureScenario:(AUIDataCaptureScenario*)captureScenario
	stringForHintType:(AUIDataCaptureHint)hintType;

@end

#pragma mark -

/**
A delegate protocol through which the data capture scenario returns its results.
*/
@protocol AUIDataCaptureScenarioDelegate <AUICaptureScenarioDelegate>
/**
 Tells the delegate that the data scan successfully completed
 
@param scenario The capture scenario
@param result The result with scanned data fields
*/
- (void)dataCaptureScenario:(AUIDataCaptureScenario*)scenario didFinishWithResult:(AUIDataCaptureScenarioResult*)result;

/**
Tells the delegate that data scan failed while the captureScenario was active

@param scenario The capture scenario.
@param error The error containing the reason for failure.
*/
- (void)dataCaptureScenario:(AUIDataCaptureScenario*)scenario didFailWithError:(NSError*)error;

/**
Tells the delegate that the user cancelled scan action.

@param scenario The capture scenario.
*/
- (void)dataCaptureScenarioDidCancel:(AUIDataCaptureScenario*)scenario;

@end

@protocol AUIDataCaptureSettings

/// Set profile (text | custom | predefinedProfileName)
@property (nonatomic, copy) NSString* profile;
/// Used for Custom Data Capture profile. Set a scheme definition.
@property (nonatomic, strong) AUICustomDataCaptureScheme* scheme;
/// Set languages for recognition.
@property (nonatomic, copy) NSSet<RTRLanguageName>* recognitionLanguages;
/**
 * Set languages available to choose by end user during recogntion process.
 * Set empty set to hide languages button after the profile is specified.
 * Set only one language to disable languages button.
 */
@property (nonatomic, copy) NSSet<RTRLanguageName>* selectableRecognitionLanguages;

/**
 * Capture Scene Type. Setting the correct scene type could improve the recognition results.
 */
@property (nonatomic, copy) RTRCaptureSceneType captureSceneType;

/// Set area of interest.
@property (nonatomic, copy) AUIAreaOfInterest* areaOfInterest;

/// Reserved for future use.
@property (nonatomic, copy) NSDictionary* extendedSettings;

/**
 * Check if the settings are consistent and applies the settings to the scenario.
 *
 * @return NO in case an error occurs while submitting profile, otherwise - YES.
 */
- (BOOL)checkAndApply:(NSError**)error;

@end

#pragma mark -

ABBYYUI_EXTERN
@interface AUIDataCaptureScenario : AUICaptureScenario

/// Additional info about UI.
@property (nonatomic, weak, nullable) id<AUIDataCaptureUISettings> uiSettings;
/// Image capture settings.
@property (nonatomic, strong, readonly) id<AUIImageCaptureSettings> imageCaptureSettings;
/// Data capture settings.
@property (nonatomic, strong, readonly) id<AUIDataCaptureSettings> dataCaptureSettings;

/// If NO, automatic capture is disabled. Default YES. After each capture is set to NO.
@property (nonatomic, assign) BOOL active;
- (void)setActive:(BOOL)active animated:(BOOL)animated;

/// Creates scenario with a valid engine.
- (instancetype)initWithEngine:(RTREngine*)engine;

/// Capture data immediately.
- (void)captureDataManually;

@end

NS_ASSUME_NONNULL_END
