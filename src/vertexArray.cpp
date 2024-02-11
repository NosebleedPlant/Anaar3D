#include "vertexArray.hpp"

VertexArray::VertexArray(){
    glGenVertexArrays(1, &m_renderID);
};

void VertexArray::Bind(){
    glBindVertexArray(m_renderID);
};

void VertexArray::Unbind(){
    glBindVertexArray(0);
};

void VertexArray::Delete(){
    glDeleteVertexArrays(1,&m_renderID);
};

void VertexArray::Link(VertexBuffer &vbo, GLuint index, GLsizeiptr size, GLenum type, GLsizeiptr stride, void* offset){
    vbo.Bind();
    glVertexAttribPointer(index, size, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(index);
    vbo.Unbind();
};

GLuint VertexArray::getID(){
    return m_renderID;
}