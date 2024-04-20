
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

#include "pilha.h"
#include "tabela_simbolos.h"
#include "desvios.h"

int num_vars;
int num_vars_bloco;

int nivel_lex = 0;
int rotulo_print = 0;
int desloc;

pilha_t *tab_simbolos;
pilha_t *pilha_rotulos;
pilha_t *operacoes_pilha;
pilha_t *expressoes_pilha;
pilha_t *termos_pilha;
pilha_t *fatores_pilha;
pilha_t *num_vars_pilha;

char comando[50];
char mensagem_erro[50];
char token[TAM_TOKEN];

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO LABEL
%token TYPE ARRAY OF PROCEDURE FUNCTION GOTO IF 
%token ELSE WHILE DO IGUAL DIFERENTE MENOR MENOR_OU_IGUAL
%token MAIOR MAIOR_OU_IGUAL OR AND THEN NOT SOMA
%token SUBTRAI DIV MUL MOD INTEGER LONGINT REAL CHAR 
%token BOOLEAN NUMERO READ WRITE

/* Para funcionar o IF THEN ELSE
   Precedências são crescentes, logo "lower_than_else" < "else" */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

/* regra 1*/
programa    :
   {
      geraCodigo (NULL, "INPP");
   }
   PROGRAM IDENT
   ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
   bloco PONTO 
   {
      geraCodigo (NULL, "PARA");
   }
;

/* regra 2 */
bloco       :
   {
      num_vars_bloco = 0;
   }
   parte_declara_vars
   //{
      //insere_topo(&num_vars_pilha, &num_bloco_vars);

      //insere_topo(&rotulos_pilha, next_rot());

      // Gera DSVS com rotulo
      //char *rotulo = stack_item(rotulos, rotulos->top);
      //sprintf(comando, "DSVS %s", rotulo);
      //geraCodigo(NULL, comando);
   //}
   //parte_declara_subrotinas
   //{
   //   // Gera NADA com rotulo
   //   char *rotulo = stack_pop(rotulos);
   //   geraCodigo(rotulo, "NADA");
   //   free(rotulo);
   //}
   //comando_composto
   //{
   //   int *temp = stack_pop(num_vars_stack);
   //   num_bloco_vars = (*temp);
   //   free(temp);

   //   eliminaNivelLex(nivelLex+1);

   //   if (num_bloco_vars > 0) {
   //      eliminaTS(num_bloco_vars);
   //      sprintf(comando, "DMEM %d", num_bloco_vars);
   //      geraCodigo(NULL, comando);
   //   }

   //}
;

/* regras 8 e 9 */
parte_declara_vars: 
   | { 
      desloc = 0; 
   } VAR declara_vars
;

declara_vars: declara_vars declara_var
   | declara_var
;

declara_var : { num_vars = 0; }
   lista_id_var DOIS_PONTOS
   tipo
   { 
      /* Aloca memória pras variáveis */
      sprintf(comando, "AMEM %d", num_vars);
      geraCodigo(NULL, comando);
   }
   PONTO_E_VIRGULA
;

tipo: INTEGER {
      atualiza_tipo(t_integer, num_vars);
   }
   | BOOLEAN {
      atualiza_tipo(t_boolean, num_vars);
   }
;

lista_id_var: lista_id_var VIRGULA IDENT
   {
      insere_simbolo(cria_simbolo(var_simples, token, cria_atributos_var_simples(t_indefinido, desloc)));
      num_vars++;
      num_vars_bloco++;
      desloc++;
   }
   | IDENT 
   {
      insere_simbolo(cria_simbolo(var_simples, token, cria_atributos_var_simples(t_indefinido, desloc)));
      num_vars++;
      num_vars_bloco++;
      desloc++;
   }
;

lista_idents: lista_idents VIRGULA lista_aux
   | lista_aux
;

lista_aux: IDENT
   | NUMERO
;

/* regra 24 */
lista_expressoes: lista_expressoes VIRGULA expressao
   | expressao
;

/* regra 25 */
expressao: expressao_simples
   | expressao_simples relacao expressao_simples
   {
      tipo *t1, *t2;
      t1 = (tipo *)remove_topo(&expressoes_pilha);
      t2 = (tipo *)remove_topo(&expressoes_pilha);

      if (*t1 != *t2)
         imprimeErro("Comparação de tipos diferentes");

      tipo tipo_bool = tipo_boolean;
      insere_topo(&expressoes_pilha, &tipo_bool);

      operacoes *op = (operacoes *)remove_topo(&operacoes_pilha);
      sprintf(comando, "%s", gera_operacao_mepa(*op));
      geraCodigo(NULL, comando);

      free(t1);
      free(t2);
   }
;

/* regra 27 */
expressao_simples: expressao_simples sinal_ou_or termo
   {
      tipo *t1, *t2;
      t1 = (tipo *)remove_topo(&expressoes_pilha);
      t2 = (tipo *)remove_topo(&termos_pilha);

      if (*t1 != *t2)
         imprimeErro("Expressão usa tipos diferentes");

      insere_topo(&expressoes_pilha, t1);

      operacoes *op = (operacoes *)remove_topo(&operacoes_pilha);
      sprintf(comando, "%s", gera_operacao_mepa(*op));
      geraCodigo(NULL, comando);

      free(t1);
      free(t2);
   }
   | sinal termo
   {
      tipo *t1 = (tipo *)remove_topo(&termos_pilha);
      insere_topo(&expressoes_pilha, t1);

      operacoes *op = (operacoes *)remove_topo(&operacoes_pilha);
      // inverte sinal do termo
      if (*op == subt) {
         sprintf(comando, "INVR");
         geraCodigo(NULL, comando);
      }
      free(t1);
   }
   | termo
   {
      tipo *t1 = (tipo *)remove_topo(&termos_pilha);
      insere_topo(&expressoes_pilha, t1);

      free(t1);
   }
;

/* usado em expressão simples */
sinal_ou_or: sinal
   | OR
   {
      operacoes op = or;
      insere_topo(&operacoes_pilha, &op);
   }
;

sinal: SOMA
   {
      operacoes op = soma;
      insere_topo(&operacoes_pilha, &op);
   }
   | SUBTRAI
   {
      operacoes op = subt;
      insere_topo(&operacoes_pilha, &op);
   }

/* regra 26 */
relacao: IGUAL
   {
      operacoes op = igual;
      insere_topo(&operacoes_pilha, &op);
   }
   | DIFERENTE
   {
      operacoes op = diferente;
      insere_topo(&operacoes_pilha, &op);
   }
   | MENOR
   {
      operacoes op = menor;
      insere_topo(&operacoes_pilha, &op);
   }
   | MENOR_OU_IGUAL
   {
      operacoes op = menor_ou_igual;
      insere_topo(&operacoes_pilha, &op);
   }
   | MAIOR
   {
      operacoes op = maior;
      insere_topo(&operacoes_pilha, &op);
   }
   | MAIOR_OU_IGUAL
   {
      operacoes op = maior_ou_igual;
      insere_topo(&operacoes_pilha, &op);
   }
;

/* regra 16 */
comando_composto: T_BEGIN comandos T_END

/* regra 17 */
comandos:
   | comando PONTO_E_VIRGULA comandos
   | comando
;

comando: NUMERO DOIS_PONTOS comando_sem_rotulo
   | comando_sem_rotulo

/* regra 18 */
comando_sem_rotulo:
   //| atribuicao
   //| chamada_procedimento
   //| desvio
   | comando_repetitivo
   | comando_condicional
   | comando_composto
   | comando_read
   | comando_write            
;

/* regra 23 */
comando_repetitivo:
	WHILE
	{
		char *WhileInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *WhileFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		insere_topo(&pilha_rotulos, WhileInicio);
		insere_topo(&pilha_rotulos, WhileFim);
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
	}
	expressao DO
	{
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, dsvf);
	}
	comando_composto
	{
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(rot, "NADA");

		remove_topo(&pilha_rotulos, 2);
	}
;

/* regra 22 */
comando_condicional: 
   {
      char * RotElse = cria_rotulo(rotulo_print);
      rotulo_print++;
      char * RotFim = cria_rotulo(rotulo_print);
      rotulo_print++;

      insere_topo(&pilha_rotulos, RotElse);
      insere_topo(&pilha_rotulos, RotFim);
   }
   bloco_if bloco_else
   {
      free(remove_topo(&pilha_rotulos));
      free(remove_topo(&pilha_rotulos));
   }
;

bloco_if: IF expressao
   {

   }
   THEN comando_sem_rotulo
;

bloco_else: ELSE
   {
      // gera desvio para fim do if
      sprintf(comando, "DSVS %s", pega_rotulo(pilha_rotulos, 1));
      geraCodigo(NULL, comando);

      // gera rotulo do else
      geraCodigo(pega_rotulo(pilha_rotulos, 0), "NADA");
   }
   comando_sem_rotulo
   {
      // gera rotulo de fim do if
      geraCodigo(pega_rotulo(pilha_rotulos, 1), "NADA");
   }
   | %prec LOWER_THAN_ELSE
   {
      // gera rotulo do else
      geraCodigo(pega_rotulo(pilha_rotulos, 0), "NADA");
   }
;

/* read e write */
comando_read: READ ABRE_PARENTESES read_params FECHA_PARENTESES
;

/* parâmetros do read */
read_params: read_params VIRGULA IDENT
   {
      leitura(token);
   }
   | IDENT
   {
      leitura(token);
   }
;

comando_write: WRITE ABRE_PARENTESES write_params FECHA_PARENTESES
;

/* parâmetros do write */
write_params: write_params VIRGULA expressao
   {
      geraCodigo(NULL, "IMPR");
   }
   | expressao
   {
      geraCodigo(NULL, "IMPR");
   }
;

%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */
   inicializa_tabela_simbolos();
   inicializa_pilha(&num_vars_pilha);
   inicializa_pilha(&pilha_rotulos);
   inicializa_pilha(&expressoes_pilha);
   inicializa_pilha(&termos_pilha);
   inicializa_pilha(&fatores_pilha);
   inicializa_pilha(&operacoes_pilha);

   yyin=fp;
   yyparse();

   return 0;
}
