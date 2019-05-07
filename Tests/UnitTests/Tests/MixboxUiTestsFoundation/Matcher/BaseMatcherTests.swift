import MixboxUiTestsFoundation
import XCTest

class BaseMatcherTests {
    func assertMatches<T>(
        matcher: Matcher<T>,
        value: T,
        file: StaticString = #file,
        line: UInt = #line)
    {
        switch matcher.matches(value: value) {
        case .match:
            break
        case .mismatch(let percentageOfMatching, let mismatchDescription):
            XCTFail("""
                Expected: match
                Actual: mismatch
                Matcher: \(matcher.description)
                Value: \(value)
                PercentageOfMatching: \(percentageOfMatching)
                MismatchDescription: \(mismatchDescription)
                """,
                file: file,
                line: line
            )
        }
    }
    
    func assertMismatches<T>(
        matcher: Matcher<T>,
        value: T,
        percentageOfMatching: Double = 0,
        description: String? = nil,
        file: StaticString = #file,
        line: UInt = #line)
    {
        switch matcher.matches(value: value) {
        case .match:
            XCTFail("""
                Expected: mismatch
                Actual: match
                Matcher: \(matcher.description)
                Value: \(value)
                """,
                file: file,
                line: line
            )
        case .mismatch(let actualPercentageOfMatching, let mismatchDescription):
            if percentageOfMatching != actualPercentageOfMatching {
                XCTFail("""
                    Expected percentageOfMatching: \(percentageOfMatching)
                    Actual: \(actualPercentageOfMatching)
                    Matcher: \(matcher.description)
                    Value: \(value)
                    """,
                    file: file,
                    line: line
                )
            }
            if let description = description {
                let actualDescription = mismatchDescription()
                
                if description != actualDescription {
                    XCTFail("""
                        Expected mismatchDescription: \(description)
                        Actual: \(actualDescription)
                        Matcher: \(matcher.description)
                        Value: \(value)
                        """,
                        file: file,
                        line: line
                    )
                }
            }
        }
    }
}
