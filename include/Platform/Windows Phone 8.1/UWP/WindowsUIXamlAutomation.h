//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsUIXamlAutomation.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXAAutomationProperty, WUXAAutomationProperties, WUXAAutomationElementIdentifiers, WUXAAnnotationPatternIdentifiers, WUXADockPatternIdentifiers, WUXADragPatternIdentifiers, WUXADropTargetPatternIdentifiers, WUXAExpandCollapsePatternIdentifiers, WUXAGridItemPatternIdentifiers, WUXAGridPatternIdentifiers, WUXAMultipleViewPatternIdentifiers, WUXARangeValuePatternIdentifiers, WUXAScrollPatternIdentifiers, WUXASelectionItemPatternIdentifiers, WUXASelectionPatternIdentifiers, WUXATableItemPatternIdentifiers, WUXATablePatternIdentifiers, WUXATogglePatternIdentifiers, WUXATransformPatternIdentifiers, WUXAValuePatternIdentifiers, WUXAWindowPatternIdentifiers, WUXATransformPattern2Identifiers, WUXASpreadsheetItemPatternIdentifiers, WUXAStylesPatternIdentifiers;
@protocol WUXAIAutomationProperty, WUXAIAutomationProperties, WUXAIAutomationPropertiesStatics, WUXAIAutomationPropertiesStatics2, WUXAIAutomationElementIdentifiersStatics, WUXAIAutomationElementIdentifiersStatics2, WUXAIAutomationElementIdentifiers, WUXAIAnnotationPatternIdentifiersStatics, WUXAIAnnotationPatternIdentifiers, WUXAIDockPatternIdentifiersStatics, WUXAIDockPatternIdentifiers, WUXAIDragPatternIdentifiersStatics, WUXAIDragPatternIdentifiers, WUXAIDropTargetPatternIdentifiersStatics, WUXAIDropTargetPatternIdentifiers, WUXAIExpandCollapsePatternIdentifiersStatics, WUXAIExpandCollapsePatternIdentifiers, WUXAIGridItemPatternIdentifiersStatics, WUXAIGridItemPatternIdentifiers, WUXAIGridPatternIdentifiersStatics, WUXAIGridPatternIdentifiers, WUXAIMultipleViewPatternIdentifiersStatics, WUXAIMultipleViewPatternIdentifiers, WUXAIRangeValuePatternIdentifiersStatics, WUXAIRangeValuePatternIdentifiers, WUXAIScrollPatternIdentifiersStatics, WUXAIScrollPatternIdentifiers, WUXAISelectionItemPatternIdentifiersStatics, WUXAISelectionItemPatternIdentifiers, WUXAISelectionPatternIdentifiersStatics, WUXAISelectionPatternIdentifiers, WUXAITableItemPatternIdentifiersStatics, WUXAITableItemPatternIdentifiers, WUXAITablePatternIdentifiersStatics, WUXAITablePatternIdentifiers, WUXAITogglePatternIdentifiersStatics, WUXAITogglePatternIdentifiers, WUXAITransformPatternIdentifiersStatics, WUXAITransformPatternIdentifiers, WUXAIValuePatternIdentifiersStatics, WUXAIValuePatternIdentifiers, WUXAIWindowPatternIdentifiersStatics, WUXAIWindowPatternIdentifiers, WUXAITransformPattern2IdentifiersStatics, WUXAITransformPattern2Identifiers, WUXAISpreadsheetItemPatternIdentifiersStatics, WUXAISpreadsheetItemPatternIdentifiers, WUXAIStylesPatternIdentifiersStatics, WUXAIStylesPatternIdentifiers;

// Windows.UI.Xaml.Automation.AnnotationType
enum _WUXAAnnotationType {
    WUXAAnnotationTypeUnknown = 60000,
    WUXAAnnotationTypeSpellingError = 60001,
    WUXAAnnotationTypeGrammarError = 60002,
    WUXAAnnotationTypeComment = 60003,
    WUXAAnnotationTypeFormulaError = 60004,
    WUXAAnnotationTypeTrackChanges = 60005,
    WUXAAnnotationTypeHeader = 60006,
    WUXAAnnotationTypeFooter = 60007,
    WUXAAnnotationTypeHighlighted = 60008,
};
typedef unsigned WUXAAnnotationType;

// Windows.UI.Xaml.Automation.DockPosition
enum _WUXADockPosition {
    WUXADockPositionTop = 0,
    WUXADockPositionLeft = 1,
    WUXADockPositionBottom = 2,
    WUXADockPositionRight = 3,
    WUXADockPositionFill = 4,
    WUXADockPositionNone = 5,
};
typedef unsigned WUXADockPosition;

// Windows.UI.Xaml.Automation.ExpandCollapseState
enum _WUXAExpandCollapseState {
    WUXAExpandCollapseStateCollapsed = 0,
    WUXAExpandCollapseStateExpanded = 1,
    WUXAExpandCollapseStatePartiallyExpanded = 2,
    WUXAExpandCollapseStateLeafNode = 3,
};
typedef unsigned WUXAExpandCollapseState;

// Windows.UI.Xaml.Automation.RowOrColumnMajor
enum _WUXARowOrColumnMajor {
    WUXARowOrColumnMajorRowMajor = 0,
    WUXARowOrColumnMajorColumnMajor = 1,
    WUXARowOrColumnMajorIndeterminate = 2,
};
typedef unsigned WUXARowOrColumnMajor;

// Windows.UI.Xaml.Automation.ScrollAmount
enum _WUXAScrollAmount {
    WUXAScrollAmountLargeDecrement = 0,
    WUXAScrollAmountSmallDecrement = 1,
    WUXAScrollAmountNoAmount = 2,
    WUXAScrollAmountLargeIncrement = 3,
    WUXAScrollAmountSmallIncrement = 4,
};
typedef unsigned WUXAScrollAmount;

// Windows.UI.Xaml.Automation.SupportedTextSelection
enum _WUXASupportedTextSelection {
    WUXASupportedTextSelectionNone = 0,
    WUXASupportedTextSelectionSingle = 1,
    WUXASupportedTextSelectionMultiple = 2,
};
typedef unsigned WUXASupportedTextSelection;

// Windows.UI.Xaml.Automation.SynchronizedInputType
enum _WUXASynchronizedInputType {
    WUXASynchronizedInputTypeKeyUp = 1,
    WUXASynchronizedInputTypeKeyDown = 2,
    WUXASynchronizedInputTypeLeftMouseUp = 4,
    WUXASynchronizedInputTypeLeftMouseDown = 8,
    WUXASynchronizedInputTypeRightMouseUp = 16,
    WUXASynchronizedInputTypeRightMouseDown = 32,
};
typedef unsigned WUXASynchronizedInputType;

// Windows.UI.Xaml.Automation.ToggleState
enum _WUXAToggleState {
    WUXAToggleStateOff = 0,
    WUXAToggleStateOn = 1,
    WUXAToggleStateIndeterminate = 2,
};
typedef unsigned WUXAToggleState;

// Windows.UI.Xaml.Automation.WindowInteractionState
enum _WUXAWindowInteractionState {
    WUXAWindowInteractionStateRunning = 0,
    WUXAWindowInteractionStateClosing = 1,
    WUXAWindowInteractionStateReadyForUserInteraction = 2,
    WUXAWindowInteractionStateBlockedByModalWindow = 3,
    WUXAWindowInteractionStateNotResponding = 4,
};
typedef unsigned WUXAWindowInteractionState;

// Windows.UI.Xaml.Automation.WindowVisualState
enum _WUXAWindowVisualState {
    WUXAWindowVisualStateNormal = 0,
    WUXAWindowVisualStateMaximized = 1,
    WUXAWindowVisualStateMinimized = 2,
};
typedef unsigned WUXAWindowVisualState;

// Windows.UI.Xaml.Automation.ZoomUnit
enum _WUXAZoomUnit {
    WUXAZoomUnitNoAmount = 0,
    WUXAZoomUnitLargeDecrement = 1,
    WUXAZoomUnitSmallDecrement = 2,
    WUXAZoomUnitLargeIncrement = 3,
    WUXAZoomUnitSmallIncrement = 4,
};
typedef unsigned WUXAZoomUnit;

#include "WindowsUIXaml.h"
#include "WindowsUIXamlAutomationPeers.h"
#include "WindowsFoundationCollections.h"

// Windows.UI.Xaml.Automation.AutomationProperty
#ifndef __WUXAAutomationProperty_DEFINED__
#define __WUXAAutomationProperty_DEFINED__

WINRT_EXPORT
@interface WUXAAutomationProperty : RTObject
@end

#endif // __WUXAAutomationProperty_DEFINED__

// Windows.UI.Xaml.Automation.AutomationProperties
#ifndef __WUXAAutomationProperties_DEFINED__
#define __WUXAAutomationProperties_DEFINED__

WINRT_EXPORT
@interface WUXAAutomationProperties : RTObject
+ (WUXAPAccessibilityView)getAccessibilityView:(WXDependencyObject *)element;
+ (void)setAccessibilityView:(WXDependencyObject *)element value:(WUXAPAccessibilityView)value;
+ (id<NSFastEnumeration> /*WXUIElement*/ )getControlledPeers:(WXDependencyObject *)element;
+ (NSString *)getAcceleratorKey:(WXDependencyObject *)element;
+ (void)setAcceleratorKey:(WXDependencyObject *)element value:(NSString *)value;
+ (NSString *)getAccessKey:(WXDependencyObject *)element;
+ (void)setAccessKey:(WXDependencyObject *)element value:(NSString *)value;
+ (NSString *)getAutomationId:(WXDependencyObject *)element;
+ (void)setAutomationId:(WXDependencyObject *)element value:(NSString *)value;
+ (NSString *)getHelpText:(WXDependencyObject *)element;
+ (void)setHelpText:(WXDependencyObject *)element value:(NSString *)value;
+ (BOOL)getIsRequiredForForm:(WXDependencyObject *)element;
+ (void)setIsRequiredForForm:(WXDependencyObject *)element value:(BOOL)value;
+ (NSString *)getItemStatus:(WXDependencyObject *)element;
+ (void)setItemStatus:(WXDependencyObject *)element value:(NSString *)value;
+ (NSString *)getItemType:(WXDependencyObject *)element;
+ (void)setItemType:(WXDependencyObject *)element value:(NSString *)value;
+ (WXUIElement *)getLabeledBy:(WXDependencyObject *)element;
+ (void)setLabeledBy:(WXDependencyObject *)element value:(WXUIElement *)value;
+ (NSString *)getName:(WXDependencyObject *)element;
+ (void)setName:(WXDependencyObject *)element value:(NSString *)value;
+ (WUXAPAutomationLiveSetting)getLiveSetting:(WXDependencyObject *)element;
+ (void)setLiveSetting:(WXDependencyObject *)element value:(WUXAPAutomationLiveSetting)value;
+ (WXDependencyProperty *)acceleratorKeyProperty;
+ (WXDependencyProperty *)accessKeyProperty;
+ (WXDependencyProperty *)automationIdProperty;
+ (WXDependencyProperty *)helpTextProperty;
+ (WXDependencyProperty *)isRequiredForFormProperty;
+ (WXDependencyProperty *)itemStatusProperty;
+ (WXDependencyProperty *)itemTypeProperty;
+ (WXDependencyProperty *)labeledByProperty;
+ (WXDependencyProperty *)liveSettingProperty;
+ (WXDependencyProperty *)nameProperty;
+ (WXDependencyProperty *)accessibilityViewProperty;
+ (WXDependencyProperty *)controlledPeersProperty;
@end

#endif // __WUXAAutomationProperties_DEFINED__

// Windows.UI.Xaml.Automation.AutomationElementIdentifiers
#ifndef __WUXAAutomationElementIdentifiers_DEFINED__
#define __WUXAAutomationElementIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAAutomationElementIdentifiers : RTObject
+ (WUXAAutomationProperty *)acceleratorKeyProperty;
+ (WUXAAutomationProperty *)accessKeyProperty;
+ (WUXAAutomationProperty *)automationIdProperty;
+ (WUXAAutomationProperty *)boundingRectangleProperty;
+ (WUXAAutomationProperty *)classNameProperty;
+ (WUXAAutomationProperty *)clickablePointProperty;
+ (WUXAAutomationProperty *)controlTypeProperty;
+ (WUXAAutomationProperty *)hasKeyboardFocusProperty;
+ (WUXAAutomationProperty *)helpTextProperty;
+ (WUXAAutomationProperty *)isContentElementProperty;
+ (WUXAAutomationProperty *)isControlElementProperty;
+ (WUXAAutomationProperty *)isEnabledProperty;
+ (WUXAAutomationProperty *)isKeyboardFocusableProperty;
+ (WUXAAutomationProperty *)isOffscreenProperty;
+ (WUXAAutomationProperty *)isPasswordProperty;
+ (WUXAAutomationProperty *)isRequiredForFormProperty;
+ (WUXAAutomationProperty *)itemStatusProperty;
+ (WUXAAutomationProperty *)itemTypeProperty;
+ (WUXAAutomationProperty *)labeledByProperty;
+ (WUXAAutomationProperty *)liveSettingProperty;
+ (WUXAAutomationProperty *)localizedControlTypeProperty;
+ (WUXAAutomationProperty *)nameProperty;
+ (WUXAAutomationProperty *)orientationProperty;
+ (WUXAAutomationProperty *)controlledPeersProperty;
@end

#endif // __WUXAAutomationElementIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.AnnotationPatternIdentifiers
#ifndef __WUXAAnnotationPatternIdentifiers_DEFINED__
#define __WUXAAnnotationPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAAnnotationPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)annotationTypeIdProperty;
+ (WUXAAutomationProperty *)annotationTypeNameProperty;
+ (WUXAAutomationProperty *)authorProperty;
+ (WUXAAutomationProperty *)dateTimeProperty;
+ (WUXAAutomationProperty *)targetProperty;
@end

#endif // __WUXAAnnotationPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.DockPatternIdentifiers
#ifndef __WUXADockPatternIdentifiers_DEFINED__
#define __WUXADockPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXADockPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)dockPositionProperty;
@end

#endif // __WUXADockPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.DragPatternIdentifiers
#ifndef __WUXADragPatternIdentifiers_DEFINED__
#define __WUXADragPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXADragPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)dropEffectProperty;
+ (WUXAAutomationProperty *)dropEffectsProperty;
+ (WUXAAutomationProperty *)grabbedItemsProperty;
+ (WUXAAutomationProperty *)isGrabbedProperty;
@end

#endif // __WUXADragPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.DropTargetPatternIdentifiers
#ifndef __WUXADropTargetPatternIdentifiers_DEFINED__
#define __WUXADropTargetPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXADropTargetPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)dropTargetEffectProperty;
+ (WUXAAutomationProperty *)dropTargetEffectsProperty;
@end

#endif // __WUXADropTargetPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.ExpandCollapsePatternIdentifiers
#ifndef __WUXAExpandCollapsePatternIdentifiers_DEFINED__
#define __WUXAExpandCollapsePatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAExpandCollapsePatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)expandCollapseStateProperty;
@end

#endif // __WUXAExpandCollapsePatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.GridItemPatternIdentifiers
#ifndef __WUXAGridItemPatternIdentifiers_DEFINED__
#define __WUXAGridItemPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAGridItemPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)columnProperty;
+ (WUXAAutomationProperty *)columnSpanProperty;
+ (WUXAAutomationProperty *)containingGridProperty;
+ (WUXAAutomationProperty *)rowProperty;
+ (WUXAAutomationProperty *)rowSpanProperty;
@end

#endif // __WUXAGridItemPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.GridPatternIdentifiers
#ifndef __WUXAGridPatternIdentifiers_DEFINED__
#define __WUXAGridPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAGridPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)columnCountProperty;
+ (WUXAAutomationProperty *)rowCountProperty;
@end

#endif // __WUXAGridPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.MultipleViewPatternIdentifiers
#ifndef __WUXAMultipleViewPatternIdentifiers_DEFINED__
#define __WUXAMultipleViewPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAMultipleViewPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)currentViewProperty;
+ (WUXAAutomationProperty *)supportedViewsProperty;
@end

#endif // __WUXAMultipleViewPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.RangeValuePatternIdentifiers
#ifndef __WUXARangeValuePatternIdentifiers_DEFINED__
#define __WUXARangeValuePatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXARangeValuePatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)isReadOnlyProperty;
+ (WUXAAutomationProperty *)largeChangeProperty;
+ (WUXAAutomationProperty *)maximumProperty;
+ (WUXAAutomationProperty *)minimumProperty;
+ (WUXAAutomationProperty *)smallChangeProperty;
+ (WUXAAutomationProperty *)valueProperty;
@end

#endif // __WUXARangeValuePatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.ScrollPatternIdentifiers
#ifndef __WUXAScrollPatternIdentifiers_DEFINED__
#define __WUXAScrollPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAScrollPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)horizontalScrollPercentProperty;
+ (WUXAAutomationProperty *)horizontalViewSizeProperty;
+ (WUXAAutomationProperty *)horizontallyScrollableProperty;
+ (double)noScroll;
+ (WUXAAutomationProperty *)verticalScrollPercentProperty;
+ (WUXAAutomationProperty *)verticalViewSizeProperty;
+ (WUXAAutomationProperty *)verticallyScrollableProperty;
@end

#endif // __WUXAScrollPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.SelectionItemPatternIdentifiers
#ifndef __WUXASelectionItemPatternIdentifiers_DEFINED__
#define __WUXASelectionItemPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXASelectionItemPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)isSelectedProperty;
+ (WUXAAutomationProperty *)selectionContainerProperty;
@end

#endif // __WUXASelectionItemPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.SelectionPatternIdentifiers
#ifndef __WUXASelectionPatternIdentifiers_DEFINED__
#define __WUXASelectionPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXASelectionPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)canSelectMultipleProperty;
+ (WUXAAutomationProperty *)isSelectionRequiredProperty;
+ (WUXAAutomationProperty *)selectionProperty;
@end

#endif // __WUXASelectionPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.TableItemPatternIdentifiers
#ifndef __WUXATableItemPatternIdentifiers_DEFINED__
#define __WUXATableItemPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXATableItemPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)columnHeaderItemsProperty;
+ (WUXAAutomationProperty *)rowHeaderItemsProperty;
@end

#endif // __WUXATableItemPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.TablePatternIdentifiers
#ifndef __WUXATablePatternIdentifiers_DEFINED__
#define __WUXATablePatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXATablePatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)columnHeadersProperty;
+ (WUXAAutomationProperty *)rowHeadersProperty;
+ (WUXAAutomationProperty *)rowOrColumnMajorProperty;
@end

#endif // __WUXATablePatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.TogglePatternIdentifiers
#ifndef __WUXATogglePatternIdentifiers_DEFINED__
#define __WUXATogglePatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXATogglePatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)toggleStateProperty;
@end

#endif // __WUXATogglePatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.TransformPatternIdentifiers
#ifndef __WUXATransformPatternIdentifiers_DEFINED__
#define __WUXATransformPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXATransformPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)canMoveProperty;
+ (WUXAAutomationProperty *)canResizeProperty;
+ (WUXAAutomationProperty *)canRotateProperty;
@end

#endif // __WUXATransformPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.ValuePatternIdentifiers
#ifndef __WUXAValuePatternIdentifiers_DEFINED__
#define __WUXAValuePatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAValuePatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)isReadOnlyProperty;
+ (WUXAAutomationProperty *)valueProperty;
@end

#endif // __WUXAValuePatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.WindowPatternIdentifiers
#ifndef __WUXAWindowPatternIdentifiers_DEFINED__
#define __WUXAWindowPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAWindowPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)canMaximizeProperty;
+ (WUXAAutomationProperty *)canMinimizeProperty;
+ (WUXAAutomationProperty *)isModalProperty;
+ (WUXAAutomationProperty *)isTopmostProperty;
+ (WUXAAutomationProperty *)windowInteractionStateProperty;
+ (WUXAAutomationProperty *)windowVisualStateProperty;
@end

#endif // __WUXAWindowPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.TransformPattern2Identifiers
#ifndef __WUXATransformPattern2Identifiers_DEFINED__
#define __WUXATransformPattern2Identifiers_DEFINED__

WINRT_EXPORT
@interface WUXATransformPattern2Identifiers : RTObject
+ (WUXAAutomationProperty *)canZoomProperty;
+ (WUXAAutomationProperty *)maxZoomProperty;
+ (WUXAAutomationProperty *)minZoomProperty;
+ (WUXAAutomationProperty *)zoomLevelProperty;
@end

#endif // __WUXATransformPattern2Identifiers_DEFINED__

// Windows.UI.Xaml.Automation.SpreadsheetItemPatternIdentifiers
#ifndef __WUXASpreadsheetItemPatternIdentifiers_DEFINED__
#define __WUXASpreadsheetItemPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXASpreadsheetItemPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)formulaProperty;
@end

#endif // __WUXASpreadsheetItemPatternIdentifiers_DEFINED__

// Windows.UI.Xaml.Automation.StylesPatternIdentifiers
#ifndef __WUXAStylesPatternIdentifiers_DEFINED__
#define __WUXAStylesPatternIdentifiers_DEFINED__

WINRT_EXPORT
@interface WUXAStylesPatternIdentifiers : RTObject
+ (WUXAAutomationProperty *)extendedPropertiesProperty;
+ (WUXAAutomationProperty *)fillColorProperty;
+ (WUXAAutomationProperty *)fillPatternColorProperty;
+ (WUXAAutomationProperty *)fillPatternStyleProperty;
+ (WUXAAutomationProperty *)shapeProperty;
+ (WUXAAutomationProperty *)styleIdProperty;
+ (WUXAAutomationProperty *)styleNameProperty;
@end

#endif // __WUXAStylesPatternIdentifiers_DEFINED__

