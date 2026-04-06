option(DEBUG_LOGS "Enable debug logs" OFF)

if(DEBUG_LOGS)

    add_compile_definitions(EPITAPH_DEBUG)

endif()

option(EPITAPH_SOUND "Enable optional sounds" ON)

if(EPITAPH_SOUND)

    add_compile_definitions(EPITAPH_SOUND)

endif()