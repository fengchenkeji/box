cmake_minimum_required(VERSION 3.15)
project(box)

# 包含Conan生成的文件
include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

# 处理 CMP0167 策略
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif()

# 设置构建输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app/lib")

# 查找Boost
find_package(Boost REQUIRED COMPONENTS system filesystem)

# 设置安装路径
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/app")

# 生成动态库
add_library(hello SHARED src/hello.cpp)
add_library(hello_boost SHARED src/hello_boost.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 链接动态库和Boost
target_link_libraries(${PROJECT_NAME} PRIVATE 
    hello
    hello_boost
    Boost::system
    Boost::filesystem
)

# 设置RPATH
set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "$ORIGIN/../lib"
    BUILD_RPATH "$ORIGIN/../lib"
)

# 安装配置
install(TARGETS hello hello_boost
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(TARGETS ${PROJECT_NAME} 
        RUNTIME DESTINATION bin)

# 删除旧的conan_create_deploy调用