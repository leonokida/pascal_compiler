#ifndef __TAB_SIMBOLOS__
#define __TAB_SIMBOLOS__

#include "pilha.h"

// Categoria do símbolo
typedef enum categoria_simbolo {
    var_simples, procedimento, funcao, param_formal
} categoria_simbolo;

// Tipo do símbolo
typedef enum tipo {
    t_integer, t_boolean, t_char, t_real, t_indefinido
} tipo;

// Tipo de passagem do símbolo se ele for parâmetro
typedef enum tipo_passagem {
    pass_referencia, pass_atributo, pass_indefinido
} tipo_passagem;

// Entrada na tabela de símbolos
typedef struct entrada_tabela_simbolos
{
    categoria_simbolo cat;
    int nivel;
    char *id;
    void *atributos;
} entrada_tabela_simbolos;

// Atributos de variável simples
typedef struct atributos_var_simples
{
    tipo tipo_var;
    int deslocamento;
} atributos_var_simples;

// Atributos de procedimento
typedef struct atributos_procedimento
{
    char *rotulo;
    int num_params;
    entrada_tabela_simbolos **params;
} atributos_procedimento;

// Atributos de função
typedef struct atributos_funcao
{
    char *rotulo;
    int num_params;
    tipo tipo_funcao;
    int deslocamento;
    entrada_tabela_simbolos **params;
} atributos_funcao;

// Atributos de parâmetro formal
typedef struct atributos_param_formal
{
    tipo tipo_param;
    tipo_passagem pass;
    int deslocamento;
} atributos_param_formal;

// Inicializa a pilha da tabela de símbolos
pilha_t *inicializa_tabela_simbolos();

// Insere símbolos na tabela
int insere_simbolo(pilha_t **tabela_simbolos, entrada_tabela_simbolos * simbolo);

// Retira os n últimos símbolos inseridos na tabela
void retira_simbolos(pilha_t **tabela_simbolos, int n);

// Busca e retorna o símbolo com o identificador buscado; retorna Null se não encontra
entrada_tabela_simbolos *busca(pilha_t *tabela_simbolos, char *identificador);

// Cria o símbolo para ser inserido na tabela ("atributos" deve conter uma struct de atributos criada previamente)
entrada_tabela_simbolos *cria_simbolo(categoria_simbolo cat, int nivel, char *id, void *atributos);

// Cria a struct de atributos de variável simples para inserir na struct do símbolo
atributos_var_simples *cria_atributos_var_simples(tipo tipo_var, int deslocamento);

// Cria a struct de atributos de procedimento para inserir na struct do símbolo
atributos_procedimento *cria_atributos_procedimento(char *rotulo, int num_params, entrada_tabela_simbolos **params);

// Cria a struct de atributos de função para inserir na struct do símbolo
atributos_funcao *cria_atributos_funcao(char *rotulo, int num_params, tipo tipo_funcao, int deslocamento, entrada_tabela_simbolos **params);

// Cria a struct de atributos de parâmetro formal para inserir na struct do símbolo
atributos_param_formal *cria_atributos_param_formal(tipo tipo_param, tipo_passagem pass, int deslocamento);

// Função para imprimir a tabela de símbolos
void imprime_tabela_simbolos(pilha_t *tabela_simbolos);

#endif