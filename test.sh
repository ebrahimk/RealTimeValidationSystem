#!/bin/bash

cd ./Corruption/test
make clean 
make
clear
./test
make clean
cd ../../Comparator/test
make clean
make
clear
./test
make clean 
cd ../..
