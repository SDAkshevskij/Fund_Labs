#include "../include/error_manager.h"
#include <stdio.h>

void print_status(Status error){
    switch (error)
    {
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
        printf("Error: program expected non negative integer!\n");
        break;
    case NON_NATURAL_NUMBER:
        printf("ERROR: program expected natural integer as input!\n");
        break;
    case TOO_LARGE_NUMBER:
        printf("Error: number is too large to process!\n");
        break;
    default:
        printf("Error: unknown error %d !\n", error);
        break;
    }
}