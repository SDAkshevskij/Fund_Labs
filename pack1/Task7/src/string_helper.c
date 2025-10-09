#include "../include/string_helper.h"
#include "../include/error_manager.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int is_empty_string(char* string){
    if(string == NULL || *string == '\0'){
        return 1;
    }
    return 0;
}
Status check_natural_integer(char* string){
    if(is_empty_string(string)){
        return NOT_A_NUMBER;
    }
    if(*string == '-'){
        return NEGATIVE_NUMBER;
    }
    return check_integer(string);
}
Status check_integer(char* string){
    if(is_empty_string(string)){
        return NOT_A_NUMBER;
    }
    int i = 0;
    if(*string == '-'){
        i++;
    }
    for(; *(string + i) != '\0'; i++){
        if(!isdigit(*(string + i))){
            return NOT_A_NUMBER;
        }
    }
    if(i > 9){
        return TOO_LARGE_NUMBER;
    }
    return OK;
}
int is_flag(char* string){
    if(string == NULL || *string == '\0'){
        return 0;
    }
    if(*string != '-' && *string != '/'){
        return 0;
    }
    if(!isalpha(*(string + 1))){
        return 0;
    }
    if(*(string + 2) != '\0'){
        return 0;
    }
    return 1;
}

Status read_word(char **word){
    int bufferSize = 10;
    char* buffer = malloc(sizeof(char) * bufferSize);
    if(buffer == NULL) return MEMORY_ALLOCATION_ERROR;
    int nextBufferIndex = 0;
    char c;
    while((c = getchar()) != ' ' && c != '\n'){
        if(nextBufferIndex == bufferSize - 1){
            bufferSize *= 2;
            buffer = realloc(buffer, bufferSize);
            if(buffer == NULL) return MEMORY_ALLOCATION_ERROR;
        }
        buffer[nextBufferIndex] = c;
        nextBufferIndex++;
    }
    buffer[nextBufferIndex] = '\0';
    *word = buffer;
    return OK;
}
Status read_natural_integer(int *res) {
    char* word;
    if(read_word(&word)) {
        return MEMORY_ALLOCATION_ERROR;
    }
    if(check_natural_integer(word) != OK){
        return NON_NATURAL_NUMBER;
    }
    if(strlen(word) > 9){
        return TOO_LARGE_NUMBER;
    }
    *res = atoi(word);
    free(word);
    return OK;
}

Status check_double(char* string){
    if(is_empty_string(string)) return NOT_A_NUMBER;
    int i = 0;
    int digitsBeforeDotAmo = 0;
    if(*string == '-'){
        i++;
    }
    int dotAmount = 0;
    for(; *(string + i) != '\0'; i++){
        char chr = *(string  + i);
        if(!isdigit(chr)){
            if(chr == '.' && dotAmount == 0) {
                dotAmount++;
            }
            else {
                return NOT_A_NUMBER;
            }
        }
        if(dotAmount == 0){
            digitsBeforeDotAmo++;
        }
    }
    if(digitsBeforeDotAmo > 10) return TOO_LARGE_NUMBER;
    
    return OK;
}

Status read_float(double *res){
    char *word;
    if(read_word(&word)){
        return MEMORY_ALLOCATION_ERROR;
    }
    Status er;
    if(er = check_double(word) != OK){
        return er;
    }
    *res = atof(word);
    free(word);
    return OK;
}
Status remove_leading_zeros(char **numberLink) {
    char *number = *numberLink;
    if(is_empty_string(number)) return EMPTY_STRING;
    if(*number != '0') return OK;
    int leadingZerosAmo = 0;
    for(; number[leadingZerosAmo] == '0'; leadingZerosAmo++){}
    int numLen = strlen(number);
    char *newNumber = malloc(sizeof(char) * (numLen - leadingZerosAmo + 1));
    for(int i = leadingZerosAmo; i < numLen; i++){
        newNumber[i - leadingZerosAmo] = number[i];
    }
    newNumber[numLen - leadingZerosAmo] = '\0';
    free(*numberLink);
    *numberLink = newNumber;
    return OK;
}
void reverse_string(char *string){
    int start = 0;
    int end = strlen(string) - 1;
    while(start < end){
        char buffer = string[start];
        string[start] = string[end];
        string[end] = buffer;
        start++;
        end--;
    }
}
