#include "vertexBuffer.hpp"

VertexBuffer::VertexBuffer(GLsizeiptr size, GLfloat* vertices){
    glGenBuffers(1,&m_renderID);
    glBindBuffer(GL_ARRAY_BUFFER,m_renderID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); 
}

void VertexBuffer::Bind(){
    glBindBuffer(GL_ARRAY_BUFFER,m_renderID);
}

void VertexBuffer::Unbind(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VertexBuffer::Delete(){
    glDeleteBuffers(1,&m_renderID);
}

GLuint VertexBuffer::getID(){
    return m_renderID;
}