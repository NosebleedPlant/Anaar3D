#pragma once
//external
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//libraries
#include <iostream>
#include <functional>

#include "Model.hpp"
class Context {
    private:
        GLFWwindow* _window;
        int _initialize_glfw(int major_vrsn, int minor_vrsn);
        int _initialize_glad();
        GLFWwindow* _create_window(GLFWframebuffersizefun resize_callback);
    public:
        Context(GLFWframebuffersizefun resize_callback, bool depth_enabled = false);
        void start(void(*func)());
        void update(Model* test);
        void exit(void(*func)());
};