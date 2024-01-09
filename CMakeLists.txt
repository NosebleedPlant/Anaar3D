cmake_minimum_required(VERSION 3.22)

project(Anaar VERSION 0.0)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/main.cpp ${IMGUI_SRC})
target_link_libraries(
    ${PROJECT_NAME}
    glfw
    glad
    imgui
    implot
)