#include "../include/solve.h"
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

long long gcd(long long a, long long b) {
    if (a == 0) return b;

    while (b != 0) {
        long long c = b;
        b = a % b;
        a = c;
    }

    return a;
}

Status is_infinite_fractions(long long base, int **res, int count, ...) {
    va_list args;
    va_start(args, count);
    
    Status status;
    *res = (int*)malloc(sizeof(int) * count);
    if (*res == NULL) {
        return MEMORY_ALLOCATION_ERROR;
    }
    for (int i = 0; i < count; i++) {
        double fraction = va_arg(args, double);
        status = is_infinite_fraction(base, fraction, &((*res)[i]));

        if((*res)[i] == 0) {
            printf("Fract %lf is finit\n", fraction);
        }
        else {
            printf("Fract %lf is infinit\n", fraction);
        }
        
        
        if (status != OK) {
            print_status(status);
            return status;
        }
    }

    return OK;
}

Status is_infinite_fraction(long long base, long double fraction, int *res) {
    Status status;
    long long numerator, denumerator;
    status = to_proper_fracton(fraction, &numerator, &denumerator);
    if (status != OK) {
        return status;
    }
    
    long long fractGcd = gcd(numerator, denumerator);
    numerator /= fractGcd;
    denumerator /= fractGcd;

    //printf("Num: %lld Denum: %lld\n", numerator, denumerator);

    for (int i = 2; i * i <= denumerator; i++) {
        if (denumerator % i == 0 && base % i != 0) {
            *res = 1;
            return OK;
        }
        while(denumerator % i == 0) {
            denumerator /= i;
        }
    }
    if (base % denumerator != 0) {
        *res = 1;
        return OK;
    }
    *res = 0;
    return OK;
}

Status to_proper_fracton(long double fraction, long long* numerator, long long *denominator) {
    long long maxVal = 1e15;
    long long resNumerator = 0;
    long long resDenominator = 1;


    while (ceil(fraction) - fraction > 1e-5 && resDenominator < maxVal) {
        resDenominator *= 10;
        fraction *= 10;
    }
    resNumerator = llround(fraction);
    
    *numerator = resNumerator;
    *denominator = resDenominator;


    return OK;
}

// Status reduce_fraction(int *numerator, int *denominator) {
//     if (*numerator == 0) {
//         *denominator = 1;
//         return OK;
//     }
//     int localNum = *numerator;

//     for (int i = 2; i * i < localNum; i++) {
//         while (*numerator % i == 0 && *denominator % i == 0) {
//             printf("i %d\n", i);
//             *numerator /= i;
//             *denominator /= i;
//         }
//         while (localNum % i == 0) {
//             localNum /= i;
//         }
//     }

//     if (*denominator % localNum == 0) {
//         *denominator /= localNum;
//         *numerator /= localNum;
//     }

//     return OK;
// }