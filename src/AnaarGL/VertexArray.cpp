#include "AnaarGL/VertexArray.hpp"

using namespace AnaarGL;

VertexArray::VertexArray(){
    glGenVertexArrays(1, &_render_id);
};

void VertexArray::bind(VertexArray &vao){
    glBindVertexArray(vao._render_id);
};

void VertexArray::unbind(){
    glBindVertexArray(0);
};

void VertexArray::delete_array(VertexArray &vao){
    glDeleteVertexArrays(1,&vao._render_id);
};

void VertexArray::link(VertexBuffer &vbo, GLuint index, GLsizeiptr size, GLenum type, GLsizeiptr stride, void* offset){
    VertexBuffer::bind(vbo);
    glVertexAttribPointer(index, size, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(index);
    VertexBuffer::unbind();
};

GLuint VertexArray::get_id(VertexArray &vao){
    return vao._render_id;
}