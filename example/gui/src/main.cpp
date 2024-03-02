
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Anaar3D/Core.hpp>
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(){
    auto context = Context(framebuffer_size_callback);
    Model test = Model(new Mesh::TriangleMesh(), new AnaarGL::Shader());
    context.update(&test);
    context.exit(
        [](){}
    );
    return 0;
}

/*
    Kinda like threejs
    make camera
    make model with mesh and shader
    make model2 with mesh and shader
    
    scene.camera = camera
    scene.add(unorderd set<model, model2>);

    while(context.is_open()){
        //move stuff
        //move cam
        context.update(scene,camera)
    }
*/

//other primitives: pyramid, cone, torus, box, plane, sphere, circle