add_library(cos_brigde 
     ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)

target_include_directories(RequiemBridge PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(RequiemBridge PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include_p
)