cmake_minimum_required(VERSION 2.8)
project(CorruptionTests)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS})

add_executable( test
    corruptionTest.cpp 
    ../filters/Distortion.hpp ../filters/Distortion.cpp
    ../filters/Freeze.hpp ../filters/Freeze.cpp
    ../filters/White.hpp ../filters/White.cpp
    ../filters/Translate.hpp ../filters/Translate.cpp
    catch.hpp)

target_link_libraries( test
    ${OpenCV_LIBS} 
)

