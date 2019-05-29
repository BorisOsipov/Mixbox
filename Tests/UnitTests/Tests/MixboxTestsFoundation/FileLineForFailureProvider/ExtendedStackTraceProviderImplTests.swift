import XCTest
import MixboxTestsFoundation
import MixboxFoundation

final class ExtendedStackTraceProviderImplTests: XCTestCase {
    private func currentFileLine(file: StaticString = #file, line: UInt = #line) -> HeapFileLine {
        return HeapFileLine(
            file: "\(file)",
            line: UInt64(line)
        )
    }
    
    private var provider = ExtendedStackTraceProviderImpl(
        stackTraceProvider: StackTraceProviderImpl(),
        extendedStackTraceEntryFromCallStackSymbolsConverter: ExtendedStackTraceEntryFromStackTraceEntryConverterImpl()
    )
    
    // TODO: Option to remove stacktrace of functions that generate stacktrace?
    func disabled_test_returns_same_count_of_entries_as_thread() {
        XCTAssertEqual(Thread.callStackReturnAddresses.count, provider.extendedStackTrace().count)
        XCTAssertEqual(Thread.callStackSymbols.count, provider.extendedStackTrace().count)
    }
    
    func test_on_real_trace() {
        var traceOrNil: [ExtendedStackTraceEntry]?
        let specialFile = FileForStacktraceTestsWithFixedNameAndLineNumbers {
            traceOrNil = self.provider.extendedStackTrace()
        }
        specialFile.func_line2()
        
        guard let trace = traceOrNil, trace.count > 5 else {
            XCTFail("Did not receive trace from extendedStackTrace()")
            return
        }
        
        XCTAssertEqual(trace[5].file?.mb_lastPathComponent, "FileForStacktraceTestsWithFixedNameAndLineNumbers.swift")
        XCTAssertEqual(trace[5].line, 10)
        XCTAssertEqual(trace[5].owner, "UnitTests")
        
        let xcode_10_2_1_expectedSymbol = "$S9UnitTests017FileForStacktraceB27WithFixedNameAndLineNumbersC11func_line10yyF"
        let xcode_10_0_and_10_1_expectedSymbol = "$s9UnitTests017FileForStacktraceB27WithFixedNameAndLineNumbersC11func_line10yyF"
        
        let actualSymbol = trace[5].symbol
        if actualSymbol != xcode_10_2_1_expectedSymbol && actualSymbol != xcode_10_0_and_10_1_expectedSymbol {
            XCTFail(
                "Expected symbol: \(xcode_10_2_1_expectedSymbol) or \(xcode_10_0_and_10_1_expectedSymbol), actual: \(String(describing: actualSymbol))"
            )
        }
        
        XCTAssertEqual(trace[5].demangledSymbol, "UnitTests.FileForStacktraceTestsWithFixedNameAndLineNumbers.func_line10() -> ()")
    }
}
