#ifndef STRING_HELPER_H
#define STRING_HELPER_H
#include "error_manager.h"

int is_positive_integer(char* string);
int is_integer(char* string);
int is_empty_string(char* string);
int is_flag(char* string);
Error read_word(char **word);
Error read_natural_integer(int *res);


#endif 