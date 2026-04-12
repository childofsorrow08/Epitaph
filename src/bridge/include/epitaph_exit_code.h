#if !defined(EPITAPH_EXIT_CODE)
#define EPITAPH_EXIT_CODE

typedef enum exit_code {
    EPITAPH_SUCCESS = 0, // Ended without problems

    EPITAPH_FAILED_TO_INIT_FONTS = 1 // Failed to init fonts 
} exit_code;

extern exit_code magic_numbers;

#endif