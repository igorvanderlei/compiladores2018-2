%{
#include <stdlib.h>
#include <string.h>
void yyerror(char *);
#include "y.tab.h"
%}
%%
[0-9]+	{ yylval = atoi(yytext);
          return INTEGER;
				}

[0-9]+\.[0-9]+	{
							float *ptr_valor = (float *) malloc(sizeof(float));
							*ptr_valor = atof(yytext);
							yylval = (int) ptr_valor;
          		return FLOAT;
				}


[-+*\/\(\)\n]	{return *yytext; }


[ \t] 	; /* skip whitespace */
. 	yyerror("invalid character");
%%
int yywrap(void) {
return 1;
}

