#include <fonts/font_loading.h>
#include <epitaph_assets.h>

void init_ibm_plex_sans_medium_30(app_context* app, ImFontAtlas* atlas, ImFontConfig* config) {
    config->MergeMode = false;
    app->font_ibm_medium_30 = ImFontAtlas_AddFontFromMemoryTTF(atlas, 
        (void*)ibmplexsans_medium, ibmplexsans_medium_len, 30.0f, config, latin_cyrillic_ranges);

    config->MergeMode = true;
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsansjp_medium, ibmplexsansjp_medium_len, 30.0f, config, japanese_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsanskr_medium, ibmplexsanskr_medium_len, 30.0f, config, korean_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsansthai_medium, ibmplexsansthai_medium_len, 30.0f, config, thai_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsansarabic_medium, ibmplexsansarabic_medium_len, 30.0f, config, arabic_ranges);
    ImFontAtlas_AddFontFromMemoryTTF(atlas, (void*)ibmplexsanshebrew_medium, ibmplexsanshebrew_medium_len, 30.0f, config, hebrew_ranges);
}