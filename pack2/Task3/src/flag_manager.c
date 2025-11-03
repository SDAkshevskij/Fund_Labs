#include "../include/solve.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/vector.h"
#include "../include/status_manager.h"
#include "../include/flag_manager.h"
#include <string.h>
#include <ctype.h>

char* flag_Ro(int val) {
    int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    Status status;
    Vector_char *resVector = vector_char_create(&status);
    
    int i = 0;
    while(val > 0) {
        while(numbers[i] <= val) {
            for (int j = 0; romans[i][j] != '\0'; j++) {
                vector_char_push_back(resVector, romans[i][j]);
            }
            val -= numbers[i];
        }
        i++;
    }

    vector_char_push_back(resVector, '\0');
    char *result = vector_char_steal_data(resVector);
    vector_char_delete(resVector);

    return result;
}

unsigned int get_less_fibonachi_index(unsigned int value, unsigned int *fibonachi) {
    long long fib1 = 1;
    long long fib2 = 1;

    if (value == 1) {
        *fibonachi = 1;
        return 0;
    }

    int index = 0;
    while (fib1 + fib2 <= value) {
        long long temp = fib1;
        fib1 = fib2;
        fib2 = temp + fib1;
        index++;
    }

    *fibonachi = (unsigned int)fib2;
    return index;
}

char* flag_Zr(unsigned int val) {
    Vector_int *indexes = vector_int_create();

    while(val > 0) {
        int fib;
        int index = get_less_fibonachi_index(val, &fib);
        val -= fib;
        vector_int_push_back(indexes, index);
    }

    Vector_char *resVector = vector_char_create(); 
    int curIndex = 0;
    for (int i = vector_int_size(indexes) - 1; i >= 0; i--) {
        while(curIndex != vector_int_at(indexes, i)) {
            vector_char_push_back(resVector, '0');
            curIndex++;
        }

        vector_char_push_back(resVector, '1');
        curIndex++;
    }

    vector_char_push_back(resVector, '1');
    vector_int_delete(indexes);
    
    vector_char_push_back(resVector, '\0');
    char *result = vector_char_steal_data(resVector);
    vector_char_delete(resVector);

    return result;
}

char* flag_Cv(int value, int base, int upperModifier) {
    int isNeg = 0;
    if (value < 0) {
        isNeg = 1;
        value = -value;
    }

    Vector_char *resVector = vector_char_create();
    while (value > 0) {
        int num = value % base;
        value /= base;
        if (num < 10) {
            vector_char_push_back(resVector, num + '0');
        }
        else {
            vector_char_push_back(resVector, num + 'a' - 10 + upperModifier);
        }
    }
    
    if (isNeg) {
        vector_char_push_back(resVector, '-');
    }

    vector_char_reverse(resVector);

    vector_char_push_back(resVector, '\0');
    char *result = vector_char_steal_data(resVector);
    vector_char_delete(resVector);

    return result;
}

char* flag_to(char *numStr, int base, int upperModifier) {
    int strSize = strlen(numStr);
    int pow = 1;
    unsigned int result = 0;

    for (int i = strSize - 1; i >= 0; i--) {
        int val = 0;        
        if (isdigit(numStr[i])) val = numStr[i] - '0';
        else val = numStr[i] - 'a' + 10 - upperModifier;

        result += val * pow;
        pow *= base;
    }

    char *resString = (char*)malloc(sizeof(char) * 20);
    sprintf(resString, "%d", result);

    return resString;
}

char *flag_mi(int value) {
    char *result = (char*)malloc(sizeof(char) * 36);

    int curBit = 0;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 7; j++) {
            int bit = (value & (1 << (i * 8) + j));

            if (bit == 0) result[curBit] = '0';
            else result[curBit] = '1';
            
            curBit++;
        }
        result[curBit++] = ' ';
    }

    result[curBit - 1] = '\0';

    return result;
}

char *flag_mu(unsigned int value) {
    char *result = (char*)malloc(sizeof(char) * 36);

    int curBit = 0;
    unsigned char *bytes = (unsigned char *)&value;

    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 7; j++) {
            int bit = (bytes[i] & (1 << j));

            if (bit == 0) result[curBit] = '0';
            else result[curBit] = '1';
            
            curBit++;
        }
        result[curBit++] = ' ';
    }

    result[curBit - 1] = '\0';

    return result;
}

char* flag_md(double value) {
    char *result = (char*)malloc(sizeof(char) * 72);

    unsigned char *bytes = (unsigned char *)&value;

    int curBit = 0;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 7; j++) {
            int bit = (bytes[i] & (1 << j));

            if (bit == 0) result[curBit] = '0';
            else result[curBit] = '1';
            
            curBit++;
        }
        result[curBit++] = ' ';
    }

    result[curBit - 1] = '\0';

    return result;
}

char* flag_mf(float value) {
    char *result = (char*)malloc(sizeof(char) * 36);
    unsigned char *bytes = (unsigned char *)&value;

    int curBit = 0;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 7; j++) {
            int bit = (bytes[i] & (1 << j));

            if (bit == 0) result[curBit] = '0';
            else result[curBit] = '1';
            
            curBit++;
        }
        result[curBit++] = ' ';
    }

    result[curBit - 1] = '\0';

    return result;
}