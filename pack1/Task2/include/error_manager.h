#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

typedef enum {
    OK,
    WROND_FLAG,
    MEMORY_ALLOCATION_ERROR,
    NON_NATURAL_NUMBER,
    TOO_LARGE_NUMBER
} Status;

void print_status(Status error);


#endif