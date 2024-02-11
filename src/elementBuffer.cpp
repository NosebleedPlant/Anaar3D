#include "elementBuffer.hpp"

ElementBuffer::ElementBuffer(GLsizeiptr size, GLuint* indicies){
    glGenBuffers(1,&m_renderID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_renderID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW); 
}

void ElementBuffer::Bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_renderID);
}

void ElementBuffer::Unbind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void ElementBuffer::Delete(){
    glDeleteBuffers(1,&m_renderID);
}

GLuint ElementBuffer::getID(){
    return m_renderID;
}