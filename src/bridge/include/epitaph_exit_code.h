#if !defined(EPITAPH_TEXT_EXIT_CODE)
#define EPITAPH_TEXT_EXIT_CODE

typedef enum exit_code {
    EPITAPH_TEXT_SUCCESS = 0, // Ended without problems
} exit_code;

extern exit_code magic_numbers;

#endif