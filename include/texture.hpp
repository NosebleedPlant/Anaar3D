#pragma once
#include <glad/glad.h>
#include <stb_image.h>

class Texture{
    private:
        GLuint m_renderID;
    public:
        Texture();
        void Bind();
        void Unbind();
        void SetWrapping(GLenum x_mode,GLenum y_mode);
        void SetFiltering(GLenum x_mode,GLenum y_mode);
        void LoadImage(
            GLint level, 
            GLenum internal_format, GLenum format,
            GLsizei width, GLsizei height, GLint border, 
            GLenum type, void* offsetdata
        );
        GLuint getID();
};