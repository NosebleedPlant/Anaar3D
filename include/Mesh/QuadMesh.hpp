#pragma once
//external
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//custom
#include "AnaarGL/VertexArray.hpp"
#include "AnaarGL/VertexBuffer.hpp"
#include "AnaarGL/ElementBuffer.hpp"
#include "Mesh/IMesh.hpp"
//std libraries
#include <iostream>

namespace Mesh{
    class QuadMesh: public IMesh{
        private:
            float _vertices[12] = {
                0.5f,  0.5f, 0.0f,  // top right
                0.5f, -0.5f, 0.0f,  // bottom right
               -0.5f, -0.5f, 0.0f,  // bottom left
               -0.5f,  0.5f, 0.0f   // top left 
            };

            unsigned int _indicies[6] = {
                0, 1, 3,   // first triangle
                1, 2, 3    // second triangle
            }; 

            AnaarGL::VertexArray _vao = AnaarGL::VertexArray();
            AnaarGL::VertexBuffer _vbo = AnaarGL::VertexBuffer(sizeof(_vertices), _vertices, GL_STATIC_DRAW);
            AnaarGL::ElementBuffer _ebo = AnaarGL::ElementBuffer(sizeof(_indicies),_indicies, GL_STATIC_DRAW);

        public:
            QuadMesh();
            virtual void draw() override;
    };
}