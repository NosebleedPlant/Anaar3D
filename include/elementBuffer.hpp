#pragma once
#include <glad/glad.h>

class ElementBuffer{
    private:
        GLuint m_renderID;
    public:
        ElementBuffer(GLsizeiptr size, GLuint* vertices);
        void Bind();
        void Unbind();
        void Delete();
        GLuint getID();
};