#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int inicializa_pilha(pilha_t **pilha) {
    *pilha = NULL;
    return 0;
}

int tamanho_pilha(pilha_t *pilha) {
    // Pilha vazia
    if (pilha == NULL) {
        return 0;
    }
    // Contador para o tamanho da pilha
    int cont = 1;
    pilha_t *itr = pilha;
    // Percorre a pilha incrementando o contador
    while (itr != NULL) {
        cont++;
        itr = itr->prox;
    }
    return cont;
}

void imprime_pilha(pilha_t *pilha, void (*imprime_func)(void*)) {
    // Pilha vazia
    if (pilha == NULL) {
        printf("Pilha vazia.\n");
    }
    // Imprime o topo da pilha
    else {
        imprime_func(pilha->dado);
        pilha_t *itr = pilha->prox;
        // Percorre a pilha imprimindo cada elemento
        while (itr != NULL) {
            imprime_func(itr->dado);
            itr = itr->prox;
        }
    }
}

int insere_topo(pilha_t **pilha, void *elem) {
    // Pilha não existe
    if (pilha == NULL) {
        printf("Pilha não existe.\n");
        return -2;
    }

    // Cria novo elemento da pilha, contendo o dado de qualquer tipo
    pilha_t *novo_elem = malloc(sizeof(pilha_t));
    novo_elem->dado = elem;

    // Se a pilha estiver vazia, o novo elemento será o topo
    if (*pilha == NULL) {
        novo_elem->prox = NULL;
    }
    // Caso contrário, o novo elemento aponta para o topo antigo
    else {
        novo_elem->prox = *pilha;
    }

    // Atualiza o topo da pilha
    *pilha = novo_elem;
    return 1;
}

void *remove_topo(pilha_t **pilha) {
    // Pilha não existe ou está vazia
    if ((pilha == NULL) || (*pilha == NULL)) {
        printf ("Pilha não existe ou está vazia.\n");
        return NULL;
    }

    void *topo = (*pilha)->dado;
    pilha_t *remover = *pilha;
    // Atualiza o topo da pilha para o próximo elemento
    *pilha = (*pilha)->prox;
    free(remover);
    return topo;
}

void destroi_pilha(pilha_t **pilha) {
    while (tamanho_pilha(*pilha) > 0) {
        void *remover = remove_topo(pilha);
    }
}