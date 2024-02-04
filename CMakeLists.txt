cmake_minimum_required(VERSION 3.28)

project(Anaar3D VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS 
    src/*.cpp 
    src/*.hpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC 
    include
    include Anaar3D/
)

add_subdirectory(app)
