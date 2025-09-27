#include "../include/solve.h"
#include "../include/number_helper.h"
#include "../include/string_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


Error is_suitable_number(const char *word) {
    for(int i = 0; *(word + i) != '\0'; i++){
        if(!(isalpha(*(word + i)) || isdigit(*(word + i)))){
            return INVALID_CHARACTER;
        }
    }
    return OK;
}

Error conver_to_10_system(const char *number, const int system, int *res){
    Error er;
    int len = strlen(number);
    long sum = 0;
    long pow = 1;
    for(int i = len - 1; i >= 0; i--){
        int val;
        if((er = char_to_int(*(number + i), &val)) != OK){
            return er;
        }
        if(val >= system) {
            return INVALID_NUMBER_SYSTEM;
        }
        sum += val * pow;
        pow *= system;
        if(sum > __INT_MAX__){
            return TOO_LARGE_NUMBER;
        }
    }
    *res = sum;
    return OK;
}
Error convert_to_n_system(const char *number, const int curSystem, const int newSystem, char **res) {
    Error er;
    int resNumberSize = 10;
    char* resNumber = malloc(sizeof(char) * resNumberSize);
    int curResIndex = 0;
    int numberIn10;
    if((er = conver_to_10_system(number, curSystem, &numberIn10)) != OK) {
        return er;
    }
    while(numberIn10 != 0) {
        int remainder = numberIn10 % newSystem;
        char remainderChar;
        if((er = int_to_char(remainder, &remainderChar)) != OK) return er;
        if(curResIndex + 1 >= resNumberSize){
            resNumberSize *= 2;
            char *newResNumber = realloc(resNumber, sizeof(char) * resNumberSize);
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
    resNumber[curResIndex] = '\0';
    reverse_string(resNumber);
    *res = resNumber;
    return OK;
}
Error char_to_int(const char chr, int *res){
    if(chr >= '0' && chr <= '9'){
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
Error int_to_char(const int val, char *res){
    if(val >= 0 && val <= 9){
        *res = '0' + val;
        return OK;
    }
    if(val >= 10 && val <= 35){
        *res = 'A' + val - 10;
        return OK;
    }
    return TOO_LARGE_NUMBER;
}