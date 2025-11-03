#ifndef STUDENT_H
#define STUDENT_H

#include "status_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/vector.h"

typedef struct {
    unsigned int id;
    char *firstName;
    char *lastName;
    char *groupNumber;
    unsigned char *examScores;
} Student;

typedef enum {
    STUDENT_FIRST_NAME,
    STUDENT_LAST_NAME,
    STUDENT_GROUP_NUMBER
} Student_data;

DECLARE_VECTOR(Student);

Status fread_student(FILE *inputFile, Student *student);
Status check_student(Student *student);
Status check_student_name(char *name);
Status fread_students(FILE *inputFile, Vector_Student *students);
Status fwrite_student(FILE *outputFile, Student *student);
Status fwrite_students(FILE *outputFile, Vector_Student *students);
Status find_student_by_id(int id, Vector_Student *students, Vector_Student *result);
Status find_student_by_field(char *value, Student_data findBy, Vector_Student *students, Vector_Student *result);
Status calc_student_average_score(Student *student, double *res);
Status calc_students_average_score(Vector_Student *students, double *res);
Status find_botans(Vector_Student *students, Vector_Student *result);
void fwrite_botans(FILE* outputFile, Vector_Student *botans);
Status write_student(Student *student);
Status write_students(Vector_Student *student);

Status students_sort(Vector_Student *students, int (*comp)(const void*, const void*));
int comp_students_by_id(const void* student1, const void* student2);
int comp_students_by_first_name(const void* student1, const void* student2);
int comp_students_by_last_name(const void* student1, const void* student2);
int comp_students_by_group_number(const void* student1, const void* student2);

#endif 