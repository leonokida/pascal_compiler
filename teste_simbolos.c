#include "pilha.h"
#include "tabela_simbolos.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    pilha_t * tabela_de_simbolos = NULL;
    tabela_de_simbolos = inicializa_tabela_simbolos();
    atributos_var_simples * atrvar = cria_atributos_var_simples(t_integer, 1);
    entrada_tabela_simbolos * entrtab = cria_simbolo(var_simples, 1, "entrtab", atrvar);
    insere_simbolo(tabela_de_simbolos, entrtab);
    imprime_tabela_simbolos(tabela_de_simbolos);
}