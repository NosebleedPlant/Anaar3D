#pragma once
#include <glad/glad.h>
#include "vertexBuffer.hpp"

class VertexArray{
    private:
        GLuint m_renderID;
    public:
        VertexArray();
        void Unbind();
        void Bind();
        void Delete();
        void Link(VertexBuffer &vbo, GLuint index, GLsizeiptr size, GLenum type, GLsizeiptr stride, void* offset);
        GLuint getID();
};