@echo off

mkdir build
cd build
cmake ../src
cmake --build .
cd Debug
