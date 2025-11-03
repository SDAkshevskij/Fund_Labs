#include "../include/solve.h"
#include "../include/test.h"
#include <stdio.h>

void test_from10_to_2r() {
    printf("Тесты для функции from10_to_2r:\n\n");
    
    // Базовые тесты для всех r
    printf("=== Базовые тесты ===\n");
    printf("%d %d -> %s\n", 0, 1, from10_to_2r(0, 1));
    printf("%d %d -> %s\n", 5, 1, from10_to_2r(5, 1));
    printf("%d %d -> %s\n", 10, 1, from10_to_2r(10, 1));
    printf("%d %d -> %s\n", 255, 1, from10_to_2r(255, 1));
    
    printf("%d %d -> %s\n", 0, 2, from10_to_2r(0, 2));
    printf("%d %d -> %s\n", 5, 2, from10_to_2r(5, 2));
    printf("%d %d -> %s\n", 10, 2, from10_to_2r(10, 2));
    printf("%d %d -> %s\n", 25, 2, from10_to_2r(25, 2));
    
    printf("%d %d -> %s\n", 0, 3, from10_to_2r(0, 3));
    printf("%d %d -> %s\n", 8, 3, from10_to_2r(8, 3));
    printf("%d %d -> %s\n", 64, 3, from10_to_2r(64, 3));
    printf("%d %d -> %s\n", 255, 3, from10_to_2r(255, 3));
    
    printf("%d %d -> %s\n", 0, 4, from10_to_2r(0, 4));
    printf("%d %d -> %s\n", 10, 4, from10_to_2r(10, 4));
    printf("%d %d -> %s\n", 255, 4, from10_to_2r(255, 4));
    printf("%d %d -> %s\n", 4095, 4, from10_to_2r(4095, 4));
    
    printf("%d %d -> %s\n", 0, 5, from10_to_2r(0, 5));
    printf("%d %d -> %s\n", 31, 5, from10_to_2r(31, 5));
    printf("%d %d -> %s\n", 32, 5, from10_to_2r(32, 5));
    printf("%d %d -> %s\n", 1024, 5, from10_to_2r(1024, 5));
    
    // Граничные значения
    printf("\n=== Граничные значения ===\n");
    printf("%d %d -> %s\n", 1, 1, from10_to_2r(1, 1));
    printf("%d %d -> %s\n", 1, 5, from10_to_2r(1, 5));
    printf("%d %d -> %s\n", 0, 5, from10_to_2r(0, 5));
    
    // Отрицательные числа (если поддерживаются)
    printf("%d %d -> %s\n", -1, 1, from10_to_2r(-1, 1));
    printf("%d %d -> %s\n", -10, 2, from10_to_2r(-10, 2));
    
    // Степени двойки
    printf("\n=== Степени двойки ===\n");
    printf("%d %d -> %s\n", 2, 1, from10_to_2r(2, 1));
    printf("%d %d -> %s\n", 4, 2, from10_to_2r(4, 2));
    printf("%d %d -> %s\n", 8, 3, from10_to_2r(8, 3));
    printf("%d %d -> %s\n", 16, 4, from10_to_2r(16, 4));
    printf("%d %d -> %s\n", 32, 5, from10_to_2r(32, 5));
    
    // Большие числа
    printf("\n=== Большие числа ===\n");
    printf("%d %d -> %s\n", 1000, 1, from10_to_2r(1000, 1));
    printf("%d %d -> %s\n", 1000, 2, from10_to_2r(1000, 2));
    printf("%d %d -> %s\n", 1000, 3, from10_to_2r(1000, 3));
    printf("%d %d -> %s\n", 1000, 4, from10_to_2r(1000, 4));
    printf("%d %d -> %s\n", 1000, 5, from10_to_2r(1000, 5));
}