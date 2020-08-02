#include "Application.h"

// STL
#include <stdexcept>

namespace vx {
    Application::Application(int width, int height, std::string title)
            : _width(width)
            , _height(height)
            , _title(std::move(title)) {
        // GLFW initialization
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        // GLFW properties
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Window creation
        _window = std::shared_ptr<GLFWwindow>(
                glfwCreateWindow(
                        _width,
                        _height,
                        _title.c_str(),
                        nullptr,
                        nullptr
                ),
                // Custom ptr deleter
                [](GLFWwindow* ptr) {
                    glfwDestroyWindow(ptr);
                }
        );

        if (!_window) {
            glfwTerminate();
            throw std::runtime_error("Failed to open GLFW window");
        }

        glfwMakeContextCurrent(_window.get());

        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            throw std::runtime_error("Failed to initialize GLEW");
        }

        glfwSetInputMode(_window.get(), GLFW_STICKY_KEYS, GL_TRUE);
    }

    int Application::width() const {
        return _width;
    }

    int Application::height() const {
        return _height;
    }

    const std::string& Application::title() const {
        return _title;
    }

    std::shared_ptr<GLFWwindow> Application::window() const {
        return _window;
    }

    void Application::run(std::function<void()> renderHook) {
        while (!glfwWindowShouldClose(_window.get())) {
            // Rendering is inserted here
            renderHook();
            // Display rendered content
            glfwSwapBuffers(_window.get());
            // Fetch input events
            glfwPollEvents();
        }
    }
}