#echo off

echo Building project...
cmake --build build

echo Running executable...
build\SideScroller.exe
