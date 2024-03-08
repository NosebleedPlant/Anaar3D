#pragma once
//external
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//custom
#include "AnaarGL/VertexArray.hpp"
#include "AnaarGL/VertexBuffer.hpp"
#include "Mesh/IMesh.hpp"
//std libraries
#include <iostream>

namespace Mesh{
    class TriangleMesh: public IMesh{
        private:
            float _vertices[9] = {
               -0.5f, -0.5f, 0.0f, // left  
                0.5f, -0.5f, 0.0f, // right 
                0.0f,  0.5f, 0.0f  // top   
            };
            
            AnaarGL::VertexArray _vao = AnaarGL::VertexArray();
            AnaarGL::VertexBuffer _vbo = AnaarGL::VertexBuffer(sizeof(_vertices), _vertices, GL_STATIC_DRAW);

        public:
            TriangleMesh();
            virtual void draw() override;
    };
}