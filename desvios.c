#include "desvios.h"
#include "compilador.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *cria_rotulo(int numero_rotulo)
{
    char *rotulo = (char *)malloc(10 * sizeof(char));
    sprintf(rotulo, "R%02d", numero_rotulo);
    return rotulo;
}

char *pega_rotulo(pilha_t *pilha, int posicao)
{
    pilha_t *aux = pilha;

    // Verifica se a pilha está vazia
    if (aux == NULL)
    {
        imprimeErro("Erro ao processar rótulos");
    }

    // Navega até a posição desejada
    for (int i = 0; i < posicao && aux != NULL; i++)
    {
        aux = aux->prox;
    }

    // Verifica se a posição é válida
    if (aux == NULL)
    {
        imprimeErro("Erro ao processar rótulos");
    }

    // Retorna o rótulo na posição desejada
    return (char *)aux->dado;
}