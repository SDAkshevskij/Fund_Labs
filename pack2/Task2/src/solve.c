#include "../include/solve.h"
#include "../include/system_errors.h"

void *memchr(const void *str, int c, size_t n){
    for (int i = 0; i < n; i++) {
        if (*(unsigned char*)(str + i) == (unsigned char)c) {
            return  (void *)(const char*)(str + i);
        }
    }
    return NULL;
}
int memcmp(const void *str1, const void *str2, size_t n) {
    for (int i = 0; i < n; i++) {
        unsigned char c1 = *(char*)(str1 + i);
        unsigned char c2 = *(char*)(str2 + i);

        if (c1 == c2) {
            if (c1 < c2) {
                return -1;
            }
            return 1;
        }
    }

    return 0;
}
void *memcpy(void *dest, const void *src, size_t n) {
    for (int i = 0; i < n; i++) {
        *(char*)(dest + i) = *(char*)(src + i);
    }
    return dest;
}
void *memset(void *str, int c, size_t n) {
    for (int i = 0; i < n; i++) {
        *(unsigned char*)(str + i) = (unsigned char)c;
    }
    return str;
}
char *strncat(char *dest, const char *src, size_t n) {
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }

    int j = 0;
    for (; j < n && src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';

    return dest;
}

char *strchr(const char *str, int c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == (unsigned char)c) {
            return (char*)(str + i);
        }
    }
    return NULL;
}

int strncmp(const char *str1, const char *str2, size_t n) {
    for (int i = 0; i < n && str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            if (str1[i] < str2[i]) {
                return -1;
            }
            return 1;
        }
    }

    return 0;
}
char *strncpy(char *dest, const char *src, size_t n) {
    for (int i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    return dest;
}
size_t strcspn(const char *str1, const char *str2) {
    int i = 0;
    for (; str1[i] != '\0'; i++) {
        char c1 = str1[i];
        int flag = 1;

        for (int j = 0; str2[j] != '\0'; j++) {
            if (str2[j] == c1) {
                flag = 0;
                break;
            }
        }

        if (!flag) {
            return i;
        }
    }

    return i;
}
char *strerror(int errnum) {
    return (char*)errors_arr[errnum];
}
size_t strlen(const char *str) {
    size_t size = 0;
    for(; str[size] != '\0'; size++) {}

    return size;
}
char *strpbrk(const char *str1, const char *str2) {
    for (int i = 0; str1[i] != '\0'; i++) {

        for (int j = 0; str2[j] != '\0'; j++) {
            if (str2[j] == str1[i]) {
                return (char*)(str1 + i);
            }
        }
    }

    return NULL;
}
char *strrchr(const char *str, int c) {
    char *chr = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == (unsigned char)c) {
            chr = (char*)(str + i);
        }
    }

    return chr;
}
char *strstr(const char *haystack, const char *needle) {
    for (int i = 0; haystack[i] != '\0'; i++) {
        int isSimilar = 1;
        for (int j = 0; needle[j] != '\0'; j++) {
            if(haystack[i + j] == '\0') {
                return NULL;
            }

            if (haystack[i + j] != needle[j]) {
                isSimilar = 0;
                break;
            }
        }

        if (isSimilar) {
            return (char*)(haystack + i);
        }
    }

    return NULL;
}
char *strtok(char *str, const char *delim) {
    static char* nextToken;
    char *tokenStart;

    if (str == NULL) {
        if (nextToken == NULL) return NULL;
        tokenStart = nextToken;
    }
    else {
        tokenStart = str;
    }

    char *delimStart = strstr(tokenStart, delim);
    if (delimStart == NULL) {
        nextToken = NULL;
        return tokenStart;
    }

    int j = 0;
    for (; delim[j] != '\0'; j++) {
        *(delimStart + j) = '\0';
    }

    nextToken = (delimStart + j);
    if (*nextToken == '\0') {
        nextToken = NULL;
    }

    while(*tokenStart == '\0') {
        tokenStart++;
    }

    return tokenStart;
}