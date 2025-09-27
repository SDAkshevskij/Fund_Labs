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
    int system;
    Error er;
    if((er = read_natural_integer(&system)) != OK){
        print_error(er);
        return er;
    }
    if(system < 2 || system > 36){
        printf("Error: Wrong number system value!\n");
        return INVALID_NUMBER;
    }
    char *word = NULL;
    int maxVal = -1;
    char *maxWord = NULL;
    while((er = read_word(&word)) == OK){
        if(strcmp(word, "STOP") == 0) break;
        int valueIn10;
        if((er = conver_to_10_system(word, system, &valueIn10)) != OK){
            free(word);
            if(maxWord != NULL) free(maxWord);
            print_error(er);
            return er;
        }
        if(valueIn10 > maxVal){
            maxVal = valueIn10;
            if(maxWord != NULL) free(maxWord);
            maxWord = malloc(sizeof(char) * (strlen(word) + 1));
            strcpy(maxWord, word);
        }
        free(word);
    }
    free(word);
    if(er != OK){
        free(maxWord);
        print_error(er);
        return er;
    }
    remove_leading_zeros(&maxWord);
    char *numberIn9;
    char *numberIn18;
    char *numberIn27;
    char *numberIn36;
    if((er = convert_to_n_system(maxWord, system, 9, &numberIn9)) != OK){
        free(maxWord);
        print_error(er);
        return er;
    }
     if((er = convert_to_n_system(maxWord, system, 18, &numberIn18)) != OK){
        free(maxWord);
        free(numberIn9);
        print_error(er);
        return er;
    }
     if((er = convert_to_n_system(maxWord, system, 27, &numberIn27)) != OK){
        free(maxWord);
        free(numberIn9);
        free(numberIn18);
        print_error(er);
        return er;
    }
    if((er = convert_to_n_system(maxWord, system, 36, &numberIn36)) != OK){
        free(maxWord);
        free(numberIn9);
        free(numberIn18);
        free(numberIn27);
        print_error(er);
        return er;
    }
    printf("MAX VAL: %s %d \n9: %s \n18: %s \n27: %s \n36: %s\n", maxWord, maxVal, numberIn9, numberIn18, numberIn27, numberIn36);
    free(maxWord);
    free(numberIn9);
    free(numberIn18);
    free(numberIn27);
    free(numberIn36);
    return OK;
}