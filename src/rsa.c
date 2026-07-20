#include <stdio.h>
#include <stdlib.h>
#include "rsa.h"

unsigned long long int expmod(unsigned long long int base, unsigned long long int n, unsigned long long int e){
    
    unsigned long long int resultado = 1;

    if(base >= n){
        base%=n;
    }

    while(e > 0){
        if(e & 1){
            resultado = (resultado * base) % n;
        }

        e >>= 1;

        if(e>0){
            base =  (base * base) % n;
        }
    }

    return resultado;
}

unsigned long long int invmod(Params p){
    long long int r_ant = p.phi;
    long long int r_atual = p.e;
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
    if(t_ant < 0){t_ant += p.phi;}

    return t_ant;

}

void genParams(Params *pa){

    printf("Digite p: ");
    scanf("%lld", &pa->p);

    printf("Digite q: ");
    scanf("%lld", &pa->q);

    printf("Digite e: ");
    scanf("%lld", &pa->e);

    pa->phi = (pa->p-1)*(pa->q-1);
}

PublicKey genPubk(Params p){
    PublicKey nova;

    nova.n = (p.p*p.q);
    nova.e = p.e;

    return nova;
}

PrivKey genPrivk(Params p, PublicKey pk){
    PrivKey nova;

    nova.n = pk.n;
    nova.d = invmod(p);

    return nova;
}
unsigned long long int criptar(unsigned long long int base, PublicKey pub){
    return expmod(base, pub.n, pub.e);
}

unsigned long long int decriptar(unsigned long long int cifra, PrivKey priv){
    return expmod(cifra, priv.n, priv.d);
}

int cifrarTexto(char *msg, unsigned long long *cifra, PublicKey pub){
    int i = 0;
    while(msg[i] != '\0'){
        cifra[i] = criptar((unsigned long long)msg[i], pub);
        i++;
    }
    return i;
}

void decifrarTexto(unsigned long long *cifra, char *decifra, int tamanho, PrivKey priv){
    int i = 0;
    for(int i = 0; i < tamanho; i++){
        decifra[i] = decriptar(cifra[i], priv);
    }
    decifra[i] = '\0';
}
