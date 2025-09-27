#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

typedef enum {
    OK,
    NOT_OK,
    WRONG_FLAG,
    WRONG_ARGUMENT_AMOUNT,
    MEMORY_ALLOCATION_ERROR,
    NOT_A_NUMBER,
    NEGATIVE_NUMBER,
    NON_NATURAL_NUMBER,
    NUMBER_IS_ZERO,
    TOO_LARGE_NUMBER,
    SOLUTION_IS_ANY_NUMBER,
    NO_SOLUTION
} Error;

void print_error(Error error);


#endif 