#ifndef RSA_H
#define RSA_H

//tipos

typedef struct PublicKey{
    unsigned long long int n;
    unsigned long long int e;
}publicKey;

typedef struct PrivKey{
    unsigned long long int n;
    unsigned long long int d;
}privKey;

typedef struct Parameters{
    unsigned long long int p;
    unsigned long long int q;
    unsigned long long int phi;
} parameters;



//funcs
unsigned long long int expmod(unsigned long long int base, unsigned long long int n, unsigned long long int e);
unsigned long long int invmod(unsigned long long int phi, unsigned long long int e);
publicKey genpubk(unsigned long long int p, unsigned long long int q, unsigned long long int e);
publicKey genprivk(unsigned long long int phi, unsigned long long int e);

#endif