#include <fonts/font_loading.h>
#include <epitaph_assets.h>

void init_yuji_boku_45(app_context* app, ImFontAtlas* atlas, ImFontConfig* config) {
    config->MergeMode = false;
    app->font_yuji_45 = ImFontAtlas_AddFontFromMemoryTTF(atlas, 
        (void*)yujiboku_regular, yujiboku_regular_len, 45.0f, config, japanese_ranges);

    config->MergeMode = true;
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)yujiboku_regular, yujiboku_regular_len, 45.0f, config, latin_cyrillic_ranges);
}