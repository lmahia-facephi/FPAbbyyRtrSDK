/// ABBYY Mobile Capture © 2020 ABBYY Development, Inc.
/// ABBYY is a registered trademark or a trademark of ABBYY Software Ltd.

#import <Foundation/Foundation.h>
#import <AbbyyRtrSDK/AbbyyRtrSDK.h>
#import "AUIDefinitions.h"
#import "AUIConstants.h"

NS_ASSUME_NONNULL_BEGIN

@class AUIImageCaptureResult;
@class AUIDataFieldInfo;

ABBYYUI_EXTERN
/// Extended information about the character's formatting.
@interface AUICharInfo : NSObject

/// Four vertices of the bounding quadrangle.
@property (nonatomic, readonly, nullable) NSArray<NSValue*>* quadrangle;
/// The bounding rectangle.
@property (nonatomic, readonly) CGRect rect;
@property (nonatomic, readonly) BOOL isUncertain;

+ (instancetype)new __unavailable;
- (instancetype)init __unavailable;

@end

ABBYYUI_EXTERN
/// A line in a recognition result with location and additional information.
@interface AUITextLine : NSObject

/// The recognized text.
@property (nonatomic, readonly, nullable) NSString* text;
/// Bounding rectangle of the line to determine its location.
@property (nonatomic, readonly) CGRect rect;
/// Four vertices of the bounding quadrangle.
@property (nonatomic, readonly, nullable) NSArray<NSValue*>* quadrangle;
/// Additional information about the characters.
@property (nonatomic, readonly, nullable) NSArray<AUICharInfo*>* charInfo;
/// YES for the right-to-left line of the text.
@property (nonatomic, readonly) BOOL isRTL;

+ (instancetype)new __unavailable;
- (instancetype)init __unavailable;

@end

ABBYYUI_EXTERN
/// A recognized field.
@interface AUIDataField : NSObject

/// The field Identifier.
@property (nonatomic, readonly, nullable) NSString* id;
/// Extended description of the field.
@property (nonatomic, readonly, nullable) NSString* name;
/// Recognized text value for the field.
@property (nonatomic, readonly, nullable) NSString* text;
/// Bounding rectangle of the field to determine its location.
@property (nonatomic, readonly) CGRect rect;
/// Four vertices of the bounding quadrangle.
@property (nonatomic, readonly, nullable) NSArray<NSValue*>* quadrangle;
/// In some cases the field contains several components, like for example passport number or address.
@property (nonatomic, readonly, nullable) NSArray<AUIDataField*>* components;
/// Lines of the recognized text.
@property (nonatomic, readonly, nullable) NSArray<AUITextLine*>* textLines;

+ (instancetype)new __unavailable;
- (instancetype)init __unavailable;

@end

ABBYYUI_EXTERN
/// Field description.
@interface AUIDataFieldInfo : NSObject

/// Field Identifier.
@property (nonatomic, copy, readonly) NSString* id;
/// Extended localized field description.
@property (nonatomic, copy, readonly) NSString* name;
/// In some cases the field contains several components, like for example passport number or last name.
@property (nonatomic, copy, readonly, nullable) NSArray<AUIDataFieldInfo*>* components;

+ (instancetype)new __unavailable;
- (instancetype)init __unavailable;

@end

ABBYYUI_EXTERN
/// Represents the data scheme applied to the recognized frame.
@interface AUIDataScheme : NSObject

/// The scheme identifier.
@property (nonatomic, copy, readonly) NSString* id;
/// The human-readable name of the scheme.
@property (nonatomic, copy, readonly) NSString* name;
/// Supported fields.
@property (nonatomic, copy, readonly) NSArray<AUIDataFieldInfo*>* fields;

+ (instancetype)new __unavailable;
- (instancetype)init __unavailable;

@end

ABBYYUI_EXTERN
/// Result of the capture.
@interface AUIDataCaptureScenarioResult : NSObject

/// Captured image.
@property (nonatomic, readonly, nullable) AUIImageCaptureResult* image;
/// Represents the data scheme applied to the captured image.
@property (nonatomic, readonly, nullable) AUIDataScheme* scheme;
/// Recognition result.
@property (nonatomic, readonly) NSArray<AUIDataField*>* dataFields;

+ (instancetype)new __unavailable;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
