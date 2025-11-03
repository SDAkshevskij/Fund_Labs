#ifndef FLAG_MANAGER_H
#define FLAG_MANAGER_H

#include "status_manager.h"
#include <stdarg.h>
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

int flag_Ro(char *roman);
unsigned int flag_Zr(char* string);
int flag_Cv(char *string, int base, int upperModifier);

#endif