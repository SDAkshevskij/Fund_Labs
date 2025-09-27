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
    Error er = OK;
    if(argc != 3){
        print_error(WRONG_ARGUMENT_AMOUNT);
        return WRONG_ARGUMENT_AMOUNT;
    }
    char *inputFilePath = argv[1];
    char *outputFilePath = argv[2];
    FILE *inputFile = fopen(inputFilePath, "r");
    if(inputFile == NULL){
        print_error(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }
    FILE *outputFile = fopen(outputFilePath, "w");
    if(outputFile == NULL){
        fclose(inputFile);
        print_error(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }

    char *word;
    while((er = file_read_word(inputFile, &word)) == OK && !is_empty_string(word)) {
        int minSystem;
        remove_leading_zeros(&word);
        if(((er = determine_min_number_system(word, &minSystem)) != OK)){
            free(word);
            break;
        }
        int number10;
        if((er = conver_to_10_system(word, minSystem, &number10)) != OK){
            free(word);
            break;
        }
        fprintf(outputFile, "%s %d %d\n", word, minSystem, number10);
        free(word);
    }
    if(er != OK && er != EMPTY_STRING) {
        print_error(er);
        fclose(inputFile);
        fclose(outputFile);
        return er;
    }
    fclose(inputFile);
    fclose(outputFile);

}