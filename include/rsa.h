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
Params genParams(unsigned long long int p, unsigned long long int q, unsigned long long int e);
unsigned long long int invmod(Params p);
PublicKey genPubk(Params p);
PrivKey genPrivk(Params p, PublicKey pk);

#endif