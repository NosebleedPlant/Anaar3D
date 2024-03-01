#pragma once
//external
#include <glad/glad.h>

namespace AnaarGL{
    class VertexBuffer{
        private:
            GLuint _render_id;
        public:
            VertexBuffer(GLsizeiptr size, GLfloat* vertices);
            
            GLuint get_id();
            void bind();
            void unbind();
            void delete_buffer();
    };
}