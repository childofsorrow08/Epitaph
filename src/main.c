#if defined(EPITAPH_DEBUG)
    #include <stdio.h>
#endif

#include "epitaph_exit_code.h"

int main(int args, char *argv[]) {

    magic_numbers = EPITAPH_TEXT_SUCCESS;
    
    // TODO: Make compile options, to actually use this
    #if defined(EPITAPH_DEBUG)
        printf("[APP] [Info] Exiting with code %d \n", magic_numbers);
    #endif
    
    return magic_numbers;
}