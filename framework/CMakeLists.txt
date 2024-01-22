project(AnaarFramework VERSION 0.0)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS 
    src/*.cpp 
    src/*.hpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    include 
    include/Anaar
    include/Anaar/math
)

target_precompile_headers(${PROJECT_NAME} PUBLIC
    include/Anaar/_pch.hpp
)


target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE implot)
target_link_libraries(${PROJECT_NAME} PRIVATE stb)