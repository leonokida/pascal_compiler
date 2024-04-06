#include "pilha.h"
#include "tabela_simbolos.h"
#include <stdio.h>
#include <stdlib.h>

pilha_t *tab_simbolos = NULL;
int nivel_lex = 0;

int main (){

    inicializa_tabela_simbolos();
    atributos_var_simples * atrvar = cria_atributos_var_simples(t_integer, 1);
    entrada_tabela_simbolos * entrtab = cria_simbolo(var_simples, "entrtab", atrvar);
    entrada_tabela_simbolos * entrtab2 = cria_simbolo(var_simples, "entrtab2", atrvar);
    entrada_tabela_simbolos * entrtab3 = cria_simbolo(var_simples, "entrtab3", atrvar);
    insere_simbolo(entrtab);
    insere_simbolo(entrtab2);
    insere_simbolo(entrtab3);

    imprime_tabela_simbolos();

    retira_simbolos(2);
    imprime_tabela_simbolos();
    retira_simbolos(2);

    imprime_tabela_simbolos();
}