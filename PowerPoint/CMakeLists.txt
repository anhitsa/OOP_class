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
        user_interface/application_window.cpp
        user_interface/application_window.h
        user_interface/appliction_window.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PowerPoint
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        controller/controller.h controller/controller.cpp
        document/document.h document/document.cpp
        document/slide.h document/slide.cpp

        commands/command.h
        parser/commandparser.h parser/commandparser.cpp








        commands/addcommand.h commands/addcommand.cpp
        commands/removecommand.h commands/removecommand.cpp
        commands/displaycommand.h commands/displaycommand.cpp
        commands/changecommand.h commands/changecommand.cpp
        commands/exitcommand.h commands/exitcommand.cpp

        parser/lexer.h parser/lexer.cpp




        factory/commandfactory.h factory/commandfactory.cpp




        validator/validator.h validator/validator.cpp








        user_interface/draggableitemhandler.h user_interface/draggableitemhandler.cpp
        user_interface/uicomponent.h
        commands/savecommand.h commands/savecommand.cpp
        user_interface/itemrenderer.h user_interface/itemrenderer.cpp
        items/target.h
        commandHistory/commandhistory.h commandHistory/commandhistory.cpp
        commandHistory/stackcommandhistory.h commandHistory/stackcommandhistory.cpp
        actions/commandaction.h
        actions/addremoveaction.h actions/addremoveaction.cpp
        document/container.h document/container.cpp
        document/item.h document/item.cpp
        document/coord.h document/coord.cpp
        document/target.h






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
