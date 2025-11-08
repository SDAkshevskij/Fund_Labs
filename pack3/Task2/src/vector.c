#include "../include/vector.h"


Vector create_vector(size_t initial_capacity, 
    VECTOR_TYPE (*copyFunc)(VECTOR_TYPE), void (*deleteFunc)(VECTOR_TYPE)) {
        if (initial_capacity < 1) initial_capacity = 1;

        Vector vector;
        vector.capacity = initial_capacity;
        vector.data = (VECTOR_TYPE*)malloc(sizeof(VECTOR_TYPE) * vector.capacity);
        vector.size = 0;
        vector.copyFunc = copyFunc;
        vector.deleteFunc = deleteFunc;

        return vector;
}

void erase_vector(Vector *v) { 
    if (v == NULL) return;
    if (v->deleteFunc != NULL) {
        for (int i = 0; i < v->size; i++) {
            v->deleteFunc(v->data[i]);
        }
    }
    if (v->data != NULL) {
        free(v->data);
    }

    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}

int is_equal_vector(const Vector *v1, const Vector *v2) {
    if (v1 == NULL || v2 == NULL) return 0;
    if (v1->size != v2->size) return 0;

    for (int i = 0; i < v1->size; i++) {
        if (v1->data[i] != v2->data[i]) {
            return 0;
        }
    }

    return 1;
}

void copy_vector(Vector *dest, const Vector *src) {
    for (int i = 0; i < src->size; i++) {
        push_back_vector(dest, get_at_vector(src, i));
    }
}

Vector *copy_vector_new(const Vector *src) {
    Vector *newVector = (Vector*)malloc(sizeof(Vector));
    *newVector = create_vector(src->capacity, src->copyFunc, src->deleteFunc);

    copy_vector(newVector, src);
    return newVector;
}

void push_back_vector(Vector *v, VECTOR_TYPE value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        if (v->capacity == 0) v->capacity = 1;

        VECTOR_TYPE *temp = (VECTOR_TYPE*)realloc(v->data, sizeof(VECTOR_TYPE) * v->capacity);
        if (temp == NULL) return;

        v->data = temp;
    }

    if (v->copyFunc == NULL) {
        v->data[v->size++] = value;
    }
    else {
        v->data[v->size++] = v->copyFunc(value); 
    }
}

void delete_at_vector(Vector *v, size_t index) {
    if (v->deleteFunc != NULL) {
        v->deleteFunc(get_at_vector(v, index));
    }

    for (int i = index + 1; i < v->size; i++) {
        v->data[i - 1] = v->data[i];
    }

    v->size--;
}

VECTOR_TYPE get_at_vector(const Vector *v, size_t index) {
    return v->data[index];
}

void delete_vector(Vector *v) {
    if (v == NULL) return;
    erase_vector(v);
    free(v);
} 