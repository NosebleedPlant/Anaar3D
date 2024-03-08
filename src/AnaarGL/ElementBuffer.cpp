#include "AnaarGL/ElementBuffer.hpp"

using namespace AnaarGL;

ElementBuffer::ElementBuffer(GLsizeiptr size, GLuint* indicies, GLenum draw_mode){
    glGenBuffers(1,&_render_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_render_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, draw_mode); 
}

void ElementBuffer::bind(ElementBuffer &ebo){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo._render_id);
}

void ElementBuffer::unbind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void ElementBuffer::delete_buffer(ElementBuffer &ebo){
    glDeleteBuffers(1,&ebo._render_id);
}

GLuint ElementBuffer::getID(ElementBuffer &ebo){
    return ebo._render_id;
}