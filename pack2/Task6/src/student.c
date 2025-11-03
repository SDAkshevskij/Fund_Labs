#include "../include/student.h"
#include "../include/string_manager.h"
#include "../include/file_manager.h"
#include <ctype.h>
#include <string.h>

DEFINE_VECTOR(Student);

Status fread_student(FILE *inputFile, Student *student) {
    Status status = fread_natural_integer(inputFile, &student->id);
    if (status != OK) {
        if (status == EMPTY_STRING) return END_OF_INPUT;
        return status;
    }

    status = fread_word(inputFile, &student->firstName);
    if (status != OK) {
        return status;
    }

    status = fread_word(inputFile, &student->lastName);
    if (status != OK) {
        return status;
    }

    status = fread_word(inputFile, &student->groupNumber);
    if (status != OK) {
        return status;
    }

    student->examScores = (unsigned char*)malloc(sizeof(unsigned char) * 5);
    for (int i = 0; i < 5; i++) {
        status = fread_non_space_symb(inputFile, student->examScores + i);
        if (status != OK) {
            return status;
        }
    }

    status = check_student(student);
    if (status != OK) {
        return status;
    }
    return status;
}
Status check_student(Student *student) {
    if (student->id < 0) {
        return NEGATIVE_NUMBER;
    }  

    Status status;

    if ((status = check_student_name(student->firstName)) != OK) {
        return status;
    }

    if ((status = check_student_name(student->lastName)) != OK) {
        return status;
    }

    if (is_empty_string(student->groupNumber)) {
        return EMPTY_STRING;
    }

    return OK;
}

Status check_student_name(char *name) {
    if (is_empty_string(name)) return EMPTY_STRING;

    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            return INVALID_CHARACTER;
        }
    }
    return OK;
}

Status fread_students(FILE *inputFile, Vector_Student *students) {
    Status status = vector_Student_create(students);
    if (status != OK) return status;
    
    Student curStudent;
    
    while ((status = fread_student(inputFile, &curStudent)) == OK) {
        vector_Student_push_back(students, curStudent);
    }
    
    if (status != END_OF_INPUT) {
        vector_Student_delete(students);
        return status;
    }
    return OK;
}

Status fwrite_student(FILE *outputFile, Student *student) {
    double avarangeScore = 0;
    for (int i = 0; i < 5; i++) {
        if (isdigit(student->examScores[i])) {
            avarangeScore += student->examScores[i] - '0';
        }
        else {
            avarangeScore += student->examScores[i] - 'A' + 10;
        }
    }
    avarangeScore /= 5;
    fprintf(outputFile, "%d %s %s %s %lf\n", (int)student->id, student->firstName, student->lastName, student->groupNumber, avarangeScore);
}

Status write_student(Student *student) {
    double avarangeScore = 0;
    for (int i = 0; i < 5; i++) {
        if (isdigit(student->examScores[i])) {
            avarangeScore += student->examScores[i] - '0';
        }
        else {
            avarangeScore += student->examScores[i] - 'A' + 10;
        }
    }
    avarangeScore /= 5;
    printf("%d %s %s %s %lf\n", (int)student->id, student->firstName, student->lastName, student->groupNumber, avarangeScore);
}

Status write_students(Vector_Student *students) {
    for (int i = 0; i < vector_Student_size(students); i++) {
        Student curStudent;
        vector_Student_at(students, i, &curStudent);

        write_student(&curStudent);
    }
    return OK;
}


Status fwrite_students(FILE *outputFile, Vector_Student *students) {
    for (int i = 0; i < vector_Student_size(students); i++) {
        Student curStudent;
        vector_Student_at(students, i, &curStudent);

        fwrite_student(outputFile, &curStudent);
    }
    return OK;
}

Status find_student_by_id(int id, Vector_Student *students, Vector_Student *result) {
    Status status = vector_Student_create(result);
    if (status != OK) return status;

    int isFind = 0;

    for (int i = 0; i < vector_Student_size(students); i++) {
        Student curStudent;
        vector_Student_at(students, i, &curStudent);

        if (curStudent.id == id) {
            vector_Student_push_back(result, curStudent);
            isFind = 1;
        }
    }
    return OK;
}

Status find_student_by_field(char *value, Student_data findBy, Vector_Student *students, Vector_Student *result) {
    Status status = vector_Student_create(result);
    if (status != OK) return status;

    for (int i = 0; i < vector_Student_size(students); i++) {
        Student curStudent;
        vector_Student_at(students, i, &curStudent);

        char *comp;

        switch (findBy)
        {
        case STUDENT_FIRST_NAME:
            comp = curStudent.firstName;
            break;
        case STUDENT_LAST_NAME:
            comp = curStudent.lastName;
            break;
        case STUDENT_GROUP_NUMBER:
            comp = curStudent.groupNumber;
            break;
        default:
            break;
        }

        if (strcmp(value, comp) == 0) {
            status = vector_Student_push_back(result, curStudent);
            if (status != OK) return status;
        }
    }

    return OK;
}

Status calc_student_average_score(Student *student, double *res) {
    double scoreSum = 0;
    for (int j = 0; j < 5; j++) {
        scoreSum += student->examScores[j] - '0';
    }
    *res = scoreSum / 5;
    return OK;
}

Status calc_students_average_score(Vector_Student *students, double *res) {
    double scoreSum = 0;
    int scoreAmo = 0;

    for (int i = 0; i < vector_Student_size(students); i++) {
        Student curStudent;
        double avarange = 0;

        vector_Student_at(students, i, &curStudent);
        calc_student_average_score(&curStudent, &avarange);

        scoreSum += avarange;
        scoreAmo++;
    }

    *res = scoreSum / scoreAmo;
    return OK;
}

Status find_botans(Vector_Student *students, Vector_Student *result) {
    Status status = vector_Student_create(result);
    if (status != OK) return status;

    double averageScore;
    calc_students_average_score(students, &averageScore);

    for (int i = 0; i < vector_Student_size(students); i++) {
        double curStudentAverage;
        Student curStudent;

        status = vector_Student_at(students, i, &curStudent);
        if (status != OK) return status;

        calc_student_average_score(&curStudent, &curStudentAverage);

        if (curStudentAverage > averageScore) {
            status = vector_Student_push_back(result, curStudent);
            if (status != OK) return status;
        }
    }

    return OK;
}

void fwrite_botans(FILE* outputFile, Vector_Student *botans) {
    for (int i = 0; i < vector_Student_size(botans); i++) {
        Student curBotan;
        vector_Student_at(botans, i, &curBotan);

        fprintf(outputFile, "%s %s\n", curBotan.firstName, curBotan.lastName);
    }
}



Status students_sort(Vector_Student *students, int (*comp)(const void*, const void*)) {
    qsort(students->data, vector_Student_size(students), sizeof(Student), comp);
}

int comp_students_by_id(const void* student1, const void* student2) {
    const Student* s1 = (const Student*)student1;
    const Student* s2 = (const Student*)student2;
    
    if (s1->id < s2->id) return -1;
    if (s1->id > s2->id) return 1;
    return 0;
}

int comp_students_by_first_name(const void* student1, const void* student2) {
    const Student* s1 = (const Student*)student1;
    const Student* s2 = (const Student*)student2;
    
    return strcmp(s1->firstName, s2->firstName);
}

int comp_students_by_last_name(const void* student1, const void* student2) {
    const Student* s1 = (const Student*)student1;
    const Student* s2 = (const Student*)student2;
    
    return strcmp(s1->lastName, s2->lastName);
}

int comp_students_by_group_number(const void* student1, const void* student2) {
    const Student* s1 = (const Student*)student1;
    const Student* s2 = (const Student*)student2;
    
    return strcmp(s1->groupNumber, s2->groupNumber);
}