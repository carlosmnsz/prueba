#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;

extern FILE * yyin ;
extern int yylineno ;

int yyparse ( void );

void yyerror ( char * s ){
   fprintf ( stderr , "[Linea %2d] *** %s\n" , yylineno , s) ;
}

FILE *abrirEntrada(int argc, char *argv[] )
{
	FILE *f = NULL;
	if (argc > 1) {
		f = fopen(argv[1], "r");
		if (f==NULL) {
			fprintf(stderr, "fichero ´%s´ no encontrado\n", argv[1]);
			exit(1);
		} else{
			printf("leyendo fichero ´%s´.\n", argv[1]);
		}
	}else {
		printf("leyendo entrada estándar.\n");
	}
	return f;
}

int main( int argc, char *argv[1])
{
	yyin = abrirEntrada(argc, argv);

	return yyparse();
}

