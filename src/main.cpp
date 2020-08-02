#include <iostream>

#include "Application.h"

int main() {
    try {
        auto app = vx::Application(800, 600, "Test");
        app.run([]() {});
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
