#pragma once

// STL
#include <string>
#include <memory>
#include <functional>

// OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace vx {
    class Application {
    public:
        Application(int width, int height, std::string title);

        [[nodiscard]] int width() const;
        [[nodiscard]] int height() const;
        [[nodiscard]] const std::string& title() const;
        [[nodiscard]] std::shared_ptr<GLFWwindow> window() const;
        void run(std::function<void()> renderHook);

    private:
        int _width;
        int _height;
        std::string _title;
        std::shared_ptr<GLFWwindow> _window;
    };
}