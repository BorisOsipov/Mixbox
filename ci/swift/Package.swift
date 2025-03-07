// swift-tools-version:4.2
// swiftlint:disable trailing_comma

import PackageDescription

let package = Package(
    name: "MixboxSwiftCI",
    products: [
        .executable(
            name: "TeamcityGrayBoxTestsBuild",
            targets: [
                "TeamcityGrayBoxTestsBuild"
            ]
        ),
        .executable(
            name: "TeamcityBlackBoxTestsBuild",
            targets: [
                "TeamcityBlackBoxTestsBuild"
            ]
        ),
        .executable(
            name: "TravisLogicTestsBuild",
            targets: [
                "TravisLogicTestsBuild"
            ]
        ),
        .executable(
            name: "TeamcityStaticChecksBuild",
            targets: [
                "TeamcityStaticChecksBuild"
            ]
        ),
        .executable(
            name: "TravisOversimplifiedDemoBuild",
            targets: [
                "TravisOversimplifiedDemoBuild"
            ]
        ),
        .executable(
            name: "TeamcityIpcDemoBuild",
            targets: [
                "TeamcityIpcDemoBuild"
            ]
        ),
        .executable(
            name: "TeamcityLogicTestsBuild",
            targets: [
                "TeamcityLogicTestsBuild"
            ]
        ),
        .executable(
            name: "TeamcityOversimplifiedDemoBuild",
            targets: [
                "TeamcityOversimplifiedDemoBuild"
            ]
        ),
        .executable(
            name: "TravisIpcDemoBuild",
            targets: [
                "TravisIpcDemoBuild"
            ]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/AliSoftware/Dip", .revision("e02f1697155cdcb546ee350e5803ecc6fc66cfa9"))
    ],
    targets: [
        .target(
            name: "TeamcityGrayBoxTestsBuild",
            dependencies: [
                "BuildDsl",
                "RunGrayBoxTestsTask",
                "SingletonHell",
            ]
        ),
        .target(
            name: "TeamcityBlackBoxTestsBuild",
            dependencies: [
                "BuildDsl",
                "RunBlackBoxTestsTask",
                "SingletonHell",
            ]
        ),
        .target(
            name: "Tasks",
            dependencies: [
                "CiFoundation",
            ]
        ),
        .target(
            name: "Di",
            dependencies: [
                "Bash",
                "Brew",
                "CiFoundation",
                "Cocoapods",
                "Dip",
                "Emcee",
                "Git",
                "Simctl",
                "SingletonHell",
                "Tasks",
            ]
        ),
        .target(
            name: "CheckDemoTask",
            dependencies: [
                "Bash",
                "SingletonHell",
                "Tasks",
            ]
        ),
        .target(
            name: "RunBlackBoxTestsTask",
            dependencies: [
                "Bash",
                "CiFoundation",
                "Emcee",
                "SingletonHell",
                "Tasks",
            ]
        ),
        .target(
            name: "StaticChecksTask",
            dependencies: [
                "Bash",
                "CiFoundation",
                "Cocoapods",
                "Git",
                "SingletonHell",
                "Tasks",
            ]
        ),
        .target(
            name: "CiFoundation",
            dependencies: [
            ]
        ),
        .testTarget(
            name: "AllTests",
            dependencies: [
                "Bash",
                "CiFoundation",
                "Di",
                "Simctl",
                "StaticChecksTask",
            ]
        ),
        .target(
            name: "TravisLogicTestsBuild",
            dependencies: [
                "BuildDsl",
                "RunUnitTestsTask",
            ]
        ),
        .target(
            name: "TeamcityStaticChecksBuild",
            dependencies: [
                "BuildDsl",
                "StaticChecksTask",
            ]
        ),
        .target(
            name: "Brew",
            dependencies: [
                "Bash",
            ]
        ),
        .target(
            name: "SingletonHell",
            dependencies: [
                "Bash",
                "CiFoundation",
                "Emcee",
                "Git",
                "Simctl",
            ]
        ),
        .target(
            name: "Bash",
            dependencies: [
                "CiFoundation",
            ]
        ),
        .target(
            name: "BuildDsl",
            dependencies: [
                "Di",
                "Tasks",
            ]
        ),
        .target(
            name: "Simctl",
            dependencies: [
                "Bash",
                "CiFoundation",
            ]
        ),
        .target(
            name: "TravisOversimplifiedDemoBuild",
            dependencies: [
                "BuildDsl",
                "CheckDemoTask",
            ]
        ),
        .target(
            name: "TeamcityIpcDemoBuild",
            dependencies: [
                "BuildDsl",
                "CheckIpcDemoTask",
            ]
        ),
        .target(
            name: "RunGrayBoxTestsTask",
            dependencies: [
                "Bash",
                "CiFoundation",
                "Emcee",
                "SingletonHell",
                "Tasks",
            ]
        ),
        .target(
            name: "TeamcityLogicTestsBuild",
            dependencies: [
                "BuildDsl",
                "RunUnitTestsTask",
            ]
        ),
        .target(
            name: "Emcee",
            dependencies: [
                "Bash",
                "Brew",
                "CiFoundation",
            ]
        ),
        .target(
            name: "CheckIpcDemoTask",
            dependencies: [
                "Bash",
                "SingletonHell",
                "Tasks",
            ]
        ),
        .target(
            name: "Cocoapods",
            dependencies: [
                "Bash",
            ]
        ),
        .target(
            name: "Git",
            dependencies: [
                "CiFoundation",
            ]
        ),
        .target(
            name: "TeamcityOversimplifiedDemoBuild",
            dependencies: [
                "BuildDsl",
                "CheckDemoTask",
            ]
        ),
        .target(
            name: "TravisIpcDemoBuild",
            dependencies: [
                "BuildDsl",
                "CheckIpcDemoTask",
            ]
        ),
        .target(
            name: "RunUnitTestsTask",
            dependencies: [
                "Bash",
                "CiFoundation",
                "Cocoapods",
                "Git",
                "SingletonHell",
                "Tasks",
            ]
        ),
    ],
    swiftLanguageVersions: [
        .v4_2
    ]
)
