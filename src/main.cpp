// main.cpp（调用动态库的函数）
#include <iostream>

// 声明动态库中的函数
extern "C" void hello();

int main() {
    hello();  // 调用动态库中的函数
    return 0;
}