// main.cpp（调用动态库的函数）
#include <iostream>
#include <boost/dll.hpp>
// 声明动态库中的函数
extern "C" void hello();

int main() {
    hello();  // 调用动态库中的函数
    try {
        // 加载动态库
        boot::dll::shared_library lib;

        // Linux: "./libmylib.so"
        // Windows: "mylib.dll"
        lib.load("lib/libhello_boost.so", dll::load_mode::default_mode);

        // 2. 获取函数指针
        // 方式 1: 使用 get<T>() 获取函数
        auto hi = lib.get<void()>("hi");
        hi();  // 调用动态库中的 hello()
    }
    return 0;
}