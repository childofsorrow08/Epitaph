if(NOT LINUX AND NOT WIN32)

    message(FATAL_ERROR "The project supports only Linux and Windows.")
    
endif()

if(WIN32 AND NOT MINGW)

    message(WARNING     "You are trying to compile Epitaph on Windows without using MinGW.")
    message(STATUS      "At this time, only the MinGW compiler is officially supported for Windows.")
    message(STATUS      "I cannot guarantee that other compilers will work.")
    
endif()

