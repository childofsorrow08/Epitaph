option(DEBUG_LOGS "Enable debug logs" OFF)

if(DEBUG_LOGS)

    add_compile_definitions(COS_TEXT_EDITOR_DEBUG)

endif()