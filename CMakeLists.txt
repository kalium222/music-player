cmake_minimum_required(VERSION 3.10)
project(music_player LANGUAGES CXX VERSION 0.1.2)
configure_file(Config.h.in Config.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MPV REQUIRED IMPORTED_TARGET mpv)
message(STATUS "MPV include dirs: ${MPV_INCLUDE_DIRS}")
message(STATUS "MPV libraries: ${MPV_LIBRARIES}")

set(EXECUTABLE ${PROJECT_NAME})
add_executable(${EXECUTABLE} src/main.cpp)
add_subdirectory(
    src/mpv_backend
)

target_link_libraries(${EXECUTABLE} PRIVATE
    PkgConfig::MPV
    mpv_backend
)

target_compile_options(${EXECUTABLE} PRIVATE
    -Wall
    -Wextra
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()
