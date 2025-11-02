cmake_minimum_required(VERSION 3.15)
project(box)

# 处理 CMP0167 策略
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif()

# 设置构建输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app/lib")

# 查找 Boost 依赖（移除 dll 组件，因为它不是链接库）
find_package(Boost REQUIRED COMPONENTS system filesystem)

# 设置安装路径（修正语法错误）
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/app")

# 生成动态库
add_library(hello SHARED src/hello.cpp)
add_library(hello_boost SHARED src/hello_boost.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 链接动态库和 Boost
target_link_libraries(${PROJECT_NAME} PRIVATE 
    hello
    hello_boost
    Boost::system
    Boost::filesystem
    # 不需要链接 Boost::dll，因为它是头文件库
)

# 设置 RPATH
set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "$ORIGIN/lib"
    BUILD_RPATH "$ORIGIN/lib"
)

# 安装配置
install(TARGETS hello DESTINATION lib)
install(TARGETS hello_boost DESTINATION lib)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)  # 可执行文件通常安装到 bin

# 获取并安装 Boost 库（如果需要）
if(Boost_FOUND)
    # 对于非头文件库，安装它们
    foreach(lib system filesystem)
        if(TARGET Boost::${lib})
            get_target_property(boost_lib_path Boost::${lib} IMPORTED_LOCATION)
            if(boost_lib_path)
                install(FILES "${boost_lib_path}" DESTINATION lib)  # 添加引号处理路径空格
            endif()
        endif()
    endforeach()
endif()