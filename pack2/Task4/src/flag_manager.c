#include "../include/solve.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/vector.h"
#include "../include/status_manager.h"
#include "../include/flag_manager.h"
#include <string.h>
#include <ctype.h>

int getRomanVal(char c) {
    int values[] = {1000, 500, 100, 50, 10, 5, 1};
    char romans[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

    for (int i = 0; i < 7; i++) {
        if (c == romans[i]) {
            return values[i];
        }
    }

    return 0;
}

int flag_Ro(char *roman) {
    int size = strlen(roman);
    int maxVal = -1;
    int result = 0;

    for (int i = size - 1; i >= 0; i--) {
        int val = getRomanVal(roman[i]);
        
        if (val < maxVal) {
            result -= val;
        }
        else {
            result += val;
            maxVal = val;
        }
    }

    return result;
}

int get_less_fibonachi_index(int value, int *fibonachi) {
    int fib1 = 1;
    int fib2 = 1;

    if (value == 1) {
        *fibonachi = 1;
        return 0;
    }

    int index = 0;
    while (fib1 + fib2 <= value) {
        int temp = fib1;
        fib1 = fib2;
        fib2 = temp + fib1;
        index++;
    }

    *fibonachi = fib2;
    return index;
}

unsigned int flag_Zr(char* string) {
    unsigned int result = 0;

    unsigned int fib1 = 1;
    unsigned int fib2 = 1;

    for (int i = 0; string[i + 1] != '\0'; i++) {
        if (string[i] == '1') {
            result += fib2;
        }

        unsigned int temp = fib1;
        fib1 = fib2;
        fib2 = temp + fib2;
    }

    return result;
}

int flag_Cv(char *string, int base, int upperModifier) {
    int isNeg = 0;
    int size = strlen(string);

    if (*string == '-') {
        isNeg = 1;
    }


    int result = 0;
    int pow = 1;

    for (int i = size - 1; i >= isNeg; i--) {
        int val = 0;
        if (string[i] >= '0' && string[i] <= '9') {
            val = string[i] - '0';
        }
        else {
            val = string[i] - 'a' - upperModifier + 10;
        }

        result += val * pow;
        pow *= base;
    }

    if (isNeg) {
        result = -result;
    }

    return result;
}
