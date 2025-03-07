import MixboxArtifacts

public protocol InteractionResultMaker: class {
    func decorateFailure(
        interactionFailure: InteractionFailure)
        -> InteractionResult
}

extension InteractionResultMaker {
    public func failure(
        message: String,
        attachments: [Artifact] = [])
        -> InteractionResult
    {
        return decorateFailure(
            interactionFailure: InteractionFailure(
                message: message,
                attachments: attachments,
                nestedFailures: []
            )
        )
    }
    
    public func makeResultCatchingErrors(
        body: () throws -> (InteractionResult))
        -> InteractionResult
    {
        do {
            return try body()
        } catch {
            return failure(message: "\(error)")
        }
    }
}
