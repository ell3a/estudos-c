#include "config.h"
//trabalha com a lista de comando
typedef struct l {
    char comando;
    struct l *proximo;
} lista;

lista * inserir_comando(lista *l, char c) {
    if(l == NULL) {
        l = (lista *)malloc(sizeof(lista));
        l->comando = c;
        l->proximo = NULL;
    } else {
        l->proximo = inserir_comando(l->proximo, c);
    }
}

void imprimir_comandos(lista *l) {
    if (l == NULL) return;
    printf("%c, ", l->comando);
    imprimir_comandos(l->proximo);
}
