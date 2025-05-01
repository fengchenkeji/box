#include <fmt/core.h>      // 包含 fmt 库，用于格式化输出
#include <boost/dll.hpp>   // 包含 Boost.DLL 库，用于动态加载共享库

int main() {
    fmt::print("Hello World\n");  // 使用 fmt 库打印 "Hello World"

    // 动态加载共享库并调用函数
    boost::dll::shared_library("api/libhello.so").get<void()>("hello")();
}