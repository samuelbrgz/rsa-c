#include <stdio.h>
#include <string.h>
#include "rsa.h"

int main(){
    long long int p;
    long long int q;
    Params prmts;

 

    printf("\n╔═══════════════ PRE-CODIFICACAO ═══════════════╗\n");
    
    genParams(&prmts);
    PublicKey pbk = genPubk(&prmts);
    PrivKey pvk = genPrivk(&prmts, &pbk);

    if (pvk.d == 0)
    {
        printf("\n[ERRO] expoente E (%lld) nao possui inverso modular em relacao a Phi (%lld)\n", prmts.e, prmts.phi);
        printf("MDC(E, PHI) tem que ser igual a 1, tente outros valores.\n");
        printf("=====================================================\n");
        return 1;
    }


    FILE *arquivo = fopen("arquivos/precodificação.csv", "w");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return 1;
    }


    fprintf(arquivo,"PARAMETRO ; VALOR\n");
    fprintf(arquivo,"P         ; %lld\n", prmts.p);
    fprintf(arquivo,"Q         ; %lld\n", prmts.q);
    fprintf(arquivo,"E         ; %lld\n", prmts.e);
    fprintf(arquivo,"PHI       ; %lld\n", prmts.phi);
    fprintf(arquivo,"N (pub)   ; %lld\n", pbk.n);
    fprintf(arquivo,"D (priv)  ; %lld\n", pvk.d);
    
    fclose(arquivo);
    
    printf("\n[OK] Chaves geradas e salvas em 'precodificacao.csv'\n");
    printf("╚═══════════════════════════════════════════════╝\n");

}