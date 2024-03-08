#include "AnaarGL/VertexBuffer.hpp"

using namespace AnaarGL;

VertexBuffer::VertexBuffer(GLsizeiptr size, GLfloat* vertices, GLenum draw_mode){
    glGenBuffers(1,&_render_id);
    glBindBuffer(GL_ARRAY_BUFFER,_render_id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, draw_mode); 
}

void VertexBuffer::bind(VertexBuffer &vbo){
    glBindBuffer(GL_ARRAY_BUFFER,vbo._render_id);
}

void VertexBuffer::unbind(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VertexBuffer::delete_buffer(VertexBuffer &vbo){
    glDeleteBuffers(1,&vbo._render_id);
}

GLuint VertexBuffer::get_id(VertexBuffer &vbo){
    return vbo._render_id;
}
