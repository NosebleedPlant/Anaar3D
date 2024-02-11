#pragma once
#include <glad/glad.h>

class VertexBuffer{
    private:
        GLuint m_renderID;
    public:
        VertexBuffer(GLsizeiptr size, GLfloat* vertices);
        ~VertexBuffer();
        void bindBuffer();
        void unbindBuffer();
        void deleteBuffer();
        GLuint get_ID();
};