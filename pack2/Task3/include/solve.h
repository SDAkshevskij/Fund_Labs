#ifndef SOLVE_H
#define SOLVE_H

#include "status_manager.h"
#include <stdarg.h>
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>


typedef enum {
    PRINT_FILE,
    PRINT_STRING
} printType;


int overfprintf(FILE *outputFile, char *pattern, ...);
int oversprintf(char *buffer, char *pattern, ...);

#endif