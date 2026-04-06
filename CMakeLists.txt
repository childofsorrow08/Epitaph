# ----------------------------------------------------- #
#                      PREREQUISITES                    #
# ----------------------------------------------------- #

cmake_minimum_required(VERSION 3.25)
project(Epitaph C CXX)

include(cmake/cmake_check.cmake)
include(cmake/cmake_options.cmake)
include(cmake/cmake_dirs.cmake)

# TODO: Add mingw toolchain

# ----------------------------------------------------- #
#                  EXEQUTABLE AND LIBS                  #
# ----------------------------------------------------- #

add_executable(Epitaph 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)

target_link_libraries(Epitaph
    epitaph_bridge

    epitaph_gui
)