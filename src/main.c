#include <stdio.h>
#include "rsa.h"

int main(void){

    long long int teste = expmod(12, 391, 3);
    printf("resultado: %lld\n", teste);
    return 0;
    
}