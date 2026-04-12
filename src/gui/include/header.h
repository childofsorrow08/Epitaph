/*
 * Perhaps this is a bad decision, but I decided to keep 
 * all the necessary information here, in one header file, 
 * because it is used almost everywhere in this library.
 */
#if !defined(STRUCTS_H)
#define STRUCTS_H

#include <stdbool.h>

#include <epitaph_assets.h>

#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include <cimgui.h>
#include <cimgui_impl.h>

#include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>

// things from stuff.cpp
extern bool ImGui_ImplSDL2_InitForSDLRenderer_C(SDL_Window* window, SDL_Renderer* renderer);
extern void ImGui_ImplSDLRenderer2_Init_C(SDL_Renderer* renderer);
extern void ImGui_ImplSDLRenderer2_NewFrame_C(void);
extern void ImGui_ImplSDL2_NewFrame_C(void);
extern void ImGui_ImplSDL2_ProcessEvent_C(const SDL_Event* event);
extern void ImGui_ImplSDLRenderer2_RenderDrawData_C(ImDrawData* draw_data, SDL_Renderer* renderer);
extern void ImGui_ImplSDLRenderer2_Shutdown_C(void);
extern void ImGui_ImplSDL2_Shutdown_C(void);

// Enums

typedef enum window_work {
    EPITAPH_WINDOW_WORKS,
    EPITAPH_WINDOW_CLOSED
} window_work;

typedef enum current_page {
    EPITAPH_HOME,
} current_page;

// Structs

typedef struct app_context {
    // Window related
    SDL_Window *win;
    SDL_Renderer *renderer;

    // Styles and stuff
    int width;
    int height;

    // IBM PLEX SANS
    ImFont* font_ibm_medium_30;             // IBM Plex Sans Medium     - 30 px
    ImFont* font_ibm_medium_18;             // IBM Plex Sans Medium     - 18 px
    ImFont* font_ibm_regular_16;            // IBM Plex Sans Regular    - 16 px

    // YUJI BOKU
    ImFont* font_yuji_45;                   // Yuji Boku                - 45 px
    ImFont* font_yuji_24;                   // Yuji Boku                - 24 px
    ImFont* font_yuji_16;                   // Yuji Boku                - 16 px

    // Different stuff to check or display
    current_page current_page_info; 
} app_context;


// Functions
extern app_context init_sdl_window();
extern void init_fonts(app_context* app);

extern void init_ibm_plex_sans_medium_30(app_context* app, ImFontAtlas* atlas, ImFontConfig* config);
extern void init_ibm_plex_sans_medium_18(app_context* app, ImFontAtlas* atlas, ImFontConfig* config);
extern void init_ibm_plex_sans_regular_16(app_context* app, ImFontAtlas* atlas, ImFontConfig* config);

extern void init_yuji_boku_45(app_context* app, ImFontAtlas* atlas, ImFontConfig* config);
extern void init_yuji_boku_24(app_context* app, ImFontAtlas* atlas, ImFontConfig* config);
extern void init_yuji_boku_16(app_context* app, ImFontAtlas* atlas, ImFontConfig* config);

#endif