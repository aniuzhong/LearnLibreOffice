cmake_minimum_required(VERSION 3.25.1)

project(LearnLibreOffice C)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK4 REQUIRED gtk4)
include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

pkg_check_modules(gstreamr-1.0 REQUIRED gstreamer-1.0)
include_directories(${gstreamr-1.0_INCLUDE_DIRS})
link_directories(${gstreamr-1.0_LIBRARY_DIRS})

add_subdirectory(LearnCairo)
# add_subdirectory(LearnGTK)
add_subdirectory(LearnGstreamer)