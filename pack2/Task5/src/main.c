#include <stdio.h>
#include <stdlib.h>
#include "../include/status_manager.h"
#include "../include/string_manager.h"
#include "../include/solve.h"

int main(int argc, char* argv[]) {
    char *inputFileName;
    char *outputFileName;
    Status status;
    if ((status = read_word(&inputFileName)) != OK) {
        print_status(status);
        return status;
    }
    
    if ((status = read_word(&outputFileName)) != OK) {
        print_status(status);
        return status;
    }


    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        print_status(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        print_status(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }

    char *string;
    int required;
    int totalSpaceAmo;
    while((status = read_string_or_80(inputFile, &string, &required, &totalSpaceAmo)) == OK) {
        //printf("String: %s\n requaredSpaceAmo: %d SpaceAmo: %d\n", string, required, totalSpaceAmo);
        write_string_or_80(outputFile, string, required, totalSpaceAmo);
        free(string);
    }

    if (status != END_OF_INPUT) {
        print_status(status);
        return status;
    }
    //printf("String: %s\n requaredSpaceAmo: %d SpaceAmo: %d\n", string, required, totalSpaceAmo);
    write_string_or_80(outputFile, string, required, totalSpaceAmo);
    free(string);
    fclose(inputFile);
    fclose(outputFile);
}