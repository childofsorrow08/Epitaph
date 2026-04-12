#include <fonts/font_loading.h>

void init_yuji_boku_16(app_context* app, ImFontAtlas* atlas, ImFontConfig* config) {
    config->MergeMode = false;
    app->font_yuji_16 = ImFontAtlas_AddFontFromMemoryTTF(atlas, 
        (void*)yuji_boku, yuji_boku_len, 16.0f, config, japanese_ranges);

    config->MergeMode = true;
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)yuji_boku, yuji_boku_len, 16.0f, config, latin_cyrillic_ranges);
}