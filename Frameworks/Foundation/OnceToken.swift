// Execute things once.
// Possible extension: generic return type (I didn't find advantages of it over lazy yet).
// E.g.:
//
//  let onceToken: OnceToken<Int>
//  ...
//  return onceToken.executeOnce { 2 + 2 } // 4
//
public final class OnceToken {
    private let semaphore = DispatchSemaphore(value: 1)
    private var wasExecutedUnsafeValue = false
    
    public init() {
    }
    
    public func wasExecuted() -> Bool {
        if wasExecutedUnsafeValue {
            return true
        } else {
            semaphore.wait()
            defer {
                semaphore.signal()
            }
            return wasExecutedUnsafeValue
        }
    }
    
    public func executeOnce(_ closure: () throws -> ()) rethrows {
        if !wasExecutedUnsafeValue {
            semaphore.wait()
            
            if !wasExecutedUnsafeValue {
                wasExecutedUnsafeValue = true
                semaphore.signal()
                try closure()
            } else {
                semaphore.signal()
            }
        }
    }
}
