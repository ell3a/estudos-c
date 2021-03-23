#include <stdio.h>
#include "comandos.h"

//trabalha com arquivos (lugar da memória que indica onde há um aquivo)
FILE * abrir_arquivo(FILE *x) {
    x = fopen("log.out", "w");
    return x;
}

FILE * escrever_no_arquivo(FILE *x, char y) {
    fprintf(x, "%c", y);
    return x;
}

//retono 0 (recebe como parametro um arquivo e uma lista)
void escrever_comandos_no_arquivo(FILE *x, lista *l) {

    char comando;
    if (l == NULL) return;

    comando = l->comando;
    x = escrever_no_arquivo(x, comando);
    x = escrever_no_arquivo(x, '\n');

    escrever_comandos_no_arquivo(x, l->proximo);
}

/*abre o arquivo, escreve os comando recebidos pelo o robô e fecha o 
arquivo no final*/
void criar_arquivo(FILE *arq, lista *comandos) {
    arq = abrir_arquivo(arq);
    escrever_comandos_no_arquivo(arq, comandos);
    fclose(arq);
}
