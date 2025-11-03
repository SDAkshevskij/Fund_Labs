#include "../include/string_manager.h"
#include "../include/status_manager.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>


int is_empty_string(const char* string){
    if (string == NULL || *string == '\0') {
        return 1;
    }
    return 0;
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

Status read_non_space_symb(char *res) {
    char c;
    while((c = getchar()) != EOF && isspace(c)) {}

    if (c == EOF) {
        return EMPTY_STRING;
    }

    *res = c;
    return OK;
}

Status read_word(char **word){
    int bufferSize = 10;
    char* buffer = (char*)malloc(sizeof(char) * bufferSize);
    if(buffer == NULL) return MEMORY_ALLOCATION_ERROR;

    int nextBufferIndex = 0;
    char c;
    while((c = getchar()) != ' ' && c != '\n' && c != EOF){
        if(nextBufferIndex == bufferSize - 1){
            bufferSize *= 2;
            char *newBuffer = (char*)realloc(buffer, bufferSize);

            if(newBuffer == NULL) return MEMORY_ALLOCATION_ERROR;

            buffer = newBuffer;
        }

        buffer[nextBufferIndex] = c;
        nextBufferIndex++;
    }

    buffer[nextBufferIndex] = '\0';
    *word = buffer;
    if (c == EOF) {
        return END_OF_INPUT;
    }
    return OK;
}

Status read_natural_integer(int *res) {
    char* word;
    Status wordStatus = read_word(&word);
    if (wordStatus != OK && wordStatus != END_OF_INPUT) {
        return wordStatus;
    }
   
    Status status = string_to_natural_int(word, res);
    free(word);

    if(status == OK) {
        return wordStatus;
    }

    return status;
}

Status read_float(double *res){
    char *word;
    Status wordStatus = read_word(&word);
    if (wordStatus != OK && wordStatus != END_OF_INPUT) {
        return wordStatus;
    }

    Status status = string_to_double(word, res);
    free(word);

    if(status == OK) {
        return wordStatus;
    }

    return status;
}

Status remove_leading_zeros(char **numberLink) {
    char *number = *numberLink;
    if (is_empty_string(number)) return EMPTY_STRING;

    if (*number != '0') return OK;

    int leadingZerosAmo = 0;
    for (; number[leadingZerosAmo] == '0'; leadingZerosAmo++){}

    int numLen = strlen(number);

    if (numLen == leadingZerosAmo) {
        *numberLink = "0";
        return OK;
    }

    char *newNumber = malloc(sizeof(char) * (numLen - leadingZerosAmo + 1));
    for (int i = leadingZerosAmo; i < numLen; i++) {
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

    while (start < end) {
        char buffer = string[start];
        string[start] = string[end];
        string[end] = buffer;

        start++;
        end--;
    }
}

Status string_to_int(char *word, int *res) {
    char *endptr = NULL;
    long num = strtol(word, &endptr, 10);

    if (endptr == word) {
        return NOT_A_NUMBER;
    }

    if (*endptr != '\0') {
        return NOT_A_NUMBER;
    }

    if (num < INT_MIN || num > INT_MAX) {
        return TOO_LARGE_NUMBER;
    }

    *res = num;

    return OK;
}

Status string_to_natural_int(char *word, int *res) {
    Status status = string_to_int(word, res);
    if (status != OK) { 
        return status;
    }

    if (*res < 0) {
        return NON_NATURAL_NUMBER;
    }

    return OK;
}

Status string_to_double(char *word, double *res) {
    char *endptr = NULL;
    double num = strtod(word, &endptr);

    if (endptr == word) {
        return NOT_A_NUMBER;
    }

    if (*endptr != '\0') {
        return NOT_A_NUMBER;
    }

    *res = num;

    return OK;
}

void string_to_lower(char *string) {
    if (is_empty_string(string)) return;
    
    for (int i = 0; string[i] != '\0'; i++) {
        string[i] = tolower(string[i]);
    }
}
