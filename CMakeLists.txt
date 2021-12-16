cmake_minimum_required(VERSION 3.12)

project(CMakeAdobeNativeExtension VERSION 0.1
             DESCRIPTION "Adobe Native Extension template to use with CMake and vcpkg."
             HOMEPAGE_URL "https://github.com/al-sabr/FractalServer")

find_package(flash-runtime-extensions CONFIG REQUIRED)

add_library(${PROJECT_NAME} SHARED src/dllMain.cpp include/dllMain.h)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE flash-runtime-extensions::flash-runtime-extensions)