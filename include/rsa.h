#ifndef RSA_H
#define RSA_H

//tipos

typedef struct {
    unsigned long long int n;
    unsigned long long int e;
}PublicKey;

typedef struct {
    unsigned long long int n;
    unsigned long long int d;
}PrivKey;

typedef struct {
    unsigned long long int p;
    unsigned long long int q;
    unsigned long long int e;
    unsigned long long int phi;
} Params;



//funcs
unsigned long long int expmod(unsigned long long int base, unsigned long long int n, unsigned long long int e);
void genParams(Params *pa);
unsigned long long int invmod(Params p);
PublicKey genPubk(Params p);
PrivKey genPrivk(Params p, PublicKey pk);
unsigned long long int criptar(unsigned long long int base, PublicKey pub);
unsigned long long int decriptar(unsigned long long int cifra, PrivKey priv);
int cifrarTexto(char *msg, unsigned long long *cifra, PublicKey pub);
void decifrarTexto(unsigned long long *cifra, char *decifra, int tamanho, PrivKey priv);

#endif