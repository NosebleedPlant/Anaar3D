#include "texture.hpp"

Texture::Texture(){
    glGenTextures(1, &m_renderID);
};

void Texture::Bind(){
    glBindTexture(GL_TEXTURE_2D, m_renderID);
};

void Texture::Unbind(){
    glDeleteTextures(GL_TEXTURE_2D, &m_renderID);
};

void Texture::SetWrapping(GLenum x_mode,GLenum y_mode){
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, x_mode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, y_mode);
}

void Texture::SetFiltering(GLenum x_mode,GLenum y_mode){
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, x_mode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, y_mode);
}

void Texture::LoadImage(
        GLint level, 
        GLenum internal_format, GLenum format,
        GLsizei width, GLsizei height, GLint border, 
        GLenum type, void* data){
    glTexImage2D(GL_TEXTURE_2D,level,internal_format,width,height,border,format,type,data);
    glGenerateMipmap(GL_TEXTURE_2D);
}

GLuint Texture::getID(){
    return m_renderID;
}