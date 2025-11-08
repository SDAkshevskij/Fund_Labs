// #include "../include/vector.h"
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "../include/test2.h"

// // Функции для работы со строками (глубокое копирование)
// char* string_copy(char* str) {
//     if (str == NULL) return NULL;
//     char *newStr = (char*)malloc(sizeof(char) * (strlen(str) + 1));
//     strcpy(newStr, str);
//     return newStr;
// }

// void string_delete(char* str) {
//     free(str);
// }

// void run_tests2() {
//     printf("=== Начало тестирования Vector с строками ===\n\n");
//     string_copy("rqwer");
//     string_copy("gasdf");

//     printf("1. Создание вектора строк с начальной емкостью 2: ");
//     Vector vec = create_vector(2, string_copy, string_delete);
//     printf("size=%zu, capacity=%zu\n", vec.size, vec.capacity);
    

//     printf("2. Добавление строк 'hello', 'world', 'test': ");
//     push_back_vector(&vec, "hello");
//     push_back_vector(&vec, "world");
//     push_back_vector(&vec, "test");  
//     printf("size=%zu, capacity=%zu\n", vec.size, vec.capacity);
    

//     printf("3. Получение элементов: ");
//     printf("vec[0]='%s', vec[1]='%s', vec[2]='%s'\n", 
//            get_at_vector(&vec, 0), 
//            get_at_vector(&vec, 1), 
//            get_at_vector(&vec, 2));
    
   
//     printf("4. Проверка глубокого копирования: ");
//     char original[] = "modified";
//     push_back_vector(&vec, original);
//     strcpy(original, "CHANGED");  
//     printf("элемент в векторе='%s', исходная строка='%s'\n", 
//            get_at_vector(&vec, 3), original);
    

//     printf("5. Копирование первого вектора в третий: ");
//     Vector vec3 = create_vector(1, string_copy, string_delete);
//     copy_vector(&vec3, &vec);
//     printf("size=%zu, элементы: '%s','%s','%s','%s'\n", vec3.size, 
//            get_at_vector(&vec3, 0), get_at_vector(&vec3, 1), 
//            get_at_vector(&vec3, 2), get_at_vector(&vec3, 3));
    

//     printf("6. Создание копии вектора в куче: ");
//     Vector *vec4 = copy_vector_new(&vec);
//     printf("size=%zu, capacity=%zu\n", vec4->size, vec4->capacity);
    

//     printf("7. Удаление элемента с индексом 1 из первого вектора: ");
//     delete_at_vector(&vec, 1);
//     printf("size=%zu, элементы: '%s','%s','%s'\n", vec.size, 
//            get_at_vector(&vec, 0), get_at_vector(&vec, 1), 
//            get_at_vector(&vec, 2));
    

//     printf("8. Очистка третьего вектора: ");
//     erase_vector(&vec3);
//     printf("size=%zu, capacity=%zu\n", vec3.size, vec3.capacity);
    

//     printf("9. Добавление в очищенный вектор: ");
//     push_back_vector(&vec3, "new1");
//     push_back_vector(&vec3, "new2");
//     printf("size=%zu, элементы: '%s','%s'\n", vec3.size, 
//            get_at_vector(&vec3, 0), get_at_vector(&vec3, 1));
    

//     printf("10. Создание вектора с емкостью 0: ");
//     Vector vec5 = create_vector(0, string_copy, string_delete);
//     printf("size=%zu, capacity=%zu\n", vec5.size, vec5.capacity);
    

//     printf("11. Добавление в вектор с емкостью 0: ");
//     push_back_vector(&vec5, "first");
//     push_back_vector(&vec5, "second");
//     printf("size=%zu, capacity=%zu\n", vec5.size, vec5.capacity);
    

//     printf("12. Получение элемента по индексу 10: ");
//     char* value = get_at_vector(&vec5, 10);
//     printf("значение=%s (должно быть NULL или мусор)\n", value);
    

//     printf("13. Сравнение вектора с NULL: ");
//     int result = is_equal_vector(&vec5, NULL);
//     printf("результат=%d\n", result);
    

//     printf("14. Очистка NULL вектора: ");
//     erase_vector(NULL); 
//     printf("успешно (без падения)\n");
    

//     printf("15. Добавление пустой строки: ");
//     push_back_vector(&vec5, "");
//     printf("элемент='%s' (пустая строка)\n", get_at_vector(&vec5, 2));
    

//     printf("16. Добавление NULL строки: ");
//     push_back_vector(&vec5, NULL);
//     printf("элемент=%p (NULL указатель)\n", get_at_vector(&vec5, 3));
    

//     printf("17. Удаление векторов из памяти: ");
//     delete_vector(vec4);
//     printf("успешно\n");
    

//     erase_vector(&vec);
//     erase_vector(&vec3);
//     erase_vector(&vec5);
    
//     printf("\n=== Все тесты со строками завершены успешно! ===\n");
// }
