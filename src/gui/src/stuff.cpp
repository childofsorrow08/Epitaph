#include "imgui.h" 
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

/*
 * A necessary evil for everything to work properly
 * cimgui may wrap imgui, but it's not what you need to work with SDL
 */

extern "C" {
    bool ImGui_ImplSDL2_InitForSDLRenderer_C(SDL_Window* window, SDL_Renderer* renderer) {
        return ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    }

    void ImGui_ImplSDLRenderer2_Init_C(SDL_Renderer* renderer) {
        ImGui_ImplSDLRenderer2_Init(renderer);
    }

    void ImGui_ImplSDLRenderer2_NewFrame_C() { 
        ImGui_ImplSDLRenderer2_NewFrame(); 
    }

    void ImGui_ImplSDL2_NewFrame_C() { 
        ImGui_ImplSDL2_NewFrame(); 
    }

    void ImGui_ImplSDL2_ProcessEvent_C(const SDL_Event* event) { 
        ImGui_ImplSDL2_ProcessEvent(event); 
    }

    void ImGui_ImplSDLRenderer2_RenderDrawData_C(ImDrawData* draw_data, SDL_Renderer* renderer) {
        ImGui_ImplSDLRenderer2_RenderDrawData(draw_data, renderer);
    }

    void ImGui_ImplSDLRenderer2_Shutdown_C() {
        ImGui_ImplSDLRenderer2_Shutdown();
    }

    void ImGui_ImplSDL2_Shutdown_C() {
        ImGui_ImplSDL2_Shutdown();
    }
}