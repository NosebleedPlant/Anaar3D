#include "AnaarGL/VertexBuffer.hpp"

using namespace AnaarGL;

VertexBuffer::VertexBuffer(GLsizeiptr size, GLfloat* vertices){
    glGenBuffers(1,&_render_id);
    glBindBuffer(GL_ARRAY_BUFFER,_render_id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); 
}

GLuint VertexBuffer::get_id(){
    return _render_id;
}

void VertexBuffer::bind(){
    glBindBuffer(GL_ARRAY_BUFFER,_render_id);
}

void VertexBuffer::unbind(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VertexBuffer::delete_buffer(){
    glDeleteBuffers(1,&_render_id);
}
