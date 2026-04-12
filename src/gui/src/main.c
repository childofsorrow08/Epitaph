#include "epitaph_exit_code.h"
#include <header.h>

#if defined(REQUIEM_DEBUG)
    #include <stdio.h>
    #define LOG_FONT_ERROR(code) printf("[GUI] [Critical] Can't load font set: %s\n", code)
#else
    #define LOG_FONT_ERROR(code)
#endif

exit_code start_gui() {
    #if defined(REQUIEM_DEBUG)
        printf("[GUI] [Info] Starting creating window and ui.\n");
    #endif

    app_context app = init_sdl_window();
    if(app.alive != EPITAPH_WINDOW_WORKS) return 3;

    igCreateContext(NULL);

    init_fonts(&app);

    if(!app.font_ibm_medium_30)  { LOG_FONT_ERROR("font_ibm_medium_30");  return EPITAPH_FAILED_TO_INIT_FONTS; }
    if(!app.font_ibm_medium_18)  { LOG_FONT_ERROR("font_ibm_medium_18");  return EPITAPH_FAILED_TO_INIT_FONTS; }
    if(!app.font_ibm_regular_16) { LOG_FONT_ERROR("font_ibm_regular_16"); return EPITAPH_FAILED_TO_INIT_FONTS; }
    if(!app.font_yuji_45)        { LOG_FONT_ERROR("font_yuji_45");        return EPITAPH_FAILED_TO_INIT_FONTS; }
    if(!app.font_yuji_24)        { LOG_FONT_ERROR("font_yuji_24");        return EPITAPH_FAILED_TO_INIT_FONTS; }
    if(!app.font_yuji_16)        { LOG_FONT_ERROR("font_yuji_16");        return EPITAPH_FAILED_TO_INIT_FONTS; }

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

        ImGui_ImplSDLRenderer2_NewFrame_C();
        ImGui_ImplSDL2_NewFrame_C();
        igNewFrame();

        igSetNextWindowPos((ImVec2){50, 50}, ImGuiCond_Once, (ImVec2){0, 0});
        igSetNextWindowSize((ImVec2){650, 450}, ImGuiCond_Once);
        igBegin("Epitaph Font Debugger", NULL, 0);

        igPushFont(app.font_ibm_medium_30, 0.0f);
        igText("IBM Plex Sans Medium 30: Привіт Світ!");
        igPopFont();

        igSeparator();

        igPushFont(app.font_ibm_medium_18, 0.0f);
        igText("IBM Plex Sans Medium 18: Testing 123...");
        igPopFont();

        igSeparator();

        igPushFont(app.font_ibm_regular_16, 0.0f);
        igText("IBM Regular 16: Multilingual 日本語, 한국어, ภาษาไทย, العربية");
        igPopFont();

        igSeparator();

        igPushFont(app.font_yuji_45, 0.0f);
        igText("Yuji Boku 45: 漢字 テст");
        igPopFont();

        igPushFont(app.font_yuji_24, 0.0f);
        igText("Yuji Boku 24: Traditional Style");
        igPopFont();

        igPushFont(app.font_yuji_16, 0.0f);
        igText("Yuji Boku 16: Small Decorative Text");
        igPopFont();

        igEnd();

        igRender();
        SDL_SetRenderDrawColor(app.renderer, 20, 20, 20, 255); 
        SDL_RenderClear(app.renderer);
        
        ImGui_ImplSDLRenderer2_RenderDrawData_C(igGetDrawData(), app.renderer);
        SDL_RenderPresent(app.renderer);
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