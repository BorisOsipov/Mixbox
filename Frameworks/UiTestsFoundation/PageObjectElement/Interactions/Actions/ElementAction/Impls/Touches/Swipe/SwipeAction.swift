import MixboxUiKit

public final class SwipeAction: ElementInteraction {
    private let swipeActionPathCalculator: SwipeActionPathCalculator
    private let swipeActionDescriptionProvider: SwipeActionDescriptionProvider
    private let minimalPercentageOfVisibleArea: CGFloat
    
    public init(
        startPoint: SwipeActionStartPoint,
        endPoint: SwipeActionEndPoint,
        speed: TouchActionSpeed?,
        minimalPercentageOfVisibleArea: CGFloat)
    {
        let swipeActionPathSettings = SwipeActionPathSettings(
            startPoint: startPoint,
            endPoint: endPoint,
            speed: speed
        )
        
        self.swipeActionPathCalculator = SwipeActionPathCalculator(
            swipeActionPathSettings: swipeActionPathSettings
        )
        
        self.swipeActionDescriptionProvider = SwipeActionDescriptionProvider(
            swipeActionPathSettings: swipeActionPathSettings,
            minimalPercentageOfVisibleArea: minimalPercentageOfVisibleArea
        )
        
        self.minimalPercentageOfVisibleArea = minimalPercentageOfVisibleArea
    }
    
    public func with(
        dependencies: ElementInteractionDependencies)
        -> ElementInteractionWithDependencies
    {
        return WithDependencies(
            dependencies: dependencies,
            swipeActionPathCalculator: swipeActionPathCalculator,
            swipeActionDescriptionProvider: swipeActionDescriptionProvider,
            minimalPercentageOfVisibleArea: minimalPercentageOfVisibleArea
        )
    }
    
    public final class WithDependencies: ElementInteractionWithDependencies {
        private let dependencies: ElementInteractionDependencies
        private let swipeActionPathCalculator: SwipeActionPathCalculator
        private let swipeActionDescriptionProvider: SwipeActionDescriptionProvider
        private let minimalPercentageOfVisibleArea: CGFloat
        
        public init(
            dependencies: ElementInteractionDependencies,
            swipeActionPathCalculator: SwipeActionPathCalculator,
            swipeActionDescriptionProvider: SwipeActionDescriptionProvider,
            minimalPercentageOfVisibleArea: CGFloat)
        {
            self.dependencies = dependencies
            self.swipeActionPathCalculator = swipeActionPathCalculator
            self.swipeActionDescriptionProvider = swipeActionDescriptionProvider
            self.minimalPercentageOfVisibleArea = minimalPercentageOfVisibleArea
        }
    
        public func description() -> String {
            return swipeActionDescriptionProvider.swipeActionDescription(
                elementName: dependencies.elementInfo.elementName
            )
        }
        
        public func interactionFailureShouldStopTest() -> Bool {
            return true
        }
        
        public func perform() -> InteractionResult {
            return dependencies.interactionRetrier.retryInteractionUntilTimeout {
                [dependencies, swipeActionPathCalculator, minimalPercentageOfVisibleArea] _ in
                
                dependencies.snapshotResolver.resolve(minimalPercentageOfVisibleArea: minimalPercentageOfVisibleArea) { elementSnapshot in
                    let path = swipeActionPathCalculator.path(elementSnapshot: elementSnapshot)
                    
                    dependencies.retriableTimedInteractionState.markAsImpossibleToRetry()
                    
                    return dependencies.interactionResultMaker.makeResultCatchingErrors {
                        try dependencies.eventGenerator.pressAndDrag(
                            from: path.startPoint,
                            to: path.endPoint,
                            durationOfInitialPress: 0,
                            velocity: path.velocity,
                            cancelInertia: false
                        )
                        
                        return .success
                    }
                }
            }
        }
    }
}
