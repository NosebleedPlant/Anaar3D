cmake_minimum_required(VERSION 3.1)
project(imgui)

add_library(imgui)
target_sources(imgui PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_demo.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_draw.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_tables.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_widgets.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/misc/cpp/imgui_stdlib.cpp"
)
target_include_directories(imgui 
PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/imgui"
PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends"
PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/imgui/misc")
target_link_libraries(imgui PUBLIC glfw glad)

project(implot)
add_library(implot)
target_sources(implot PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/implot/implot.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/implot/implot_items.cpp")
target_include_directories(implot PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/implot")
target_link_libraries(implot imgui)