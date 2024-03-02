#pragma once
#include "Shader.hpp"
#include "Mesh/IMesh.hpp"

class Model{
    private:
        Mesh::IMesh* _mesh;
        AnaarGL::Shader* _shader;
    public:
        Model(Mesh::IMesh* mesh, AnaarGL::Shader* shader);
        void draw();
};