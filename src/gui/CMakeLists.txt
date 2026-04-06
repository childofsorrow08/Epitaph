add_library(epitaph_gui
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stuff.cpp
    
    # some shit
    ${cimgui_SOURCE_DIR}/imgui/backends/imgui_impl_sdl2.cpp
    ${cimgui_SOURCE_DIR}/imgui/backends/imgui_impl_sdlrenderer2.cpp
)

target_include_directories(epitaph_gui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include

    ${cimgui_SOURCE_DIR}
    ${cimgui_SOURCE_DIR}/imgui
    ${cimgui_SOURCE_DIR}/imgui/backends
)

target_link_libraries(epitaph_gui PRIVATE 
    epitaph_bridge 

    cimgui 
    SDL2::SDL2-static
)