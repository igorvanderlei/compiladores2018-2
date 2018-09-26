%{
#include <stdio.h>
//#include "tabela.h"

//tabela tab;

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
						//instalar_simbolo(tab);
						printf("<ID, %d>", 1);
					}


%%

int yywrap() {
	return 0;
}
int main(int argc, char * argv[]) {
	//inicializar(&tab);
	yylex();
}
