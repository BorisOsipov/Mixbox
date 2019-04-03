public final class ElementSettings {
    public let name: String // TODO: rename to elementName
    public let matcher: ElementMatcher
    public let searchMode: SearchMode
    public let searchTimeout: TimeInterval // TODO: Rename to interactionTimeout
    public let interactionMode: InteractionMode
    
    public init(
        name: String,
        matcher: ElementMatcher,
        searchMode: SearchMode,
        searchTimeout: TimeInterval?, // nil == default
        interactionMode: InteractionMode)
    {
        self.name = name
        self.matcher = matcher
        self.searchMode = searchMode
        self.searchTimeout = searchTimeout ?? 15
        self.interactionMode = interactionMode
    }
    
    func with(name: String) -> ElementSettings {
        return ElementSettings(
            name: name,
            matcher: matcher,
            searchMode: searchMode,
            searchTimeout: searchTimeout,
            interactionMode: interactionMode
        )
    }
    
    func with(matcher: ElementMatcher) -> ElementSettings {
        return ElementSettings(
            name: name,
            matcher: matcher,
            searchMode: searchMode,
            searchTimeout: searchTimeout,
            interactionMode: interactionMode
        )
    }
    
    func with(searchMode: SearchMode) -> ElementSettings {
        return ElementSettings(
            name: name,
            matcher: matcher,
            searchMode: searchMode,
            searchTimeout: searchTimeout,
            interactionMode: interactionMode
        )
    }
    
    func with(searchTimeout: TimeInterval?) -> ElementSettings {
        return ElementSettings(
            name: name,
            matcher: matcher,
            searchMode: searchMode,
            searchTimeout: searchTimeout,
            interactionMode: interactionMode
        )
    }
    
    func with(interactionMode: InteractionMode) -> ElementSettings {
        return ElementSettings(
            name: name,
            matcher: matcher,
            searchMode: searchMode,
            searchTimeout: searchTimeout,
            interactionMode: interactionMode
        )
    }
}

extension ElementSettings {
    public var shouldAutoScroll: Bool {
        return searchMode == .scrollUntilFound
    }
}
