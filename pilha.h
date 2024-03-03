#ifndef __QUEUE__
#define __QUEUE__

#ifndef NULL
#define NULL ((void *) 0)
#endif

// Pilha genérica para qualquer tipo de dado
typedef struct pilha_t
{
   void *dado;
   struct pilha_t *prox;
} pilha_t ;

// Retorna o tamanho da pilha
int tamanho_pilha(pilha_t *pilha);

// Chama a função de impressão para cada elemento da pilha
void imprime_pilha(pilha_t *pilha, void imprime_func(void*));

// Insere um novo elemento no topo da pilha (push)
int insere_topo(pilha_t **pilha, void *elem);

// Remove e retorna o topo da pilha (pop) e libera memória
void *remove_topo(pilha_t **pilha);

// Remove todos os elementos da pilha, liberando memória
void destroi_pilha(pilha_t **pilha);

#endif