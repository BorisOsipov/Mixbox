import MixboxTestsFoundation
import MixboxIpcCommon
import MixboxUiTestsFoundation
import XCTest

// Swift wrapper for private XCTest Obj-C class `XCElementSnapshot`
final class XcuiElementSnapshot: ElementSnapshot {
    private let xcElementSnapshot: XCElementSnapshot
    
    init(_ xcElementSnapshot: XCElementSnapshot) {
        self.xcElementSnapshot = xcElementSnapshot
    }
    
    var isEnabled: Bool {
        return xcElementSnapshot.enabled
    }
    
    var text: OptionalAvailability<String?> {
        if let enhancedAccessibilityValue = enhancedAccessibilityValue {
            return .available(enhancedAccessibilityValue.text)
        } else {
            return .unavailable
        }
    }
    
    var isDefinitelyHidden: OptionalAvailability<Bool> {
        if let enhancedAccessibilityValue = enhancedAccessibilityValue {
            return .available(enhancedAccessibilityValue.isDefinitelyHidden)
        } else {
            return .unavailable
        }
    }
    
    var uniqueIdentifier: OptionalAvailability<String> {
        if let enhancedAccessibilityValue = enhancedAccessibilityValue {
            return .available(enhancedAccessibilityValue.uniqueIdentifier)
        } else {
            return .unavailable
        }
    }
    
    var customValues: OptionalAvailability<[String: String]> {
        if let enhancedAccessibilityValue = enhancedAccessibilityValue {
            return .available(enhancedAccessibilityValue.customValues)
        } else {
            return .unavailable
        }
    }
    
    var hasKeyboardFocus: Bool {
        return xcElementSnapshot.hasKeyboardFocus
    }
    
    var elementType: ElementType? {
        return ElementType(rawValue: UInt(xcElementSnapshot.elementType.rawValue))
    }
    
    var accessibilityPlaceholderValue: String? {
        return xcElementSnapshot.placeholderValue as String?
    }
    
    var accessibilityLabel: String {
        return xcElementSnapshot.label ?? ""
    }
    
    var accessibilityValue: Any? {
        if let enhancedAccessibilityValue = enhancedAccessibilityValue {
            return enhancedAccessibilityValue.originalAccessibilityValue
        } else {
            return xcElementSnapshot.value
        }
    }
    
    var accessibilityIdentifier: String {
        return xcElementSnapshot.identifier ?? ""
    }
    
    var frameRelativeToScreen: CGRect {
        return xcElementSnapshot.frame
    }

    var children: [ElementSnapshot] {
        return xcElementSnapshot.children.compactMap { child in
            (child as? XCElementSnapshot).flatMap { XcuiElementSnapshot($0) }
        }
    }
    
    var parent: ElementSnapshot? {
        guard let parent = xcElementSnapshot.parent else {
            return nil
        }
        return XcuiElementSnapshot(parent)
    }
    
    var uikitClass: String? {
        return additionalAttributes[5004 as NSObject] as? String
    }
    
    var customClass: String? {
        return additionalAttributes[5041 as NSObject] as? String
    }
    
    // MARK: - Private
    
    private var enhancedAccessibilityValue: EnhancedAccessibilityValue? {
        return EnhancedAccessibilityValue.fromAccessibilityValue(xcElementSnapshot.value as? String)
    }
    
    private var additionalAttributes: [NSObject: Any]  {
        return (xcElementSnapshot.additionalAttributes as [NSObject: Any]?) ?? [:]
    }
    
    // MARK: -
    
    var debugDescription: String {
        var fields = [String]()
        if let elementType = elementType {
            fields.append("elementType: \(elementType)")
        }
        fields.append("additionalAttributes: \(additionalAttributes)")
        fields.append("uniqueIdentifier: \(uniqueIdentifier)")
        fields.append("accessibilityIdentifier: \(accessibilityIdentifier)")
        fields.append("accessibilityLabel: \(accessibilityLabel)")
        if let placeholderValue = accessibilityPlaceholderValue {
            fields.append("placeholderValue: \(placeholderValue)")
        }
        fields.append("isDefinitelyHidden: \(isDefinitelyHidden)")
        if let value = accessibilityValue {
            fields.append("value: \(value)")
        }
        fields.append("isEnabled: \(isEnabled)")
        // fields.append("isSelected: \(selected)")
        if let pathDescription = xcElementSnapshot.pathDescription as String? {
            fields.append("pathDescription: \(pathDescription)")
        }
        return fields.joined(separator: "\n")
    }
}
