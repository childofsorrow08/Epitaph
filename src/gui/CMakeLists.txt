add_library(epitaph_gui
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stuff.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/init/init_fonts.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/init/init_window.c

    ${CMAKE_CURRENT_SOURCE_DIR}/src/init/fonts/ibm_plex_sans_medium_18.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/init/fonts/ibm_plex_sans_medium_30.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/init/fonts/ibm_plex_sans_regular_16.c

    ${CMAKE_CURRENT_SOURCE_DIR}/src/init/fonts/yuji_boku_16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/init/fonts/yuji_boku_24.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/init/fonts/yuji_boku_45.c

    ${CMAKE_CURRENT_SOURCE_DIR}/src/pages/home_page.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pages/settings_page.c

    # some shit
    ${cimgui_SOURCE_DIR}/imgui/backends/imgui_impl_sdl2.cpp
    ${cimgui_SOURCE_DIR}/imgui/backends/imgui_impl_sdlrenderer2.cpp

    ${PROJECT_SOURCE_DIR}/build/generated/src/assets.c
)

target_include_directories(epitaph_gui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include

    ${cimgui_SOURCE_DIR}
    ${cimgui_SOURCE_DIR}/imgui
    ${cimgui_SOURCE_DIR}/imgui/backends

    ${PROJECT_SOURCE_DIR}/build/generated/include
)

target_link_libraries(epitaph_gui PRIVATE 
    epitaph_bridge 

    cimgui 
    SDL2::SDL2-static
)