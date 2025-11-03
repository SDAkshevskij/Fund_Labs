#ifndef SOLVE_H
#define SOLVE_H
#include "status_manager.h"
#include <stdio.h>

Status is_infinite_fractions(long long base, int **res, int count, ...);
Status is_infinite_fraction(long long base, long double fraction, int *res);
Status to_proper_fracton(long double fraction, long long* numerator, long long *denominator);
Status reduce_fraction(long long *newNumerator, long long *newDenominator);

#endif 