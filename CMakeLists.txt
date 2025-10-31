cmake_minimum_required(VERSION 3.10)
project(box)

set(CMAKE_INSTALL_PREFIX "./app")

# 生成动态库
add_library(hello SHARED src/hello.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 链接动态库
target_link_libraries(${PROJECT_NAME} PRIVATE hello)

# 设置 RPATH（修复空格和括号问题）
set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "\$ORIGIN/lib"  # 属性名后必须有空格
    BUILD_RPATH "\$ORIGIN/lib"    # 此处同理
)  # 闭合括号不可缺失

# 安装配置
install(TARGETS hello DESTINATION lib)
install(TARGETS ${PROJECT_NAME} DESTINATION ./)