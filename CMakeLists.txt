cmake_minimum_required(VERSION 3.14)
project(treeview)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# External deps
include(FetchContent)
find_package(Qt6 COMPONENTS Core Gui Qml Quick QuickControls2 REQUIRED)

FetchContent_Declare(
        qttreeview
        GIT_REPOSITORY https://code.qt.io/qt-extensions/qttreeview.git
        GIT_TAG ec074133d9c652a4bb9bf03acf57343f9e7015e5
        GIT_SHALLOW true
)
FetchContent_MakeAvailable(qttreeview)

add_executable(${PROJECT_NAME} main.cpp)
qt6_add_resources(${PROJECT_NAME} resources
        PREFIX /
        FILES MainWindow.qml)
target_link_libraries(${PROJECT_NAME}
        PRIVATE Qt::Core Qt::Gui Qt::Qml Qt::Quick Qt::QuickControls2)
add_dependencies(${PROJECT_NAME} Qt6::qquicktreeviewplugin)
