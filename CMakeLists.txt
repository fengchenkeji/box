cmake_minimum_required(VERSION 3.10)
project(box)

set(CMAKE_INSTALL_PREFIX "./app")

# 生成动态库
add_library(hello SHARED src/hello.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 链接动态库
target_link_libraries(${PROJECT_NAME} PRIVATE hello)

# 设置 RPATH（关键优化）
set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "\$ORIGIN/lib"
    BUILD_RPATH "\$ORIGIN/lib"
    # 允许运行时修改 RPATH（调试用）
    INSTALL_RPATH_USE_LINK_PATH TRUE
)

# 安装配置
install(TARGETS hello DESTINATION lib)
install(TARGETS ${PROJECT_NAME} DESTINATION ./)