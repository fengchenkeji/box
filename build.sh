# 清理并进入构建目录
rm -rf build/*
cd build

# 安装 Conan 依赖并生成工具链文件
conan install .. --build=missing --output-folder=. --generator=CMakeDeps --generator=CMakeToolchain -pr=../android.ini 

# 配置 CMake（显式指定工具链）
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

# 构建项目
cmake --build .

# 仅在构建成功后运行程序

