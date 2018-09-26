#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(tabela_simbolo *tabela) {
	tabela->primeiro = NULL;
	tabela->ultimo = NULL;
	proximo_codigo = 1;
}


void inserir_simbolo(tabela_simbolo *tabela, simbolo s) {
	no_tabela *novo = (no_tabela *) malloc(sizeof(struct no_tabela));	
	novo->proximo = NULL;
	novo->dado = s;

	if(tabela->primeiro == NULL) {
			tabela->primeiro = tabela->ultimo = novo;
	} else {
			tabela->ultimo->proximo = novo;
			tabela->ultimo = novo;
	}
}

simbolo * criar_simbolo(int cod, char *lexema, int tipo) {
	simbolo *s = (simbolo *) malloc(sizeof(struct simbolo));
	s->cod = cod;
	s->lexema = strdup(lexema);
	s->tipo = tipo;
	return s;
}


void exibir_tabela(tabela_simbolo *tabela);
simbolo * localizar_simbolo(tabela_simbolo *tabela, char *lexema);
simbolo * localizar_simbolo_cod(tabela_simbolo *tabela, int cod);
