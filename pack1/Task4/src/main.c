#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/error_manager.h"
#include "../include/string_helper.h"
#include "../include/number_helper.h"
#include "../include/solve.h"


int main(int argc, char* argv[]) {
    double eps = 0.000001;
    printf("e by lim: %f\n", e_lim(eps));
    printf("e by sum: %f\n", e_sum(eps));
    printf("e by ln: %f\n", e_ln(eps));
    printf("pi by lim: %f\n", pi_lim(eps));
    printf("pi by sum: %f\n", pi_sum(eps));
    printf("pi by cos: %f\n", pi_cos(eps));
    printf("ln2 by lim: %f\n", ln2_lim(eps));
    printf("ln2 by sum: %f\n", ln2_sum(eps));
    printf("ln2 by exp: %f\n", ln2_e(eps));
    printf("sqrt2 by lim: %f\n", sqrt2_lim(eps));
    printf("sqrt2 by prod: %f\n", sqrt2_prod(eps));
    printf("sqrt2 by pow: %f\n", sqrt2_pow(eps));
    printf("y by lim: %f\n", y_lim(eps));
    printf("y by sum: %f\n", y_sum(eps));
    printf("e - x: %f\n", y_e(eps));
    //printf("%f %f", factorial(120), ln_factorial(50));
}