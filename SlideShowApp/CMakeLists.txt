cmake_minimum_required(VERSION 3.5)

project(SlideShowApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        UserInterface/applicationwindow.cpp
        UserInterface/applicationwindow.h
        UserInterface/applicationwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SlideShowApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        UserInterface/applicationwindow.h

        Renderer/renderer.h Renderer/renderer.cpp
        Serializer/serializer.h Serializer/serializer.cpp
        CommandLineInterface/Commands/addcommand.h CommandLineInterface/Commands/addcommand.cpp
        CommandLineInterface/Commands/removecommand.h CommandLineInterface/Commands/removecommand.cpp
        CommandLineInterface/Commands/changecommand.h CommandLineInterface/Commands/changecommand.cpp
        CommandLineInterface/Commands/displaycommand.h CommandLineInterface/Commands/displaycommand.cpp
        CommandLineInterface/Commands/drawcommand.h CommandLineInterface/Commands/drawcommand.cpp
        CommandLineInterface/Commands/savecommand.h CommandLineInterface/Commands/savecommand.cpp
        CommandLineInterface/Commands/command.h
        CommandLineInterface/Commands/exitcommand.h CommandLineInterface/Commands/exitcommand.cpp
        CommandLineInterface/CommandParser/commandparser.h CommandLineInterface/CommandParser/commandparser.cpp
        CommandLineInterface/CommandParser/lexer.h CommandLineInterface/CommandParser/lexer.cpp
        CommandLineInterface/CommandFactory/commandfactory.h CommandLineInterface/CommandFactory/commandfactory.cpp


        PresentationElements/document.h PresentationElements/document.cpp
        PresentationElements/slide.h PresentationElements/slide.cpp
        PresentationElements/Item/item.h PresentationElements/Item/item.cpp
        PresentationElements/Item/coord.h PresentationElements/Item/coord.cpp

        ActionHandler/Actions/changeaction.h ActionHandler/Actions/changeaction.cpp
        ActionHandler/Actions/commandaction.h
        ActionHandler/ActionManager/actionmanager.h ActionHandler/ActionManager/actionmanager.cpp

        PresentationElements/Item/rectanglegeometry.h PresentationElements/Item/rectanglegeometry.cpp
        Application/application.h Application/application.cpp
        UserInterface/commandlineinputbox.h UserInterface/commandlineinputbox.cpp

        CommandLineInterface/Controller/controller.h CommandLineInterface/Controller/controller.cpp
        ActionHandler/Actions/additemaction.h ActionHandler/Actions/additemaction.cpp
        ActionHandler/Actions/addslideaction.h ActionHandler/Actions/addslideaction.cpp
        ActionHandler/Actions/removeitemaction.h ActionHandler/Actions/removeitemaction.cpp
        ActionHandler/Actions/removeslideaction.h ActionHandler/Actions/removeslideaction.cpp
        Renderer/Shapes/Shape.h
        Renderer/Shapes/circle.h Renderer/Shapes/circle.cpp
        Renderer/Shapes/elipse.h Renderer/Shapes/elipse.cpp
        Renderer/Shapes/rectangle.h Renderer/Shapes/rectangle.cpp
        Renderer/Shapes/line.h Renderer/Shapes/line.cpp
        UserInterface/commandlineoutputlog.h UserInterface/commandlineoutputlog.cpp



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SlideShowApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SlideShowApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SlideShowApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SlideShowApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SlideShowApp)
endif()
set_target_properties(SlideShowApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SlideShowApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SlideShowApp)
endif()
