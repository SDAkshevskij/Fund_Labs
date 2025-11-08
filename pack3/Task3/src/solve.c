#include "../include/liver.h"
#include "../include/file_manager.h"
#include "../include/solve.h"
#include <ctype.h>

Status check_unique_id(LinkedList *list, Liver *liver) {
    int index = find_by_val_list(list, *liver, liver_compare_by_id);
    if (index != -1) return NOT_UNIQUE_ID;
    return OK;
}

LinkedList fread_livers(FILE* inputFile, Status *status) {
    LinkedList list = create_list();
    *status = OK;

    while(*status == OK) {
        Liver liver = fread_liver(inputFile, status);

        Status idStatus = check_unique_id(&list, &liver);
        if (idStatus != OK) {
            *status = idStatus;
            return list;
        }
        sorter_push_list(&list, liver, liver_compare_by_date);
        //push_back_list(&list, liver);
    }
    
    if (*status == END_OF_INPUT) {
        *status = OK;
    }

    return list;
}



int find_liver_in_list(LinkedList *list, Liver *liver) {
    int index = find_by_val_list(list, *liver, liver_compare_without_id);
    return index != 1;
}