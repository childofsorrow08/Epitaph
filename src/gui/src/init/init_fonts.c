#include "epitaph_exit_code.h"
#include <header.h>
#include <epitaph_assets.h>

#if defined(EPITAPH_DEBUG)
    #include <stdio.h>
    #define LOG_FONT_ERROR(code) printf("[GUI] [Critical] Can't load font set: %s\n", code)
#else
    #define LOG_FONT_ERROR(code)
#endif

const ImWchar latin_cyrillic_ranges[] = { 0x0020, 0x00FF, 0x0400, 0x052F, 0 };
const ImWchar japanese_ranges[]       = { 0x3000, 0x30FF, 0x31F0, 0x31FF, 0xFF00, 0xFFEF, 0x4E00, 0x9FAF, 0 };
const ImWchar korean_ranges[]         = { 0xAC00, 0xD7AF, 0x3130, 0x318F, 0 };
const ImWchar thai_ranges[]           = { 0x0E00, 0x0E7F, 0 };
const ImWchar arabic_ranges[]         = { 0x0600, 0x06FF, 0x0750, 0x077F, 0xFB50, 0xFDFF, 0xFE70, 0xFEFF, 0 };
const ImWchar hebrew_ranges[]         = { 0x0590, 0x05FF, 0xFB1D, 0xFB4F, 0 };

void init_fonts(app_context* app) {
    ImGuiIO* io = igGetIO_Nil();
    ImFontAtlas* atlas = io->Fonts;

    ImFontConfig* config = ImFontConfig_ImFontConfig();
    config->FontDataOwnedByAtlas = false; 
    config->OversampleH = 3; 
    config->PixelSnapH = true;

    // --- IBM Plex Sans Medium - 30px ---
    init_ibm_plex_sans_medium_30(app, atlas, config);
    // --- IBM Plex Sans Medium - 18px ---
    init_ibm_plex_sans_medium_18(app, atlas, config);
    // --- IBM Plex Sans Regular - 16px ---
    init_ibm_plex_sans_regular_16(app, atlas, config);

    // --- Yujo Boku - 45px ; ---
    init_yuji_boku_45(app, atlas, config);
    // --- Yujo Boku - 24px ; ---
    init_yuji_boku_24(app, atlas, config);
    // --- Yujo Boku - 16px ; ---
    init_yuji_boku_16(app, atlas, config);

    ImFontConfig_destroy(config);

    /*
     * I don't think the fonts would fail to load for 
     * any reason if they're included in the program's binary, 
     * but just in case, I'll leave this in, at least 
     * until the app is released
     */

    if(!app->font_ibm_medium_30) { 
        LOG_FONT_ERROR("font_ibm_medium_30");  
        magic_numbers = EPITAPH_FAILED_TO_INIT_FONTS; 
    }

    if(!app->font_ibm_medium_18) { 
        LOG_FONT_ERROR("font_ibm_medium_18");  
        magic_numbers = EPITAPH_FAILED_TO_INIT_FONTS; 
    }

    if(!app->font_ibm_regular_16) { 
        LOG_FONT_ERROR("font_ibm_regular_16"); 
        magic_numbers = EPITAPH_FAILED_TO_INIT_FONTS; 
    }

    if(!app->font_yuji_45) { 
        LOG_FONT_ERROR("font_yuji_45");        
        magic_numbers = EPITAPH_FAILED_TO_INIT_FONTS; 
    }

    if(!app->font_yuji_24) { 
        LOG_FONT_ERROR("font_yuji_24");        
        magic_numbers = EPITAPH_FAILED_TO_INIT_FONTS; 
    }

    if(!app->font_yuji_16) { 
        LOG_FONT_ERROR("font_yuji_16");        
        magic_numbers = EPITAPH_FAILED_TO_INIT_FONTS; 
    }

    #if defined(EPITAPH_DEBUG)
        printf("[GUI] [Info] Fonts initiated.\n");
    #endif
}