#include "../include/status_manager.h"
#include <stdio.h>

void print_status(Status error){
    switch (error){
    case OK:
        printf("Error: everything is fine!\n");
        break;
    case YOU_FORGET_ABOUT_PARENTHESIS:
        printf("Error: you forget about parenthesis! again...\n");
        break;
    case NOT_OK:
        printf("Error: not ok!\n");
        break;
    case WRONG_FLAG:
        printf("Error: unknown flag!\n");
        break;
    case WRONG_ARGUMENT_AMOUNT:
        printf("Error: wrong argument amount!\n");
        break;
    case MEMORY_ALLOCATION_ERROR:
        printf("Error: memory allocation error\n");
        break;
    case NOT_A_NUMBER:
        printf("Error: program expected number as input!\n");
        break;
    case NEGATIVE_NUMBER:
        printf("Error: program expected non negative number!\n");
        break;
    case NON_NATURAL_NUMBER:
        printf("ERROR: program expected natural numbers as input!\n");
        break;
    case NUMBER_IS_ZERO:
        printf("Error: number must be not zero!\n");
        break;
    case INVALID_NUMBER:
        printf("Error: invalid number value!\n");
        break;
    case INVALID_NUMBER_SYSTEM:
        printf("Error: invalid number system!\n");
        break;
    case TOO_LARGE_NUMBER:
        printf("Error: number is too large to process!\n");
        break;
    case SOLUTION_IS_ANY_NUMBER:
        printf("Any x is a solution\n");
        break;
    case NO_SOLUTION:
        printf("Error: this equation has no solutions!\n");
        break;
    case CANT_OPEN_FILE:
        printf("Error: can`t open file!\n");
        break;
    case TOO_LONG_WORD:
        printf("Error: too long word to process!\n");
        break;
    case INVALID_CHARACTER:
        printf("Error: input have invalid characters!\n");
        break;
    case END_OF_INPUT:
        printf("Error: end of input!\n");
        break;
    case EMPTY_STRING:
        printf("Error: an empty string was received!\n");
        break;
    default:
        printf("Error: unknown error %d !\n", error);
        break;
    }
}