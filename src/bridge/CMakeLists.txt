add_library(epitaph_bridge STATIC 
    src/main.c
    src/exit_code.c
)

target_include_directories(epitaph_bridge 
    PUBLIC 
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include_p"
)