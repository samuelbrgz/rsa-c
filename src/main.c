#include <stdio.h>
#include "rsa.h"

int main(void){

    long long int teste = expmod(12, 391, 3);
    long long int teste1 = invmod(352, 3);
    printf("resultado: crip: %lld inv mod: %lld\n ", teste, teste1);
    return 0;
    
}