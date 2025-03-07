#if MIXBOX_ENABLE_IN_APP_SERVICES

import MixboxIpcCommon

public protocol KeyboardEventInjector: class {
    func inject(events: [KeyboardEvent], completion: @escaping () -> ())
}

#endif
