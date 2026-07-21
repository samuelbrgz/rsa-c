#include <stdio.h>
#include <string.h>
#include "rsa.h"

int main(){
    char lixocab[100];
    char nomeprmt[100];
    char mensagem[MSG];
    unsigned long long cifra[MSG];
    long long int valor;
    PublicKey pbk;
    pbk.e = 0;
    pbk.n = 0;

    FILE* arquivo = fopen("arquivos/precodificação.csv", "r");
    if(arquivo == NULL){
        printf("falha ao abrir o arquivo!");
        return 1;
    }
    

    fgets(lixocab, sizeof(lixocab), arquivo);

    while(fscanf(arquivo, "%[^;] ; %lld\n",nomeprmt, &valor)==2){

        if (nomeprmt[0]== 'E')
        {
            pbk.e = valor;
        } else if (nomeprmt[0]== 'N')
        {
            pbk.n = valor;
        }
    }

    fclose(arquivo);

    if (pbk.e == 0 || pbk.n == 0) {
        printf("\n[ERRO CRITICO] Chave Publica incompleta ou corrompida no arquivo!\n");
        printf("Certifique-se de que os parametros 'E' e 'N (pub)' existem e sao validos.\n");
        printf("Rode a pre-codificacao novamente.\n");
        return 1;
    }

    printf("\n==================== codificacao ====================\n");
    printf("Qual mensagem deseja cifrar?\n");
    if (fgets(mensagem, sizeof(mensagem), stdin) != NULL){
        mensagem[strcspn(mensagem, "\n")] = 0;
    }

    int tamanho = cifrarTexto(mensagem, cifra, pbk);

    printf("\n[MENSAGEM CIFRADA]: \n");

    for(int i = 0; i < tamanho; i++){
        printf("%llu ", cifra[i]);
    }
    printf("\n=====================================================\n");

    arquivo = fopen("arquivos/codificação.csv", "w");
    fprintf(arquivo, "==== Mensagem Original ====\n");
    fprintf(arquivo, "%s\n", mensagem);
    fprintf(arquivo, "==== Mensagem Cifrada ====\n");
    for(int i = 0; i < tamanho; i++){
        fprintf(arquivo, "%llu\n", cifra[i]);
    }
    fprintf(arquivo, "==== Tamanho ====\n");
    fprintf(arquivo, "%d\n", tamanho);

    fclose(arquivo);

    return 0;
}