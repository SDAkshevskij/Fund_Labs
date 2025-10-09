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
} Status;

void print_status(Status error);


#endif 