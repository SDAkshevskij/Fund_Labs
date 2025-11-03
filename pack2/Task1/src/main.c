#include <stdio.h>
#include <stdlib.h>
#include "../include/status_manager.h"
#include "../include/string_manager.h"
#include "../include/solve.h"


int main(int argc, char* argv[]) {
    int *res;
    is_infinite_fractions(2, &res, 5, 0.234, 0.333333333333333333, 0.1, 0.5, 0.666);
    printf("\n");
    double b = 1.0/255;
    is_infinite_fractions(255, &res, 5, 0.6, 0.49, b, 0.2222222, 0.123456);

}