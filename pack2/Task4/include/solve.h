#ifndef SOLVE_H
#define SOLVE_H

#include "status_manager.h"
#include <stdarg.h>
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>


int overfscanf(FILE *inputFile, const char *pattern, ...);
int oversscanf(char *src, const char *pattern, ...);

#endif