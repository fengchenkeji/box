cmake_minimum_required(VERSION 3.15)

project(BOX LANGUAGES CXX)

# 确保 Conan 工具链文件只包含一次
if(EXISTS "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
    include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
else()
    message(FATAL_ERROR "Conan toolchain file not found. Run 'conan install'.")
endif()

# 使用 Conan 查找并链接依赖
find_package(fmt REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

# 定义可执行文件
add_executable(my_app src/main.cpp)

# 将依赖库链接到可执行文件
target_link_libraries(my_app PRIVATE 
    fmt::fmt 
    Boost::filesystem
    Boost::system
)

# 添加任何子目录
add_subdirectory(api)