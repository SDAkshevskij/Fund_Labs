#include <stdio.h>
#include <stdlib.h>
#include "../include/string_helper.h"
#include "../include/number_process.h"
#include "../include/error_manager.h"

int main(int argc, char* argv[]) {
    if(argc != 3){
        print_error(WRONG_ARGUMENT_AMOUNT);
        return WRONG_ARGUMENT_AMOUNT;
    }
    Error er;
    if((is_integer(argv[1]) && is_flag(argv[2])) || (is_flag(argv[1])) && is_integer(argv[2])){
        int x;
        char* flag;
        if(is_integer(argv[1]) && is_flag(argv[2])){
            x = atoi(argv[1]);
            flag = argv[2];
        }
        else{
            x = atoi(argv[2]);
            flag = argv[1];
        }
        switch(flag[1]){
            case 'h':
                int* multiples = get_multiples(x);
                if(multiples == NULL){
                    print_error(MEMORY_ALLOCATION_ERROR);
                    return MEMORY_ALLOCATION_ERROR;
                }
                print_multiples(multiples);
                free(multiples);
                break;
            case 'p':
                if(is_prime(x)){
                    printf("Number %d is prime\n", x);
                }
                else{
                    printf("Number %d is composite\n", x);
                }
                break;
            case 's':
                char* hex;
                if(er = to_hex(x, &hex)){
                    print_error(er);
                    return er;
                }
                print_hex(hex);
                free(hex);
                break;
            case 'e':
                if(x > 10){
                    print_error(TOO_LARGE_NUMBER);
                    return TOO_LARGE_NUMBER;
                }
                if(x < 1){
                    print_error(NON_NATURAL_NUMBER);
                    return NON_NATURAL_NUMBER;
                }
                print_table_of_degrees(x);
                break;
            case 'a':
                int prefSum;
                if(er = calc_pref_sum(x, &prefSum)){
                    print_error(er);
                    return er;
                }
                printf("%d\n", prefSum);
                break;
            case 'f':
                int fact;
                if(er = factorial(x, &fact)){
                    print_error(er);
                    return er;
                }
                printf("%d\n", fact);
                break;
            default:
                print_error(WRONG_FLAG);
                break;
        }
    }
    else {
        printf("Error: wrong values type input, expected: <x> <flag>\n");
    }
    return OK;
}