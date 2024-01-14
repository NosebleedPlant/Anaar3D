#include <Anaar/math/adder.hpp>
#include <Anaar/core_test.hpp>
#include <glm/vec2.hpp>
#include <iostream>
#include "test.hpp"

int main(void)
{
    include_test::include_test_print();
    Anaar::check_glm(0.5, glm::vec2(0.5f, 0.5f));
    Anaar::test_imgui();

    return 0;
}