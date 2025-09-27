#include "../include/prime_search.h"
#include "../include/error_manager.h"
#include <stdlib.h>

int get_n_prime(int n){
    int primeCount = 0;
    int num = 1;
    while(primeCount < n){
        num++;
        if(is_prime(num)){
            primeCount++;
        }
    }
    return num;
}
int is_prime(int n) {
    n = abs(n);
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
void set_prime_array(int **array, int size){
    int num = 2;
    int curPrimeAmo = 0;
    while(curPrimeAmo < size){
        if(is_prime(num)){
            *(*array + curPrimeAmo) = num;
            curPrimeAmo++;
        }
        num++;
    }
}
int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}