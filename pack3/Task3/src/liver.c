#include "../include/liver.h"
#include "../include/string_manager.h"
#include "../include/file_manager.h"
#include <ctype.h>
#include <string.h>
#include <math.h>

int liver_compare_without_id(Liver *l1, Liver *l2) {
    int res;
    if ((res = strcmp(l1->firstName, l2->firstName)) != 0) {
        return res;
    }
    if ((res = strcmp(l1->lastName, l2->lastName)) != 0) {
        return res;
    }
    if ((res = strcmp(l1->surName, l2->surName)) != 0) {
        return res;
    }
    if ((res = date_compare(&l1->birthDate, &l2->birthDate)) != 0) {
        return res;
    }
    if ((res = l1->gender - l2->gender) != 0) {
        return res;
    }
    if (fabs(l1->income - l2->income) >= 0.0000001) {
        return -1;
    }
    return 0;
}

int liver_compare_with_id(Liver *l1, Liver *l2) {
    if (l1->id != l2->id) {
        return l1->id - l2->id;
    }
    return liver_compare_without_id(l1, l2);
}

int liver_compare_by_id(Liver *l1, Liver *l2) {
    if (l1->id == l2->id) return 0;

    return l1->id - l2->id;
}

int liver_compare_by_date(Liver *l1, Liver *l2) {
    if (l1->birthDate.year == l2->birthDate.year) {
        if (l1->birthDate.mount == l2->birthDate.mount) {
            return l2->birthDate.day - l1->birthDate.day;
        }
        return l2->birthDate.mount - l1->birthDate.mount;
    }
    return l2->birthDate.year - l1->birthDate.year;
}

int date_compare(Date *d1, Date *d2) {
    if (d1->day != d2->day) {
        return d1->day - d2->day;
    }
    if (d1->mount != d2->mount) {
        return d1->mount - d2->mount;
    }
    return d1->year - d2->year;
}

Status validate_Liver(Liver *liver) {
    Status status = validate_Date(&liver->birthDate);
    if (status != OK) return status;

    if (liver->gender != 'M' && liver->gender != 'W') return THIRD_GENDER;

    return OK;
}

Status validate_Date(Date *date) {
    if (date == NULL) return NULL_VALUE;
    if (date->year < 1000 || date->year > 2025) return INVALID_DATE;
    if (date->mount < 1 || date->mount > 12) return INVALID_DATE;
    
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (date->mount == 2) {
        int febDays = 28;
        if ((date->year % 4 == 0 && date->year % 100 != 0) || (date->year % 400 == 0)) {
            febDays = 29;
        }
        if (date->day > febDays) return INVALID_DATE;
    } 
    else {
        if (date->day > days_in_month[date->mount - 1]) return INVALID_DATE;
    }
    
    return OK;
}

Status validate_name(char *name) {
    if (is_empty_string(name)) return EMPTY_STRING;

    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            return INVALID_CHARACTER;
        }
    }
    return OK;
}

void fprint_liver(FILE* outputFile, Liver *liver) {
    fprintf(outputFile, "%d %s %s %s %d %d %d %c %lf\n", liver->id, 
        liver->firstName, liver->lastName, liver->surName, liver->birthDate.day, 
        liver->birthDate.mount, liver->birthDate.year, liver->gender, liver->income);
}

Liver fread_liver(FILE* inputFile, Status *status) {
    Liver liver;
    *status = fread_natural_integer(inputFile, &liver.id);
    if (*status != OK) {
        return liver;
    }

    *status = fread_word(inputFile, &liver.firstName);
    if (*status != OK) {
        return liver;
    }

    *status = fread_word(inputFile, &liver.lastName);
    if (*status != OK) {
        return liver;
    }

    int haveSurName = 1;

    *status = fread_word(inputFile, &liver.surName);
    if (*status != OK) return liver;

    if (isdigit(*liver.surName)) {
        *status = string_to_int(liver.surName, &liver.birthDate.day);
        liver.surName = "";
        haveSurName = 0;
        if (*status != OK) {
            return liver;
        }
    }
    
    Date date;
    if (haveSurName) {
        *status = fread_natural_integer(inputFile, &date.day);
        if (*status != OK) return liver;
    }
    else {
        date.day = liver.birthDate.day;
    }

    *status = fread_natural_integer(inputFile, &date.mount);
    if (*status != OK) return liver;

    *status = fread_natural_integer(inputFile, &date.year);
    if (*status != OK) return liver;

   liver.birthDate = date;


    *status = fread_non_space_symb(inputFile, &liver.gender);
    if (*status != OK) return liver;

    *status = fread_float(inputFile, &liver.income);
    if (*status != OK && *status != END_OF_INPUT) return liver;

    Status validateStatus = validate_Liver(&liver);
    if (validateStatus != OK) *status = validateStatus;
     
    return liver;
}

Date fread_date(FILE *inputFile, Status *status) {
    Date date;
    *status = fread_natural_integer(inputFile, &date.day);
    if (*status != OK) return date;

    *status = fread_natural_integer(inputFile, &date.mount);
    if (*status != OK) return date;

    *status = fread_natural_integer(inputFile, &date.year);
    if (*status != OK) return date;

    *status = OK;
    return date;
}
