#ifndef NUMBER_PROCESS_H
#define NUMBER_PROCESS_H
#include "error_manager.h"

int* get_multiples(int x);
void print_multiples(int* multiples);
int is_prime(int x);
Error to_hex(int x, char **res);
void print_hex(char* hex);
long long_pow(long num, long p);
void print_table_of_degrees(int x);
Error calc_pref_sum(int x, int *res);
Error factorial(int x, int *res);



#endif 