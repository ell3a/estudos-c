#include "arquivo.h" //biblioteca que armazena os comandos recebidos pelo robo.

// Estrutura do robô
typedef struct r {
    //inalteráveis nessa implementação
    int linha_inicial, coluna_inicial;

    //Variam no decorrer da aplicação
    int linha;
    int coluna;
    int carga;
    lista *comandos;
} robo;

//Funções do robô
robo * iniciar_robo(robo *x, int l, int c);
robo * para_frente(robo *x);
robo * para_atras(robo *x);
robo * para_direita(robo *x);
robo * para_esquerda(robo *x);
void imprimir_estado_robo(robo *x);
