#include "AnaarGL/VertexArray.hpp"

using namespace AnaarGL;

VertexArray::VertexArray(){
    glGenVertexArrays(1, &_render_id);
};

GLuint VertexArray::get_id(){
    return _render_id;
}

void VertexArray::bind(){
    glBindVertexArray(_render_id);
};

void VertexArray::unbind(){
    glBindVertexArray(0);
};

void VertexArray::link(VertexBuffer &vbo, GLuint index, GLsizeiptr size, GLenum type, GLsizeiptr stride, void* offset){
    vbo.bind();
    glVertexAttribPointer(index, size, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(index);
    vbo.unbind();
};

void VertexArray::delete_buffer(){
    glDeleteVertexArrays(1,&_render_id);
};