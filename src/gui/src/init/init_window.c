#include <header.h>

app_context init_sdl_window() {
    app_context app = {0};
    
    app.width = 1200;
    app.height = 800;
    app.alive = true;
    app.current_page_info = EPITAPH_HOME;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0) {
        printf("[SDL] [Error] Failed to init: %s\n", SDL_GetError());
        app.alive = EPITAPH_WINDOW_CLOSED;
        return app;
    }

    app.win = SDL_CreateWindow(
        "Epitaph", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        app.width, 
        app.height, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );

    if (!app.win) {
        printf("[SDL] [Error] Window creation failed: %s\n", SDL_GetError());
        app.alive = EPITAPH_WINDOW_CLOSED;
        return app;
    }

    app.renderer = SDL_CreateRenderer(
        app.win, 
        -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!app.renderer) {
        printf("[SDL] [Error] Renderer creation failed: %s\n", SDL_GetError());
        app.alive = EPITAPH_WINDOW_CLOSED;
        return app;
    }

    SDL_GetWindowSize(app.win, &app.width, &app.height);

    printf("[GUI] [Info] SDL Window & Renderer initialized successfully.\n");
    app.alive = EPITAPH_WINDOW_WORKS;
    
    return app;
}