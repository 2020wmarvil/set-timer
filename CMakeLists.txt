cmake_minimum_required(VERSION 3.1)

project(Set_Timer VERSION 1.0 DESCRIPTION "Nuanced timing of sets." LANGUAGES CXX)

find_package(PkgConfig)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})
