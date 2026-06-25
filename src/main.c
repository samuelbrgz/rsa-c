#include <stdio.h>
#include "rsa.h"

int main(void){

    printf("Teste/n");
    unsigned long long int p = 17;
    unsigned long long int q = 23;
    unsigned long long int e = 3;

    Params pa = genParams(p, q, e);
    PublicKey pbk = genPubk(pa);
    PrivKey pvk = genPrivk(pa, pbk);

    printf("n = %llu, e = %llu, d = %llu\n", pbk.n, pbk.e, pvk.d);


    
    return 0;
    
}