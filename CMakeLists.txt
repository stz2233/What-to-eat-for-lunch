cmake_minimum_required(VERSION 3.10)
project(FoodManagementSystem)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加源文件和头文件目录
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# 生成可执行文件
add_executable(FoodManagementSystem ${SOURCES})
