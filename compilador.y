
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
pilha_t *num_vars_pilha;

int nivel_lex = 0;
int rotulo_print = 0;
int desloc;

pilha_t *tab_simbolos;

pilha_t *pilha_rotulos;

char ident[50];
char comando[50];

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO LABEL
%token TYPE ARRAY OF PROCEDURE FUNCTION GOTO IF 
%token ELSE WHILE DO IGUAL DIFERENTE MENOR MENOR_OU_IGUAL
%token MAIOR MAIOR_OU_IGUAL OR AND THEN NOT SOMA
%token SUBTRAI DIV MUL MOD INTEGER LONGINT REAL CHAR 
%token BOOLEAN NUMERO 

%%

/* regra 1*/
programa    :{
             geraCodigo (NULL, "INPP");
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             geraCodigo (NULL, "PARA");
             }
;

/* regra 2 */
bloco       :{
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


parte_declara_vars:  var
;

var         : { desloc = 0; } VAR declara_vars
            |
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

tipo        : INTEGER {
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
                  num_bloco_vars++;
                  desloc++;
              }
            | IDENT {
                  insere_simbolo(cria_simbolo(var_simples, token, cria_atributos_var_simples(t_indefinido, desloc)));

                  num_vars++;
                  num_bloco_vars++;
                  desloc++;
            }
;

lista_idents: lista_idents VIRGULA lista_aux
            | lista_aux
;

lista_aux: IDENT
         | NUMERO
;



comando_composto: T_BEGIN comandos T_END

comandos:
         | comando PONTO_E_VIRGULA comandos
         | comando
;

comando: NUMERO DOIS_PONTOS comando_sem_rotulo
         | comando_sem_rotulo

comando_sem_rotulo:
         | comando_repetitivo
                  
;

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

   yyin=fp;
   yyparse();

   return 0;
}
