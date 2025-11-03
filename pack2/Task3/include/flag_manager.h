#ifndef FLAG_MANAGER_H
#define FLAG_MANAGER_H

#include "status_manager.h"
#include <stdarg.h>
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

char* flag_Ro(int val);
char* flag_Zr(unsigned int val);
char* flag_Cv(int value, int base, int upperModifier);
char* flag_to(char *numStr, int base, int upperModifier);
char *flag_mi(int value);
char *flag_mu(unsigned int value);
char* flag_md(double value);
char* flag_mf(float value);

#endif