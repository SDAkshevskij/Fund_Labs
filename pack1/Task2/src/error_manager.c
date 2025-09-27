#include "../include/error_manager.h"
#include <stdio.h>

void print_error(Error error){
    switch (error)
    {
    case WROND_FLAG:
        printf("Error: unknown flag!\n");
        break;
    case MEMORY_ALLOCATION_ERROR:
        printf("Error: memory allocation error\n");
        break;
    case NON_NATURAL_NUMBER:
        printf("ERROR: program expected natural numbers as input!\n");
        break;
    case TOO_LARGE_NUMBER:
        printf("Error: number is too large to process!\n");
        break;
    default:
        printf("Error: unknown error %d !\n", error);
        break;
    }
}