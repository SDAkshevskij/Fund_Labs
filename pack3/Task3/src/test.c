// #include "../include/vector.h"
// #include <stdio.h>
// #include <assert.h>
// #include "../include/test.h"

// // Функции для работы с int (простое копирование значений)
// int int_copy(int value) {
//     return value;
// }

// void int_delete(int value) {
//     // Для простых типов ничего не делаем
// }

// void run_tests1() {
//     printf("=== Начало тестирования Vector ===\n\n");
    

//     printf("1. Создание вектора с начальной емкостью 2: ");
//     Vector vec = create_vector(2, NULL, NULL);
//     printf("size=%zu, capacity=%zu\n", vec.size, vec.capacity);
    

//     printf("2. Добавление элементов 10, 20, 30: ");
//     push_back_vector(&vec, 10);
//     push_back_vector(&vec, 20);
//     push_back_vector(&vec, 30);  // Должен вызвать реаллокацию
//     printf("size=%zu, capacity=%zu\n", vec.size, vec.capacity);
    

//     printf("3. Получение элементов: ");
//     printf("vec[0]=%d, vec[1]=%d, vec[2]=%d\n", 
//            get_at_vector(&vec, 0), get_at_vector(&vec, 1), get_at_vector(&vec, 2));
    

//     printf("4. Создание второго вектора с такими же элементами: ");
//     Vector vec2 = create_vector(2, int_copy, NULL);
//     push_back_vector(&vec2, 10);
//     push_back_vector(&vec2, 20);
//     push_back_vector(&vec2, 30);
//     printf("Сравнение: %s\n", is_equal_vector(&vec, &vec2) ? "равны" : "не равны");
    

//     printf("5. Изменение второго вектора: ");
//     push_back_vector(&vec2, 40);
//     printf("Сравнение после изменения: %s\n", is_equal_vector(&vec, &vec2) ? "равны" : "не равны");
    

//     printf("6. Копирование первого вектора в третий: ");
//     Vector vec3 = create_vector(1, NULL, int_delete);
//     copy_vector(&vec3, &vec);
//     printf("size=%zu, элементы: %d,%d,%d\n", vec3.size, 
//            get_at_vector(&vec3, 0), get_at_vector(&vec3, 1), get_at_vector(&vec3, 2));
    

//     printf("7. Создание копии вектора в куче: ");
//     Vector *vec4 = copy_vector_new(&vec);
//     printf("size=%zu, capacity=%zu\n", vec4->size, vec4->capacity);
    

//     printf("8. Удаление элемента с индексом 1 из первого вектора: ");
//     delete_at_vector(&vec, 1);
//     printf("size=%zu, элементы: %d,%d\n", vec.size, get_at_vector(&vec, 0), get_at_vector(&vec, 1));
    

//     printf("9. Очистка третьего вектора: ");
//     erase_vector(&vec3);
//     printf("size=%zu, capacity=%zu\n", vec3.size, vec3.capacity);
    

//     printf("10. Добавление в очищенный вектор: ");
//     push_back_vector(&vec3, 100);
//     push_back_vector(&vec3, 200);
//     printf("size=%zu, элементы: %d,%d\n", vec3.size, get_at_vector(&vec3, 0), get_at_vector(&vec3, 1));
    

//     printf("11. Создание вектора с емкостью 0: ");
//     Vector vec5 = create_vector(0, int_copy, int_delete);
//     printf("size=%zu, capacity=%zu\n", vec5.size, vec5.capacity);
    

//     printf("12. Добавление в вектор с емкостью 0: ");
//     push_back_vector(&vec5, 1);
//     push_back_vector(&vec5, 2);
//     printf("size=%zu, capacity=%zu\n", vec5.size, vec5.capacity);

//     printf("13. Сравнение вектора с NULL: ");
//     int result = is_equal_vector(&vec5, NULL);
//     printf("результат=%d\n", result);
    

//     printf("14. Очистка NULL вектора: ");
//     erase_vector(NULL); 
//     printf("успешно (без падения)\n");
    

//     printf("15. Удаление векторов из памяти: ");
//     delete_vector(vec4);
//     printf("успешно\n");
    

//     erase_vector(&vec);
//     erase_vector(&vec2);
//     erase_vector(&vec3);
//     erase_vector(&vec5);
    
//     printf("\n=== Все тесты завершены успешно! ===\n");
// }
