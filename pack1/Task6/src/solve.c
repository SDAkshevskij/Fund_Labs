#include "../include/solve.h"
#include "../include/number_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double solve_a(double eps){ 
    double n = 1;
    double step = 1;
    double cur_res = 10;
    double prev_res = 0;
    double curX = 0;
    while(fabs(cur_res - prev_res) > eps){
        prev_res = cur_res;
        curX = 0;
        step = 1 / n;
        cur_res = 0;
        for(int i = 0; i < n; i++){
            curX += step;
            cur_res += (log(1 + curX) / curX) * step;
        }
        n *= 2;
    }
    return cur_res;
}
double solve_b(double eps){
    double n = 1;
    double step = 1;
    double cur_res = 10;
    double prev_res = 0;
    double curX = 0;
    while(fabs(cur_res - prev_res) > eps){
        prev_res = cur_res;
        curX = 0;
        step = 1 / n;
        cur_res = 0;
        for(int i = 0; i < n; i++){
            curX += step;
            cur_res += (exp(-(curX * curX) / 2)) * step;
        }
        n *= 2;
    }
    return cur_res;
}
double solve_c(double eps) {
    double n = 1;
    double step = 1;
    double cur_res = 10;
    double prev_res = 0;
    double curX = 0;
    while(fabs(cur_res - prev_res) > eps){
        prev_res = cur_res;
        curX = 0;
        step = 1 / n;
        cur_res = 0;
        for(int i = 0; i < n; i++){
            cur_res += (log(1 / (1 - curX))) * step;
            curX += step;
        }
        n *= 2;
    }
    return cur_res;
}
double solve_d(double eps) {
    double n = 1;
    double step = 1;
    double cur_res = 10;
    double prev_res = 0;
    double curX = 0;
    while(fabs(cur_res - prev_res) > eps){
        prev_res = cur_res;
        curX = 0;
        step = 1 / n;
        cur_res = 0;
        for(int i = 0; i < n; i++){
            curX += step;
            cur_res += (powl(curX, curX)) * step;
        }
        n *= 2;
    }
    return cur_res;
}