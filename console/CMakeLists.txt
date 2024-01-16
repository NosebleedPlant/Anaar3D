cmake_minimum_required(VERSION 3.24)
project(AnaarConsole VERSION 0.0)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS 
    src/*.cpp 
    src/*.hpp
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_precompile_headers(${PROJECT_NAME} REUSE_FROM AnaarFramework)

target_link_libraries(${PROJECT_NAME} PRIVATE glm)
target_link_libraries(${PROJECT_NAME} PRIVATE AnaarFramework)

