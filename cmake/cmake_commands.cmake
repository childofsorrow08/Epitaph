# --- Assets Generation ---

set(LUA_SCRIPT "${CMAKE_SOURCE_DIR}/scripts/assets.lua")
set(FONTS_DIR "${CMAKE_SOURCE_DIR}/assets/fonts")
set(GEN_SRC "${CMAKE_BINARY_DIR}/generated/src/assets.c")
set(GEN_INC "${CMAKE_BINARY_DIR}/generated/include/epitaph_assets.h")

# Get list of all .ttf files to track changes
file(GLOB FONT_FILES "${FONTS_DIR}/*.ttf")

# Custom command to run the Lua script
add_custom_command(
    OUTPUT "${GEN_SRC}" "${GEN_INC}"
    COMMAND lua "${LUA_SCRIPT}"
    DEPENDS "${LUA_SCRIPT}" ${FONT_FILES}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    COMMENT "Generating binary arrays from fonts..."
    VERBATIM
)

# Target that forces the generation
add_custom_target(generate_assets DEPENDS "${GEN_SRC}" "${GEN_INC}")

# --- Project Configuration ---

# Ensure the compiler can find the generated header
include_directories("${CMAKE_BINARY_DIR}/generated/include")

add_dependencies(epitaph_gui generate_assets)
add_dependencies(epitaph_bridge generate_assets)