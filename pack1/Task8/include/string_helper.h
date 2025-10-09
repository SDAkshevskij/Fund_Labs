#ifndef STRING_HELPER_H
#define STRING_HELPER_H
#include "status_manager.h"

typedef enum {
    UNKNOWN_FLAG,
    SOLVE_QUAD_EQUATION,
    
} Flag;

Status check_natural_integer(char* string);
Status check_integer(char* string);
int is_empty_string(const char* string);
int is_flag(char* string);
Status read_word(char **word);
Status read_natural_integer(int *res);
Status read_float(double *res);
Status remove_leading_zeros(char **number);
Status string_to_int(char *word, int *res);
Status string_to_natural_int(char *word, int *res);
Status string_to_double(char *word, double *res);
void reverse_string(char *string);
#endif 