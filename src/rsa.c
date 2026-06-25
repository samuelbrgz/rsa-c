#include <stdio.h>
#include <stdlib.h>
#include "rsa.h"

unsigned long long int expmod(unsigned long long int base, unsigned long long int n, unsigned long long int e){
    unsigned long long int resultado = 1;

    for(unsigned long long int i = 1; i <= e; i++){
        resultado = ((resultado * base) % n );
    }
    return resultado;
}

unsigned long long int invmod(unsigned long long int phi, unsigned long long int e){
    long long int r_ant = phi;
    long long int r_atual = e;
    long long int t_ant = 0;
    long long int t_atual = 1;

    while(r_atual != 0){
        long long int q = (long long int)(r_ant/r_atual);

        long long int novo_r = r_ant - (q*r_atual);
        long long int novo_t = t_ant - (q*t_atual);

        r_ant   = r_atual;
        r_atual = novo_r;
        t_ant   = t_atual;
        t_atual = novo_t;

        
    };

    if(r_ant != 1){return 0;}
    if(t_ant < 0){t_ant += phi;}

    return t_ant;

}

publicKey genpubk(unsigned long long int p, unsigned long long int q, unsigned long long int e){
    publicKey nova;
    nova.n = (p*q);
    nova.e = e;

    return nova;
}
