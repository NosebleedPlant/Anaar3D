#pragma once
#include "AnaarGL.hpp"
#include "TriangleMesh.hpp"

namespace Primitive{
    class Triangle{
        private:
            Mesh::TriangleMesh _mesh = Mesh::TriangleMesh();;
            AnaarGL::Shader _shader = AnaarGL::Shader();
        public:
            void draw();
    };
}