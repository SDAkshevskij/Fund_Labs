#ifndef SOLVE
#define SOLVE
#include "error_manager.h"

typedef struct {
    double a;
    double b;
    double c;
    double ans1;
    double ans2;
    Error errorFlag;
} Equation;

Error process_flag_q(const double eps, const double a, const double b, const double c, Equation **res, int *resLen); 
Error set_unique_permutation_arr(const double eps, const double a, const double b, const double c, double ***res, int *size);
Error solve_quad_equation(const double eps, const double a, const double b, const double c, double *ans1, double *ans2);
Error is_multiple(int a, int b);
Error is_right_triangle(double eps, double a, double b, double c);

#endif 