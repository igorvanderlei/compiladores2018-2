%{
#include <stdio.h>
#include "tabela.h"

tabela_simbolo tab;
%}

ws			[ \t\n]
letra		[a-zA-Z]
digito	[0-9]
numero	{digito}+
id			{letra}({letra}|{digito})*
%%

{ws}			{}
if				{ printf("<IF, NULL>"); }
"<="				{ printf("<RELOP, LE>"); }
{id}			{ //criar o símbolo, inserir na tabela
						//através do método instalar_simbolo
						int cod = instalar_simbolo(yytext);
						printf("<ID, %d>", cod);
					}


%%

int main(int argc, char *argv[]) {
	inicializar(&tab);
	yylex();
}

int yywrap() { return 1; }
