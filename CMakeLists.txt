# ----------------------------------------------------- #
#                      PREREQUISITES                    #
# ----------------------------------------------------- #

cmake_minimum_required(VERSION 3.16)
project(COS_Text_Editor C CXX)

include(cmake/cmake_options.cmake)
include(cmake/cmake_dirs.cmake)

# TODO: Add mingw toolchain

# ----------------------------------------------------- #
#                  EXEQUTABLE AND LIBS                  #
# ----------------------------------------------------- #

add_executable(cos_text_editor 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)

target_link_libraries(cos_text_editor
    cos_bridge
)