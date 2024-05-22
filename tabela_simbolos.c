#include "tabela_simbolos.h"
#include "compilador.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Variáveis globais da tabela de símbolos e do nível léxico
extern pilha_t *tab_simbolos;

void inicializa_tabela_simbolos() {
    inicializa_pilha(&tab_simbolos);
}

int insere_simbolo(entrada_tabela_simbolos * simbolo) {
    size_t tamanho;
    switch (simbolo->cat)
    {
    case var_simples:
        tamanho = sizeof(atributos_var_simples);
        break;
    
    case procedimento:
        tamanho = sizeof(atributos_procedimento) + 15*sizeof(atributos_param_formal);
        break;
    
    case funcao:
        tamanho = sizeof(atributos_funcao) + 15*sizeof(atributos_param_formal);
        break;
    
    default:
        tamanho = sizeof(atributos_param_formal);
        break;
    }

    if (insere_topo(&tab_simbolos, simbolo, sizeof(entrada_tabela_simbolos) + tamanho)) {
        free(simbolo);
        return 1;
    }
    else
        imprimeErro("Erro ao adicionar símbolo na tabela de símbolos");
}

void retira_simbolos(int n) {
    for (int i = 0; i < n; i++) {
        void *remover = remove_topo(&tab_simbolos);
        free(remover);
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
        void *remover = remove_topo(&tab_simbolos);
        free(remover);
    }
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

entrada_tabela_simbolos **obter_ultimo_simbolo_categoria(categoria_simbolo cat) {
    pilha_t *iter = tab_simbolos;
    while (iter != NULL) {
        entrada_tabela_simbolos *item = (entrada_tabela_simbolos *) iter->dado;
        if (item->cat == cat) {
            return (entrada_tabela_simbolos **) &(iter->dado);
        }
        iter = iter->prox;
    }
    return NULL;
}

void atualiza_tipo(tipo t, int n) {
    pilha_t *iter = tab_simbolos;
    int i = 0;
    while ((iter != NULL) && (i<n)) {
        entrada_tabela_simbolos *simbolo_atual = (entrada_tabela_simbolos *)iter->dado;
        atributos_var_simples *atributo_atual = (atributos_var_simples *)simbolo_atual->atributos;
        atributo_atual->tipo_var = t;
        iter = iter->prox;
        i++;
    }
}

void atualiza_tipo_param(tipo t, int n) {
    pilha_t *iter = tab_simbolos;
    int i = 0;
    while ((iter != NULL) && (i<n)) {
        entrada_tabela_simbolos *simbolo_atual = (entrada_tabela_simbolos *)iter->dado;
        atributos_param_formal *atributo_atual = (atributos_param_formal *)simbolo_atual->atributos;
        atributo_atual->tipo_param = t;
        iter = iter->prox;
        i++;
    }
}

void atualiza_tipo_passagem(tipo_passagem pass, int n) {
    pilha_t *iter = tab_simbolos;
    int i = 0;
    while ((iter != NULL) && (i<n)) {
        entrada_tabela_simbolos *simbolo_atual = (entrada_tabela_simbolos *)iter->dado;
        atributos_param_formal *atributo_atual = (atributos_param_formal *)simbolo_atual->atributos;
        atributo_atual->pass = pass;
        iter = iter->prox;
        i++;
    }
}

void trata_parametros(int deslocamento) {
    if (deslocamento == 0)
        return;

    int novo_desloc = -4;

    entrada_tabela_simbolos *procedimento_simb;
    int k = 0;
    pilha_t *iter = tab_simbolos;
    while ((iter != NULL) && (k <= deslocamento)) {
        if (k == deslocamento) {
            procedimento_simb = (entrada_tabela_simbolos *)iter->dado;
            break;
        }
        iter = iter->prox;
        k++;
    }

    if (procedimento_simb->cat == funcao) {
        atributos_funcao *atr_func = (atributos_funcao *)procedimento_simb->atributos;
        atr_func->num_params = deslocamento;
        atr_func->params = malloc(atr_func->num_params * sizeof(entrada_tabela_simbolos *));

        // atualiza deslocamento dos parametros e adiciona referencia a eles no simbolo do procedimento
        for (int i = 0; i < deslocamento; i++) {
            
            // encontra o parametro
            pilha_t *iter = tab_simbolos;
            entrada_tabela_simbolos *param_simb;
            int j = 0;
            while ((iter != NULL) && (j <= i)) {
                if (j == i) {
                    param_simb = (entrada_tabela_simbolos *)iter->dado;
                    break;
                }
                iter = iter->prox;
                j++;
            }

            int index_param = deslocamento - 1 - i;

            atributos_param_formal *atr_param = (atributos_param_formal *)param_simb->atributos;
            atr_param->deslocamento = novo_desloc;
            atr_func->params[index_param] = malloc(sizeof(entrada_tabela_simbolos) + sizeof(atributos_param_formal));
            memcpy(atr_func->params[index_param], param_simb, sizeof(entrada_tabela_simbolos) + sizeof(atributos_param_formal));
            novo_desloc--;
        }

        // atualiza deslocamento da função
        atr_func->deslocamento = novo_desloc;
    }
    else if (procedimento_simb->cat == procedimento) {
        atributos_procedimento *atr_proc = (atributos_procedimento *)procedimento_simb->atributos;
        atr_proc->num_params = deslocamento;
        atr_proc->params = malloc(atr_proc->num_params * sizeof(entrada_tabela_simbolos *));

        // atualiza deslocamento dos parametros e adiciona referencia a eles no simbolo do procedimento
        for (int i = 0; i < deslocamento; i++) {

            // encontra o parametro
            pilha_t *iter = tab_simbolos;
            entrada_tabela_simbolos *param_simb;
            int j = 0;
            while ((iter != NULL) && (j <= i)) {
                if (j == i) {
                    param_simb = (entrada_tabela_simbolos *)iter->dado;
                    break;
                }
                iter = iter->prox;
                j++;
            }

            int index_param = deslocamento - 1 - i;

            atributos_param_formal *atr_param = (atributos_param_formal *)param_simb->atributos;
            atr_param->deslocamento = novo_desloc;
            atr_proc->params[index_param] = malloc(sizeof(entrada_tabela_simbolos) + sizeof(atributos_param_formal));
            memcpy(atr_proc->params[index_param], param_simb, sizeof(entrada_tabela_simbolos) + sizeof(atributos_param_formal));
            novo_desloc--;
        }
    }
    else {
        imprimeErro("Erro ao tratar parâmetros");
    }
}

void atualiza_tipo_funcao(tipo t) {
    pilha_t *iter = tab_simbolos;
    entrada_tabela_simbolos *simb;
    while (iter != NULL) {
        simb = (entrada_tabela_simbolos *)iter->dado;
        if (simb->cat == funcao)
            break;
        else {
            iter = iter->prox;
        }
    }

    atributos_funcao *atr_func = (atributos_funcao *)simb->atributos;
    atr_func->tipo_funcao = t;
}

entrada_tabela_simbolos *cria_simbolo(categoria_simbolo cat, char *id, void *atributos) {
    entrada_tabela_simbolos *novo_simb = (entrada_tabela_simbolos *)malloc(sizeof(entrada_tabela_simbolos));
    novo_simb->cat = cat;
    novo_simb->nivel = nivel_lex;
    strncpy(novo_simb->id, id, TAM_TOKEN);
    novo_simb->atributos = atributos;
    return novo_simb;
}

atributos_var_simples *cria_atributos_var_simples(tipo tipo_var, int deslocamento) {
    atributos_var_simples *novo_atr = (atributos_var_simples *)malloc(sizeof(atributos_var_simples));
    novo_atr->deslocamento = deslocamento;
    novo_atr->tipo_var = tipo_var;
    return novo_atr;
}

atributos_procedimento *cria_atributos_procedimento(char *rotulo) {
    atributos_procedimento *novo_atr = (atributos_procedimento *)malloc(sizeof(atributos_procedimento));
    strncpy(novo_atr->rotulo, rotulo, 10);
    return novo_atr;
}

atributos_funcao *cria_atributos_funcao(char *rotulo) {
    atributos_funcao *novo_atr = (atributos_funcao *)malloc(sizeof(atributos_funcao));
    strncpy(novo_atr->rotulo, rotulo, 10);
    return novo_atr;
}

atributos_param_formal *cria_atributos_param_formal(tipo tipo_param, tipo_passagem pass) {
    atributos_param_formal *novo_atr = (atributos_param_formal *)malloc(sizeof(atributos_param_formal));
    novo_atr->tipo_param = tipo_param;
    novo_atr->pass = pass;
    return novo_atr;
}

// Imprime os dados de um símbolo de acordo com sua categoria
void imprime_simbolo(void *simbolo) {
    entrada_tabela_simbolos *simb = (entrada_tabela_simbolos *)simbolo;

    atributos_var_simples *atr_var;
    atributos_procedimento *atr_proc;
    atributos_funcao *atr_func;
    atributos_param_formal *atr_param;

    printf("###########\n");
    switch (simb->cat) {
    case var_simples:
        printf("# Variável simples\n");
        atr_var = (atributos_var_simples *)simb->atributos;
        printf("# Tipo: %d\n", atr_var->tipo_var);
        printf("# N.L.: %d\n", simb->nivel);
        printf("# Desloc: %d\n", atr_var->deslocamento);
        break;
    case procedimento:
        printf("# Procedimento\n");
        atr_proc = (atributos_procedimento *)simb->atributos;
        printf("# Número de parâmetros: %d\n", atr_proc->num_params);
        printf("# Rótulo: %s\n", atr_proc->rotulo);
        printf("# N.L.: %d\n", simb->nivel);
        break;
    case funcao:
        printf("# Função\n");
        atr_func = (atributos_funcao *)simb->atributos;
        printf("# Tipo: %d\n", atr_func->tipo_funcao);
        printf("# Rótulo: %s\n", atr_func->rotulo);
        printf("# N.L.: %d\n", simb->nivel);
        printf("# Desloc: %d\n", atr_func->deslocamento);
        break;
    case param_formal:
        printf("# Parâmetro formal\n");
        atr_param = (atributos_param_formal *)simb->atributos;
        printf("# Tipo: %d\n", atr_param->tipo_param);
        printf("# Tipo de passagem: %d\n", atr_param->pass);
        printf("# N.L.: %d\n", simb->nivel);
        printf("# Desloc: %d\n", atr_param->deslocamento);
        break;
    default:
        printf("# Indefinido\n");
        break;
    }
    printf("# Identificador: %s\n", (char *)simb->id);
    printf("###########\n");
}

void imprime_tabela_simbolos() {
    imprime_pilha(tab_simbolos, imprime_simbolo);
}
