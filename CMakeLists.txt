cmake_minimum_required(VERSION 3.10)
project(box)

set(CMAKE_INSTALL_PREFIX "app")
# 生成动态库
add_library(hello SHARED src/hello.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 链接动态库
target_link_libraries(${PROJECT_NAME} PRIVATE hello)

# 设置 RPATH，使可执行文件在运行时从 `$ORIGIN/lib` 查找 .so
set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "$ORIGIN/lib"  # 安装后运行时路径
    BUILD_RPATH "$ORIGIN/lib"    # 构建时运行时路径（适用于测试）
)

# 可选：将动态库安装到 lib 目录
install(TARGETS hello DESTINATION lib)
install(TARGETS ${PROJECT_NAME} DESTINATION .)