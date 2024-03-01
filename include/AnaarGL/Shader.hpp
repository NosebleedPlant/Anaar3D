#pragma once
//external
#include <glad/glad.h>
#include <glm/glm.hpp>
//libraries
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace AnaarGL{
    class Shader
    {
        private:
            void _check_compile(GLuint shader, std::string type);
        
        public:
            unsigned int id = 0;
            Shader(const char* vertexPath, const char* fragmentPath);
            Shader(): Shader(
                "../resources/shaders/debug.vert",
                "../resources/shaders/debug.frag"){};
            void use() const;

            //Uniforms
            void set_bool(const std::string &name, bool value) const;
            void set_float(const std::string &name, float value) const;
    };
}