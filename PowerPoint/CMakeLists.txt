cmake_minimum_required(VERSION 3.5)

project(PowerPoint VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        user_interface/mainwindow.cpp
        user_interface/mainwindow.h
        user_interface/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PowerPoint
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        controller/controller.h controller/controller.cpp
        document/document.h document/document.cpp
        document/slide.h document/slide.cpp
        items/item.h items/item.cpp
        commands/command.h
        parser/commandparser.h parser/commandparser.cpp

        factory/itemfactory.h factory/itemfactory.cpp
        items/triangle.h items/triangle.cpp
        items/rectangle.h items/rectangle.cpp
        items/circle.h items/circle.cpp
        items/elipse.h items/elipse.cpp
        items/line.h items/line.cpp

        commands/addcommand.h commands/addcommand.cpp
        commands/removecommand.h commands/removecommand.cpp
        commands/displaycommand.h commands/displaycommand.cpp
        commands/changecommand.h commands/changecommand.cpp
        commands/exitcommand.h commands/exitcommand.cpp

        parser/lexer.h parser/lexer.cpp

        builders/addcommandbuilder.h builders/addcommandbuilder.cpp
        builders/commanddirector.h builders/commanddirector.cpp
        builders/commandbuilder.h
        factory/commandbuilderfactory.h factory/commandbuilderfactory.cpp
        builders/changecommandbuilder.h builders/changecommandbuilder.cpp
        builders/displaycommandbuilder.h builders/displaycommandbuilder.cpp
        builders/removecommandbuilder.h builders/removecommandbuilder.cpp
        builders/exitcommandbuilder.h builders/exitcommandbuilder.cpp
        user_interface/itemdrawer.h user_interface/itemdrawer.cpp




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PowerPoint APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PowerPoint SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PowerPoint
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PowerPoint PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PowerPoint)
endif()
set_target_properties(PowerPoint PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PowerPoint
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PowerPoint)
endif()
