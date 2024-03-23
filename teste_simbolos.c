#include "pilha.h"
#include "tabela_simbolos.h"
#include <stdio.h>
#include <stdlib.h>

void imprime_numero(void *simbolo) {
    int *simb = (int *) simbolo;
    printf("%d\n", *simb);
}

int main (){
    pilha_t * tabela_de_simbolos = inicializa_tabela_simbolos();
    atributos_var_simples * atrvar = cria_atributos_var_simples(t_integer, 1);
    entrada_tabela_simbolos * entrtab = cria_simbolo(var_simples, 1, "entrtab", atrvar);
    entrada_tabela_simbolos * entrtab2 = cria_simbolo(var_simples, 1, "entrtab2", atrvar);
    entrada_tabela_simbolos * entrtab3 = cria_simbolo(var_simples, 1, "entrtab3", atrvar);
    insere_simbolo(&tabela_de_simbolos, entrtab);
    insere_simbolo(&tabela_de_simbolos, entrtab2);
    insere_simbolo(&tabela_de_simbolos, entrtab3);

    imprime_tabela_simbolos(tabela_de_simbolos);

    retira_simbolos(&tabela_de_simbolos, 2);
    imprime_tabela_simbolos(tabela_de_simbolos);
    retira_simbolos(&tabela_de_simbolos, 2);

    imprime_tabela_simbolos(tabela_de_simbolos);
}