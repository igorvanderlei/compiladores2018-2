#ifndef TABELA_H
#define TABELA_H

typedef struct simbolo {
	int cod;
	char *lexema;
	int tipo;
} simbolo;


typedef struct no_tabela {
	simbolo dado;
	struct no_tabela * proximo;
} no_tabela;

typedef struct tabela_simbolo {
	no_tabela *primeiro;
	no_tabela *ultimo;
	int proximo_codigo;
} tabela_simbolo;
	
void inicializar(tabela_simbolo *tabela);
void inserir_simbolo(tabela_simbolo *tabela, simbolo s);
void exibir_tabela(tabela_simbolo *tabela);
simbolo * localizar_simbolo(tabela_simbolo *tabela, char *lexema);
simbolo * localizar_simbolo_cod(tabela_simbolo *tabela, int cod);
simbolo * criar_simbolo(int cod, char *lexema, int tipo);
//criar o símbolo, com o código automático
//retorna o código gerado
int instalar_simbolo(char *lexema);


	

#endif
