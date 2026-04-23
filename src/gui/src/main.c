#include "epitaph_exit_code.h"
#include <header.h>

exit_code start_gui() {

    #if defined(EPITAPH_DEBUG)
        printf("[GUI] [Info] Starting creating window and ui.\n");
    #endif

    app_context app = init_sdl_window();
    if(app.alive != EPITAPH_WINDOW_WORKS) return 3;

    igCreateContext(NULL);

    init_fonts(&app);

    ImGui_ImplSDL2_InitForSDLRenderer_C(app.win, app.renderer);
    ImGui_ImplSDLRenderer2_Init_C(app.renderer);

    SDL_Event event;
    SDL_EventState(SDL_DROPFILE, SDL_ENABLE);

    while(app.alive == EPITAPH_WINDOW_WORKS) {
        while(SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent_C(&event);

            if(event.type == SDL_QUIT) app.alive = EPITAPH_WINDOW_CLOSED;

            if(event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_F11) {
                    Uint32 flags = SDL_GetWindowFlags(app.win);
                    if (flags & SDL_WINDOW_FULLSCREEN) { 
                        SDL_SetWindowFullscreen(app.win, 0); 
                    } else { 
                        SDL_SetWindowFullscreen(app.win, SDL_WINDOW_FULLSCREEN_DESKTOP); 
                    }
                }
            }
        }

        SDL_GetWindowSize(app.win, &app.width, &app.height);
    }

cleanup:
    ImGui_ImplSDLRenderer2_Shutdown_C();
    ImGui_ImplSDL2_Shutdown_C();
    igDestroyContext(NULL);
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.win);
    SDL_Quit();

    return EPITAPH_SUCCESS;
}