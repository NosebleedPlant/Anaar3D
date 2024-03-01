cmake_minimum_required(VERSION 3.24)
project(Anaar3D_gui VERSION 0.0)
file(GLOB GUI_SOURCE_FILES CONFIGURE_DEPENDS 
    gui/src/*.cpp 
    gui/src/*.hpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

add_executable(${PROJECT_NAME} ${GUI_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE Anaar3D)