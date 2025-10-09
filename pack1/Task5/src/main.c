#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/status_manager.h"
#include "../include/solve.h"

int is_flag(char* string){
    if(string == NULL || *string == '\0'){
        return 0;
    }
    if(*string != '-' && *string != '/'){
        return 0;
    }
    if(!isalpha(*(string + 1)) || !isalpha(*(string + 2))){
        if(*(string + 2) == '\0'){
            return 1;
        }
        return 0;
    }
    if(*(string + 3) != '\0'){
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        print_status(WRONG_ARGUMENT_AMOUNT);
        return WRONG_ARGUMENT_AMOUNT;
    }
    if (!is_flag(argv[1])) {
        print_status(WRONG_FLAG);
        return WRONG_FLAG;
    }

    char *flag = malloc(sizeof(char) * (strlen(argv[1]) + 1));
    if (flag == NULL) {
        print_status(MEMORY_ALLOCATION_ERROR);
        return MEMORY_ALLOCATION_ERROR;
    }
    strcpy(flag, argv[1]);
    char flagVal = flag[1];

    char *inputFileName = malloc(sizeof(char) * (strlen(argv[2]) + 1));
    if (inputFileName == NULL) {
        free(flag);
        print_status(MEMORY_ALLOCATION_ERROR);
        return MEMORY_ALLOCATION_ERROR;
    }
    strcpy(inputFileName, argv[2]);

    char *outputFileName;
    if (flag[1] == 'n') {
        if(argc != 4){
            print_status(WRONG_ARGUMENT_AMOUNT);
            return WRONG_ARGUMENT_AMOUNT;
        }

        outputFileName = malloc(sizeof(char) * (strlen(argv[3]) + 1));
        if (outputFileName == NULL) {
            free(flag);
            free(inputFileName);
            print_status(MEMORY_ALLOCATION_ERROR);
            return MEMORY_ALLOCATION_ERROR;
        }

        strcpy(outputFileName, argv[3]);
        flagVal = flag[2];
    }
    else {
        if (argc != 3) {
            print_status(WRONG_ARGUMENT_AMOUNT);
            return WRONG_ARGUMENT_AMOUNT;
        }

        outputFileName = malloc(sizeof(char) * (strlen(argv[2]) + 5));
        if (outputFileName == NULL) {
            free(flag);
            free(inputFileName);
            print_status(MEMORY_ALLOCATION_ERROR);
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
        print_status(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }

    FILE* outputFile = fopen(outputFileName, "w");
    if(outputFile == NULL){
        free(flag);
        free(inputFileName);
        free(outputFileName);
        fclose(inputFile);
        print_status(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }

    switch (flagVal) {
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
            Status er = process_flag_a(inputFile, outputFile);
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
            print_status(WRONG_FLAG);
            free(flag);
            free(inputFileName);
            free(outputFileName);
            fclose(inputFile);
            fclose(outputFile);
            return WRONG_FLAG;
    }
    free(flag);
    free(inputFileName);
    free(outputFileName);
    fclose(inputFile);
    fclose(outputFile);
    return OK;
}