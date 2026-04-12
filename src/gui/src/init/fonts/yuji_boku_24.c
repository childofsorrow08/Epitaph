#include <fonts/font_loading.h>

void init_yuji_boku_24(app_context* app, ImFontAtlas* atlas, ImFontConfig* config) {
    config->MergeMode = false;
    app->font_yuji_24 = ImFontAtlas_AddFontFromMemoryTTF(atlas, 
        (void*)yuji_boku, yuji_boku_len, 24.0f, config, japanese_ranges);

    config->MergeMode = true;
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)yuji_boku, yuji_boku_len, 24.0f, config, latin_cyrillic_ranges);
}