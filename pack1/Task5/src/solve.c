#include "../include/solve.h"
#include "../include/number_helper.h"
#include "../include/string_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


void process_flag_d(FILE *inputFile, FILE *outputFile) {
    char c;
    while((c = fgetc(inputFile)) != EOF){
        if(isdigit(c)) continue;
        fputc(c, outputFile);
    }
}
void process_flag_i(FILE *inputFile, FILE *outputFile) {
    char prevC = '\n';
    char curC;
    int alphaCount = 0;
    while((curC = fgetc(inputFile)) != EOF){
        if(curC == '\n'){
            fprintf(outputFile, "%d\n", alphaCount);
            alphaCount = 0;
        }
        else {
            if(isalpha(curC)){
                alphaCount++;
            }
        }
        prevC = curC;
    }
    if(prevC != '\n'){
        fprintf(outputFile, "%d\n", alphaCount);
        alphaCount = 0;
    }
}

void process_flag_s(FILE *inputFile, FILE *outputFile) {
    char prevC = '\n';
    char curC;
    int alphaCount = 0;
    while((curC = fgetc(inputFile)) != EOF){
        if(curC == '\n'){
            fprintf(outputFile, "%d\n", alphaCount);
            alphaCount = 0;
        }
        else {
            if(!isalnum(curC) && !isspace(curC)){
                alphaCount++;
            }
        }
        prevC = curC;
    }
    if(prevC != '\n'){
        fprintf(outputFile, "%d\n", alphaCount);
        alphaCount = 0;
    }
}
Error process_flag_a(FILE *inputFile, FILE *outputFile) {
    char c;
    while((c = fgetc(inputFile)) != EOF){
        if(isdigit(c)){
            fprintf(outputFile, "%d ", c - '0');
        }
        else {
            char *numIn16;
            Error er = convert_to_16((int)c, &numIn16);
            if(er != OK) return er;
            fprintf(outputFile, "%s ", numIn16);
            free(numIn16);
        }
    }
    return OK;
}
Error convert_to_16(int num, char **res) {
    Error er;
    int resNumberSize = 10;
    char* resNumber = malloc(sizeof(char) * resNumberSize);
    int curResIndex = 0;
    while(num != 0) {
        int remainder = num % 16;
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
        num /= 16;
    }
    resNumber[curResIndex] = '\0';
    reverse_string(resNumber);
    *res = resNumber;
    return OK;
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