/// ABBYY Mobile Capture © 2020 ABBYY Development, Inc.
/// ABBYY is a registered trademark or a trademark of ABBYY Software Ltd.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AUIDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

/// Document size type.
typedef CGSize AUIDocumentSize NS_TYPED_EXTENSIBLE_ENUM;

/// Any document size.
ABBYYUI_EXTERN AUIDocumentSize const AUIDocumentSizeAny;

/// A4 210 x 297 mm.
ABBYYUI_EXTERN AUIDocumentSize const AUIDocumentSizeA4;

/// BusinessCard 53.98 x 85.6 mm.
ABBYYUI_EXTERN AUIDocumentSize const AUIDocumentSizeBusinessCard;

/// Letter 215.9 x 279.4 mm.
ABBYYUI_EXTERN AUIDocumentSize const AUIDocumentSizeLetter;

/// ID 53.98 x 85.6 mm.
ABBYYUI_EXTERN AUIDocumentSize const AUIDocumentSizeID1;

/// ID 74 x 105 mm.
ABBYYUI_EXTERN AUIDocumentSize const AUIDocumentSizeID2;

/// ID 88 x 125 mm.
ABBYYUI_EXTERN AUIDocumentSize const AUIDocumentSizeID3;

NS_ASSUME_NONNULL_END
