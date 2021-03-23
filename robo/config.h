#include <stdio.h>
#include <stdlib.h>

#define DIMENCAO 12 //Essa é a medida do tabuleiro quadrado, deve ser modificada aqui.
#define OBJETOS 10 //Valores muito altos causam falha de segmentação de memória.

/*
Hierarquia de linquedação:

ambiente.h >> funcoes_ambiente.h >> robo.h >> funcoes_robo.h >> arquivo.h >> comandos.h >> config.h
*/