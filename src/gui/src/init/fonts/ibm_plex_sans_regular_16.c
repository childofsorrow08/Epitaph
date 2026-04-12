#include <fonts/font_loading.h>
#include <epitaph_assets.h>

void init_ibm_plex_sans_regular_16(app_context* app, ImFontAtlas* atlas, ImFontConfig* config) {
    config->MergeMode = false;
    app->font_ibm_regular_16 = ImFontAtlas_AddFontFromMemoryTTF(atlas, 
        (void*)ibmplexsans_regular, ibmplexsans_regular_len, 16.0f, config, latin_cyrillic_ranges);

    config->MergeMode = true;
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsansjp_regular, ibmplexsansjp_regular_len, 16.0f, config, japanese_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsanskr_regular, ibmplexsanskr_regular_len, 16.0f, config, korean_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsansthai_regular, ibmplexsansthai_regular_len, 16.0f, config, thai_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsansarabic_regular, ibmplexsansarabic_regular_len, 16.0f, config, arabic_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsanshebrew_regular, ibmplexsanshebrew_regular_len, 16.0f, config, hebrew_ranges);
}