#ifndef TABELA_H
#define TABELA_H

#include <string.h>
/* Como estamos implementando um interpretador, precisamos armazenar o valor das
variáveis na tabela de símbolos. Este valor pode ser do tipo float ou inteiro */
typedef union valor {
	int dval;
	float fval;
} valor;

typedef struct simbolo {
	int tipo;
	char *lexema;
	valor val;
} simbolo;

/* Nó da lista encadeada de símbolos */
typedef struct no_tabela {
	simbolo *dado;
	struct no_tabela *proximo;
} no_tabela;

/* Encapsulamento da tabela de símbolos. Observe o ponteiro para o pai,
que permite implementar a ideia da tabela contextual. */
typedef struct tabela {
	no_tabela *primeiro;
	no_tabela *ultimo;
	struct tabela *pai;
} tabela;

/* Nó da estrutura de dados pilha, utilizada como auxiliar para montar a árvore de 
tabelas de símbolos */
typedef struct pilha_contexto  {
	tabela *dado;
	struct pilha_contexto *anterior;
} pilha_contexto;

/* Insere o símbolo na tabela do contexto atual. */
void inserir_simbolo(tabela *t, simbolo *s);

/* Localiza o símbolo na hierarquia das tabelas de símbolos */
simbolo * localizar_simbolo (tabela *contexto, char *lexema);


/* Localiza o símbolo apenas no contexto atual, sem considerar a hierarquia */
simbolo * localizar_simbolo_contexto (tabela *contexto, char *lexema);

/* Simula o construtor do símbolo */
simbolo *  criar_simbolo (char *lexema, int tipo);


pilha_contexto* empilhar_contexto(pilha_contexto *pilha, tabela *contexto);
void desempilhar_contexto(pilha_contexto **pilha);
tabela* topo_pilha(pilha_contexto *pilha);

/* Simula o construtor da tabela de símbolos */
tabela * criar_contexto(tabela *pai);

void imprimir_contexto(tabela *t);

#endif
