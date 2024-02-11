#pragma once
#include <glad/glad.h>

class VertexBuffer{
    private:
        GLuint m_renderID;
    public:
        VertexBuffer(GLsizeiptr size, GLfloat* vertices);
        void Bind();
        void Unbind();
        void Delete();
        GLuint getID();
};