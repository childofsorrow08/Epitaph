#if !defined(EPITAPH_EXIT_CODE)
#define EPITAPH_EXIT_CODE

typedef enum exit_code {
    EPITAPH_SUCCESS = 0, // Ended without problems
} exit_code;

extern exit_code magic_numbers;

#endif