#ifndef STRING_HELPER_H
#define STRING_HELPER_H
#include "error_manager.h"

typedef enum {
    UNKNOWN_FLAG,
    SOLVE_QUAD_EQUATION,
    
} Flag;

Error check_natural_integer(char* string);
Error check_integer(char* string);
int is_empty_string(char* string);
int is_flag(char* string);
Error read_word(char **word);
Error read_natural_integer(int *res);
Error check_double(char* string);
Error read_float(double *res);

#endif