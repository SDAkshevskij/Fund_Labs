#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/error_manager.h"
#include "../include/string_helper.h"
#include "../include/number_helper.h"
#include "../include/solve.h"


int main(int argc, char* argv[]) {
    if(argc < 3){
        print_error(WRONG_ARGUMENT_AMOUNT);
        return WRONG_ARGUMENT_AMOUNT;
    }
    if(!is_flag(argv[1])){
        print_error(WRONG_FLAG);
        return WRONG_FLAG;
    }

    char *flag = malloc(sizeof(char) * (strlen(argv[1]) + 1));
    if(flag == NULL){
        print_error(MEMORY_ALLOCATION_ERROR);
        return MEMORY_ALLOCATION_ERROR;
    }
    strcpy(flag, argv[1]);
    char flagVal = flag[1];

    char *inputFileName = malloc(sizeof(char) * (strlen(argv[2]) + 1));
    if(inputFileName == NULL){
        free(flag);
        print_error(MEMORY_ALLOCATION_ERROR);
        return MEMORY_ALLOCATION_ERROR;
    }
    strcpy(inputFileName, argv[2]);

    char *outputFileName;
    if(flag[1] == 'n') {
        if(argc != 4){
            print_error(WRONG_ARGUMENT_AMOUNT);
            return WRONG_ARGUMENT_AMOUNT;
        }
        outputFileName = malloc(sizeof(char) * (strlen(argv[3]) + 1));
        if(outputFileName == NULL){
            free(flag);
            free(inputFileName);
            print_error(MEMORY_ALLOCATION_ERROR);
            return MEMORY_ALLOCATION_ERROR;
        }
        strcpy(outputFileName, argv[3]);
        flagVal = flag[2];
    }
    else {
        outputFileName = malloc(sizeof(char) * (strlen(argv[2]) + 5));
        if(outputFileName == NULL){
            free(flag);
            free(inputFileName);
            print_error(MEMORY_ALLOCATION_ERROR);
            return MEMORY_ALLOCATION_ERROR;
        }
        strcpy(outputFileName, "out_");
        strcat(outputFileName, inputFileName);
    }
    
    FILE* inputFile = fopen(inputFileName, "r");
    if(inputFile == NULL) {
        free(flag);
        free(inputFileName);
        free(outputFileName);
        print_error(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }

    FILE* outputFile = fopen(outputFileName, "w");
    if(outputFile == NULL){
        free(flag);
        free(inputFileName);
        free(outputFileName);
        fclose(inputFile);
        print_error(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }
    printf("switch start\n");
    switch(flagVal){
        case 'd':
            process_flag_d(inputFile, outputFile);
            break;
        case 'i':
            process_flag_i(inputFile, outputFile);
            break;
        case 's':
            process_flag_s(inputFile, outputFile);
            break;
        case 'a':
            Error er = process_flag_a(inputFile, outputFile);
            if(er != OK) {
                free(flag);
                free(inputFile);
                free(outputFile);
                fclose(outputFile);
                fclose(inputFile);
                return er;
            }
            break;
        default:
            print_error(UNKNOWN_FLAG);
            free(flag);
            free(inputFileName);
            free(outputFileName);
            fclose(inputFile);
            fclose(outputFile);
            return UNKNOWN_FLAG;
    }
    free(flag);
    free(inputFileName);
    free(outputFileName);
    fclose(inputFile);
    fclose(outputFile);
    return OK;
}