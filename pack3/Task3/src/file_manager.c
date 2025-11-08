#include "../include/file_manager.h"
#include <stdlib.h>
#include <ctype.h>

Status fread_non_space_symb(FILE *inputFile, char *res) {
    char c;
    while((c = fgetc(inputFile)) != EOF && isspace(c)) {}

    if (c == EOF) {
        return EMPTY_STRING;
    }

    *res = c;
    return OK;
}

Status fread_word(FILE* inputFile, char **word) {
    int bufferSize = 10;
    char* buffer = (char*)malloc(sizeof(char) * bufferSize);
    if(buffer == NULL) return MEMORY_ALLOCATION_ERROR;

    int nextBufferIndex = 0;
    char c;

    while((c = fgetc(inputFile)) != EOF && isspace(c)) {}
    
    if (c == EOF) {
        free(buffer);
        return END_OF_INPUT;
    }

    while(!isspace(c) && c != EOF){
        if(nextBufferIndex == bufferSize - 1){
            bufferSize *= 2;
            char *newBuffer = (char*)realloc(buffer, bufferSize);

            if(newBuffer == NULL) return MEMORY_ALLOCATION_ERROR;

            buffer = newBuffer;
        }

        buffer[nextBufferIndex] = c;
        nextBufferIndex++;
        c = fgetc(inputFile);
    }

    buffer[nextBufferIndex] = '\0';
    *word = buffer;
    if (c == EOF) {
        return END_OF_INPUT;
    }
    return OK;
}

Status fread_natural_integer(FILE *inputFile, int *res) {
    char* word = NULL;
    Status wordStatus = fread_word(inputFile, &word);
    if (is_empty_string(word)) return EMPTY_STRING;
    if (wordStatus != OK && wordStatus != END_OF_INPUT) {
        return wordStatus;
    }
   
    Status status = string_to_natural_int(word, res);
    free(word);

    if(status == OK) {
        return wordStatus;
    }

    return status;
}
Status fread_float(FILE *inputFile, double *res) {
    char *word;
    Status wordStatus = fread_word(inputFile, &word);
    if (wordStatus != OK && wordStatus != END_OF_INPUT) {
        return wordStatus;
    }

    Status status = string_to_double(word, res);
    free(word);

    if(status == OK) {
        return wordStatus;
    }

    return status;
}