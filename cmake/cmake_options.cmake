option(DEBUG_LOGS "Enable debug logs" OFF)

if(DEBUG_LOGS)

    add_compile_definitions(EPITAPH_DEBUG)

endif()