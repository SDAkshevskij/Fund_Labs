#ifndef SOLVE_H
#define SOLVE_H
#include "linked_list.h"
#include "stdio.h"
#include "liver.h"

Status check_unique_id(LinkedList *list, Liver *liver);
LinkedList fread_livers(FILE* inputFile, Status *status);

int find_liver_in_list(LinkedList *list, Liver *liver);

#endif