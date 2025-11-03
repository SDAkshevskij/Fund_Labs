#include "../include/solve.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/vector.h"
#include "../include/status_manager.h"
#include "../include/flag_manager.h"
#include <string.h>

DEFINE_VECTOR(char);
DEFINE_VECTOR(int);
const int MAX_ROMAN_LEN = 20;

int overprintManager(void *output, printType type, char *pattern, va_list args) {

    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] == '%') {
            i += 2;
            char *result;
            if (pattern[i - 1] == 'R' && pattern[i] == 'o') {
                int value = va_arg(args, int);
                result = flag_Ro(value);
            }
            else if (pattern[i - 1] == 'Z' && pattern[i] == 'r') {
                unsigned int value = va_arg(args, unsigned int);
                result = flag_Zr(value);
            }
            else if (pattern[i - 1] == 'C' && pattern[i] == 'v') {
                int value = va_arg(args, int);
                int base = va_arg(args, int);
                if (base < 2 || base > 36) base = 10;
                result = flag_Cv(value, base, 0);
            }
            else if (pattern[i - 1] == 'C' && pattern[i] == 'V') {
                int value = va_arg(args, int);
                int base = va_arg(args, int);
                if (base < 2 || base > 36) base = 10;
                result = flag_Cv(value, base, 'A' - 'a');
            }
            else if (pattern[i - 1] == 't' && pattern[i] == 'o') {
                char* value = va_arg(args, char*);
                int base = va_arg(args, int);
                if (base < 2 || base > 36) base = 10;
                result = flag_to(value, base, 0);
            }
            else if (pattern[i - 1] == 'T' && pattern[i] == 'O') {
                char* value = va_arg(args, char*);
                int base = va_arg(args, int);
                if (base < 2 || base > 36) base = 10;
                result = flag_to(value, base, 'A' - 'a');
            }
            else if (pattern[i - 1] == 'm' && pattern[i] == 'i') {
                int value = va_arg(args, int);
                result = flag_mi(value);
            }
            else if (pattern[i - 1] == 'm' && pattern[i] == 'u') {
                unsigned int value = va_arg(args, unsigned int);
                result = flag_mu(value);
            }
            else if (pattern[i - 1] == 'm' && pattern[i] == 'd') {
                double value = va_arg(args, double);
                result = flag_md(value);
            }
            else if (pattern[i - 1] == 'm' && pattern[i] == 'f') {
                double temp = va_arg(args, double);
                float value = (float)(temp);
                result = flag_mf(value);
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

                if (type == PRINT_FILE) {
                    FILE *outputFile = (FILE*)output;
                    vfprintf(outputFile, flag, args);
                }
                else {
                    char *buffer = (char*)output;
                    int writeAmo = vsprintf(buffer, flag, args);
                }
                
                continue;
            }

            if (type == PRINT_FILE) {
                FILE *outputFile = (FILE*)output;
                fprintf(outputFile, "%s", result);
            }
            else {
                char *buffer = (char*)output;
                strcat(buffer, result);
            }
            
        }
        else {
            if (type == PRINT_FILE) {
                FILE *outputFile = (FILE*)output;
                fputc(pattern[i], outputFile);
            }
            else {
                char *buffer = (char*)output;
                *buffer = pattern[i];
                buffer++;
                *buffer = '\0'; 
            }
        }
    }
}

int overfprintf(FILE *outputFile, char *pattern, ...) {
    va_list args;
    va_start(args, pattern);
    overprintManager(outputFile, PRINT_FILE, pattern, args);
}

int oversprintf(char *buffer, char *pattern, ...) {
    va_list args;
    va_start(args, pattern);
    overprintManager(buffer, PRINT_STRING, pattern, args);
}



