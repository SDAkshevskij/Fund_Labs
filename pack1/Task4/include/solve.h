#ifndef SOLVE
#define SOLVE
#include "error_manager.h"

double e_lim(double eps);
double e_sum(double eps);
double e_ln(double eps);
double pi_lim(double eps);
double pi_sum(double eps);
double pi_cos(double eps);
double ln2_lim(double eps);
double ln2_sum(double eps);
double ln2_e(double eps);
double sqrt2_lim(double eps);
double sqrt2_prod(double eps);
double sqrt2_pow(double eps);
double factorial(double n);
double imcomplete_fact(double start, double end);
double C_n_k(long n, long k, long **cache);
double y_lim(double eps);
double y_sum(double eps);
double y_e(double eps);
double ln_factorial(double n);

#endif 