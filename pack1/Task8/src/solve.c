#include "../include/solve.h"
#include "../include/string_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


Status is_suitable_number(const char *word) {
    for (int i = 0; *(word + i) != '\0'; i++) {
        if (!(isalpha(*(word + i)) || isdigit(*(word + i)))) {
            return INVALID_CHARACTER;
        }
    }
    return OK;
}

Status conver_to_10_system(const char *number, const int system, int *res) {
    Status er;
    if (is_empty_string(number)) return EMPTY_STRING;

    int firstLitPos = 0;
    if (*number == '-') {
        firstLitPos = 1;
    }

    int len = strlen(number);
    long sum = 0;
    long pow = 1;
    for(int i = len - 1; i >= firstLitPos; i--){
        int val;
        if ((er = char_to_int(*(number + i), &val)) != OK){
            return er;
        }

        if (val >= system) {
            return INVALID_NUMBER_SYSTEM;
        }

        sum += val * pow;
        pow *= system;

        if (sum > __INT_MAX__){
            return TOO_LARGE_NUMBER;
        }
    }
    
    if (firstLitPos == 0) {
        *res = sum;
    }
    else {
        *res = -sum;
    }

    return OK;
}
Status convert_to_n_system(const char *number, const int curSystem, const int newSystem, char **res) {
    Status status;
    int resNumberSize = 10;
    char* resNumber = malloc(sizeof(char) * resNumberSize);
    int curResIndex = 0;
    int numberIn10;

    if ((status = conver_to_10_system(number, curSystem, &numberIn10)) != OK) {
        return status;
    }

    int isNegative = 0;
    if (numberIn10 < 0) {
        isNegative = 1;
        numberIn10 = -numberIn10;
    }

    if (numberIn10 == 0) {
        resNumber[0] = '0';
        resNumber[1] = '\0';
        *res = resNumber;
        return OK;
    }

    while(numberIn10 != 0) {
        int remainder = numberIn10 % newSystem;
        char remainderChar;
        if ((status = int_to_char(remainder, &remainderChar)) != OK) return status;
        if (curResIndex + 1 >= resNumberSize){
            resNumberSize *= 2;

            char *newResNumber = realloc(resNumber, sizeof(char) * (resNumberSize + isNegative));
            if(newResNumber == NULL){
                free(resNumber);
                return MEMORY_ALLOCATION_ERROR;
            }
            resNumber = newResNumber;
        }
        resNumber[curResIndex] = remainderChar;
        curResIndex++;
        numberIn10 /= newSystem;
    }
    
    if (isNegative) {
        resNumber[curResIndex] = '-';
        curResIndex++;
    }

    resNumber[curResIndex] = '\0';

    reverse_string(resNumber);
    *res = resNumber;
    return OK;
}
Status char_to_int(const char chr, int *res){
    if (chr >= '0' && chr <= '9') {
        *res = chr - '0';
        return OK;
    }
    else if(chr >= 'A' && chr <= 'Z') {
        *res = chr - 'A' + 10;
        return OK;
    }
    else if(chr >= 'a' && chr <= 'z'){
        *res = chr - 'a' + 10;
        return OK;
    }
    return INVALID_CHARACTER;
} 
Status int_to_char(const int val, char *res){
    if (val >= 0 && val <= 9) {
        *res = '0' + val;
        return OK;
    }
    if (val >= 10 && val <= 35) {
        *res = 'A' + val - 10;
        return OK;
    }
    printf("Can`t convert int to number system character\n"); 
    return NOT_OK;
}