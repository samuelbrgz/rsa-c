#include <stdio.h>
#include <stdlib.h>
#include "rsa.h"

long long int expmod(long long int base, long long int n, long long int e){
    long long int resultado = 1;

    for(long long int i = 1; i <= e; i++){
        resultado = ((resultado * base) % n );
    }
    return resultado;
}