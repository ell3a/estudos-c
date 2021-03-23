#include "funcoes_robo.h"
//construções das Funções do robo

//retorna o um ponterio com o tipo de dado robo
robo * iniciar_robo(robo *x, int l, int c) {
    if(x == NULL) {
        x = (robo *)malloc(sizeof(robo));
        x->linha_inicial = l%DIMENCAO;
        x->coluna_inicial = c%DIMENCAO;

        x->linha = l%DIMENCAO;
        x->coluna = c%DIMENCAO;
        x->carga = 0;
        x->comandos = NULL;
        x->comandos = inserir_comando(x->comandos, 'i');
    }
    return x;
}

//retorna um ponterio para robo e recebe um robo
robo * para_frente(robo *x) {
    if(x == NULL) return x;
    else {
        if(x->linha-1 < 0) x->linha = DIMENCAO - 1;
        else x->linha = (x->linha-1)%DIMENCAO;
        x->comandos = inserir_comando(x->comandos, 'f');
    }
    return x;
}
//retorna um ponterio para robo e recebe um r
robo * para_atras(robo *x) {
    if(x == NULL) return x;
    else {
        x->linha = (x->linha+1)%DIMENCAO;
        x->comandos = inserir_comando(x->comandos, 'a');
    }
    return x;
}
//retorna um ponterio para robo e recebe um r
robo * para_direita(robo *x) {
    if(x == NULL) return x;
    else {
        x->coluna = (x->coluna+1)%DIMENCAO;
        x->comandos = inserir_comando(x->comandos, 'd');
    }
    return x;
}
//retorna um ponterio para robo e recebe um r
robo * para_esquerda(robo *x) {
    if(x == NULL) return x;
    else {
        if(x->coluna-1 < 0) x->coluna = DIMENCAO - 1;
        else x->coluna = (x->coluna-1)%DIMENCAO;
        x->comandos = inserir_comando(x->comandos, 'e');
    }
    return x;
}

void imprimir_estado_robo(robo *x) {
    if(x == NULL) printf("Robo fora do ambiente!\n");
    else {
        printf("Posicao inicial: A[%i][%i].\n", x->linha_inicial, x->coluna_inicial);
        printf("Posicao atual A[%i][%i], carga %i.\nComandos: ", x->linha, x->coluna, x->carga);
        imprimir_comandos(x->comandos);
        printf(".\n");
    }
}