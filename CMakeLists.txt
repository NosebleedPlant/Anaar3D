cmake_minimum_required(VERSION 3.28)
project(Anaar3D VERSION 0.0)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -g)
endif()

# Enable Testing
include(CTest)

# Build dependencies
add_subdirectory(external)

# Get source files
file(GLOB SOURCE_FILES CONFIGURE_DEPENDS 
    src/*.cpp 
    src/*.hpp
    src/AnaarGL/*.cpp
    src/Mesh/*.cpp
)

#build make files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC 
    include
    include/Anaar3D/
    include/AnaarGL/
    include/Mesh/
)

#link dependencies
target_link_libraries(${PROJECT_NAME} 
    PUBLIC glfw
    PUBLIC glm
    PUBLIC glad
    # PUBLIC assimp
    PUBLIC stb
)

# Add Applications 
add_subdirectory(example)

# Add Testing Directory
if (BUILD_TESTING)
    project(unit_tests)

    # Get source files
    file(GLOB TEST_FILES CONFIGURE_DEPENDS 
        test/*.cpp 
        test/*.hpp
    )

    add_executable(${PROJECT_NAME} 
        ${TEST_FILES}
    )

    target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)
    target_link_libraries(${PROJECT_NAME} PUBLIC Anaar3D)

    include(GoogleTest)

    # Finds all the Google tests associated with the executable
    gtest_discover_tests(${PROJECT_NAME})
endif()
