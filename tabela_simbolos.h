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
    pass_referencia, pass_valor, pass_indefinido
} tipo_passagem;

// Entrada na tabela de símbolos
typedef struct entrada_tabela_simbolos
{
    categoria_simbolo cat;
    int nivel;
    char id[16];
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
    char rotulo[10];
    int num_params;
    entrada_tabela_simbolos **params;
} atributos_procedimento;

// Atributos de função
typedef struct atributos_funcao
{
    char rotulo[10];
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
void inicializa_tabela_simbolos();

// Insere símbolos na tabela de símbolos
int insere_simbolo(entrada_tabela_simbolos * simbolo);

// Retira os n últimos símbolos inseridos na tabela de símbolos
void retira_simbolos(int n);

// Remove os símbolos na tabela de símbolos do nível léxico especificado
void remove_nivel_lexico(int nL);

// Busca e retorna o símbolo com o identificador especificado; retorna NULL se não encontra
entrada_tabela_simbolos *busca(char *identificador);

// Busca e retorna o símbolo da última categoria especificada; retorna NULL se não encontra
entrada_tabela_simbolos **obter_ultimo_simbolo_categoria(categoria_simbolo cat);

// Atualiza o tipo das últimas n entradas na tabela de símbolos (para variáveis simples)
void atualiza_tipo(tipo t, int n);

// Atualiza o tipo das últimas n entradas na tabela de símbolos (para parâmetros formais)
void atualiza_tipo_param(tipo t, int n);

// Atualiza o tipo de passagem das últimas n entradas da tabela de símbolos (para parâmetros)
void atualiza_tipo_passagem(tipo_passagem pass, int n);

// Atualiza deslocamento de cada parâmetro, adiciona referência aos parâmetros
// no símbolo do último procedimento/função na tabela de símbolos
void trata_parametros(int deslocamento);

// Atualiza o tipo da última função inserida na tabela de símbolos
void atualiza_tipo_funcao(tipo t);

// Cria o símbolo para ser inserido na tabela de símbolos ("atributos" deve conter uma struct de atributos criada previamente)
entrada_tabela_simbolos *cria_simbolo(categoria_simbolo cat, char *id, void *atributos);

// Cria a struct de atributos de variável simples para inserir na struct do símbolo
atributos_var_simples *cria_atributos_var_simples(tipo tipo_var, int deslocamento);

// Cria a struct de atributos de procedimento para inserir na struct do símbolo
atributos_procedimento *cria_atributos_procedimento(char *rotulo);

// Cria a struct de atributos de função para inserir na struct do símbolo
atributos_funcao *cria_atributos_funcao(char *rotulo);

// Cria a struct de atributos de parâmetro formal para inserir na struct do símbolo
atributos_param_formal *cria_atributos_param_formal(tipo tipo_param, tipo_passagem pass);

// Função para imprimir a tabela de símbolos
void imprime_tabela_simbolos();

#endif
