#ifndef SOLVE_H
#define SOLVE_H
#include "status_manager.h"
#include <stdio.h>

Status is_suitable_number(const char *word);
Status convert_to_n_system(const char *number, const int curSystem, const int newSystem, char **res);
Status conver_to_10_system(const char *number, const int system, int* res);
Status char_to_int(const char chr, int *res);
Status int_to_char(const int val, char *res);

#endif 