cmake_minimum_required(VERSION 3.10)
project(box)

# 设置安装路径（可选，默认是 /usr/local）
set(CMAKE_INSTALL_PREFIX ./bin/app")

# 生成动态库
add_library(hello SHARED src/hello.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 链接动态库
target_link_libraries(${PROJECT_NAME} PRIVATE hello)

# 设置 RPATH：使可执行文件在运行时从 `$ORIGIN/../lib` 查找 .so
set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "$ORIGIN/../lib"  # 安装后：./bin/app/box 查找 ./bin/app/../lib/
    BUILD_RPATH "$ORIGIN"          # 构建时：./box 直接从当前目录查找
)

# 安装动态库到 lib/，可执行文件到 bin/
install(TARGETS hello DESTINATION lib)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)