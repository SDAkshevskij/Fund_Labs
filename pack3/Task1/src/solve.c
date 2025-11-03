#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char int_to_char(int num) {
    if (num < 10) {
        return '0' + num;
    }
    else if (num <= 36){
        return 'A' + num - 10;
    }
    else {
        return '!';
    }
}

void reverse_string(char *string){
    int start = 0;
    int end = strlen(string) - 1;

    while (start < end) {
        char buffer = string[start];
        string[start] = string[end];
        string[end] = buffer;

        start++;
        end--;
    }
}

void from10_to_2r_inner(int num, int r, char *result) {
    int base = 1 << r;
    int mask = 0;
    for (int i = 1; i < base; i = i << 1) {
        mask = mask | i;
    }

    int remainNum = num;

    while (remainNum != 0) {
        int res = remainNum & mask;

        *(result++) = int_to_char(res);

        remainNum = remainNum >> r;
    }

    *result = '\0';
}


char* from10_to_2r(int num, int r) {
    if (r < 1 || r > 5) return NULL;

    int isNeg = 0;

    if (num < 0) {
        isNeg = 1;
        num = -num;
    }

    int resultSize = ceil(32.0 / r);
    char *result = (char*)malloc(sizeof(char) * (resultSize + isNeg + 1));

    if (result == NULL) return NULL;

    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    from10_to_2r_inner(num, r, result);


    if (isNeg) {
        int realResultSize = strlen(result);
        result[realResultSize] = '-';
        result[realResultSize + 1] = '\0';
    }
    else {
        result[resultSize] = '\0';
    }


    reverse_string(result);

    return result;
}