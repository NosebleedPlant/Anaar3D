#include "Context.hpp"

int Context::_initialize_glfw(int major_vrsn, int minor_vrsn){
    if (!glfwInit()) {
        std::cout << "FAILED to init GLFW" << std::endl;
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major_vrsn);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor_vrsn);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return EXIT_SUCCESS;
}

int Context::_initialize_glad(){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "FAILED to intialize GLAD" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void _resize_window(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* Context::_create_window(const char* title, unsigned int resolution_x, unsigned int resolution_y){
    GLFWwindow* window = glfwCreateWindow(resolution_x, resolution_y, title, NULL, NULL);
    if (window == NULL) {
        std::cout << "FAILED to create GLFW Windw" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, _resize_window);
    return window;
}


void Context::create(const char* title, int x_resolution, int y_resolution, bool depth_enabled){    
    _initialize_glfw(4,2);
    _window = _create_window(title,x_resolution,y_resolution);
    _initialize_glad();
    if(depth_enabled){
        glEnable(GL_DEPTH_TEST);
    }
}

void Context::clear(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Context::close(){
    glfwTerminate();
}

void Context::render(Model* test){
    test->draw();
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

bool Context::check_open(){
    return !(glfwWindowShouldClose(_window));
}