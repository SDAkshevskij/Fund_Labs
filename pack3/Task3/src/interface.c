#include "../include/linked_list.h"
#include "../include/solve.h"
#include "../include/liver.h"
#include "../include/string_manager.h"
#include "../include/status_manager.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>



Status read_liver_info(Liver *liver) {
    printf("First name: ");
    Status status = read_word(&liver->firstName);
    if (status != OK) return status;
    status = validate_name(liver->firstName);
    if (status != OK) return status;

    printf("Last name: ");
    status = read_word(&liver->lastName);
    if (status != OK) return status;
    status = validate_name(liver->lastName);
    if (status != OK) return status;

    printf("Sur name: ");
    status = read_word(&liver->surName);
    if (status != OK) return status;
    status = validate_name(liver->surName);
    if (status != OK) return status;
    if (strcmp(liver->surName, "NULL") == 0) {
        liver->surName = "";
    }

    printf("Birth date {dd mm yyyy}: ");
    Date date;
    status = read_natural_integer(&date.day);
    if (status != OK) return status;

    status = read_natural_integer(&date.mount);
    if (status != OK) return status;

    status = read_natural_integer(&date.year);
    if (status != OK) return status;

    status = validate_Date(&date);
    if (status != OK) return status;
    liver->birthDate = date;

    printf("Gender {M/W}: ");
    status = read_non_space_symb(&liver->gender);
    if (status != OK) return status;
    if (liver->gender != 'M' && liver->gender != 'W') return THIRD_GENDER;

    printf("Income: ");
    status = read_float(&liver->income);
    if (status != OK) return status;

    return OK;
}

Status is_presented_check(LinkedList *list) {
    Liver liver;
    Status status = read_liver_info(&liver);
    if (status != OK) return OK;
    
    int index = find_by_val_list(list, liver, liver_compare_without_id);
    if (index == -1) {
        return UNKNOWN_LIVER;
    }

    int id = get_at_list(list, index).id;
    printf("Liver found, his id is %d\n", id);
    return OK;
}

Status edit_processor(Liver *liver, char *command, void *newValue) {
    Status status;
    if (strcmp(command, "first") == 0) {
        char *name = (char*)newValue;
        if ((status = validate_name(name)) != OK) return status;
        liver->firstName = name;
    }
    else if (strcmp(command, "last") == 0) {
        char *name = (char*)newValue;
        if ((status = validate_name(name)) != OK) return status;
        liver->lastName = name;
    }
    else if (strcmp(command, "sur") == 0) {
        char *name = (char*)newValue;
        if ((status = validate_name(name)) != OK) return status;
        if (strcmp(name, "NULL") == 0) {
            liver->surName = "";
        }
        else {
            liver->surName = name;
        }
    }
    else if (strcmp(command, "birth_date") == 0) {
        Date date =  *(Date*)newValue;
        if ((status = validate_Date(&date)) != OK) return status;
        liver->birthDate = date;
    }
    else if (strcmp(command, "gender") == 0) {
        char gender = *(char*)newValue;
        if (gender != 'M' && gender != 'W') {
            return THIRD_GENDER;
        }
        liver->gender = gender;
    }
    else if (strcmp(command, "income") == 0) { 
        double income;
        status = string_to_double((char*)newValue, &income);
        if (status != OK) return status;
        liver->income = income;
    }
    else {
        return UNKNOWN_FLAG;
    }

    return OK;
}

Status edit_process(LinkedList *list, Vector_Transaction *trans) {
    printf("Id: ");
    int id;
    Status status = read_natural_integer(&id);

    Liver liver;
    liver.id = id;
    int index = find_by_val_list(list, liver, liver_compare_by_id);

    if (index == -1) return UNKNOWN_LIVER;
    

    Liver *link = get_likn_at_list(list, index);

    Transaction tran;
    tran.index = index;
    tran.liver = *link;
    tran.type = TRANSACTION_EDIT;

    printf("Select field to edit {first, last, sur, birth_date, gender, income} and new value: ");
    char *field, *value;
    status = read_word(&field);
    if (status != OK) return status;
    string_to_lower(field);

    if (strcmp(field, "birth_date") == 0) {
        Date date;
        status = read_natural_integer(&date.day);
        if (status != OK) return status;

        status = read_natural_integer(&date.mount);
        if (status != OK) return status;

        status = read_natural_integer(&date.year);
        if (status != OK) return status;

        status = edit_processor(link, field, &date);
    }
    else {
        status = read_word(&value);
        if (status != OK) return status;

        status = edit_processor(link, field, value);
    }
    if (status == OK) {
        vector_Transaction_push_back(trans, tran);
    }
    return status;
}

void delete_processor(LinkedList *list, int index) {
    delete_at_list(list, index);
}

Status delete_process(LinkedList *list, Vector_Transaction *trans) {
    printf("Id: ");
    int id;
    Status status = read_natural_integer(&id);
    if (status != OK) return status;

    Liver liver;
    liver.id = id;
    int index = find_by_val_list(list, liver, liver_compare_by_id);
    if (index == -1) return UNKNOWN_LIVER;

    Liver link = get_at_list(list, index);

    Transaction tran;
    tran.index = index;
    tran.liver = link;
    tran.type = TRANSACTION_DELETE;
    vector_Transaction_push_back(trans, tran);

    delete_processor(list, index);

    return OK;
}

Status add_processor(LinkedList *list, Liver *liver, int index) {
    insert_at_list(list, index, *liver);
    return OK;
}

Status add_process(LinkedList *list, Vector_Transaction *trans) {
    Liver liver;

    printf("Id: ");
    Status status = read_natural_integer(&liver.id);
    if (status != OK) return status;
    status = check_unique_id(list, &liver);
    if (status != OK) return status;

    status = read_liver_info(&liver);
    if (status != OK) return status;

    int index = get_sorted_index_list(list, liver, liver_compare_by_date);
    add_processor(list, &liver, index);

    Transaction tran;
    tran.index = index;
    tran.liver = liver;
    tran.type = TRANSACTION_ADD;
    vector_Transaction_push_back(trans, tran);

    return OK;
}

Status print_process(LinkedList *list) {
    printf("Output file path: ");
    char *outputFileName;
    Status status = read_word(&outputFileName);
    if (status != OK) return status;

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        return CANT_OPEN_FILE;
    }

    fprintf_elements_list(outputFile, list, fprint_liver);
    fclose(outputFile);

    return OK;
}

Status undo_transaction(LinkedList *list, Transaction *tran) {
    if (tran->type == TRANSACTION_EDIT) {
        delete_processor(list, tran->index);
        add_processor(list, &tran->liver, tran->index);
    }
    else if (tran-> type == TRANSACTION_ADD) {
        delete_processor(list, tran->index);
    }
    else if (tran -> type == TRANSACTION_DELETE) {
        add_processor(list, &tran->liver, tran->index);
    }
}

Status talk_to_user() {
    printf("Send input file path: ");

    char *inputFileName;
    Status status = read_word(&inputFileName);
    if (status != OK) return status;
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        return CANT_OPEN_FILE;
    }

    LinkedList list = fread_livers(inputFile, &status);
    if (status != OK) return status;

    Vector_Transaction transactions;
    vector_Transaction_create(&transactions);
    int wasUndo = 0;

    printf("Is_present/Edit/Delete/Add/Print/Undo\n");

    while(1) {
        char *command;
        status = read_word(&command);
        if (status != OK) return status;
        string_to_lower(command);

        if (strcmp(command, "is_present") == 0) {
            status = is_presented_check(&list);
        }
        else if (strcmp(command, "edit") == 0) {
            if (wasUndo) vector_Transaction_clear(&transactions);
            status = edit_process(&list, &transactions);
        }
        else if (strcmp(command, "delete") == 0) {
            if (wasUndo) vector_Transaction_clear(&transactions);
            status = delete_process(&list, &transactions);
        }
        else if (strcmp(command, "add") == 0) {
            if (wasUndo) vector_Transaction_clear(&transactions);
            status = add_process(&list, &transactions);
        }
        else if (strcmp(command, "print") == 0) {
            status = print_process(&list);
        }
        else if (strcmp(command, "undo") == 0) {
            int size = vector_Transaction_size(&transactions);
            if (size == 0) {
                printf("Nothing to undo! ¯\\_(ツ)_/¯\n");
                continue;
            }
            else {
                Transaction tran;
                vector_Transaction_pop_back(&transactions, &tran);
                undo_transaction(&list, &tran);
                wasUndo = 1;
            }
        }
        else if (strcmp(command, "end") == 0) {
            printf("(－ω－) zzZ\n");
            return OK;
        }
        else {
            printf("Unknown command!!!╮(￣_￣)╭\n");
            continue;
        }

        if (status != OK) {
            print_status(status);
        }
        else {
            printf("Success!(⌒‿⌒)\n");
        }
    }
}
