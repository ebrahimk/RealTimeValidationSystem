#!/bin/bash

clear
cd ./Corruption/test 
echo -e "\e[96mBuilding Corruption unit test suite"
make clean 
make
echo -e "\e[95mBuild successful"
clear
echo -e "\e[96mStarting Corruption unit tests"
./test
echo -e "\e[95mTests complete"
make clean

cd ../../Comparator/test
make clean
echo -e "\e[95mBuilding Comparison unit test suite..."
make
echo -e "\e[96mBuild successful"
clear
echo -e "\e[95mStarting Comparison unit test suite..."
./test
make clean
echo -e "\e[96mTests complete"
cd ../..
