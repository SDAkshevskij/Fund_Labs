#include "../include/solve.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/vector.h"
#include "../include/status_manager.h"
#include "../include/flag_manager.h"
#include "../include/string_manager.h"
#include "../include/file_manager.h"
#include <string.h>

DEFINE_VECTOR(int);

int overfscanf(FILE *inputFile, const char *pattern, ...) {
    va_list args;
    va_start(args, pattern);

    int readAmo = 0;

    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] == '%') {
            i += 2;
            if (pattern[i - 1] == 'R' && pattern[i] == 'o') {
                int *value = va_arg(args, int*);
                char *string;
                fread_word(inputFile, &string);
                printf("%p\n", value);
                *value = flag_Ro(string);
                
                readAmo++;
            }
            else if (pattern[i - 1] == 'Z' && pattern[i] == 'r') {
                unsigned int* value = va_arg(args, unsigned int*);
                char *string;
                fread_word(inputFile, &string);
                *value = flag_Zr(string);

                readAmo++;
            }
            else if (pattern[i - 1] == 'C' && pattern[i] == 'v') {
                int* value = va_arg(args, int*);
                int base = va_arg(args, int);
                if (base < 2 || base > 36) base = 10;

                char *string;
                fread_word(inputFile, &string);
                printf("%p\n", value);

                *value = flag_Cv(string, base, 0);
                readAmo++;
            }
            else if (pattern[i - 1] == 'C' && pattern[i] == 'V') {
                int* value = va_arg(args, int*);
                int base = va_arg(args, int);
                if (base < 2 || base > 36) base = 10;

                char *string;
                fread_word(inputFile, &string);

                *value = flag_Cv(string, base, 'A' - 'a');
                readAmo++;
            }
            else {
                i--;
                char flag[5];
                flag[0] = '%';

                int index = 1;
                while (pattern[i] == 'l' || pattern[i] == 'h' || pattern[i] == 'L') {
                    flag[index++] = pattern[i++];
                }
                flag[index++] = pattern[i];
                flag[index] = '\0';

                if (pattern[i] == 'd' || pattern[i] == 'i') {
                    int *value = va_arg(args, int*);
                    fscanf(inputFile, flag, value);
                } else if (pattern[i] == 'u') {
                    unsigned int *value = va_arg(args, unsigned int*);
                    fscanf(inputFile, flag, value);
                } else if (pattern[i] == 'f' || pattern[i] == 'F' || 
                           pattern[i] == 'e' || pattern[i] == 'E' ||
                           pattern[i] == 'g' || pattern[i] == 'G' ||
                           pattern[i] == 'a' || pattern[i] == 'A') {
                    double *value = va_arg(args, double*);
                    fscanf(inputFile, flag, value);
                } else if (pattern[i] == 's') {
                    char *value = va_arg(args, char*);
                    fscanf(inputFile, flag, value);
                } else {
                    fscanf(inputFile, flag, args);
                }
                readAmo++;
                continue;
            }
        }
    }

    return readAmo;
}


int oversscanf(char *src, const char *pattern, ...) {
    va_list args;
    va_start(args, pattern);

    int readAmo = 0;

    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] == '%') {
            i += 2;
            if (pattern[i - 1] == 'R' && pattern[i] == 'o') {
                int *value = va_arg(args, int*);
                char *string;
                src = string_copy_till_space(src, &string);
                *value = flag_Ro(string);

                readAmo++;
            }
            else if (pattern[i - 1] == 'Z' && pattern[i] == 'r') {
                unsigned int* value = va_arg(args, unsigned int*);
                char *string;
                src = string_copy_till_space(src, &string);
                *value = flag_Zr(string);

                readAmo++;
            }
            else if (pattern[i - 1] == 'C' && pattern[i] == 'v') {
                int* value = va_arg(args, int*);
                int base = va_arg(args, int);
                if (base < 2 || base > 36) base = 10;

                char *string;
                src = string_copy_till_space(src, &string);
                printf("%p\n", value);

                *value = flag_Cv(string, base, 0);

                readAmo++;
            }
            else if (pattern[i - 1] == 'C' && pattern[i] == 'V') {
                int* value = va_arg(args, int*);
                int base = va_arg(args, int);
                if (base < 2 || base > 36) base = 10;

                char *string;
                src = string_copy_till_space(src, &string);

                *value = flag_Cv(string, base, 'A' - 'a');
                readAmo++;
            }
            else {
                i--;
                char flag[5];
                flag[0] = '%';

                int index = 1;
                while (pattern[i] == 'l' || pattern[i] == 'h' || pattern[i] == 'L') {
                    flag[index++] = pattern[i++];
                }
                flag[index++] = pattern[i];
                flag[index] = '\0';

                if (pattern[i] == 'd' || pattern[i] == 'i') {
                    int *value = va_arg(args, int*);
                    sscanf(src, flag, value);
                } else if (pattern[i] == 'u') {
                    unsigned int *value = va_arg(args, unsigned int*);
                    sscanf(src, flag, value);
                } else if (pattern[i] == 'f' || pattern[i] == 'F' || 
                           pattern[i] == 'e' || pattern[i] == 'E' ||
                           pattern[i] == 'g' || pattern[i] == 'G' ||
                           pattern[i] == 'a' || pattern[i] == 'A') {
                    double *value = va_arg(args, double*);
                    sscanf(src, flag, value);
                } else if (pattern[i] == 's') {
                    char *value = va_arg(args, char*);
                    sscanf(src, flag, value);
                } else {
                    sscanf(src, flag, args);
                }
                char *skip;
                src = string_copy_till_space(src, &skip);

                readAmo++;
                continue;
            }
        }
    }

    return readAmo;
}