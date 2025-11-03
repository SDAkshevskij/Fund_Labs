#include "../include/solve.h"
#include <stdlib.h>

Status read_string_or_80(FILE *inputFile, char **string, int *requaredSpaceAmo, int *spaceAmo) {
    int counter = 0;
    int blockStartIndex = 0;
    int totalSpaceAmo = 0;

    char *string80 = (char*)malloc(sizeof(char) * 81);
    if (string80 == NULL) {
        return MEMORY_ALLOCATION_ERROR;
    }

    char prevChar = '-';
    char curChar;

    while ((curChar = fgetc(inputFile)) == ' ' || curChar == '\n') {}

    while (curChar != EOF && curChar != '\n') {
        string80[counter] = curChar;
        //printf("%d: %c\n", counter, curChar);
        if (curChar == ' ' && prevChar != ' ') {
            blockStartIndex = counter;
            totalSpaceAmo++;
        }
        else if (curChar != ' ' && prevChar == ' ') {
            blockStartIndex = counter;
        }
        
        counter++;
        prevChar = curChar;

        if (counter == 80) {
            if (curChar == ' ') {
                string80[blockStartIndex] = '\0';
                totalSpaceAmo--;
                *requaredSpaceAmo = counter - blockStartIndex;
                break;
            }

            char nextChar = fgetc(inputFile);
            if (nextChar == ' ' || nextChar == '\n' || nextChar == EOF) {
                string80[counter] = '\0';
                *requaredSpaceAmo = 0;
            }
            else {
                int offset = counter - blockStartIndex;
                if (offset == 80) {
                    string80[80] = '\0';
                    *string = string80;
                    fseek(inputFile, - 1, SEEK_CUR);
                    break;
                }
                //printf("Offset: %d\n", offset);

                if (string80[blockStartIndex] == ' ') {
                    *requaredSpaceAmo = counter - blockStartIndex;
                }
                else {
                    *requaredSpaceAmo = counter - blockStartIndex + 1;
                }

                string80[counter - offset - 1] = '\0';
                totalSpaceAmo--;

                fseek(inputFile, -offset - 1, SEEK_CUR);
                
            }
            break;
        }
        curChar = fgetc(inputFile);
    }

    if (curChar == '\n' || curChar == EOF) {
        string80[counter] = '\0';
        if (prevChar == ' ') {
            string80[blockStartIndex] = '\0';
            //printf("%d", blockStartIndex);
        }

        *spaceAmo = totalSpaceAmo;
        *requaredSpaceAmo = 0;
        *string = string80;

        if (curChar == EOF) {
            return END_OF_INPUT;
        }
        return OK;
    }

    *spaceAmo = totalSpaceAmo;
    *string = string80;
    return OK;
}

Status write_string_or_80(FILE *outputFile, char *string, int requaredSpaceAmo, int spaceAmo) {
    if(spaceAmo == 0) spaceAmo = 1;
    int spaceBlockAmo = requaredSpaceAmo / spaceAmo;
    int remainder = requaredSpaceAmo % spaceAmo;

    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i] != ' ') {
            fputc(string[i], outputFile);
        }
        else if (string[i] == ' ' && string[i - 1] != ' ') {
            fputc(' ', outputFile);
            for (int j = 0; j < spaceBlockAmo; j++) {
                fputc(' ', outputFile);
            }
            if (remainder > 0) {
                fputc(' ', outputFile);
                remainder--;
            }
        }
        else {
            fputc(' ', outputFile);
        }

    }
    fputc('\n', outputFile);
}