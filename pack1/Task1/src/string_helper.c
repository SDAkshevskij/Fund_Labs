#include "../include/string_helper.h"
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>


int is_integer(char* string){
    if(string == NULL || *string == '\0'){
        return 0;
    }
    int i = 0;
    if(string[i] == '-'){
        i++;
    }
    int len = 0;
    for(; string[i] != '\0'; i++){
        len++;
        if(!isdigit(string[i])){
            return 0;
        }
    }
    if(len > 8){
        return 0;
    }
    return 1;
}
int is_flag(char* string){
    if(string == NULL || *string == '\0'){
        return 0;
    }
    if(string[0] != '-' && string[0] != '/'){
        return 0;
    }
    if(!isalpha(string[1])){
        return 0;
    }
    if(string[2] != '\0'){
        return 0;
    }
    return 1;
}