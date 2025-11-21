#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "../include/linked_list.h"

char to_open_bracket(char bracket) {
    if (bracket == ')') return '(';
    if (bracket == ']') return '[';
    if (bracket == '}') return '{';
    if (bracket == '>') return '<';
}

int check_brackets(const char *str) {
    LinkedList stack = create_list();

    while(*str != '\0') {
        if (*str == '(' || *str == '[' || *str == '{' || *str == '<') {
            push_stack(&stack, *str);
        }
        else if (*str == ')' || *str == ']' || *str == '}' || *str == '>') {
            if (stack.size == 0 || pop_stack(&stack) != to_open_bracket(*str)) {
                return 0;
            }
        }
        str++;
    }
    if (stack.size != 0) return 0;
    return 1;
}
