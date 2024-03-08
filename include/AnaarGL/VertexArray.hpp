#pragma once
//external
#include <glad/glad.h>
//custom
#include "AnaarGL/VertexBuffer.hpp"

namespace AnaarGL{
    class VertexArray{
        private:
            GLuint _render_id;
        public:
            VertexArray();
            
            static void bind(VertexArray &vao);
            static void unbind();
            static void delete_array(VertexArray &vao);

            static void link(
                VertexBuffer &vbo,      // VBO that is bound to this array.
                GLuint index,           // Index of the vertex attribute on the shader.
                GLsizeiptr size,        // Size of the vertex attribute, for position this is usally 3 floats. One for each axis.
                GLenum type,            // type used in the buffer.
                GLsizeiptr stride,      // space between each vertex coord, needed when a buffer includes other data like tex coords.
                void* offset);          // starting position for buffers that have other data like tex coords.
            
            static GLuint get_id(VertexArray &vao);
    };
}