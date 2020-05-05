cmake_minimum_required(VERSION 2.8)
project(CompareTests)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS})

add_executable( test
    comparatorTest.cpp 
    ../Compare.hpp ../Compare.cpp
    catch.hpp)

target_link_libraries( test
    ${OpenCV_LIBS} 
)

