#ifndef VECTOR_H
#define VECTOR_H
#include "status_manager.h"

#define DECLARE_VECTOR(T) \
typedef struct { \
    T *data; \
    int size; \
    int capacity; \
} Vector_##T; \
\
Status vector_##T##_create(Vector_##T *vec);\
Status vector_##T##_push_back(Vector_##T* vec, T val);\
Status vector_##T##_pop_back(Vector_##T* vec, T *val);\
int vector_##T##_size(Vector_##T* vec);\
Status vector_##T##_last(Vector_##T* vec, T *val);\
Status vector_##T##_at(Vector_##T* vec, int index, T *val);\
Status vector_##T##_delete(Vector_##T* vec);\

//DECLARE_VECTOR(char);
//DECLARE_VECTOR(int);

#define DEFINE_VECTOR(T)\
\
Status vector_##T##_create(Vector_##T *vec) {\
\
    vec->size = 0;\
    vec->capacity = 4; \
    vec->data = malloc(sizeof(T) * vec->capacity);\
\
    if (!vec->data) { \
        return MEMORY_ALLOCATION_ERROR; \
    } \
\
    return OK;\
}\
Status vector_##T##_delete(Vector_##T* vec) { \
    if (vec) { \
        free(vec->data); \
    } \
    return OK;\
} \
\
\
Status vector_##T##_push_back(Vector_##T* vec, T val) { \
    if (vec->size >= vec->capacity) { \
        vec->capacity *= 2; \
        T *new_data = realloc(vec->data, vec->capacity * sizeof(T)); \
    \
        if (new_data == NULL) return MEMORY_ALLOCATION_ERROR; \
        \
        vec->data = new_data; \
    } \
    vec->data[vec->size] = val; \
    vec->size++;\
    return OK;\
} \
\
Status vector_##T##_pop_back(Vector_##T* vec, T *val) {\
    if (vec->size == 0) { \
        return POP_EMPTY_VECTOR; \
    }\
    vec->size--;\
    *val = vec->data[vec->size];\
    return OK;\
}\
\
Status vector_##T##_at(Vector_##T* vec, int index, T *val) {\
    if (index >= vec->size) { \
        return INDEX_OUT_OF_THE_RANGE; \
    } \
\
    *val = vec->data[index];\
\
    return OK;\
}\
Status vector_##T##_set(Vector_##T* vec, int index, T val) {\
    if (index >= vec->size) {\
        return INDEX_OUT_OF_THE_RANGE;\
    }\
    vec->data[index] = val;\
\
    return 0;\
}\
\
Status vector_##T##_last(Vector_##T* vec, T *val) {\
    return vector_##T##_at(vec, vec->size - 1, val);\
}\
\
int vector_##T##_size(Vector_##T* vec) { \
    return vec->size;\
} \

//DEFINE_VECTOR(char);
//DEFINE_VECTOR(int);

#endif 