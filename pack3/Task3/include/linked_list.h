#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "liver.h"
#include <stddef.h>
#include <stdlib.h>

#define LIST_TYPE Liver

typedef struct Node {
    LIST_TYPE *data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

LinkedList create_list();
void erase_list(LinkedList *list);
void delete_list(LinkedList *list);
void push_back_list(LinkedList *list, LIST_TYPE value);
void push_front_list(LinkedList *list, LIST_TYPE value);
void sorter_push_list(LinkedList *list, LIST_TYPE value, int (*comparator)(LIST_TYPE*, LIST_TYPE*));
void insert_at_list(LinkedList *list, size_t index, LIST_TYPE value);
LIST_TYPE pop_back_list(LinkedList *list);
LIST_TYPE pop_front_list(LinkedList *list);
void insert_at_list(LinkedList *list, size_t index, LIST_TYPE value);
void delete_at_list(LinkedList *list, size_t index);
LIST_TYPE get_at_list(const LinkedList *list, size_t index);
LIST_TYPE* get_likn_at_list(const LinkedList *list, size_t index);
int get_sorted_index_list(LinkedList *list, LIST_TYPE value, int (*comparator)(LIST_TYPE*, LIST_TYPE*));
int is_equal_list(const LinkedList *l1, const LinkedList *l2);
int find_by_val_list(LinkedList *list, LIST_TYPE value, int (*comparator)(LIST_TYPE*, LIST_TYPE*));
void fprintf_elements_list(FILE* outputFile, LinkedList *list, void (*printer)(FILE*, LIST_TYPE*));

void push_stack(LinkedList *stack, LIST_TYPE value);
LIST_TYPE pop_stack(LinkedList *stack);
LIST_TYPE peek_stack(const LinkedList *stack);

void enqueue(LinkedList *queue, LIST_TYPE value);
LIST_TYPE dequeue(LinkedList *queue);
LIST_TYPE peek_queue(const LinkedList *queue);

#endif