#include <header.h>

void epitaph_home_page(app_context *app) {
    igSetNextWindowPos((ImVec2){0, 0}, ImGuiCond_Always, (ImVec2){0, 0});
    igSetNextWindowSize((ImVec2){app->width, app->height}, ImGuiCond_Always);

    igBegin("Home", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);

    // igText("Epitaph Editor");
    // igSeparator();

    if (igButton("Open File", (ImVec2){200, 50})) {
        // todo
    }

    if (igButton("Settings", (ImVec2){200, 50})) {
        app->current_page = EPITAPH_SETTINGS;
    }

    if (igButton("Exit", (ImVec2){200, 50})) {
        app->alive = EPITAPH_WINDOW_CLOSED;
    }

    igEnd();
}