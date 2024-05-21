#ifndef __QUEUE__
#define __QUEUE__

#include <stdlib.h>

// Pilha genérica para qualquer tipo de dado
typedef struct pilha_t
{
   void *dado;
   struct pilha_t *prox;
} pilha_t ;

// Inicializa pilha
int inicializa_pilha(pilha_t **pilha);

// Retorna o tamanho da pilha
int tamanho_pilha(pilha_t *pilha);

// Chama a função de impressão para cada elemento da pilha
void imprime_pilha(pilha_t *pilha, void imprime_func(void*));

// Insere um novo elemento no topo da pilha (push)
int insere_topo(pilha_t **pilha, void *elem, size_t tamanho);

// Remove e retorna o topo da pilha (pop) e libera memória
void *remove_topo(pilha_t **pilha);

// Remove todos os elementos da pilha, liberando memória
void destroi_pilha(pilha_t **pilha);

// Retorna um item específico da pilha pela posição
void **obter_item_pilha(pilha_t **pilha, int pos);

#endif
