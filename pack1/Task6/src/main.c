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
    printf("Integral a: %f\n", solve_a(eps));
    printf("Integral b: %f\n", solve_b(eps));
    printf("Integral c: %f\n", solve_c(eps));
    printf("Integral d: %f\n", solve_d(eps));
}