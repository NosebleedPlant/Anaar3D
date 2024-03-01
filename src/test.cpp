#include "test.hpp"
#include <iostream>

void Test::test_outpt(){
    std::cout<<"HelloWorld!"<<std::endl;
}

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "AnaarContext.hpp"
#include "Anaar3D/Primitive.hpp"

#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int Test::CreateAFContext_Raw()
{    
    auto context = AnaarContext(framebuffer_size_callback);
    
    Primitive::Triangle test = Primitive::Triangle();
    
    context.update(&test);
    context.exit(
        [](){}
    );
    return 0;
}


//TODO:
//-create lambdas