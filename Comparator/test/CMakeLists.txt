cmake_minimum_required(VERSION 2.8)
project(CompareTests)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS})

add_executable( test
    comparatorTest.cpp 
    ../Compare.hpp ../Compare.cpp
../../Corruption/filters/Distortion.hpp
../../Corruption/filters/Distortion.cpp
../../Corruption/filters/Freeze.hpp
../../Corruption/filters/Freeze.cpp
../../Corruption/filters/Translate.hpp
../../Corruption/filters/Translate.cpp
../../Corruption/filters/White.hpp
../../Corruption/filters/White.cpp
    catch.hpp)

target_link_libraries( test
    ${OpenCV_LIBS} 
)

