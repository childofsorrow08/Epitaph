#if defined(COS_TEXT_EDITOR_DEBUG)
    #include <stdio.h>
#endif

int main(int args, char *argv[]) {
    
    // TODO: Make enum and normal exit code managing
    // TODO: Make exit code global variable read-only
    // TODO: Make func that changes exit code
    magic_number = 0; 
    

    #if defined(COS_TEXT_EDITOR_DEBUG)
        printf("[APP] [Info] Exiting with code %d \n", magic_number);
    #endif
    
    return magic_number;
}