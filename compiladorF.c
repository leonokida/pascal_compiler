
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
        case soma:
            return "SOMA";
        case subt:
            return "SUBT";
        case div:
            return "DIVI";
        case mult:
            return "MULT";
        case and:
            return "CONJ";
        case or:
            return "DISJ";
        case not:
            return "NEGA";
        case menor:
            return "CMME";
        case maior:
            return "CMMA";
        case igual:
            return "CMIG";
        case diferente:
            return "CMDG";
        case menor_ou_igual:
            return "CMEG";
        case maior_ou_igual:
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
        atributos_var_simples *atr = (atributos_var_simples *)simbolo->atributos;
        sprintf(comando, "ARMZ %d, %d", simbolo->nivel, atr->deslocamento);
        break;
    
    case param_formal:
        atributos_param_formal *atr = (atributos_param_formal *)simbolo->atributos;
        sprintf(comando, "ARMZ %d, %d", simbolo->nivel, atr->deslocamento);
        break;

    default:
        sprintf(mensagem_erro, "read() - %s não é variável ou parâmetro", token);
        imprimeErro(mensagem_erro);
        break;
    }
    geraCodigo(NULL, comando);

}