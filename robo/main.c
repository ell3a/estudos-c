#include <stdio.h>
#include "ambiente.h"

int main(int argc, char const *argv[]) {

    int ambiente[DIMENCAO][DIMENCAO];
    int entrada, opcao;
    int linha_entrada, coluna_entrada;
    int ambiente_prepado = 0;
    
    //tipo de arquivo
    FILE *arquivo;
    
    //onde robo começa dentro da matriz(mudar aqui para a posição diferente do robo)
    linha_entrada = DIMENCAO/2; coluna_entrada = DIMENCAO/2;
    
    //ponteiro separando um espaço na memória
    robo *x = NULL;
    
    //mostra o ambiente (o menu das funcões do projeto)
    while (1==1) {

        printf("\nDigite:\n\n   1 - para preparar o ambiente;\n");
        printf("   2 - para mostrar ambiente;\n");
        printf("   3 - para mostrar estado do robo;\n");
        //comando de movimentação do robo
        printf("\n   10 - para mover o robo uma casa para direita;\n");
        printf("   20 - para mover o robo uma casa para esquerda;\n");
        printf("   30 - para mover o robo uma casa para frente;\n");
        printf("   40 - para mover o robo uma casa para atras;\n");

        printf("\n   999 - para encerrar o programa.\n\n");

        printf("Entrada: ");
        scanf("%i", &entrada);
        //função preparar ambiente inserida
        switch (entrada) {
            case 1:

                if(ambiente_prepado == 0) {
                    x = iniciar_robo(x, DIMENCAO/2, DIMENCAO/2);
                    preparar_ambiente(ambiente);
                    ambiente_prepado = 1;
                    printf("Ambiente preparado.\n");
                    imprimir_ambiente(ambiente);

                } else {
                    printf("Ambiente ja preparado. Deseja reiniciar o ambiente atual?\n");
                    printf("Digite 0 para nao ou 1 para sim: ");
                    scanf("%i", &opcao);
                    switch (opcao) {
                        case 0:
                            break;
                        case 1:
                            x = iniciar_robo(x, DIMENCAO/2, DIMENCAO/2);
                            preparar_ambiente(ambiente);
                            ambiente_prepado = 1;
                            printf("Ambiente reiniciado.\n");
                            break;
                    }
                }
                break;

            case 2:
                if(ambiente_prepado == 0) {
                    printf("Ambiente ainda nao preparado.\n");
                    break;
                } else {
                    printf("\n");
                    imprimir_ambiente(ambiente);
                    break;
                }

            case 3:
                if(ambiente_prepado == 0) {
                    printf("Ambiente ainda nao preparado.\n");
                    break;
                } else {
                    imprimir_estado_robo(x);
                    break;
                }
            /* movimentos do robô e possiveis consequência dos movimentos(como pegar 
            garrafas, encontar um bostáculo, espaço vazio que será ocupado, etc)*/
            case 10:
                if(ambiente_prepado == 0) {
                    printf("Ambiente ainda nao preparado.\n");
                    break;
                } else {
                    switch (ambiente[linha_entrada][coluna_entrada+1]) {

                        case 0:
                            alterar_posicao_robo(ambiente, linha_entrada, coluna_entrada, linha_entrada, coluna_entrada+1);
                            x = para_direita(x);
                            coluna_entrada++;
                            break;

                        case 2:
                            if(x->carga == 1) {
                                x->carga = 0;
                                x = para_direita(x);
                                coluna_entrada++;
                                x->comandos = inserir_comando(x->comandos, 'Q');
                                x = para_esquerda(x);
                                coluna_entrada--;
                                printf("\nCarga esvaziada.\n");
                                break;
                            } else {
                                x = para_direita(x);
                                coluna_entrada++;
                                x->comandos = inserir_comando(x->comandos, 'S');
                                x = para_esquerda(x);
                                coluna_entrada--;
                                printf("\nRobo sem carga.\n");
                                break;
                            }

                        case 3:
                            if(x->carga == 0) {
                                alterar_posicao_robo(ambiente, linha_entrada, coluna_entrada, linha_entrada, coluna_entrada+1);
                                x = para_direita(x);
                                coluna_entrada++;
                                x->comandos = inserir_comando(x->comandos, 'G');
                                x->carga = 1;
                                printf("\nGarrafa captada.\n");
                                break;

                            } else {
                                x = para_direita(x);
                                coluna_entrada++;
                                x = para_esquerda(x);
                                x->comandos = inserir_comando(x->comandos, 'T');
                                coluna_entrada--;
                                printf("\nRobo com Garrafa.\n");
                                break;
                            }

                        case 4:
                            x = para_direita(x);
                            coluna_entrada++;
                            x->comandos = inserir_comando(x->comandos, 'O');
                            x = para_esquerda(x);
                            coluna_entrada--;
                            printf("\nObstaculo, robo nao pode avancar!\n");
                            break;

                    }

                }
                imprimir_ambiente(ambiente);
                break;

            case 20:
                if(ambiente_prepado == 0) {
                    printf("Ambiente ainda nao preparado.\n");
                    break;
                } else {
                    switch (ambiente[linha_entrada][coluna_entrada-1]) {

                        case 0:
                            alterar_posicao_robo(ambiente, linha_entrada, coluna_entrada, linha_entrada, coluna_entrada-1);
                            x = para_esquerda(x);
                            coluna_entrada--;
                            break;

                        case 2:
                            if(x->carga == 1) {
                                x->carga = 0;
                                x = para_esquerda(x);
                                coluna_entrada--;
                                x->comandos = inserir_comando(x->comandos, 'Q');
                                x = para_direita(x);
                                coluna_entrada++;
                                printf("\nCarga esvaziada.\n");
                                break;
                            } else {
                                x = para_esquerda(x);
                                coluna_entrada--;
                                x->comandos = inserir_comando(x->comandos, 'S');
                                x = para_direita(x);
                                coluna_entrada++;
                                printf("\nRobo sem carga.\n");
                                break;
                            }

                        case 3:
                            if(x->carga == 0) {
                                alterar_posicao_robo(ambiente, linha_entrada, coluna_entrada, linha_entrada, coluna_entrada-1);
                                x = para_esquerda(x);
                                coluna_entrada--;
                                x->comandos = inserir_comando(x->comandos, 'G');
                                x->carga = 1;
                                printf("\nGarrafa captada.\n");
                                break;

                            } else {
                                x = para_esquerda(x);
                                coluna_entrada--;
                                x = para_direita(x);
                                x->comandos = inserir_comando(x->comandos, 'T');
                                coluna_entrada++;
                                printf("\nRobo com Garrafa.\n");
                                break;
                            }

                        case 4:
                            x = para_esquerda(x);
                            coluna_entrada--;
                            x->comandos = inserir_comando(x->comandos, 'O');
                            x = para_direita(x);
                            coluna_entrada++;
                            printf("\nObstaculo, robo nao pode avancar!\n");
                            break;
                    }
                }
                imprimir_ambiente(ambiente);
                break;

            case 30:
                if(ambiente_prepado == 0) {
                    printf("Ambiente ainda nao preparado.\n");
                    break;
                } else {
                    switch (ambiente[linha_entrada-1][coluna_entrada]) {

                        case 0:
                            alterar_posicao_robo(ambiente, linha_entrada, coluna_entrada, linha_entrada-1, coluna_entrada);
                            x = para_frente(x);
                            linha_entrada--;
                            break;

                        case 2:
                            if(x->carga == 1) {
                                x->carga = 0;
                                x = para_frente(x);
                                linha_entrada--;
                                x->comandos = inserir_comando(x->comandos, 'Q');
                                x = para_atras(x);
                                linha_entrada++;
                                printf("\nCarga esvaziada.\n");
                                break;
                            } else {
                                x = para_frente(x);
                                linha_entrada--;
                                x->comandos = inserir_comando(x->comandos, 'O');
                                x = para_atras(x);
                                linha_entrada++;
                                printf("\nRobo sem carga.\n");
                                break;
                            }

                        case 3:
                            if(x->carga == 0) {
                                alterar_posicao_robo(ambiente, linha_entrada, coluna_entrada, linha_entrada-1, coluna_entrada);
                                x = para_frente(x);
                                linha_entrada--;
                                x->comandos = inserir_comando(x->comandos, 'G');
                                x->carga = 1;
                                printf("\nGarrafa captada.\n");
                                break;

                            } else {
                                x = para_frente(x);
                                linha_entrada--;
                                x->comandos = inserir_comando(x->comandos, 'T');
                                x = para_atras(x);
                                linha_entrada++;
                                printf("\nRobo com Garrafa.\n");
                                break;
                            }

                        case 4:
                            x = para_frente(x);
                            linha_entrada--;
                            x->comandos = inserir_comando(x->comandos, 'O');
                            x = para_atras(x);
                            linha_entrada++;
                            printf("\nObstaculo, robo nao pode avancar!\n");
                            break;
                    }
                }
                imprimir_ambiente(ambiente);
                break;

            case 40:
                if(ambiente_prepado == 0) {
                    printf("Ambiente ainda nao preparado.\n");
                    break;
                } else {
                    switch (ambiente[linha_entrada+1][coluna_entrada]) {

                        case 0:
                            alterar_posicao_robo(ambiente, linha_entrada, coluna_entrada, linha_entrada+1, coluna_entrada);
                            x = para_atras(x);
                            linha_entrada++;
                            break;

                        case 2:
                            if(x->carga == 1) {
                                x->carga = 0;
                                x = para_atras(x);
                                linha_entrada++;
                                x->comandos = inserir_comando(x->comandos, 'Q');
                                x = para_frente(x);
                                linha_entrada--;
                                printf("\nCarga esvaziada.\n");
                                break;
                            } else {
                                x = para_atras(x);
                                linha_entrada++;
                                x->comandos = inserir_comando(x->comandos, 'O');
                                x = para_frente(x);
                                linha_entrada--;
                                printf("\nRobo sem carga.\n");
                                break;
                            }
                        
                        /*robô pega a garrafa e fica com carga carregada, caso ele esteja
                        descarregado (sem garrafa em seu armazenamento)*/
                        case 3:
                            if(x->carga == 0) {
                                alterar_posicao_robo(ambiente, linha_entrada, coluna_entrada, linha_entrada+1, coluna_entrada);
                                x = para_atras(x);
                                linha_entrada++;
                                x->comandos = inserir_comando(x->comandos, 'G');
                                x->carga = 1;
                                printf("\nGarrafa captada.\n");
                                break;

                            } else {
                                x = para_atras(x);
                                linha_entrada++;
                                x->comandos = inserir_comando(x->comandos, 'T');
                                x = para_frente(x);
                                linha_entrada--;
                                printf("\nRobo com Garrafa.\n");
                                break;
                            }
                        
                        //o robo encontra um obstáculo
                        case 4:
                            x = para_atras(x);
                            linha_entrada++;
                            x->comandos = inserir_comando(x->comandos, 'O');
                            x = para_frente(x);
                            linha_entrada--;
                            printf("\nObstaculo, robo nao pode avancar!\n");
                            break;

                    }
                }
                imprimir_ambiente(ambiente);
                break;

            case 999:
                criar_arquivo(arquivo, x->comandos);
                exit(0);
            
            //caso não seja inserido o comando 999 aparece a mensagem comando invalido
            default:
                printf("Comando invalido.\n\7");
                break;

        }
    }

    return 0;
}
//o main irá executar o menu