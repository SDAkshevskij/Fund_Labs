#include "../include/linked_list.h"
#include <stdlib.h>
#include <string.h>

LinkedList create_list() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return list;
}

void erase_list(LinkedList *list) {
    if (list == NULL) return;
    
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void delete_list(LinkedList *list) {
    erase_list(list);
}

void push_back_list(LinkedList *list, LIST_TYPE value) {
    if (list == NULL) return;
    
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return;
    
    new_node->data = (LIST_TYPE*)malloc(sizeof(LIST_TYPE));
    if (new_node->data == NULL) {
        free(new_node);
        return;
    }
    *(new_node->data) = value;
    
    new_node->next = NULL;
    new_node->prev = list->tail;
    
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    
    if (list->head == NULL) {
        list->head = new_node;
    }
    
    list->size++;
}

void push_front_list(LinkedList *list, LIST_TYPE value) {
    if (list == NULL) return;
    
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return;
    
    new_node->data = (LIST_TYPE*)malloc(sizeof(LIST_TYPE));
    if (new_node->data == NULL) {
        free(new_node);
        return;
    }
    *(new_node->data) = value;
    
    new_node->prev = NULL;
    new_node->next = list->head;
    
    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    list->head = new_node;
    
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    
    list->size++;
}

void sorter_push_list(LinkedList *list, LIST_TYPE value, int (*comparator)(LIST_TYPE*, LIST_TYPE*)) {
    int index = get_sorted_index_list(list, value, comparator);
    insert_at_list(list, index, value);
}

LIST_TYPE pop_back_list(LinkedList *list) {
    if (list == NULL || list->tail == NULL) {
        LIST_TYPE empty = {0};
        return empty;
    }
    
    Node *last = list->tail;
    LIST_TYPE value = *(last->data);
    
    if (last->prev != NULL) {
        last->prev->next = NULL;
        list->tail = last->prev;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    
    free(last->data);
    free(last);
    list->size--;
    
    return value;
}

LIST_TYPE pop_front_list(LinkedList *list) {
    if (list == NULL || list->head == NULL) {
        LIST_TYPE empty = {0};
        return empty;
    }
    
    Node *first = list->head;
    LIST_TYPE value = *(first->data);
    
    if (first->next != NULL) {
        first->next->prev = NULL;
        list->head = first->next;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    
    free(first->data);
    free(first);
    list->size--;
    
    return value;
}

void insert_at_list(LinkedList *list, size_t index, LIST_TYPE value) {
    if (list == NULL || index > list->size) return;
    
    if (index == 0) {
        push_front_list(list, value);
        return;
    }
    
    if (index == list->size) {
        push_back_list(list, value);
        return;
    }
    
    Node *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return;
    
    new_node->data = (LIST_TYPE*)malloc(sizeof(LIST_TYPE));
    if (new_node->data == NULL) {
        free(new_node);
        return;
    }
    *(new_node->data) = value;
    
    new_node->prev = current->prev;
    new_node->next = current;
    current->prev->next = new_node;
    current->prev = new_node;
    
    list->size++;
}

void delete_at_list(LinkedList *list, size_t index) {
    if (list == NULL || index >= list->size) return;
    
    if (index == 0) {
        pop_front_list(list);
        return;
    }
    
    if (index == list->size - 1) {
        pop_back_list(list);
        return;
    }
    
    Node *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    
    free(current->data);
    free(current);
    list->size--;
}

LIST_TYPE get_at_list(const LinkedList *list, size_t index) {
    if (list == NULL || index >= list->size) {
        LIST_TYPE empty = {0};
        return empty;
    }
    
    Node *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    
    return *(current->data);
}

LIST_TYPE* get_likn_at_list(const LinkedList *list, size_t index) {
    if (list == NULL || index >= list->size) {
        return NULL;
    }
    
    Node *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    
    return current->data;
}

int get_sorted_index_list(LinkedList *list, LIST_TYPE value, int (*comparator)(LIST_TYPE*, LIST_TYPE*)) {
    if (list == NULL) return -1;

    Node *cur = list->head;
    int index = 0;
    while(cur != NULL) {
        if (comparator(cur->data, &value) >= 0) {
            break;
        }
        index++;
        cur = cur->next;
    }

    return index;
}

int is_equal_list(const LinkedList *l1, const LinkedList *l2) {
    if (l1 == NULL || l2 == NULL) return 0;
    if (l1->size != l2->size) return 0;
    
    Node *current1 = l1->head;
    Node *current2 = l2->head;
    
    while (current1 != NULL && current2 != NULL) {
        if (memcmp(current1->data, current2->data, sizeof(LIST_TYPE)) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    
    return 1;
}

int find_by_val_list(LinkedList *list, LIST_TYPE value, int (*comparator)(LIST_TYPE*, LIST_TYPE*)) {
    if (list == NULL) return -1;
    if (list->size == 0) return -1;

    Node *cur = list->head;
    int index = 0;
    while (cur != NULL) {
        if (comparator(cur->data, &value) == 0) {
            return index;
        }

        cur = cur->next;
        index++;
    }

    return -1;
}

void fprintf_elements_list(FILE* outputFile, LinkedList *list, void (*printer)(FILE*, LIST_TYPE*)) {
    if (list == NULL) return;
    if (list->size == 0) return;

    Node *cur = list->head;
    while(cur != NULL) {
        printer(outputFile, cur->data);
        cur = cur->next;
    }
}

void push_stack(LinkedList *stack, LIST_TYPE value) {
    push_back_list(stack, value);
}

LIST_TYPE pop_stack(LinkedList *stack) {
    return pop_back_list(stack);
}

LIST_TYPE peek_stack(const LinkedList *stack) {
    if (stack == NULL || stack->tail == NULL) {
        LIST_TYPE empty = {0};
        return empty;
    }
    return *(stack->tail->data);
}

void enqueue(LinkedList *queue, LIST_TYPE value) {
    push_back_list(queue, value);
}

LIST_TYPE dequeue(LinkedList *queue) {
    return pop_front_list(queue);
}

LIST_TYPE peek_queue(const LinkedList *queue) {
    if (queue == NULL || queue->head == NULL) {
        LIST_TYPE empty = {0};
        return empty;
    }
    return *(queue->head->data);
}