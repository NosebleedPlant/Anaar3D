#pragma once
//external
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//std libraries
#include <iostream>
#include <functional>

#include "Model.hpp"

void _resize(GLFWwindow* window, int width, int height);

class Context {
    private:
        GLFWwindow* _window;
        int _initialize_glfw(int major_vrsn, int minor_vrsn);
        int _initialize_glad();
        GLFWwindow* _create_window(const char* title, unsigned int resolution_x, unsigned int resolution_y);
    public:
        void create(const char* title, int x_resolution, int y_resolution, bool depth_enabled = false);        
        void clear();
        void close();
        void render(Model* test);
        bool check_open();
};