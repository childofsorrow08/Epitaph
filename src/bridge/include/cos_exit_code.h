#if !defined(COS_TEXT_EXIT_CODE)
#define COS_TEXT_EXIT_CODE

typedef enum exit_code {
    COS_TEXT_SUCCESS = 0, // Ended without problems
} exit_code;

extern exit_code magic_numbers;

#endif