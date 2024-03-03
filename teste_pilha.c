#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>


void imprime(void *dado) {
    int *valor = (int *)dado;
    printf("%c\n", *valor);
}

int main() {
    pilha_t *pilha = NULL;
    char a = 'a', b = 'b', c = 'c', d = 'd';
    insere_topo(&pilha, &a);
    insere_topo(&pilha, &b);
    insere_topo(&pilha, &c);
    insere_topo(&pilha, &d);
    imprime_pilha(pilha, imprime);

    while (tamanho_pilha(pilha) > 0) {
        int *topo = remove_topo(&pilha);
        printf("%c\n", *topo);
    }


    destroi_pilha(&pilha);
}