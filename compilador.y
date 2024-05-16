
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
int num_params

entrada_tabela_simbolos *ident_comando;

pilha_t *tab_simbolos;
pilha_t *pilha_rotulos;
pilha_t *operacoes_pilha;
pilha_t *expressoes_pilha;
pilha_t *termos_pilha;
pilha_t *fatores_pilha;
pilha_t *num_vars_pilha;
pilha_t *ident_comando_pilha;
pilha_t *rotulos;

char comando[50];
char mensagem_erro[100];
char ident[TAM_TOKEN];

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
      insere_topo(&num_vars_pilha, &num_bloco_vars);

      insere_topo(&rotulos_pilha, next_rot());

      Gera DSVS com rotulo
      char *rotulo = stack_item(rotulos, rotulos->top);
      sprintf(comando, "DSVS %s", rotulo);
      geraCodigo(NULL, comando);
   //}
   parte_declara_subrotinas
   {
      // Gera NADA com rotulo
      char *rotulo = stack_pop(rotulos);
      geraCodigo(rotulo, "NADA");
      free(rotulo);
   }
   comando_composto
   {
      int *temp = stack_pop(num_vars_stack);
      num_bloco_vars = (*temp);
      free(temp);

      eliminaNivelLex(nivelLex+1);

      if (num_bloco_vars > 0) {
         eliminaTS(num_bloco_vars);
         sprintf(comando, "DMEM %d", num_bloco_vars);
         geraCodigo(NULL, comando);
      }

   }
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
      atributos_var_simples *atr_var = cria_atributos_var_simples(t_indefinido, desloc);
      entrada_tabela_simbolos *entrada = cria_simbolo(var_simples, token, atr_var);
      insere_simbolo(entrada);
      num_vars++;
      num_vars_bloco++;
      desloc++;
   }
   | IDENT 
   {
      atributos_var_simples *atr_var = cria_atributos_var_simples(t_indefinido, desloc);
      entrada_tabela_simbolos *entrada = cria_simbolo(var_simples, token, atr_var);
      insere_simbolo(entrada);
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

/* REGRA 12 */
declara_proc: PROCEDURE IDENT
            {
               char *rotulo;

               nivelLex++;

               // Adiciona procedimento à tabela de simbolos
               if (busca(token) == -1) {
                  insere_topo(rotulos, next_rot());
                  rotulo = obter_item_pilha(rotulos, rotulos->top);
                  insere_simbolo(token, cat_procedimento,
                     cria_atributos_procedimento(rotulo));
               }

            }
            param_formais
            PONTO_E_VIRGULA declara_proc_extra
;

/* REGRA 12 - extra */
declara_proc_extra: FORWARD PONTO_E_VIRGULA { nivelLex--; }
            | {
               char *rotulo;

               // Gera ENPR k com rotulo
               rotulo = obter_item_pilha(rotulos, rotulos->top);
               sprintf(comando, "ENPR %d", nivelLex);
               geraCodigo(rotulo, comando);

            } bloco PONTO_E_VIRGULA
            {
               char *rotulo;

               entrada_tabela_simbolos *simb = obter_ultimo_simbolo_categoria(cat_procedimento);
               atributos_procedimento *atrProc = simb->atributos;

               // Gera RTPR
               sprintf(comando, "RTPR %d, %d", nivelLex, atrProc->num_params);
               geraCodigo(NULL, comando);

               retira_simbolos(atrProc->num_params);

               nivelLex--;

               rotulo = remove_topo(rotulos);
               free(rotulo);
            }
;

/* REGRA 13 */
declara_func: FUNCTION IDENT
            {
               char *rotulo;

               nivelLex++;

               // Se não existe, adiciona função à tabela de simbolos
               if (busca(token) == -1) {
                  insere_simbolo(rotulos, next_rot());
                  rotulo = obter_item_pilha(rotulos, rotulos->top);
                  insere_simbolo(token, cat_funcao, cria_atributos_funcao(rotulo));
               }

            }
            param_formais DOIS_PONTOS tipo
            {
               switch (simbolo) {
                  case simb_integer:
                     atualiza_tipo_funcao(obter_ultimo_simbolo_categoria(cat_funcao), tipo_integer);
                     break;
                  case simb_boolean:
                     atualiza_tipo_funcao(obter_ultimo_simbolo_categoria(cat_funcao), tipo_boolean);
                     break;
                  default:
                     break;
               }
            }
            PONTO_E_VIRGULA declara_func_extra
;

/* REGRA 13 - extra */
declara_func_extra: FORWARD PONTO_E_VIRGULA { nivelLex--; }
            | {
               char *rotulo;

               // Gera ENPR k com rotulo
               rotulo = obter_item_pilha(rotulos, rotulos->top);
               sprintf(comando, "ENPR %d", nivelLex);
               geraCodigo(rotulo, comando);

            } bloco PONTO_E_VIRGULA
            {
               char *rotulo;

               entrada_tabela_simbolos *simb = obter_ultimo_simbolo_categoria(cat_funcao);
               atributos_funcao *atrFuncao = simb->atributos;

               // Gera RTPR
               sprintf(comando, "RTPR %d, %d", nivelLex, atributos_funcao->num_params);
               geraCodigo(NULL, comando);

               retira_simbolos(atrFuncao->num_params);

               nivelLex--;

               rotulo = remove_topo(rotulos);
               free(rotulo);
            }
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

      tipo tipo_bool = t_boolean;
      insere_topo(&expressoes_pilha, &tipo_bool);

      operacoes *op = (operacoes *)remove_topo(&operacoes_pilha);
      sprintf(comando, "%s", gera_operacao_mepa(*op));
      geraCodigo(NULL, comando);
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
   }
   | sinal termo
   {
      tipo *t1 = (tipo *)remove_topo(&termos_pilha);
      insere_topo(&expressoes_pilha, t1);

      operacoes *op = (operacoes *)remove_topo(&operacoes_pilha);
      // inverte sinal do termo
      if (*op == op_subt) {
         sprintf(comando, "INVR");
         geraCodigo(NULL, comando);
      }
   }
   | termo
   {
      tipo *t1 = (tipo *)remove_topo(&termos_pilha);
      insere_topo(&expressoes_pilha, t1);
   }
;

/* usado em expressão simples */
sinal_ou_or: sinal
   | OR
   {
      operacoes op = op_or;
      insere_topo(&operacoes_pilha, &op);
   }
;

sinal: SOMA
   {
      operacoes op = op_soma;
      insere_topo(&operacoes_pilha, &op);
   }
   | SUBTRAI
   {
      operacoes op = op_subt;
      insere_topo(&operacoes_pilha, &op);
   }
;

/* regra 28 */
termo: fator
   {
      tipo *t1 = (tipo *)remove_topo(&fatores_pilha);
      insere_topo(&termos_pilha, t1);
   }
   | termo operacao_termo fator
   {
      tipo *t1, *t2;
      t1 = (tipo *)remove_topo(&termos_pilha);
      t2 = (tipo *)remove_topo(&fatores_pilha);

      if (*t1 != *t2)
         imprimeErro("Termo usa tipos diferentes!");

      insere_topo(&termos_pilha, t1);
      operacoes *op = remove_topo(&operacoes_pilha);
      sprintf(comando, "%s", gera_operacao_mepa(*op));
      geraCodigo(NULL, comando);
   }
;

operacao_termo: MUL
   {
      operacoes op = op_mult;
      insere_topo(&operacoes_pilha, &op);
   }
   | DIV
   {
      operacoes op = op_div;
      insere_topo(&operacoes_pilha, &op);
   }
   | AND
   {
      operacoes op = op_and;
      insere_topo(&operacoes_pilha, &op);
   }
;

/* regra 29 */
fator: IDENT
   {
      entrada_tabela_simbolos *simb =  busca(token);
      tipo t;

      if (simb == NULL) {
         sprintf(mensagem_erro, "Identificador %s não encontrado", token);
         imprimeErro(mensagem_erro);
      }

      switch(simb->cat) {
         case var_simples:
            atributos_var_simples *atr_var = (atributos_var_simples *)simb->atributos;
            t = atr_var->tipo_var;
            break;

         case funcao:
            atributos_funcao *atr_func = (atributos_funcao *)simb->atributos;
            t = atr_func->tipo_funcao;
            break;

         case param_formal:
            atributos_param_formal *atr_param = (atributos_param_formal *)simb->atributos;
            t = atr_param->tipo_param;
            break; 
      }

      strncpy(ident, token, strlen(token));
      ident[strlen(token)] = '\0';

      insere_topo(&fatores_pilha, &t);
   }
   var_ou_func
   | NUMERO
   {
      sprintf(comando, "CRCT %s", token);
      geraCodigo(NULL, comando);

      tipo inteiro = t_integer;
      insere_topo(&fatores_pilha, &inteiro);
   }
   | ABRE_PARENTESES expressao FECHA_PARENTESES
   {
      tipo *t = (tipo *)remove_topo(&expressoes_pilha);
      insere_topo(&fatores_pilha, t);
   }
   | NOT fator
;

var_ou_func: variavel
   | chamada_de_funcao
;

variavel:
   {
      entrada_tabela_simbolos *simb = busca(ident);
      if (simb == NULL) {
         sprintf(mensagem_erro, "Símbolo %s não encontrado", ident);
         imprimeErro(mensagem_erro);
      }
      gera_carregamento(simb);
   }
;

chamada_de_funcao:
;

/* regra 26 */
relacao: IGUAL
   {
      operacoes op = op_igual;
      insere_topo(&operacoes_pilha, &op);
   }
   | DIFERENTE
   {
      operacoes op = op_diferente;
      insere_topo(&operacoes_pilha, &op);
   }
   | MENOR
   {
      operacoes op = op_menor;
      insere_topo(&operacoes_pilha, &op);
   }
   | MENOR_OU_IGUAL
   {
      operacoes op = op_menor_ou_igual;
      insere_topo(&operacoes_pilha, &op);
   }
   | MAIOR
   {
      operacoes op = op_maior;
      insere_topo(&operacoes_pilha, &op);
   }
   | MAIOR_OU_IGUAL
   {
      operacoes op = op_maior_ou_igual;
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
comando_sem_rotulo: IDENT
   {
      ident_comando = busca(token);
      if (ident_comando == NULL) {
         sprintf(mensagem_erro, "Símbolo %s não encontrado", token);
         imprimeErro(mensagem_erro);
      }
   }
   trata_ident
   //| desvio
   | comando_repetitivo
   | comando_condicional
   | comando_composto
   | comando_read
   | comando_write            
;

trata_ident: atribuicao
   | chama_proc
;

atribuicao: ATRIBUICAO
   {
      insere_topo(&ident_comando_pilha, ident_comando);
   }
   expressao
   {
      ident_comando = remove_topo(&ident_comando_pilha);
      tipo *t = remove_topo(&expressoes_pilha);

      switch(ident_comando->cat) {
         case var_simples:
            atributos_var_simples *atr_var = (atributos_var_simples *)ident_comando->atributos;
            if (atr_var->tipo_var != *t)
               imprimeErro("Atribuição de valor que não é do tipo da variável");
            
            sprintf(comando, "ARMZ %d, %d", ident_comando->nivel, atr_var->deslocamento);
            break;

         case param_formal:
            atributos_param_formal *atr_param = (atributos_param_formal *)ident_comando->atributos;
            if (atr_param->tipo_param != *t)
               imprimeErro("Atribuição de valor que não é do tipo da variável");

            if (atr_param->pass == pass_valor)
               sprintf(comando, "ARMZ %d, %d", ident_comando->nivel, atr_param->deslocamento);
            else if (atr_param->pass == pass_referencia)
               sprintf(comando, "ARMI %d, %d", ident_comando->nivel, atr_param->deslocamento);
            else
               imprimeErro("Tipo de passagem do símbolo indefinido");
            break;

         case funcao:
            atributos_funcao *atr_func = (atributos_funcao *)ident_comando->atributos;
            if (atr_func->tipo_funcao != *t)
               imprimeErro("Atribuição de valor que não é do tipo da variável");

            sprintf(comando, "ARMZ %d, %d", ident_comando->nivel, atr_func->deslocamento);
            break;

         default:
            sprintf(mensagem_erro, "Um valor não pode ser atribuído ao símbolo %s", ident_comando->id);
            imprimeErro(mensagem_erro);
            break;
      }

      geraCodigo(NULL, comando);
      ident_comando = NULL;
   }
;

chama_proc:
;

/* regra 23 */
comando_repetitivo:
	WHILE
	{
		char *WhileInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *WhileFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		insere_topo(&pilha_rotulos, WhileInicio); // 1
		insere_topo(&pilha_rotulos, WhileFim); // 0
		geraCodigo(pega_rotulo(pilha_rotulos, 1), "NADA");
	}
	expressao DO
	{
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", pega_rotulo(pilha_rotulos, 0));
		geraCodigo(NULL, dsvf);
	}
	comando_composto
	{
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", pega_rotulo(pilha_rotulos, 1));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s", pega_rotulo(pilha_rotulos, 0));
		geraCodigo(rot, "NADA");

		remove_topo(&pilha_rotulos);
      remove_topo(&pilha_rotulos);
	}
;

/* regra 22 */
comando_condicional: 
   {
      char * RotElse = cria_rotulo(rotulo_print);
      rotulo_print++;
      char * RotFim = cria_rotulo(rotulo_print);
      rotulo_print++;

      insere_topo(&pilha_rotulos, RotElse); // 1
      insere_topo(&pilha_rotulos, RotFim); // 0
   }
   bloco_if bloco_else
   {
      remove_topo(&pilha_rotulos);
      remove_topo(&pilha_rotulos);
   }
;

bloco_if: IF expressao
   {
      // verifica se expressão é booleana
      tipo *t = (tipo *)remove_topo(&expressoes_pilha);

      if (*t != t_boolean){
         imprimeErro("Expressão não é booleana");
      }

      // Gera DSVF com rotulo
      sprintf(comando, "DSVF %s", pega_rotulo(pilha_rotulos, 1));
      geraCodigo(NULL, comando);
   }
   THEN comando_sem_rotulo
;

bloco_else: ELSE
   {
      // gera desvio para fim do if
      sprintf(comando, "DSVS %s", pega_rotulo(pilha_rotulos, 0));
      geraCodigo(NULL, comando);

      // gera rotulo do else
      geraCodigo(pega_rotulo(pilha_rotulos, 1), "NADA");
   }
   comando_sem_rotulo
   {
      // gera rotulo de fim do if
      geraCodigo(pega_rotulo(pilha_rotulos, 0), "NADA");
   }
   | %prec LOWER_THAN_ELSE
   {
      // gera rotulo do else
      geraCodigo(pega_rotulo(pilha_rotulos, 1), "NADA");
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
   inicializa_pilha(&ident_comando_pilha);

   yyin=fp;
   yyparse();

   return 0;
}
