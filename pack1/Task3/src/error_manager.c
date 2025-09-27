#include "../include/error_manager.h"
#include <stdio.h>

void print_error(Error error){
    switch (error)
    {
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
    case TOO_LARGE_NUMBER:
        printf("Error: number is too large to process!\n");
        break;
    case SOLUTION_IS_ANY_NUMBER:
        printf("Any x is a solution\n");
        break;
    case NO_SOLUTION:
        printf("Error: this equation has no solutions!\n");
        break;
    default:
        printf("Error: unknown error %d !\n", error);
        break;
    }
}