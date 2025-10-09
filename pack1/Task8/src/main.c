#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/status_manager.h"
#include "../include/string_helper.h"
#include "../include/solve.h"

Status print_result(char *maxWord, int numberSystem) {
    Status status;
    char *numberIn9;
    char *numberIn18;
    char *numberIn27;
    char *numberIn36;
    if ((status = convert_to_n_system(maxWord, numberSystem, 9, &numberIn9)) != OK) {
        free(maxWord);
        print_status(status);
        return status;
    }
    if ((status = convert_to_n_system(maxWord, numberSystem, 18, &numberIn18)) != OK) {
        free(maxWord);
        free(numberIn9);
        print_status(status);
        return status;
    }
    if ((status = convert_to_n_system(maxWord, numberSystem, 27, &numberIn27)) != OK) {
        free(maxWord);
        free(numberIn9);
        free(numberIn18);
        print_status(status);
        return status;
    }
    if ((status = convert_to_n_system(maxWord, numberSystem, 36, &numberIn36)) != OK) {
        free(maxWord);
        free(numberIn9);
        free(numberIn18);
        free(numberIn27);
        print_status(status);
        return status;
    }
    printf("MAX VAL: %s \n9: %s \n18: %s \n27: %s \n36: %s\n", maxWord, numberIn9, numberIn18, numberIn27, numberIn36);
    free(maxWord);
    free(numberIn9);
    free(numberIn18);
    free(numberIn27);
    free(numberIn36);
}


int main(int argc, char* argv[]) {
    int numberSystem;
    Status status;
    if ((status = read_natural_integer(&numberSystem)) != OK) {
        print_status(status);
        return status;
    }

    if (numberSystem < 2 || numberSystem > 36) {
        printf("Error: Wrong number system value!\n");
        return INVALID_NUMBER;
    }

    char *word = NULL;
    int maxVal = -1;
    char *maxWord = NULL;
    while ((status = read_word(&word)) == OK) {
        if (strcmp(word, "STOP") == 0) break;

        int valueIn10;
        if ((status = conver_to_10_system(word, numberSystem, &valueIn10)) != OK) {
            free(word);
            if(maxWord != NULL) free(maxWord);

            print_status(status);
            return status;
        }

        if (abs(valueIn10) > maxVal) {
            maxVal = abs(valueIn10);

            if (maxWord != NULL) free(maxWord);
            
            maxWord = malloc(sizeof(char) * (strlen(word) + 1));
            strcpy(maxWord, word);
        }
        free(word);
    }

    free(word);

    if (status != OK) {
        free(maxWord);
        print_status(status);
        return status;
    }

    remove_leading_zeros(&maxWord);
    status = print_result(maxWord, numberSystem);
    
    return status;
}