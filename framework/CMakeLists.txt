project(AnaarFramework VERSION 0.0)

add_library(${PROJECT_NAME} STATIC 
    src/math/adder.cpp 
    src/math/subtractor.cpp
    src/glfw_test.cpp
    src/glm_test.cpp
    src/imgui_test.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    include 
    include/Anaar
    include/Anaar/math
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE implot)