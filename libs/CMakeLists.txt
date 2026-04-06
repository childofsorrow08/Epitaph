# Many thanks to the authors of the libraries that will be found here, 
# because thanks to them I was able to get what I wanted - static 
# linking of libraries to the binary, without unnecessary dependencies.

include(FetchContent)

# ----------------------------------------------------- #
#                          GUI                          #
# ----------------------------------------------------- #

# --- SDL2 ---
set(SDL_PIPEWIRE OFF CACHE BOOL "" FORCE)
set(SDL_PULSEAUDIO OFF CACHE BOOL "" FORCE)
set(SDL_JACK OFF CACHE BOOL "" FORCE)
set(SDL_ALSA OFF CACHE BOOL "" FORCE)
set(SDL_AUDIO OFF CACHE BOOL "" FORCE)

fetchcontent_declare(
    sdl2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        release-2.30.9
    GIT_SHALLOW    TRUE
)

fetchcontent_makeavailable(sdl2)

# --- CIMGUI ---

set(CIMGUI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CIMGUI_USE_SDL2 ON CACHE BOOL "" FORCE)
set(CIMGUI_USE_SDLRENDERER2 ON CACHE BOOL "" FORCE)
set(IMGUI_STATIC ON CACHE BOOL "" FORCE)

fetchcontent_declare(
    cimgui
    GIT_REPOSITORY https://github.com/cimgui/cimgui.git
    GIT_TAG        master
    GIT_SHALLOW    TRUE
)

fetchcontent_getproperties(cimgui)
fetchcontent_makeavailable(cimgui)

# ----------------------------------------------------- #
#                       OPTIONAL                        #
# ----------------------------------------------------- #

# --- MINIAUDIO ---

if(EPITAPH_SOUND)

    add_library(miniaudio
        ${CMAKE_CURRENT_SOURCE_DIR}/miniaudio/miniaudio.c
    )

    target_include_directories(miniaudio PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/miniaudio/include
    )

    if(UNIX AND NOT APPLE)
        # The Linux build only requires linking to -ldl, -lpthread and -lm. 
        # You do not need any development packages. 
        # You may need to link with -latomic if you're compiling for 32-bit ARM. 
        # From: https://miniaud.io/docs/manual/index.html
        target_link_libraries(miniaudio PRIVATE dl pthread m)
    endif()

endif()