#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/error_manager.h"
#include "../include/string_helper.h"
#include "../include/prime_search.h"


int main(int argc, char* argv[]) {
    int t;
    Status er = OK;
    if(er = read_natural_integer(&t)){
        print_status(er);
        return 0;
    }
    int requestsAmo = t;
    int* requests = (int*)malloc(sizeof(int) * requestsAmo);
    if(requests == NULL){
        print_status(MEMORY_ALLOCATION_ERROR);
        return 0;
    }
    int curRequest = 0;
    int req;
    int maxReq = 0;
    while(t--){
        if(er = read_natural_integer(&req)){
            print_status(er);
            return 0;
        }
        maxReq = max(maxReq, req);
        *(requests + curRequest) = req;
        curRequest++;
    }
    int primeArraySize = min(maxReq, 10000) + 1;
    int* primeArray = (int*)malloc(sizeof(int) * primeArraySize);
    if(primeArray == NULL){
        free(requests);
        print_status(MEMORY_ALLOCATION_ERROR);
        return 0;
    }
    set_prime_array(&primeArray, primeArraySize);
    printf("Answers:\n");
    for(int i = 0; i < requestsAmo; i++){
        int request = *(requests + i);
        if(request < primeArraySize){
            printf("%d\n", *(primeArray + request - 1));
        }
        else {
            printf("%d\n", get_n_prime(request));
        }
    }
    free(requests);
    free(primeArray);
}