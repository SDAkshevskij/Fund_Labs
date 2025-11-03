#include <stdio.h>
#include <stdlib.h>
#include "../include/status_manager.h"
#include "../include/string_manager.h"
#include "../include/solve.h"

void print_arr(char *arr, size_t size) {
    for(int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void print_string(char *arr) {
    printf("%s\n", arr);
}

void test_memchr() {
    printf("=== Testing memchr ===\n");
    char *str = "qwerty";
    
    printf("Found 'r': %c\n", *(char*)memchr(str, 'r', 6));
    printf("Found 't': %c\n", *(char*)memchr(str, 't', 6));
    
    char *result = memchr(str, 'x', 6);
    if (result == NULL) {
        printf("'x' not found (correct)\n");
    }
    
    result = memchr(str, '\0', 7);
    if (result != NULL) {
        printf("Found null terminator\n");
    }
}

void test_memcmp() {
    printf("\n=== Testing memcmp ===\n");
    char *str1 = "abcde";
    char *str2 = "abcde";
    char *str3 = "abcdx";
    
    printf("Equal strings: %d\n", memcmp(str1, str2, 5));
    printf("First smaller: %d\n", memcmp(str1, str3, 5));
    printf("First larger: %d\n", memcmp(str3, str1, 5));
    printf("Compare first 3: %d\n", memcmp(str1, str3, 3));
}

void test_memcpy() {
    printf("\n=== Testing memcpy ===\n");
    char src[] = "123456";
    char dest[7];
    
    memcpy(dest, src, 6);
    dest[6] = '\0';
    printf("Copied: %s\n", dest);
    
    char arr1[6] = {'a','b','c','d','e','f'};
    char arr2[6];
    memcpy(arr2, arr1, 3); // Copy only 3 elements
    printf("Partial copy: ");
    print_arr(arr2, 6);
}

void test_memset() {
    printf("\n=== Testing memset ===\n");
    char arr1[10];
    memset(arr1, 'X', 5);
    printf("5 X's: ");
    print_arr(arr1, 5);
    
    char arr2[10] = "abcdefgh";
    memset(arr2 + 2, '-', 3);
    printf("Modified middle: %s\n", arr2);
}

void test_strncat() {
    printf("\n=== Testing strncat ===\n");
    char str1[20] = "Hello";
    char str2[] = " World!";
    
    strncat(str1, str2, 7);
    printf("After strncat: %s\n", str1);
    
    char str3[10] = "Hi";
    strncat(str3, "!!!", 2); // Only 2 characters
    printf("Partial concat: %s\n", str3);
}

void test_strchr() {
    printf("\n=== Testing strchr ===\n");
    char *str = "Hello World";
    
    char *result = strchr(str, 'o');
    printf("First 'o': %c at position %ld\n", *result, result - str);
    
    result = strchr(str, 'W');
    printf("First 'W': %c\n", *result);
    
    result = strchr(str, 'x');
    if (result == NULL) {
        printf("'x' not found (correct)\n");
    }
}

void test_strncmp() {
    printf("\n=== Testing strncmp ===\n");
    char *s1 = "apple";
    char *s2 = "apple";
    char *s3 = "apples";
    char *s4 = "banana";
    
    printf("Equal: %d\n", strncmp(s1, s2, 5));
    printf("Equal first 3: %d\n", strncmp(s1, s3, 3));
    printf("Different: %d\n", strncmp(s1, s4, 3));
    printf("s1 < s3 (first 5): %d\n", strncmp(s1, s3, 5));
}

void test_strncpy() {
    printf("\n=== Testing strncpy ===\n");
    char dest[10];
    char src[] = "Hello";
    
    strncpy(dest, src, 5);
    dest[5] = '\0';
    printf("Copied: %s\n", dest);
    
    // Partial copy
    strncpy(dest, src, 3);
    dest[3] = '\0';
    printf("Partial copy: %s\n", dest);
    
    // Copy more than source length
    strncpy(dest, src, 8);
    printf("Over copy: %s\n", dest);
}

void test_strcspn() {
    printf("\n=== Testing strcspn ===\n");
    char *str = "hello world";
    char *reject1 = "aeiou";
    char *reject2 = "xyz";
    char *reject3 = "h";
    
    printf("First vowel at position: %ld\n", strcspn(str, reject1));
    printf("No reject chars found, length: %ld\n", strcspn(str, reject2));
    printf("First char rejected: %ld\n", strcspn(str, reject3));
}

void test_strerror() {
    printf("\n=== Testing strerror ===\n");
    printf("Error 0: %s\n", strerror(0));
    printf("Error 1: %s\n", strerror(1));
    printf("Error 2: %s\n", strerror(2));
}

void test_strlen() {
    printf("\n=== Testing strlen ===\n");
    printf("Empty: %ld\n", strlen(""));
    printf("Hello: %ld\n", strlen("Hello"));
    printf("Long string: %ld\n", strlen("This is a longer string"));
}

void test_strpbrk() {
    printf("\n=== Testing strpbrk ===\n");
    char *str = "hello world";
    char *accept1 = "aeiou";
    char *accept2 = "xyz";
    char *accept3 = " w";
    
    char *result = strpbrk(str, accept1);
    printf("First vowel: %c\n", *result);
    
    result = strpbrk(str, accept2);
    if (result == NULL) {
        printf("No xyz found (correct)\n");
    }
    
    result = strpbrk(str, accept3);
    printf("First space or w: %c\n", *result);
}

void test_strrchr() {
    printf("\n=== Testing strrchr ===\n");
    char *str = "hello world";
    
    char *result = strrchr(str, 'l');
    printf("Last 'l': %c at position %ld\n", *result, result - str);
    
    result = strrchr(str, 'o');
    printf("Last 'o': %c\n", *result);
    
    result = strrchr(str, 'x');
    if (result == NULL) {
        printf("'x' not found (correct)\n");
    }
}

void test_strstr() {
    printf("\n=== Testing strstr ===\n");
    char *str = "This is a test string for testing";
    
    char *result = strstr(str, "test");
    printf("Found 'test': %s\n", result);
    
    result = strstr(str, "string");
    printf("Found 'string': %s\n", result);
    
    result = strstr(str, "nonexistent");
    if (result == NULL) {
        printf("'nonexistent' not found (correct)\n");
    }
    
    result = strstr(str, "");
    printf("Empty string: %s\n", result);
}

void test_strtok() {
    printf("\n=== Testing strtok ===\n");
    
    char text1[] = "apple,banana,cherry";
    printf("Tokens from '%s':\n", text1);
    char *token = strtok(text1, ",");
    while (token != NULL) {
        printf("  %s\n", token);
        token = strtok(NULL, ",");
    }
    
    char text2[] = "one;two;three;four";
    printf("Tokens from '%s':\n", text2);
    token = strtok(text2, ";");
    while (token != NULL) {
        printf("  %s\n", token);
        token = strtok(NULL, ";");
    }
    
    char text3[] = "single";
    printf("Single token: %s\n", strtok(text3, ","));
}

int main(int argc, char* argv[]) {
    test_memchr();
    test_memcmp();
    test_memcpy();
    test_memset();
    test_strncat();
    test_strchr();
    test_strncmp();
    test_strncpy();
    test_strcspn();
    test_strerror();
    test_strlen();
    test_strpbrk();
    test_strrchr();
    test_strstr();
    test_strtok();
}