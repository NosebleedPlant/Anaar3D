#include "Mesh/QuadMesh.hpp"

using namespace Mesh;

QuadMesh::QuadMesh(){
    AnaarGL::VertexArray::bind(_vao);
    AnaarGL::ElementBuffer::bind(_ebo);
    AnaarGL::VertexArray::link(_vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    AnaarGL::VertexArray::unbind();
    AnaarGL::ElementBuffer::unbind();
}

void QuadMesh::draw(){
    AnaarGL::VertexArray::bind(_vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}