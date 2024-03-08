#pragma once
#include <glad/glad.h>

namespace AnaarGL{
    class ElementBuffer{
        private:
            GLuint _render_id;
        public:
            ElementBuffer(GLsizeiptr size, GLuint* vertices, GLenum draw_mode);

            static void bind(ElementBuffer &ebo);
            static void unbind();
            static void delete_buffer(ElementBuffer &ebo);

            static GLuint getID(ElementBuffer &ebo);
    };
}