cmake_minimum_required(VERSION 3.28)
project(Anaar3D VERSION 0.0)
set(CMAKE_CXX_STANDARD 17)

# Build dependencies
add_subdirectory(external)

# Get source files
file(GLOB SOURCE_FILES CONFIGURE_DEPENDS 
    src/*.cpp 
    src/*.hpp
)

# Additional source files from header only libraries
set(STB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/stb)
set(STB_SOURCE_FILES 
    "${STB_DIR}/stb_image.h"
)

#build make files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${STB_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC 
    include
    include/Anaar3D/
    "${STB_DIR}"
)

#link dependencies
target_link_libraries(${PROJECT_NAME} 
    PUBLIC glfw
    PUBLIC glm
    PUBLIC glad
)
add_subdirectory(app)
