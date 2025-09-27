#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

typedef enum {
    OK,
    WROND_FLAG,
    MEMORY_ALLOCATION_ERROR,
    NON_NATURAL_NUMBER,
    TOO_LARGE_NUMBER
} Error;

void print_error(Error error);


#endif