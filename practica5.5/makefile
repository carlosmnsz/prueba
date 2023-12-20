.SUFFIXES :

analizador : main.o Sintactico.tab.o
	gcc -o Analizador main.o Sintactico.tab.o

Sintactico.tab.o : Sintactico.tab.c
	gcc -c Sintactico.tab.c

main.o : main.c
	gcc -c main.c

Sintactico.tab.c : Sintactico.y lex.yy.c
	bison -t -v -d Sintactico.y

lex.yy.c : Lexico.lex
	flex -l Lexico.lex

clean :
	rm -f Analizador main.o Sintactico.tab.o Sintactico.tab.c lex.yy.c

all :
	make clean
	make analizador
