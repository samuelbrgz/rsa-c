#include <stdio.h>
#include <string.h>
#include "rsa.h"

int main(){
    PrivKey pvk;
    char nomeprmt[100];
    char lixocab[100];
    unsigned long long mensagem[MSG];
    char msgdcf [MSG] ;
    char msgorig[MSG] = "";
    char linhatmp[MSG];

    int tamanho;
    long long int valor;

    pvk.d = 0;
    pvk.n = 0;

    FILE* arquivo = fopen("arquivos/precodificação.csv", "r");
    if(arquivo == NULL){
        printf("falha ao abrir o arquivo!");
        return 1;
    }
    

    fgets(lixocab, sizeof(lixocab), arquivo);

    while(fscanf(arquivo, "%[^;] ; %lld\n",nomeprmt, &valor)==2){

        if (nomeprmt[0]== 'D')
        {
            pvk.d = valor;
        } else if (nomeprmt[0]== 'N')
        {
            pvk.n = valor;
        }
    }
    fclose(arquivo);

    if (pvk.d == 0 || pvk.n == 0) {
        printf("\n[ERRO CRITICO] Chave Publica incompleta ou corrompida no arquivo!\n");
        printf("Certifique-se de que os parametros 'E' e 'N (pub)' existem e sao validos.\n");
        printf("Rode a pre-codificacao novamente.\n");
        return 1;
    }

    arquivo = fopen("arquivos/codificação.csv", "r");
    fgets(lixocab, sizeof(lixocab), arquivo);

    while (fgets(linhatmp, sizeof(linhatmp), arquivo) != NULL){
        if (strncmp(linhatmp, "==== Mensagem Cifrada", 21)==0)
        {
            break;
        }
        linhatmp[strcspn(linhatmp, "\n")] = '\0';
        strcat(msgorig, linhatmp);
    }

    int tamanho_msg = 0;
    while (fscanf(arquivo, "%llu", &mensagem[tamanho_msg]) == 1) {
        tamanho_msg++; 
    }
    fclose(arquivo);
    decifrarTexto(mensagem, msgdcf, tamanho_msg, pvk);

    printf("\n=================== decodificacao ===================\n");
    printf("\n[MENSAGEM CIFRADA]: \n");

    for(int i = 0; i < tamanho_msg; i++){
        printf("%llu ", mensagem[i]);
    }
    printf("\n[MENSAGEM DECIFRADA]: \n");

    for(int i = 0; i < tamanho_msg; i++){
        printf("%d ", msgdcf[i]);
    }
    printf("\n=\n");
    printf("%s\n", msgdcf);

    if (strncmp(msgorig, msgdcf, MSG) == 0) {
        printf("SUCESSO ABSOLUTO! A mensagem decifrada e identica a original.\n");
    } else {
        printf("ALERTA! As mensagens estao diferentes.\n");
        printf("Original:  \"%s\"\n", msgorig);
        printf("Decifrada: \"%s\"\n", msgdcf);
    }
    
    printf("\n=====================================================\n");

    arquivo = fopen("arquivos/decodificação.csv", "w");
    fprintf(arquivo, "==== Mensagem Decifrada (string) ====\n");
    fprintf(arquivo, "%s\n", msgdcf);
    fprintf(arquivo, "==== Mensagem Decifrada ====\n");
    for(int i = 0; i < tamanho_msg; i++){
        fprintf(arquivo, "%d\n", msgdcf[i]);
    }

    fclose(arquivo);

    return 0;
}