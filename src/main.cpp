#include <iostream>
#include <fmt/format.h>  // 使用 fmt 库进行格式化输出

int main() {
    std::string name = "Conan";
    int version = 2;
    
    // 使用标准库输出
    std::cout << "Hello World from C++!" << std::endl;
    
    // 使用 fmt 库进行格式化输出（演示依赖管理）
    std::cout << fmt::format("This project uses {} v{}", name, version) << std::endl;
    
    return 0;
}
