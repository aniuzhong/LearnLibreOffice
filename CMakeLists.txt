cmake_minimum_required(VERSION 3.25.1)

project(LearnLibreOffice C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

message(STATUS "----- GTK3_INCLUDE_DIRS: ${GTK4_INCLUDE_DIRS}")
message(STATUS "----- GKT3_LIBRARIES: ${GTK4_LIBRARY_DIRS}")
message(STATUS "----- GTK3_LINK_LIBRARIES: ${GTK4_LINK_LIBRARIES}")

add_subdirectory(LearnCairo)
add_subdirectory(LearnGTK)