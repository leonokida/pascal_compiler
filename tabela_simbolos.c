#include "tabela_simbolos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Variáveis globais da tabela de símbolos e do nível léxico
extern pilha_t *tab_simbolos;
extern int nivel_lex;

void inicializa_tabela_simbolos() {
    inicializa_pilha(&tab_simbolos);
}

int insere_simbolo(entrada_tabela_simbolos * simbolo) {
    return insere_topo(&tab_simbolos, simbolo);
}

void retira_simbolos(int n) {
    for (int i = 0; i < n; i++)
        remove_topo(&tab_simbolos);
}

entrada_tabela_simbolos *busca(char *identificador) {
    pilha_t *iter = tab_simbolos;
    while (iter != NULL) {
        entrada_tabela_simbolos *simbolo_atual = (entrada_tabela_simbolos *) iter->dado;
        if (strcmp(identificador, simbolo_atual->id) == 0)
            return simbolo_atual;
        iter = iter->prox;
    }
    return NULL;
}

void atualiza_tipo(tipo t, int n) {
    pilha_t *iter = tab_simbolos;
    int i = 0;
    while ((iter != NULL) || (i<n)) {
        entrada_tabela_simbolos *simbolo_atual = (entrada_tabela_simbolos *)iter->dado;
        atributos_var_simples *atributo_atual = (atributos_var_simples *)simbolo_atual->atributos;
        atributo_atual->tipo_var = t;
        iter = iter->prox;
        i++;
    }
}

void remove_nivel_lexico(int nL) {
    if(tab_simbolos == NULL) 
        return;
    pilha_t *iter = tab_simbolos;
    while (iter != NULL) {
        entrada_tabela_simbolos *simbolo_atual = (entrada_tabela_simbolos *) iter->dado;
        if (simbolo_atual->nivel < nL)
            return;

        iter = iter->prox;
        remove_topo(&tab_simbolos);
    }
}

entrada_tabela_simbolos *cria_simbolo(categoria_simbolo cat, char *id, void *atributos) {
    entrada_tabela_simbolos *novo_simb = (entrada_tabela_simbolos *)malloc(sizeof(entrada_tabela_simbolos));
    novo_simb->cat = cat;
    novo_simb->nivel = nivel_lex;
    novo_simb->id = id;
    novo_simb->atributos = atributos;
    return novo_simb;
}

atributos_var_simples *cria_atributos_var_simples(tipo tipo_var, int deslocamento) {
    atributos_var_simples *novo_atr = (atributos_var_simples *)malloc(sizeof(atributos_var_simples));
    novo_atr->deslocamento = deslocamento;
    novo_atr->tipo_var = tipo_var;
    return novo_atr;
}

atributos_procedimento *cria_atributos_procedimento(char *rotulo, int num_params, entrada_tabela_simbolos **params) {
    atributos_procedimento *novo_atr = (atributos_procedimento *)malloc(sizeof(atributos_procedimento));
    novo_atr->rotulo = rotulo;
    novo_atr->num_params = num_params;
    novo_atr->params = params;
    return novo_atr;
}

atributos_funcao *cria_atributos_funcao(char *rotulo, int num_params, tipo tipo_funcao, int deslocamento, entrada_tabela_simbolos **params) {
    atributos_funcao *novo_atr = (atributos_funcao *)malloc(sizeof(atributos_funcao));
    novo_atr->rotulo = rotulo;
    novo_atr->num_params = num_params;
    novo_atr->tipo_funcao = tipo_funcao;
    novo_atr->deslocamento = deslocamento;
    novo_atr->params = params;
    return novo_atr;
}

atributos_param_formal *cria_atributos_param_formal(tipo tipo_param, tipo_passagem pass, int deslocamento) {
    atributos_param_formal *novo_atr = (atributos_param_formal *)malloc(sizeof(atributos_param_formal));
    novo_atr->tipo_param = tipo_param;
    novo_atr->pass = pass;
    novo_atr->deslocamento = deslocamento;
    return novo_atr;
}

void imprime_simbolo(void *simbolo) {
    entrada_tabela_simbolos *simb = (entrada_tabela_simbolos *)simbolo;
    printf("###########\n");
    switch (simb->cat)
    {
    case var_simples:
        printf("# Variável simples\n");
        atributos_var_simples *atr_var = (atributos_var_simples *)simb->atributos;
        printf("# Tipo: %d\n", atr_var->tipo_var);
        break;
    case procedimento:
        printf("# Procedimento\n");
        break;
    case funcao:
        printf("# Função\n");
        break;
    case param_formal:
        printf("# Parâmetro formal\n");
        break;
    default:
        printf("# Indefinido\n");
        break;
    }
    printf("# Identificador: %s\n", simb->id);
    printf("###########\n");
}

void imprime_tabela_simbolos() {
    imprime_pilha(tab_simbolos, imprime_simbolo);
}