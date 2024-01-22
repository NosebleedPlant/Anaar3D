#include <implot.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "PrimitiveRenderer.hpp"
#include "Shader.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int anaar_framework::CreateAFContext_Raw()
{
    if (!glfwInit()) {
        std::cout << "FAILED to init GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "FAILED to create GLFW Windw" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "FAILED to intialize GLAD" << std::endl;
        return -1;
    }

    // TODO: change this so that it uses relative directories or so that cmake packages the shaders with the rest 
    // "copy files cmake"
    // custom command in cmake seems to be the way to go
    Shader ourShader(
        "/home/yarrow/Anaar/framework/shaders/test.vs", 
        "/home/yarrow/Anaar/framework/shaders/test.fs"
    );

    float vertices[] = {
     0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,// top right
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,// bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 0.0f,// bottom left
    -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    unsigned int VAO;                                                             
    glGenVertexArrays(1, &VAO);                                                         // Make VAO

    unsigned int VBO;                                                                
    glGenBuffers(1, &VBO);                                                              // Make VBO
    
    //First Triangle
    glBindVertexArray(VAO);                                                         
    glBindBuffer(GL_ARRAY_BUFFER, VBO);                                             
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);    

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);     
    glEnableVertexAttribArray(0);                       
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);                                                                          

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);                                                   // Unbind VBO
    glBindVertexArray(0);                                                               // Unbind VAO


    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
