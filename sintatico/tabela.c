#include <stdlib.h>
#include <stdio.h>
#include "tabela.h"
#include "y.tab.h"



/* Insere o símbolo na tabela do contexto atual. */
void inserir_simbolo(tabela *t, simbolo *s) {
	no_tabela *no = (no_tabela *) malloc(sizeof(no_tabela));
	no->dado = s;
	no->proximo = t->primeiro;
	t->primeiro = no;
}

/* Localiza o símbolo na hierarquia das tabelas de símbolos */
simbolo * localizar_simbolo (tabela *contexto, char *lexema){
	return NULL;
}

/* Localiza o símbolo apenas no contexto atual, sem considerar a hierarquia */
simbolo * localizar_simbolo_contexto (tabela *contexto, char *lexema) {
	return NULL;
}

/* Simula o construtor do símbolo */
simbolo *  criar_simbolo (char *lexema, int tipo) {
	simbolo *novo = (simbolo *) malloc(sizeof(simbolo));
	novo->tipo = tipo;
	novo->lexema = strdup(lexema);
	novo->val.dval = 0;
	return novo;
}

pilha_contexto* empilhar_contexto(pilha_contexto *pilha, tabela *contexto) {
	pilha_contexto *novo = (pilha_contexto *) malloc (sizeof(pilha_contexto));
	novo->anterior = pilha;
	novo->dado = contexto;
	return novo;
}

/* Simula o construtor da tabela de símbolos */
tabela * criar_contexto(tabela *pai) {
	tabela *novo = (tabela *) malloc(sizeof(tabela));
	novo->pai = pai;
	novo->primeiro = NULL;
	return novo;
}

void desempilhar_contexto(pilha_contexto **pilha) {
	if(*pilha != NULL)
		*pilha = (*pilha)->anterior;
}

tabela* topo_pilha(pilha_contexto *pilha) {
	if(pilha == NULL)
		return NULL;
	else
		return pilha->dado;

}

void imprimir_contexto(tabela *t) {
	no_tabela * temp = t->primeiro;
	printf("----------------------------------\n");
	while(temp != NULL) {
		if(temp->dado->tipo == INT) 
			printf("\t INT: %s (%d)\n", temp->dado->lexema, temp->dado->val.dval);
		else
			printf("\t FLOAT: %s (%d)\n", temp->dado->lexema, temp->dado->val.dval);	
		temp = temp->proximo;
	}
	printf("==================================\n");
}

