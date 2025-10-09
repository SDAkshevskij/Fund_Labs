#ifndef NUMBER_PROCESS_H
#define NUMBER_PROCESS_H
#include "error_manager.h"

int* get_multiples(int x);
void print_multiples(int* multiples);
int is_prime(int x);
Status to_hex(int x, char **res);
void print_hex(char* hex);
long long_pow(long num, long p);
void print_table_of_degrees(int x);
Status calc_pref_sum(int x, int *res);
Status factorial(int x, int *res);



#endif 