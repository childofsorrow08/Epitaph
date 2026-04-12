#include <fonts/font_loading.h>

void init_ibm_plex_sans_medium_30(app_context* app, ImFontAtlas* atlas, ImFontConfig* config) {
    config->MergeMode = false;
    app->font_ibm_medium_30 = ImFontAtlas_AddFontFromMemoryTTF(atlas, 
        (void*)ibmplex_sans_medium, ibmplex_sans_medium_len, 30.0f, config, latin_cyrillic_ranges);

    config->MergeMode = true;
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_jp_medium, ibmplex_sans_jp_medium_len, 30.0f, config, japanese_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_kr_medium, ibmplex_sans_kr_medium_len, 30.0f, config, korean_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_thai_medium, ibmplex_sans_thai_medium_len, 30.0f, config, thai_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_arabic_medium, ibmplex_sans_arabic_medium_len, 30.0f, config, arabic_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_hebrew_medium, ibmplex_sans_hebrew_medium_len, 30.0f, config, hebrew_ranges);
}
