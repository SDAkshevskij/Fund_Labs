#ifndef VECTOR_H
#define VECTOR_H
#include "status_manager.h"
#include <stdlib.h>

#define DECLARE_VECTOR(T) \
typedef struct { \
    T *data; \
    int size; \
    int capacity; \
} Vector_##T; \
\
Vector_##T* vector_##T##_create();\
Status vector_##T##_push_back(Vector_##T* vec, T val);\
T vector_##T##_pop_back(Vector_##T* vec);\
Status vector_##T##_resize(Vector_##T *vec, int newCapacity);\
int vector_##T##_size(Vector_##T* vec);\
T vector_##T##_last(Vector_##T* vec);\
T vector_##T##_at(Vector_##T* vec, int index);\
Status vector_##T##_set(Vector_##T* vec, int index, T val);\
Status vector_##T##_delete(Vector_##T* vec);\
Status vector_##T##_cat(Vector_##T *dest, Vector_##T *src);\
void vector_##T##_reverse(Vector_##T *vec);\
T* vector_##T##_steal_data(Vector_##T *vec);\

DECLARE_VECTOR(char);
DECLARE_VECTOR(int);

#define DEFINE_VECTOR(T)\
\
Vector_##T* vector_##T##_create() {\
    Vector_##T *vec = (Vector_##T*)malloc(sizeof(Vector_##T));\
    if (vec == NULL) {\
        return NULL;\
    }\
\
    vec->size = 0;\
    vec->capacity = 4; \
    vec->data = malloc(sizeof(T) * vec->capacity);\
\
    if (!vec->data) { \
        return NULL;\
    } \
\
    return vec;\
}\
Status vector_##T##_delete(Vector_##T* vec) { \
    if (vec != NULL) { \
        free(vec->data); \
        free(vec);\
    } \
    return OK;\
} \
\
\
Status vector_##T##_push_back(Vector_##T* vec, T val) { \
    if (vec->size >= vec->capacity) { \
        vector_##T##_resize(vec, vec->capacity * 2);\
    } \
    vec->data[vec->size] = val; \
    vec->size++;\
    return OK;\
} \
\
Status vector_##T##_resize(Vector_##T *vec, int newCapacity) {\
    T *new_data = realloc(vec->data, newCapacity * sizeof(T)); \
    \
    if (new_data == NULL) return MEMORY_ALLOCATION_ERROR; \
    \
    vec->capacity = newCapacity;\
    vec->data  = new_data;\
    return OK;\
}\
\
T vector_##T##_pop_back(Vector_##T* vec) {\
    vec->size--;\
    return vec->data[vec->size];\
}\
\
T vector_##T##_at(Vector_##T* vec, int index) {\
    return vec->data[index];\
}\
Status vector_##T##_set(Vector_##T* vec, int index, T val) {\
    if (index >= vec->capacity) {\
        return INDEX_OUT_OF_THE_RANGE;\
    }\
    vec->data[index] = val;\
    \
    if (index > vec->size) {\
        vec->size = index;\
    }\
\
    return 0;\
}\
\
T vector_##T##_last(Vector_##T* vec) {\
    return vector_##T##_at(vec, vec->size - 1);\
}\
\
int vector_##T##_size(Vector_##T* vec) { \
    return vec->size;\
}\
\
Status vector_##T##_cat(Vector_##T *dest, Vector_##T *src) {\
    if (dest->size + src->size >= dest->capacity) {\
        vector_##T##_resize(dest, dest->size + src->size);\
    }\
    \
    int vectorOffset = dest->size;\
    for (int i = 0; i < src->size; i++) { \
        dest->data[i + vectorOffset] = src->data[i];\
    }\
}\
\
void vector_##T##_reverse(Vector_##T *vec) {\
    int i = 0;\
    int j = vec->size - 1;\
    \
    while (i < j) {\
        T temp = vec->data[i];\
        vec->data[i] = vec->data[j];\
        vec->data[j] = temp;\
        i++;\
        j--;\
    }\
}\
T* vector_##T##_steal_data(Vector_##T *vec) {\
    T* data = vec->data;\
    \
    vec->size = 0;\
    vec->capacity = 4;\
    vec->data = (T*)malloc(sizeof(T) * vec->capacity);\
\
    return data;\
}\

//DEFINE_VECTOR(char);
//DEFINE_VECTOR(int);

#endif 