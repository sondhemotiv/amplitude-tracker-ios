cmake_minimum_required(VERSION 3.16)

project(amplitude-tracker-ios VERSION 0.1 LANGUAGES CXX OBJCXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appamplitude-tracker-ios
    main.cpp
)

qt_add_qml_module(appamplitude-tracker-ios
    URI amplitude-tracker-ios
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES AmplitudeWrapper.cpp AmplitudeWrapper.h
        SOURCES ios/AmplitudeBridge.h ios/AmplitudeBridge.mm
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appamplitude-tracker-ios PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appamplitude-tracker-ios
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appamplitude-tracker-ios
    PRIVATE Qt6::Quick
    "-framework Foundation"
    "-framework UIKit"
)

set_source_files_properties(ios/AmplitudeBridge.mm PROPERTIES
    COMPILE_FLAGS "-fobjc-arc"
)

include(GNUInstallDirs)
install(TARGETS appamplitude-tracker-ios
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
