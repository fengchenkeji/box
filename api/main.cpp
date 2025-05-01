// api/main.cpp
#include "main.h"
#include <fmt/core.h>
extern "C" {
    void hello() {
        fmt::print("Hello World\n");
    }
}