#!/bin/bash
echo -e "\nBuilding server.\n"
cd lib
git clone https://github.com/google/googletest/
cd ..
mkdir build
cd build
cmake ..
make all

