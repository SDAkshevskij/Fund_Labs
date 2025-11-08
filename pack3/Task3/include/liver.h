#ifndef LIVER_H
#define LIVER_H
#include "stdio.h"
#include "status_manager.h"

typedef struct {
    int year;
    int mount;
    int day;
} Date;

typedef struct {
    int id;
    char *firstName;
    char *lastName;
    char *surName;
    Date birthDate;
    char gender;
    double income;

} Liver;

int liver_compare_without_id(Liver *l1, Liver *l2);
int liver_compare_with_id(Liver *l1, Liver *l2);
int liver_compare_by_id(Liver *l1, Liver *l2);
int liver_compare_by_date(Liver *l1, Liver *l2);

int date_compare(Date *d1, Date *d2);

Status validate_Liver(Liver *liver);
Status validate_Date(Date *date);
Status validate_name(char *name);

void fprint_liver(FILE* outputFile, Liver *liver);

Liver fread_liver(FILE* inputFile, Status *status);
Date fread_date(FILE *inputFile, Status *status);



#endif