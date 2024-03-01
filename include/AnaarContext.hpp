#pragma once
//external
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//libraries
#include <iostream>
#include <functional>

#include "Anaar3D/Primitive.hpp"

class AnaarContext {
    private:
        GLFWwindow* _window;
        int _initialize_glfw(int major_vrsn, int minor_vrsn);
        int _initialize_glad();
        GLFWwindow* _create_window(GLFWframebuffersizefun resize_callback);
    public:
        AnaarContext(GLFWframebuffersizefun resize_callback, bool depth_enabled = false);
        void start(void(*func)());
        void update(Primitive::Triangle* test);
        void exit(void(*func)());
};