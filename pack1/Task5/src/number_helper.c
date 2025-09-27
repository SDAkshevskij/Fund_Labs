#include "../include/number_helper.h"

int double_compare(double a, double b, double eps){
    if(double_abs(a - b) < eps){
        return 0;
    }
    if(a + eps < b){
        return -1;
    }
    return 1;
}
int is_double_equal(double a, double b, double eps){
    return double_compare(a, b, eps) == 0;
}
int is_double_zero(double a, double eps){
    return double_abs(a) < eps;
}

double double_abs(double a){
    if(a < 0) {
        return -a;
    }
    return a;
}

int min_int(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}
int max_int(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}