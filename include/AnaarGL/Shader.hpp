#pragma once
//external
#include <glad/glad.h>
#include <glm/glm.hpp>
//std libraries
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace AnaarGL{
    class Shader
    {
        private:
            static void _check_compile(GLuint shader, std::string type);
        
        public:
            unsigned int id = 0;
            
            Shader(const char* vertexPath, const char* fragmentPath);
            Shader(): Shader(
                "../resources/shaders/debug.vert",
                "../resources/shaders/debug.frag"){};
            
            static void use(Shader &shader);

            //Uniforms
            static void set_bool(Shader &shader, const std::string &name, bool value);
            static void set_float(Shader &shader, const std::string &name, float value);
    };
}