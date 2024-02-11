#include "vertexBuffer.hpp"

VertexBuffer::VertexBuffer(GLsizeiptr size, GLfloat* vertices){
    glGenBuffers(1,&m_renderID);
    glBindBuffer(GL_ARRAY_BUFFER,m_renderID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);  
}

VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1,&m_renderID);
}

void VertexBuffer::bindBuffer(){
    glBindBuffer(GL_ARRAY_BUFFER,m_renderID);
}

void VertexBuffer::unbindBuffer(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VertexBuffer::deleteBuffer(){
    glDeleteBuffers(1,&m_renderID);
}

GLuint VertexBuffer::get_ID(){
    return m_renderID;
}