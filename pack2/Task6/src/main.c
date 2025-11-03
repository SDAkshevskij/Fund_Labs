#include <stdio.h>
#include <stdlib.h>
#include "../include/status_manager.h"
#include "../include/string_manager.h"
#include "../include/student.h"
#include "string.h"

Status sort_process(Vector_Student *students) {
    printf("Send sorting type: ");
    char *sortVal;
    Status status = read_word(&sortVal);
    string_to_lower(sortVal);

    if (status != OK) {
        return status;
    }

    if (strcmp(sortVal, "id") == 0) {
        students_sort(students, comp_students_by_id);
    }
    else if (strcmp(sortVal, "first_name") == 0) {
        students_sort(students, comp_students_by_first_name);
    }
    else if (strcmp(sortVal, "last_name") == 0) {
        students_sort(students, comp_students_by_last_name);
    }
    else if (strcmp(sortVal, "group") == 0) {
        students_sort(students, comp_students_by_group_number);
    }
    else {
        printf("Error: wrong command!\n");
    }
}

Status find_by_process(FILE* outputFile, Vector_Student *students) {
    printf("Send find type: ");
    char *type;
    Status status = read_word(&type);
    string_to_lower(type);
    Vector_Student result;

    printf("print to file? {Y or N} ");
    char *responce;
    read_word(&responce);
    string_to_lower(responce);

    if (strcmp(responce, "n") != 0 && strcmp(responce, "y")) {
        printf("Wrong responce!!\n");
        return OK;
    }

    printf("Send val: ");
    if (strcmp(type, "id") == 0) {
        int id;
        read_natural_integer(&id);
        status = find_student_by_id(id, students, &result);
    }
    else if (strcmp(type, "first_name") == 0) {
        char *name;
        read_word(&name);
        status = find_student_by_field(name, STUDENT_FIRST_NAME, students, &result);
    }
    else if (strcmp(type, "last_name") == 0) {
        char *name;
        read_word(&name);
        status = find_student_by_field(name, STUDENT_LAST_NAME, students, &result);
    }
    else if (strcmp(type, "group") == 0) {
        char *name;
        read_word(&name);
        status = find_student_by_field(name, STUDENT_GROUP_NUMBER, students, &result);
    }
    else {
        printf("No such type!!!\n");
        return OK;
    }
    if (vector_Student_size(&result) == 0){ 
        printf("NO SUCH STUDENT!!!\n");
    }
    if (status != OK) {
        return status;
    }

    if (strcmp(responce, "y") == 0) {
        fwrite_students(outputFile, &result);
    }
    else {
        write_students(&result);
    }
    
    return OK;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_status(WRONG_ARGUMENT_AMOUNT);
        return WRONG_ARGUMENT_AMOUNT;
    }

    printf("Comands:\nSort_by {id, first_name, last_name, group}\nPrint\nFind_by {id, first_name, last_name, group}\nPrint_botans\nEnd\n\n");

    
    Status status;
    
    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        print_status(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }
    
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        print_status(CANT_OPEN_FILE);
        return CANT_OPEN_FILE;
    }
    
    Vector_Student students;

    status = fread_students(inputFile, &students);
    if (status != OK) {
        print_status(status);
        return status;
    }
    
    while(1) {
        printf("Send command: ");
        char *comand;
        status = read_word(&comand);
        string_to_lower(comand);

        if (status != OK) {
            fclose(inputFile);
            fclose(outputFile);
            print_status(status);
            return status;
        }

        if (strcmp(comand, "sort_by") == 0) {
            status = sort_process(&students);
        }
        else if (strcmp(comand, "print") == 0) {
            status = fwrite_students(outputFile, &students);
            if (status != OK) {
                fclose(inputFile);
                fclose(outputFile);
                free(comand);
                print_status(status);
                return status;
            }
            fflush(outputFile);
        }
        else if (strcmp(comand, "find_by") == 0) {
            Status status = find_by_process(outputFile, &students);

            if (status == NOT_A_NUMBER || status == NON_NATURAL_NUMBER) {
                print_status(status);
                continue;
            }

            if (status != OK) {
                fclose(inputFile);
                fclose(outputFile);
                free(comand);
                print_status(status);
                return status;
            }
            fflush(outputFile);
        }
        else if (strcmp(comand, "print_botans") == 0) {
            Vector_Student botans;
            status = find_botans(&students, &botans);

            if (status != OK) {
                fclose(inputFile);
                fclose(outputFile);
                free(comand);
                print_status(status);
                return status;
            }
            fwrite_botans(outputFile, &botans);
            fflush(outputFile);
        }
        else if (strcmp(comand, "end") == 0) {
            free(comand);
            break;
        }
        else {
            printf("Unknown comand!!!\n");
        }
    }

    fclose(inputFile);
    fclose(outputFile);;
    return OK;

}