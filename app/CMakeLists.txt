cmake_minimum_required(VERSION 3.28)
project(AnaarApp VERSION 0.0)

set(SOURCE_FILES 
    src/test.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE glm)
target_link_libraries(${PROJECT_NAME} PRIVATE AnaarFramework)

