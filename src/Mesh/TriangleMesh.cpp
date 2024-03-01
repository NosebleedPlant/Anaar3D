#include "Mesh/TriangleMesh.hpp"

using namespace Mesh;

TriangleMesh::TriangleMesh(){
    _vao.bind();
    _vao.link(_vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    _vao.unbind();
}

void TriangleMesh::draw(){
    _vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}