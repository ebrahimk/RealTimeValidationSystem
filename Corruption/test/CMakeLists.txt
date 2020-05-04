cmake_minimum_required(VERSION 2.8)
project(CorruptionTests)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 11)


add_executable( corruptionTest
    corruptionTest.cpp 
    ../filters/Distortion.hpp ../filters/Distortion.cpp
    ../filters/Freeze.hpp ../filters/Freeze.cpp
    ../filters/White.hpp ../filters/White.cpp
    ../filters/Translate.hpp ../filters/Translate.cpp)

target_link_libraries( corruptionTest
    ${OpenCV_LIBS} 
    gtest_main
)

add_test(
    NAME corruptionTest
    COMMAND corruptionTest
)