/* -------------------------------------------------------------------
 *            Arquivo: compilador.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [09/08/2020, 19h:01m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e variáveis globais do compilador (via extern)
 *
 * ------------------------------------------------------------------- */

#define TAM_TOKEN 16

typedef enum simbolos {
  simb_program, simb_var, simb_begin, simb_end,
  simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  simb_else, simb_then, simb_if, simb_goto, simb_procedure,
  simb_of, simb_array, simb_type, simb_label, simb_diferente,
  simb_igual, simb_do, simb_while, simb_function, simb_maior,
  simb_menor_ou_igual, simb_menor, simb_maior_ou_igual, 
  simb_or, simb_and, simb_not, simb_soma, simb_subtrai, 
  simb_div, simb_mul, simb_mod, simb_integer, simb_longint,
  simb_real, simb_char, simb_boolean
} simbolos;

typedef enum operacoes {
    soma,
    subt,
    div,
    mult,
    and,
    or,
    not,
    menor,
    maior,
    igual,
    diferente,
    menor_ou_igual,
    maior_ou_igual
} operacoes;


/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;

extern int num_vars;
extern int num_vars_bloco;

extern int nivel_lex = 0;
extern int rotulo_print = 0;
extern int desloc;

entrada_tabela_simbolos *ident_comando;

extern pilha_t *tab_simbolos;
extern pilha_t *pilha_rotulos;
extern pilha_t *operacoes_pilha;
extern pilha_t *expressoes_pilha;
extern pilha_t *termos_pilha;
extern pilha_t *fatores_pilha;
extern pilha_t *num_vars_pilha;
extern pilha_t *ident_comando_pilha;

char comando[50];
char mensagem_erro[50];
char token[TAM_TOKEN];
char ident[TAM_TOKEN];


/* -------------------------------------------------------------------
 * prototipos globais
 * ------------------------------------------------------------------- */

void geraCodigo (char*, char*);
int imprimeErro(char *erro);
char *gera_operacao_mepa(operacoes op);
void leitura(char *token);
void gera_carregamento(entrada_tabela_simbolos *simb);

int yylex();
void yyerror(const char *s);
