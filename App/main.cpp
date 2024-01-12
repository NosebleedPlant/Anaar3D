#include <AnaarDana/math/adder.hpp>
#include <AnaarDana/core_test.hpp>
#include <glm/vec2.hpp>
#include <iostream>

int main(void)
{
    AnaarDana::check_glm(0.5, glm::vec2(0.5f, 0.5f));
    AnaarDana::test_imgui();

    return 0;
}