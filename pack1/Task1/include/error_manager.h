#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

typedef enum {
    OK,
    WRONG_FLAG,
    WRONG_ARGUMENT_AMOUNT,
    MEMORY_ALLOCATION_ERROR,
    NOT_A_NUMBER,
    NEGATIVE_NUMBER,
    NON_NATURAL_NUMBER,
    TOO_LARGE_NUMBER
} Error;

void print_error(Error error);


#endif 