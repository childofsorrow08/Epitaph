#include <fonts/font_loading.h>

void init_ibm_plex_sans_regular_16(app_context* app, ImFontAtlas* atlas, ImFontConfig* config) {
    config->MergeMode = false;
    app->font_ibm_regular_16 = ImFontAtlas_AddFontFromMemoryTTF(atlas, 
        (void*)ibmplex_sans, ibmplex_sans_len, 16.0f, config, latin_cyrillic_ranges);

    config->MergeMode = true;
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_jp, ibmplex_sans_jp_len, 16.0f, config, japanese_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_kr, ibmplex_sans_kr_len, 16.0f, config, korean_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_thai, ibmplex_sans_thai_len, 16.0f, config, thai_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_arabic, ibmplex_sans_arabic_len, 16.0f, config, arabic_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplex_sans_hebrew, ibmplex_sans_hebrew_len, 16.0f, config, hebrew_ranges);
}