#include "../include/solve.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double trapezoid_calc(int left, int right, double eps, double (*integral_func)(double)) {
    double n = 1;
    double step = 1;
    double prev_res = left;
    double cur_res = right;
    double curX = 0;
    while(fabs(cur_res - prev_res) > eps){
        prev_res = cur_res;
        curX = 0;
        step = 1 / n;
        cur_res = 0;
        for(int i = 0; i < n; i++){
            curX += step;
            cur_res += integral_func(curX) * step;
        }
        n *= 2;
    }
    return cur_res;
}

double a_func(double x) {
    return (log(1 + x) / x);
}

double b_func(double x) {
    return (exp(-(x * x) / 2));
}

double c_func(double x) {
    if(1 - x == 0) return 0;
    return (log(1 / (1 - x)));
}

double d_func(double x) {
    return (powl(x, x));
}

double solve_a(double eps){ 
    return trapezoid_calc(0, 10, eps, a_func);
}
double solve_b(double eps){
    return trapezoid_calc(0, 10, eps, b_func);
}
double solve_c(double eps) {
    return trapezoid_calc(0, 10, eps, c_func);
}
double solve_d(double eps) {
    return trapezoid_calc(0, 10, eps, d_func);
}