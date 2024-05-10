
/* -------------------------------------------------------------------
 *            Aquivo: compilador.c
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [09/08/2020, 19h:01m]
 *
 * -------------------------------------------------------------------
 *
 * Funções auxiliares ao compilador
 *
 * ------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "pilha.h"
#include "tabela_simbolos.h"


/* -------------------------------------------------------------------
 *  variáveis globais
 * ------------------------------------------------------------------- */

simbolos simbolo, relacao;
char token[TAM_TOKEN];

FILE* fp=NULL;
void geraCodigo (char* rot, char* comando) {

  if (fp == NULL) {
    fp = fopen ("MEPA", "w");
  }

  if ( rot == NULL ) {
    fprintf(fp, "     %s\n", comando); fflush(fp);
  } else {
    fprintf(fp, "%s: %s \n", rot, comando); fflush(fp);
  }
}

int imprimeErro ( char* erro ) {
  fprintf (stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}

char *gera_operacao_mepa(operacoes op) {
  switch (op) {
        case op_soma:
            return "SOMA";
        case op_subt:
            return "SUBT";
        case op_div:
            return "DIVI";
        case op_mult:
            return "MULT";
        case op_and:
            return "CONJ";
        case op_or:
            return "DISJ";
        case op_not:
            return "NEGA";
        case op_menor:
            return "CMME";
        case op_maior:
            return "CMMA";
        case op_igual:
            return "CMIG";
        case op_diferente:
            return "CMDG";
        case op_menor_ou_igual:
            return "CMEG";
        case op_maior_ou_igual:
            return "CMAG";
        default:
            return "inválido";
    }
}

void leitura(char *token) {
    entrada_tabela_simbolos *simbolo = busca(token);
    if (simbolo == NULL) {
        sprintf(mensagem_erro, "read() - Símbolo %s não encontrado", token);
        imprimeErro(mensagem_erro);
    }

    geraCodigo(NULL, "LEIT");

    switch (simbolo->cat)
    {
    case var_simples:
        atributos_var_simples *atr_var = (atributos_var_simples *)simbolo->atributos;
        sprintf(comando, "ARMZ %d, %d", simbolo->nivel, atr_var->deslocamento);
        break;
    
    case param_formal:
        atributos_param_formal *atr_param = (atributos_param_formal *)simbolo->atributos;
        sprintf(comando, "ARMZ %d, %d", simbolo->nivel, atr_param->deslocamento);
        break;

    default:
        sprintf(mensagem_erro, "read() - %s não é variável ou parâmetro", token);
        imprimeErro(mensagem_erro);
        break;
    }
    geraCodigo(NULL, comando);

}

void gera_carrega_valor(entrada_tabela_simbolos *simb) {
    switch (simb->cat) {
        case var_simples:
            atributos_var_simples *atr_var = simb->atributos;
            sprintf(comando, "CRVL %d, %d", simb->nivel, atr_var->deslocamento);
            break;

        case param_formal:
            atributos_param_formal *atr_param = simb->atributos;
            sprintf(comando, "CRVL %d, %d", simb->nivel, atr_param->deslocamento);
            break;

        default:
            imprimeErro("Símbolo não pôde ser carregado");
            break;
    }
    geraCodigo(NULL, comando);
}

void gera_carrega_valor_indireto(entrada_tabela_simbolos *simb) {
    atributos_param_formal *atr_param = simb->atributos;
    sprintf(comando, "CRVI %d, %d", simb->nivel, atr_param->deslocamento);
    geraCodigo(NULL, comando);
}

void gera_carregamento(entrada_tabela_simbolos *simb) {
    // falta cobrir casos de dentro de função
    switch (simb->cat) {
        case var_simples:
            gera_carrega_valor(simb);
            break;

        case param_formal:
            atributos_param_formal *atr_param = simb->atributos;
            if (atr_param->pass == pass_referencia)
                gera_carrega_valor_indireto(simb);
            else
                gera_carrega_valor(simb);
            break;

        case funcao:
            atributos_funcao *atr_func = simb->atributos;
            geraCodigo(NULL, "AMEM 1");
            sprintf(comando, "CHPR %s, %d", atr_func->rotulo, nivel_lex);
            geraCodigo(NULL, comando);
            break;

        default:
            sprintf(mensagem_erro, "Parâmetro %s é inválido", token);
            imprimeErro(mensagem_erro);
            break;
    }
}


void imprime_operacoes(void *op) {
    printf("ELEM: ");
    operacoes *oper = (operacoes *)op;
    switch (*oper) {
        case op_soma:
            printf("SOMA\n");
            break;
        case op_subt:
            printf("SUBT\n");
            break;
        case op_div:
            printf("DIVI\n");
            break;
        case op_mult:
            printf("MULT\n");
            break;
        case op_and:
            printf("CONJ\n");
            break;
        case op_or:
            printf("DISJ\n");
            break;
        case op_not:
            printf("NEGA\n");
            break;
        case op_menor:
            printf("CMME\n");
            break;
        case op_maior:
            printf("CMMA\n");
            break;
        case op_igual:
            printf("CMIG\n");
            break;
        case op_diferente:
            printf("CMDG\n");
            break;
        case op_menor_ou_igual:
            printf("CMEG\n");
            break;
        case op_maior_ou_igual:
            printf("CMAG\n");
            break;
        default:
            printf("inválido\n");
    }
}