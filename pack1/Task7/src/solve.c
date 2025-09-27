#include "../include/solve.h"
#include "../include/number_helper.h"
#include "../include/string_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


Error file_read_word(FILE* file, char **word){
    const int MAX_WORD_LEN = 100;
    char* buffer = malloc(MAX_WORD_LEN + 2);
    if(buffer == NULL) return MEMORY_ALLOCATION_ERROR;
    int res = fscanf(file, "%101s", buffer);
    if(res == EOF){
        free(buffer);
        return EMPTY_STRING;
    }
    if(strlen(buffer) > MAX_WORD_LEN){
        free(buffer);
        return TOO_LONG_WORD;
    }
    *word = buffer;
    return OK;
}
Error is_suitable_number(const char *word) {
    for(int i = 0; *(word + i) != '\0'; i++){
        if(!(isalpha(*(word + i)) || isdigit(*(word + i)))){
            return INVALID_CHARACTER;
        }
    }
    return OK;
}
Error determine_min_number_system(const char *word, int *system) {
    Error er;
    if((er = is_suitable_number(word)) != OK){
        return er;
    }
    char maxChar = '1';
    for(int i = 0; *(word + i) != '\0'; i++){
        char curChar = *(word + i);
        if(islower(curChar)){
            curChar = toupper(curChar);
        }
        if((int)curChar > (int)maxChar){
            maxChar = curChar;
        }
    }
    if((int)maxChar <= (int)'9'){
        *system = maxChar - '0' + 1;
        return OK;
    }
    else {
        *system = maxChar - 'A' + 11;
        return OK;
    }

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
        sum += val * pow;
        pow *= system;
        if(sum > __INT_MAX__){
            return TOO_LARGE_NUMBER;
        }
    }
    *res = sum;
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