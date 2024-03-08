#pragma once
//external
#include <glad/glad.h>

namespace AnaarGL{
    class VertexBuffer{
        private:
            GLuint _render_id;
        public:
            VertexBuffer(GLsizeiptr size, GLfloat* vertices, GLenum draw_mode);
            
            static void bind(VertexBuffer &vbo);
            static void unbind();
            static void delete_buffer(VertexBuffer &vbo);
            
            static GLuint get_id(VertexBuffer &vbo);
    };
}