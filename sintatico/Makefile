all: interpretador
interpretador: y.tab.c lex.yy.c tabela.c tabela.h
		gcc -o interpretador *.c
y.tab.c: interpretador.yacc
		yacc -d interpretador.yacc
lex.yy.c: interpretador.lex
		lex interpretador.lex
clean:
		rm y.tab.c y.tab.h lex.yy.c interpretador
test: interpretador source.ccc
		./interpretador < source.ccc

