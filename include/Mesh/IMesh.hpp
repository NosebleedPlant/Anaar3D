#pragma once
namespace Mesh
{
    /// @brief interface that inforces implementation of draw function on all meshes
    class IMesh{
        public:
            virtual void draw() = 0;
    };
}
