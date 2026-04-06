#if defined(COS_TEXT_EDITOR_DEBUG)
    #include <stdio.h>
#endif

#include "cos_exit_code.h"

int main(int args, char *argv[]) {

    magic_numbers = COS_TEXT_SUCCESS;
    
    // TODO: Make compile options, to actually use this
    #if defined(COS_TEXT_EDITOR_DEBUG)
        printf("[APP] [Info] Exiting with code %d \n", magic_number);
    #endif
    
    return magic_numbers;
}