#include "AnaarContext.hpp"

#pragma region  PRIVATE
    int AnaarContext::_initialize_glfw(int major_vrsn, int minor_vrsn){
        if (!glfwInit()) {
            std::cout << "FAILED to init GLFW" << std::endl;
            return EXIT_FAILURE;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major_vrsn);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor_vrsn);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        return EXIT_SUCCESS;
    }

    int AnaarContext::_initialize_glad(){
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            std::cout << "FAILED to intialize GLAD" << std::endl;
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

    GLFWwindow* AnaarContext::_create_window(GLFWframebuffersizefun resize_callback){
        GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
        if (window == NULL) {
            std::cout << "FAILED to create GLFW Windw" << std::endl;
            glfwTerminate();
            return nullptr;
        }

        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, resize_callback);
        return window;
    }
#pragma endregion

#pragma region PUBLIC
    AnaarContext::AnaarContext(GLFWframebuffersizefun resize_callback, bool depth_enabled){    
        _initialize_glfw(4,2);
        _window = _create_window(resize_callback);
        _initialize_glad();
        if(depth_enabled){
            glEnable(GL_DEPTH_TEST);
        }
    }

    void AnaarContext::update(Primitive::Triangle* test){

        while (!glfwWindowShouldClose(_window))
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            test->draw();
            glfwSwapBuffers(_window);
            glfwPollEvents();
        }
        return;
    }

    void AnaarContext::exit(void(*func)()){
        //call lambda
        func();
        glfwTerminate();
    }
#pragma endregion