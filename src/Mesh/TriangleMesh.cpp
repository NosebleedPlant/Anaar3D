#include "Mesh/TriangleMesh.hpp"

using namespace Mesh;

TriangleMesh::TriangleMesh(){
    AnaarGL::VertexArray::bind(_vao);
    AnaarGL::VertexArray::link(_vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    AnaarGL::VertexArray::unbind();
}

void TriangleMesh::draw(){
    AnaarGL::VertexArray::bind(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}