cmake_minimum_required(VERSION 3.28)
project(MyStr)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(MyStr ${PROJECT_SOURCE_DIR}/src/main.cpp
        src/MyString.cpp
        include/MyString.h
)
