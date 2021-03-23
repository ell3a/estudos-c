#include "robo.h"

/*
    Protótipos de todas as funções do ambiente.
*/

void preparar_ambiente(int matriz[][DIMENCAO]);
void alterar_posicao_robo(int matriz[][DIMENCAO], int x, int y, int a, int b);
void inserir_lixeira(int matriz[][DIMENCAO], int i, int j);
void inserir_garrafa(int matriz[][DIMENCAO], int i, int j);
void inserir_robo(int matriz[][DIMENCAO], int i, int j);
void criar_ambiente(int matriz[][DIMENCAO]);
void imprimir_ambiente(int matriz[][DIMENCAO]);
