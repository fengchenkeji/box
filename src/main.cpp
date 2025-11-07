#include <iostream>
#include <boost/dll/shared_library.hpp>  // 包含 Boost DLL 库头文件

int main() {
    try {
        // 正确使用 boost::dll 命名空间
        boost::dll::shared_library lib;

        // 加载动态库（Linux 路径格式）
        lib.load("lib/libhello_boost.so", boost::dll::load_mode::default_mode);

        // 获取并调用 hello 函数
        auto hello_func = lib.get<void()>("hello");
        hello_func();

        // 获取并调用 hi 函数
        auto hi_func = lib.get<void()>("hi");
        hi_func();
    }
    catch (const std::exception& e) {  // 添加异常捕获
        std::cerr << "运行时错误: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}