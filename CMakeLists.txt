cmake_minimum_required(VERSION 3.16)
project(QtLearning)

# set this to the file path for the corresponding Qt version you're using
# usually mingw73_32 for windows
# clang_64 on osx
# linux you can figure it out
set(Qt5_DIR "~/Qt/5.14.2/clang_64/lib/cmake/Qt5")


set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)


set(CMAKE_CXX_STANDARD 14)

set(project_ui
        resources/mainwindow.ui)

set(project_headers
        resources/mainwindow.h)

set(project_sources
        src/main.cpp
        resources/mainwindow.cpp)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})

add_executable(${PROJECT_NAME}
        ${project_headers}
        ${project_sources}
        ${project_headers_wrapped}
        ${project_sources_moc})

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)