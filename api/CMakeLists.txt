cmake_minimum_required(VERSION 3.15)

# 定义项目名称和使用的编程语言
project(MyProject_api LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 启用位置无关代码（共享库必需）
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# 包含Conan生成的配置信息
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)  # 修正路径为更常见的构建目录

# 查找Conan管理的依赖库
find_package(fmt REQUIRED)

# 添加共享库目标（修正目标名称和链接关系）
add_library(hello SHARED main.cpp)

# 链接Conan管理的依赖库（修正目标名称）
target_link_libraries(hello PRIVATE fmt::fmt)

# 设置头文件路径（供外部调用者包含）
target_include_directories(hello
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}  # 暴露当前目录作为头文件搜索路径
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  # 推荐使用include目录
)

# 设置共享库的输出路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)