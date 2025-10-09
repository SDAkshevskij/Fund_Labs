#ifndef SOLVE_H
#define SOLVE_H
#include "status_manager.h"
#include <stdio.h>

void process_flag_d(FILE *inputFile, FILE *outputFile);
void process_flag_i(FILE *inputFile, FILE *outputFile);
void process_flag_s(FILE *inputFile, FILE *outputFile);
Status process_flag_a(FILE *inputFile, FILE *outputFile);
Status convert_to_16(int num, char **res);
Status int_to_char(const int val, char *res);
void reverse_string(char *string);

#endif 