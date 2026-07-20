#include <stdio.h>
#include <string.h>
#include "rsa.h"

int main(void){

    printf("########## Criptografia RSA ##########\n");
    unsigned long long int p = 17;
    unsigned long long int q = 23;
    unsigned long long int e = 3;

    Params pa = genParams(p, q, e);
    PublicKey pbk = genPubk(pa);
    PrivKey pvk = genPrivk(pa, pbk);

    char mensagem[100];
    printf("Digite o texto: ");
    fgets(mensagem, 100, stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0';
    int tamanho = strlen(mensagem);

    int numeros[100];
    char m_reconstruido[101]; 
    int criptografado[100];
    int descri[100];

    for (int i = 0; i < tamanho; i++) {
        numeros[i] = (unsigned char)mensagem[i];
    }
    printf("\n");

    for(int i = 0; i < tamanho; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("\n--- Criptografando ---\n");
    for(int i = 0; i < tamanho; i++){
        criptografado[i] = (int)criptar(numeros[i], pbk);
        printf("%d ", criptografado[i]);
    }

    printf("\n");

    printf("\n--- Descriptografando ---\n");
    for(int i = 0; i < tamanho; i++){
        descri[i] = (int)decriptar(criptografado[i], pvk);
        printf("%d ", descri[i]);
    }

    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        m_reconstruido[i] = (unsigned char)descri[i];
    }
    m_reconstruido[tamanho] = '\0';

    printf("\n--- RESULTADOS ---\n");
    printf("1. Texto digitado: %s\n", mensagem);
    printf("2. Texto de volta:  %s\n", m_reconstruido);

    /*unsigned long long int m = 12;
    unsigned long long int c = criptar(mensagem, pbk);
    unsigned long long int volta = decriptar(c, pvk);
    printf("m=%llu  cifrado=%llu  decifrado=%llu\n", mensagem, c, volta);*/

    
    return 0;
    
}