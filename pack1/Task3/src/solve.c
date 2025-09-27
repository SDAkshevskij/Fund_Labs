#include "../include/solve.h"
#include "../include/number_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


Error process_flag_q(const double eps, const double a, const double b, const double c, Equation **res, int *resLen) {
    double **permutations;
    int permutationsAmo;
    Error er;
    if(er = set_unique_permutation_arr(eps, a, b, c, &permutations, &permutationsAmo)) {
        return er; 
    }
    Equation *answers = malloc(sizeof(Equation) * permutationsAmo);
    int answersAmo = 0;
    if(answers == NULL) return MEMORY_ALLOCATION_ERROR;
    for(int perm = 0; perm < permutationsAmo; perm++){
        double *permutation = permutations[perm];
        double answer1, answer2;
        answers[perm].errorFlag = solve_quad_equation(eps, permutation[0], permutation[1], permutation[2], &answer1, &answer2);
        answers[perm].a = permutation[0];
        answers[perm].b = permutation[1];
        answers[perm].c = permutation[2];
        answers[perm].ans1 = answer1;
        answers[perm].ans2 = answer2;
    }
    *res = answers;
    *resLen = permutationsAmo;
    for(int i = 0; i < permutationsAmo; i++){
        free(permutations[i]);
    }
    free(permutations); 
    return OK;
}
Error set_unique_permutation_arr(const double eps, const double a, const double b, const double c, double ***res, int *size) {
    double vals[3] = {a, b, c};
    double** arr = malloc(sizeof(double*) * 6);
    int permAmo = 0;
    if(arr == NULL) return MEMORY_ALLOCATION_ERROR;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(i == j || i == k|| j == k){
                    continue;
                }
                int is_dublicate = 0;
                for(int l = 0; l < permAmo; l++){
                    double* prevPerm = *(arr + l);
                    if(is_double_equal(*(prevPerm + i), a, eps) && is_double_equal(*(prevPerm + j), b, eps) && is_double_equal(*(prevPerm + k), c, eps)){
                        is_dublicate = 1;
                        break;
                    }
                }
                if(is_dublicate) continue;
                double* perm = (double*)malloc(sizeof(double) * 3);
                *(perm + i) = a;
                *(perm + j) = b;
                *(perm + k) = c;
                *(arr + permAmo) = perm;
                permAmo++;
            }
        }
    }
    printf("Perm amo: %d\n", permAmo);
    *res = arr;
    *size = permAmo;
    return OK;
}
Error solve_quad_equation(const double eps, const double a, const double b, const double c, double *ans1, double *ans2) {
    if(is_double_zero(a, eps)){
        if(is_double_zero(b, eps)){
            if(is_double_zero(c, eps)){
                return SOLUTION_IS_ANY_NUMBER;
            }
            return NO_SOLUTION;
        }
        *ans1 = -c / b;
        if(is_double_zero(*ans1, eps)) *ans1 = double_abs(*ans1);
        *ans2 = *ans1;
    }
    else {
        if(is_double_zero(b, eps)){
            if(c > 0){
                return NO_SOLUTION;
            }
            *ans1 = sqrt(-c);
            *ans2 = -(*ans1);
        }
        double discr = b * b - 4 * a * c;
        if(discr < 0){
            return NO_SOLUTION;
        }
        *ans1 = (-b + sqrt(discr)) / (2 * a);
        *ans2 = (-b - sqrt(discr)) / (2 * a); 
    }
    return OK;
}
Error is_multiple(int a, int b) {
    if(a == 0 || b == 0){
        return NUMBER_IS_ZERO;
    }
    if(a % b == 0){
        return OK;
    }
    return NOT_OK;
}
Error is_right_triangle(double eps, double a, double b, double c){
    if(is_double_zero(a, eps) || is_double_zero(b, eps) || is_double_zero(c, eps)) {
        return NUMBER_IS_ZERO;
    }
    if(a < 0 || b < 0 || c < 0){
        return NEGATIVE_NUMBER;
    }
    if(is_double_equal(a * a + b * b, c * c, eps) || is_double_equal(a * a + c * c, b * b, eps) || is_double_equal(b * b + c * c, a * a, eps)){
        return OK;
    }
    return NOT_OK;
}