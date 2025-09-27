#ifndef SOLVE_H
#define SOLVE_H
#include "error_manager.h"
#include <stdio.h>

Error is_suitable_number(const char *word);
Error convert_to_n_system(const char *number, const int curSystem, const int newSystem, char **res);
Error conver_to_10_system(const char *number, const int system, int* res);
Error char_to_int(const char chr, int *res);
Error int_to_char(const int val, char *res);

#endif 