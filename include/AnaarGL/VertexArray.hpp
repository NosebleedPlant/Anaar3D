#pragma once
//external
#include <glad/glad.h>
//custom
#include "AnaarGL/VertexBuffer.hpp"

namespace AnaarGL{
    class VertexArray{
        private:
            GLuint _render_id;
        public:
            VertexArray();
            
            GLuint get_id();
            void unbind();
            void bind();
            void link(VertexBuffer &vbo, GLuint index, GLsizeiptr size, GLenum type, GLsizeiptr stride, void* offset);
            void delete_buffer();
    };
}