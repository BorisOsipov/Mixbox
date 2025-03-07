import MixboxUiTestsFoundation

protocol OpenableScreen: class {
    var viewName: String { get }
}

extension OpenableScreen where Self: PageObjectElementRegistrar {
    var view: ViewElement {
        return element(viewName) { element in element.id == viewName }
    }
    
    func waitUntilViewIsLoaded() {
        view.assertIsDisplayed()
    }
}
