#include "Primitive/Triangle.hpp"

void Primitive::Triangle::draw(){
    _shader.use();
    _mesh.draw();
};