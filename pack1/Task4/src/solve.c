#include "../include/solve.h"
#include "../include/number_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define C_CACHE_SIZE 44


double e_lim(double eps){
    double prevE = 0;
    double curE = 3;
    double n = 2;
    while(fabs(curE - prevE) > eps){
        prevE = curE;
        curE = powl(1 + 1 / n, n);
        n *= 2; 
    }
    return curE;
}
double e_sum(double eps){
    double prevE = 0;
    double curE = 2;
    double n = 1;
    double factN = 1;
    while(fabs(curE - prevE) > eps){
        n++;
        factN *= n;
        prevE = curE;
        curE += 1 / factN;
    }
    return curE;
}
double e_ln(double eps){
    double leftE = 0;
    double rightE = 3;
    while(fabs(rightE - leftE) > eps){
        double mid = (rightE + leftE) / 2;
        if(log(mid) > 1){
            rightE = mid;
        }
        else {
            leftE = mid;
        }
    }
    return leftE;
}
double pi_lim(double eps) {
    double prevPi = 0;
    double curPi = 4;
    double n = 1;
    while(fabs(curPi - prevPi) > eps * n){
        n++;
        prevPi = curPi;
        curPi *= (powl(2, 4) * powl(n, 4)) / ((2 * n) * (2 * n - 1) * (2 * n) * (2 * n - 1));
    }
    return curPi / n;
}
double pi_sum(double eps) {
    double prevPi = 0;
    double curPi = 1;
    double n = 1;
    while(fabs(curPi - prevPi) > eps / 4){
        n++;
        prevPi = curPi;
        curPi += powl(-1, n - 1)  / (2 * n - 1);
    }
    return curPi * 4;
}
double pi_cos(double eps) {
    double leftPi = 3;
    double rightPi = 4;
    while(fabs(rightPi - leftPi) > eps){
        double mid = (leftPi + rightPi) / 2;
        if(cos(leftPi) > cos(rightPi)){
            leftPi = mid;
        }
        else {
            rightPi = mid;
        }
    }
    return leftPi;
}
double ln2_lim(double eps) {
    double prevLn = 0;
    double curLn = 1;
    double n = 2;
    while(fabs(curLn - prevLn) > eps){
        prevLn = curLn;
        curLn = n * (powl(2, 1 / n) - 1);
        n *= 2;
    }
    return curLn;
}
double ln2_sum(double eps) {
    double prevLn = 0;
    double curLn = 1;
    double n = 1;
    while(fabs(curLn - prevLn) > eps){
        n++;
        prevLn = curLn;
        curLn += powl(-1, n - 1) / n;
    }
    return curLn;
}
double ln2_e(double eps) {
    double leftLn = 0;
    double rightLn = 1;
    while(fabs(rightLn - leftLn) > eps){
        double mid = (leftLn + rightLn) / 2;
        if(exp(mid) > 2){
            rightLn = mid;
        }
        else {
            leftLn = mid;
        }
    }
    return leftLn;
}
double sqrt2_lim(double eps) {
    double prevSqrt = 0;
    double curSqrt = 2;
    double x = -0.5;
    while(fabs(curSqrt - prevSqrt) > eps){
        x = x - (x * x) / 2 + 1; 
        prevSqrt = curSqrt;
        curSqrt = x;
    }
    return curSqrt;
}
double sqrt2_prod(double eps) {
    double prevSqrt = 0;
    double curSqrt = 1;
    double k = 1;
    while(fabs(curSqrt - prevSqrt) > eps){
        k++;
        prevSqrt = curSqrt;
        curSqrt *= powl(2, powl(2, -k));
    }
    return curSqrt;
}
double sqrt2_pow(double eps) {
    double leftSqrt = 1;
    double rightSqrt = 2;
    while(fabs(rightSqrt - leftSqrt) > eps){
        double mid = (leftSqrt + rightSqrt) / 2;
        if(powl(mid, 2) > 2){
            rightSqrt = mid;
        }
        else {
            leftSqrt = mid;
        }
    }
    return leftSqrt;
}
double y_lim(double eps){
    long** cache = (long**)malloc(C_CACHE_SIZE * sizeof(long*));
    for(int i = 0; i < C_CACHE_SIZE; i++){
        cache[i] = calloc(C_CACHE_SIZE, sizeof(long));
    }
    double prevY = 1;
    double curY = 0;
    int m = 1;
    while(fabs(prevY - curY) > eps && m + 1 < C_CACHE_SIZE) {
        m++;
        prevY = curY;
        curY = 0;
        for(int k = 1; k <= m; k++){
            if(cache[m][k] == 0){
                cache[m][k] = C_n_k(m, k, cache);
            }
            double rs = (cache[m][k] * pow(-1, k) / k * ln_factorial(k)) ;
            curY += rs;
        }
        
    }
    for(int i = 0; i < C_CACHE_SIZE; i++){
        free(cache[i]);
    }
    free(cache);
    return curY;
}
double y_sum(double eps){
    double prevY = -1;
    double curY = 0;
    int n = 1;
    int prevN = 1;
    while(fabs(curY - prevY) > eps){
        prevN = n;
        n = n * 1.007 + 100;
        prevY = curY;
        for(int k = prevN + 1; k <= n; k++){
            curY += 1.0 / pow(floor(sqrt(k)), 2.0) - 1.0 / k;
        }
    }
    //printf("%f %f", prevY, curY);
    return - pow(3.141592653589793, 2.0) / 6.0 + curY;
}
double y_e(double eps){
    int t = 2;
    double prevRes = -1;
    double curRes = 1;
    while(fabs(curRes - prevRes) > eps){
        prevRes = curRes;
        curRes = 1;
        for(int i = 2; i <= t; i++){
            if(is_prime(i)){
                curRes *= (double)(i - 1) / i;
            }
        }
        curRes = log(t) * curRes;
        t = t * 1.05 + 100;
    }
    return -log(curRes);
}
double factorial(double n){
    double res = 1;
    for(int i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}
double imcomplete_fact(double start, double end){
    double res = 1;;
    for(int i = start; i <= end; i++){
        res *= i;
    }
    return res;
}
double C_n_k(long n, long k, long **cache){
    if(n == k) return 1;
    if(n == 0 || k == 0) return 1;
    if(cache[n][k] != 0){
        return cache[n][k];
    }
    else{
        return C_n_k(n - 1, k, cache) + C_n_k(n - 1, k - 1, cache);
    }
}
double ln_factorial(double n){
    if(n < 2) return 0;
    double res = log(2);
    for(int i = 3; i <= n; i++){
        res += log(i);
    }
    return res;
}