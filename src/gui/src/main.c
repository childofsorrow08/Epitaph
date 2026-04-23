#include "epitaph_exit_code.h"
#include <header.h>
#include <pages.h>

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

        /* Events */

        while(SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent_C(&event);

            if(event.type == SDL_QUIT) app.alive = EPITAPH_WINDOW_CLOSED;
        }

        /* ImGUI new frame */

        ImGui_ImplSDLRenderer2_NewFrame_C();
        ImGui_ImplSDL2_NewFrame_C();
        igNewFrame();

        /* Pages */

        if(app.current_page == EPITAPH_HOME) {
            epitaph_home_page(&app);
        }

        if(app.current_page == EPITAPH_SETTINGS) {
            epitaph_settings_page(&app);
        }

        /* Dialogue windows */
        // todo

        /* renderer end */
        SDL_GetWindowSize(app.win, &app.width, &app.height);
        igRender();
        SDL_SetRenderDrawColor(app.renderer, 30, 30, 30, 255);
        SDL_RenderClear(app.renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData_C(igGetDrawData(), app.renderer);
        SDL_RenderPresent(app.renderer);

        // FPS lock i guess (120 fps)
        SDL_Delay(8);
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