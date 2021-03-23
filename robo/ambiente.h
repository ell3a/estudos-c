#include "funcoes_ambiente.h"
//Chamada no case 1 do main
void preparar_ambiente(int matriz[][DIMENCAO]) {

    int i;
    int n = OBJETOS;
//onde robo começa destro da matriz(mudar aqui para a posição diferente do robo)
    criar_ambiente(matriz);
    inserir_robo(matriz, DIMENCAO/2, DIMENCAO/2);

    for(i = 1; i < n+1; i++) {
        inserir_lixeira(matriz, ((i+7)*311), i*31);
        inserir_garrafa(matriz, (i*37), ((i+5)*751));
    }
}
//definindo o funcionamento da função
void inserir_robo(int matriz[][DIMENCAO], int linha, int coluna) {

    if(matriz[linha][coluna] == 0) matriz[linha][coluna] = 1;
    else inserir_robo(matriz, linha+1, coluna+1);
}
//função que altera o comportamento do robo
void alterar_posicao_robo(int matriz[][DIMENCAO], int x, int y, int a, int b) {
    matriz[x][y] = 0;
    matriz[a][b] = 1;
}
/*função que insere uma lixeira, primeiro ela busca um lugar fazio, 
caso isso não seja possível ela segue os criterios a seguir*/
void inserir_lixeira(int matriz[][DIMENCAO], int linha, int coluna) {
    if(matriz[linha%DIMENCAO][coluna%DIMENCAO] == 0) matriz[linha%DIMENCAO][coluna%DIMENCAO] = 2;
    else inserir_lixeira(matriz, linha+9, coluna+6);
}
/*"inserir_garrafa" insere garrafa e obstáculo, motivo disso era a falha 
no segmento da memória*/
void inserir_garrafa(int matriz[][DIMENCAO], int linha, int coluna) {
    if(matriz[linha%DIMENCAO][coluna%DIMENCAO] == 0) {
        matriz[linha%DIMENCAO][coluna%DIMENCAO] = 3;
        matriz[(linha+1)%DIMENCAO][coluna%DIMENCAO] = 4; 
    }
    else inserir_garrafa(matriz, linha+7, coluna+9);
}
//sempre será chamda para mostrar o estado do ambiente
void criar_ambiente(int matriz[][DIMENCAO]) {
	for (int i = 0; i < DIMENCAO; i++) {
		for (int j = 0; j < DIMENCAO; j++) {
			matriz[i][j] = 0;
		}
	}
}
//mostra ambiente com as posições de cada elemento 
void imprimir_ambiente(int matriz[][DIMENCAO]) {
	for (int i = 0; i < DIMENCAO; i++) {
		for (int j = 0; j < DIMENCAO; j++) {
			switch (matriz[i][j]) {
                case 0:
                    printf("_ ");
                    break;

                case 1:
                    printf("R ");
                    break;

                case 2:
                    printf("L ");
                    break;

                case 3:
                    printf("G ");
                    break;

                case 4:
                    printf("O ");
                    break;

            }
		}
	    printf("\n");
	}
}
