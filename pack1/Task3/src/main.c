#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/error_manager.h"
#include "../include/string_helper.h"
#include "../include/number_helper.h"
#include "../include/solve.h"


int main(int argc, char* argv[]) {
    if(argc < 2){
        print_status(WRONG_ARGUMENT_AMOUNT);
        return WRONG_ARGUMENT_AMOUNT;
    }
    if(!is_flag(argv[1])){
        print_status(WRONG_FLAG);
        return WRONG_FLAG;
    }
    Error er;
    char flag = *(*(argv + 1) + 1);
    switch(flag){
        case 'q':
            if(argc != 6){
                print_status(WRONG_ARGUMENT_AMOUNT);
                return WRONG_ARGUMENT_AMOUNT;
            }
            for(int i = 2; i < 6; i++){
                if((er = check_double(argv[i])) != OK){
                    print_status(er);
                    return er;
                }
            }
            double eps = atof(argv[2]);
            double a = atof(argv[3]);
            double b = atof(argv[4]);
            double c = atof(argv[5]);
            Equation* equation_results;
            int resultsAmo;
            if((er = process_flag_q(eps, a, b, c, &equation_results, &resultsAmo)) != OK){
                print_status(er);
                return er;
            }
            for(int i = 0; i < resultsAmo; i++){
                Equation result = equation_results[i];
                printf("Coeffs: %f %f %f solutions: ", result.a, result.b, result.c);
                if(result.errorFlag == NO_SOLUTION){
                    printf("No solution\n");
                }
                else if(result.errorFlag == SOLUTION_IS_ANY_NUMBER){
                    printf("Solution is any number\n");
                }
                else if(is_double_equal(result.ans1, result.ans2, eps)){
                    printf("%f\n", equation_results[i].ans1);
                }
                else {
                    printf("%f %f\n", result.ans1, result.ans2);
                }
            }
            free(equation_results);
            break;
        case 'm':
            if(argc != 4){
                print_status(WRONG_ARGUMENT_AMOUNT);
                return WRONG_ARGUMENT_AMOUNT;
            }
            if((er = check_integer(argv[2])) != OK){
                print_status(er);
                return er;
            }
            if((er = check_integer(argv[3])) != OK){
                print_status(er);
                return er;
            }
            int num1 = abs(atoi(argv[2]));
            int num2 = abs(atoi(argv[3]));
            er = is_multiple(num1, num2);
            if(er == OK){
                printf("%d is multiple to %d\n", num1, num2);
            }
            else if(er == NOT_OK){
                printf("%d is not multiple to %d\n", num1, num2);
            }
            else if(er == NUMBER_IS_ZERO){
                print_status(NUMBER_IS_ZERO);
                return NUMBER_IS_ZERO;
            }
            break;
        case 't':
            if(argc != 6){
                print_status(WRONG_ARGUMENT_AMOUNT);
                return WRONG_ARGUMENT_AMOUNT;
            }
            for(int i = 2; i < 6; i++){
                if((er = check_double(argv[i])) != OK){
                    print_status(er);
                    return er;
                }
            }
            eps = atof(argv[2]);
            a = atof(argv[3]);
            b = atof(argv[4]);
            c = atof(argv[5]);
            er = is_right_triangle(eps, a, b, c);
            if(er == OK){
                printf("right triangle\n");
            }
            else if(er == NOT_OK){
                printf("triangle is not right\n");
            }
            else if(er == NUMBER_IS_ZERO){
                print_status(NUMBER_IS_ZERO);
                return er;
            }
            else if(er == NEGATIVE_NUMBER){
                print_status(NEGATIVE_NUMBER);
                return er;
            }
            break;
        default:
            print_status(UNKNOWN_FLAG);
            return UNKNOWN_FLAG;
    }
    return OK;
}