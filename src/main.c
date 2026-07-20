#include <stdio.h>
#include <string.h>
#include "rsa.h"

#define TAM 1024

int main(void){
    char mensagem[TAM];
    unsigned long long cifra[TAM];
    char decifra;

    Params params;
    genParams(&params);

    PublicKey pub = genPubk(params);
    PrivKey priv = genPrivk(params, pub);

    printf("Digite a mensagem que deseja criptografar: ");
    scanf("%s", mensagem);

    int tamanho = cifrarTexto(mensagem, cifra, pub);


    
    return 0;
    
}