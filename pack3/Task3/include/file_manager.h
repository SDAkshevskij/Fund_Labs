#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>
#include "../include/status_manager.h"
#include "../include/string_manager.h"

Status fread_non_space_symb(FILE *inputFile, char *res);
Status fread_word(FILE* inputFile, char **word);
Status fread_natural_integer(FILE *inputFile, int *res);
Status fread_float(FILE *inputFile, double *res);

#endif