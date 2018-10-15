%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token INTEGER FLOAT
%left '+' '-'
%left '*' '/'

%%

program:
	program expr '\n' {	printf("%d\n", $2);}
	| ;

expr:
		INTEGER		{	$$ = $1; }
		| FLOAT   { float *ptf_val = (float *) $1;
								$$ = *ptf_val; }
		| expr '+' expr {
									$$ = $1 + $3;
							}
		| expr '-' expr {
									$$ = $1 - $3;
							}
		| expr '*' expr {
									$$ = $1 * $3;
							}
		| expr '/' expr {
									$$ = $1 / $3;
							}
		| '(' expr ')' {
									$$ = $2;
							}
	;

%%

void yyerror(char *s) {
	fprintf(stderr, "Deu erro: %s\n", s);
}

int main(void) {
	yyparse();
	return 0;
}
