#include "../include/number_process.h"
#include "../include/error_manager.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int* get_multiples(int x){
    x = abs(x);
    int multiplesAmount = 100 / x;
    int* multiplesArray = (int*)malloc(sizeof(int) * (multiplesAmount + 1));
    if(multiplesArray == NULL){
        return NULL;
    }
    int nextArrayPosition = 0;
    for(int i = 1; i * x <= 100; i++){
        multiplesArray[nextArrayPosition] = i * x;   
        nextArrayPosition++; 
    }
    multiplesArray[nextArrayPosition] = -1;
    return multiplesArray;
}

void print_multiples(int* multiples){
    if(multiples == NULL || multiples[0] == -1){
        printf("Multiples not found\n");
        return;
    }
    printf("Multiples: ");
    for(int i = 0; multiples[i] != -1; i++){
        printf("%d ", multiples[i]);
    }
    printf("\n");
}

int is_prime(int x) {
    x = abs(x);
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}
Status to_hex(int x, char **res) {
    if(x < 0){
        return NEGATIVE_NUMBER;
    }
    if(x == 0){
        char* hex = malloc(sizeof(char) * 2);
        hex[0] = '0';
        hex[1] = '\0';
        *res = hex;
        return OK;
    }
    int binNumLen = 0;
    int copyX = x;
    while(copyX != 0) {
        binNumLen++;
        copyX /= 2;
    }
    if(binNumLen % 4 != 0){
        binNumLen += 4 - (binNumLen % 4); //Выравнивание
    }
    int nextBitPos = binNumLen - 1;
    int* binaryX = malloc(sizeof(int) * binNumLen);
    while(x != 0){
        binaryX[nextBitPos] = x % 2;
        x /= 2;
        nextBitPos--;
    }

    int hexNumLen = binNumLen / 4 + 1;
    char* hexNum = malloc(sizeof(char) * hexNumLen);

    for(int i = 3; i < binNumLen; i+=4){
        int hexVal = binaryX[i - 3] * 8 + binaryX[i - 2] * 4 + binaryX[i - 1] * 2 + binaryX[i];
        char hexChar;
        if(hexVal <= 9){
            hexChar = '0' + hexVal;
        }
        else{
            switch (hexVal){
                case 10:
                    hexChar = 'A';
                break;
                case 11:
                    hexChar = 'B';
                    break;
                case 12:
                    hexChar = 'C';
                    break;
                case 13:
                    hexChar = 'D';
                    break;
                case 14:
                    hexChar = 'E';
                    break;
                case 15:
                    hexChar = 'F';
                    break;
            }
        }
        hexNum[i / 4] = hexChar;
    }
    free(binaryX);
    hexNum[hexNumLen - 1] = '\0';
    *res = hexNum;
    return OK;
}
void print_hex(char* hex){
    for(int i = 0; hex[i] != '\0'; i++){
        printf("%c ", hex[i]);
    }
    printf("\n");
}

long long_pow(long num, long p){
    long res = 1;
    for(int i = 1; i < p; i++){
        res *= num;
    }
    return res;
}

void print_table_of_degrees(int x) {
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= x; j++){
            printf("%ld ", long_pow(i, j));
        }
        printf("\n");
    }
}
Status calc_pref_sum(int x, int *res) {
    if(x < 0){
        return NEGATIVE_NUMBER;
    }
    long prefSum = 0;
    for(int i = 1; i < x; i++) {
        prefSum += i;
    }
    if(prefSum > __INT_MAX__){
        return TOO_LARGE_NUMBER;
    }
    *res = (int)prefSum;
    return OK;
}
Status factorial(int x, int *res) {
    if(x > 10){
        return TOO_LARGE_NUMBER;
    }
    if(x < 0){
        return NEGATIVE_NUMBER;
    }
    int fact = 1;
    for(int i = 2; i <= x; i++){
        fact *= i;
    }
    *res = fact;
    return OK;
}
