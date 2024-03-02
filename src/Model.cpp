#include "Model.hpp"

Model::Model(Mesh::IMesh* mesh, AnaarGL::Shader* shader){
    this->_mesh = mesh;
    this->_shader = shader;
} 

void Model::draw(){
    _shader->use();
    _mesh->draw();
};