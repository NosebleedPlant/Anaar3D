project(glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)

project(glm)
set(GLM_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLM_BUILD_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(glm)

project(glad)
add_library(glad)
target_sources(glad PRIVATE glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

project(imgui)
add_library(imgui)
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
target_sources(imgui PRIVATE 
    "${IMGUI_DIR}/imgui.cpp"
    "${IMGUI_DIR}/imgui_demo.cpp"
    "${IMGUI_DIR}/imgui_draw.cpp"
    "${IMGUI_DIR}/imgui_tables.cpp"
    "${IMGUI_DIR}/imgui_widgets.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
    "${IMGUI_DIR}/misc/cpp/imgui_stdlib.cpp"
)
target_include_directories(imgui PUBLIC
    "${IMGUI_DIR}"
    "${IMGUI_DIR}/backends"
    "${IMGUI_DIR}/misc"
)
target_link_libraries(imgui PUBLIC glfw glad)

project(implot)
add_library(implot)
set(IMPLOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/implot)
target_sources(implot PRIVATE 
    "${IMPLOT_DIR}/implot.cpp"
    "${IMPLOT_DIR}/implot_items.cpp"
)
target_include_directories(implot PUBLIC "${IMPLOT_DIR}")
target_link_libraries(implot PUBLIC imgui)

project(stb)
add_library(stb)
set(STB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/stb)
file(GLOB STB_SRC CONFIGURE_DEPENDS 
    ${CMAKE_CURRENT_SOURCE_DIR}/stb/*.c
)
target_sources(stb PRIVATE 
    ${STB_SRC}
)
target_include_directories(stb PUBLIC "${STB_DIR}")
target_link_libraries(stb PUBLIC imgui)