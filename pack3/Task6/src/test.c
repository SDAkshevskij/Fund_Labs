#include "../include/solve.h"
#include "../include/test.h"
#include <stdio.h>

void test_check_brackets() {
    printf("=== BRACKET CHECKER TESTS ===\n\n");
    
    // Основные тесты для check_brackets
    printf("check_brackets tests:\n");
    
    // Пустые строки и строки без скобок
    printf("Test: \"\" -> %d (expected: 1)\n", check_brackets(""));
    printf("Test: \"Hello World\" -> %d (expected: 1)\n", check_brackets("Hello World"));
    printf("Test: \"123 abc 456\" -> %d (expected: 1)\n", check_brackets("123 abc 456"));
    
    // Простые корректные случаи
    printf("Test: \"()\" -> %d (expected: 1)\n", check_brackets("()"));
    printf("Test: \"[]\" -> %d (expected: 1)\n", check_brackets("[]"));
    printf("Test: \"{}\" -> %d (expected: 1)\n", check_brackets("{}"));
    printf("Test: \"<>\" -> %d (expected: 1)\n", check_brackets("<>"));
    printf("Test: \"()[]{}<>\" -> %d (expected: 1)\n", check_brackets("()[]{}<>"));
    
    // Вложенные корректные случаи
    printf("Test: \"({[]})\" -> %d (expected: 1)\n", check_brackets("({[]})"));
    printf("Test: \"[{()}]\", -> %d (expected: 1)\n", check_brackets("[{()}]"));
    printf("Test: \"((()))\" -> %d (expected: 1)\n", check_brackets("((()))"));
    printf("Test: \"a(b[c{d}])\" -> %d (expected: 1)\n", check_brackets("a(b[c{d}])"));
    
    // Простые некорректные случаи
    printf("Test: \"(\" -> %d (expected: 0)\n", check_brackets("("));
    printf("Test: \")\" -> %d (expected: 0)\n", check_brackets(")"));
    printf("Test: \"(]\" -> %d (expected: 0)\n", check_brackets("(]"));
    printf("Test: \"({)}\" -> %d (expected: 0)\n", check_brackets("({)}"));
    printf("Test: \"())\" -> %d (expected: 0)\n", check_brackets("())"));
    
    // Сложные некорректные случаи
    printf("Test: \"((())\" -> %d (expected: 0)\n", check_brackets("((())"));
    printf("Test: \"([)]\" -> %d (expected: 0)\n", check_brackets("([)]"));
    printf("Test: \"({[}])\" -> %d (expected: 0)\n", check_brackets("({[}])"));
    printf("Test: \"a(b[c)d]\" -> %d (expected: 0)\n", check_brackets("a(b[c)d]"));
    
    // Реальные примеры
    printf("Test: \"int arr[] = {1, 2, 3};\" -> %d (expected: 1)\n", check_brackets("int arr[] = {1, 2, 3};"));
    printf("Test: \"int arr[] = {1, 2, 3;\" -> %d (expected: 0)\n", check_brackets("int arr[] = {1, 2, 3;"));
    
    // Специальные символы
    printf("Test: \"(!@#$&*)\" -> %d (expected: 1)\n", check_brackets("(!@#$&*)"));
    printf("Test: \"a+b*(c-d)\" -> %d (expected: 1)\n", check_brackets("a+b*(c-d)"));
    
    // Граничные случаи
    printf("Test: \")(\" -> %d (expected: 0)\n", check_brackets(")("));
    printf("Test: \"<><>\" -> %d (expected: 1)\n", check_brackets("<><>"));
    
    printf("\n=== TESTS COMPLETED ===\n");
}