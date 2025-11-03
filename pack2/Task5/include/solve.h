#ifndef SOLVE_H
#define SOLVE_H
#include "status_manager.h"
#include <stdio.h>

Status read_string_or_80(FILE *inputFile, char **string, int *requaredSpaceAmo, int *spaceAmo);
Status write_string_or_80(FILE *outputFile, char *string, int requaredSpaceAmo, int spaceAmo);


#endif