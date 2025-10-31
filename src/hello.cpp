// main.cpp
#include <iostream>

// 导出一个函数（使用 `extern "C"` 避免 C++ 名称修饰）
extern "C" void hello() {
    std::cout << "Hello, World from .so!" << std::endl;
}