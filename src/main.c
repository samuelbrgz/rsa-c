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

    unsigned long long int m = 12;   // número pequeno, MENOR que n
    unsigned long long int c = criptar(m, pbk);
    unsigned long long int volta = decriptar(c, pvk);
    printf("m=%llu  cifrado=%llu  decifrado=%llu\n", m, c, volta);

    
    return 0;
    
}