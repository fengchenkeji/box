cmake_minimum_required(VERSION 3.15)
project(box)

# 设置构建输出路径（在 build/ 目录下）
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app")       # 可执行文件
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app/lib")  # 动态库

# 设置安装路径（安装到项目目录的 app/）
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/app")

# 生成动态库
add_library(hello SHARED src/hello.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 链接动态库
target_link_libraries(${PROJECT_NAME} PRIVATE hello)

# 设置 RPATH（可执行文件在 app/ 目录下，加载 app/lib/libhello.so）
set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "$ORIGIN/lib"
    BUILD_RPATH "$ORIGIN/lib"
)

# 安装配置
install(TARGETS hello DESTINATION lib)    # 动态库安装到 app/lib/
install(TARGETS ${PROJECT_NAME} DESTINATION .)  # 可执行文件安装到 app/