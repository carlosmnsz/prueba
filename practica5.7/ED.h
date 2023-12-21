/* ED.h */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char* EtiquetaEntrada;
	char* EtiquetaSalida;
	char* EtiquetaElse;
	char* NombreVarControl;
}DescriptorDeInstrControl;

typedef enum {
	MARCA = 0, 
	FUNCION, 
	VARIABLE, 
	PAR_FORMAL,
	DESCRIPTOR
} tEntrada;

typedef enum {
	NO_ASIG = 0, //NO ASIGNADO (PARA CUANDO AUN NO HEMOS DECLARADO EL TIPO DE LA VARIABLE)
	ENTERO, 
	REAL, 
	CARACTER, 
	BOOLEANO, 
	STRING, 
	DESC //DESCONOCIDO O ERRONEO
} tDato;

typedef struct {
	tEntrada entrada; //TIPO DE ENTRADA
	char *lexema;
	tDato tipoDato; //TIPO DE DATO
	int nParam; //NUMERO DE PARAMETROS
	
	//DIMENSIONES DE LA MATRIZ
	unsigned int numDim;
	int tamDim1;
	int tamDim2;

	DescriptorDeInstrControl descriptor;
} entradaTS;

typedef struct {
	int atrib; //ATRIBUTOS (SI LOS TIENE)
	char *lexema; 
	tDato tipo; //TIPO DE DATO

	//DIMENSIONES DE LA MATRIZ
	unsigned int numDim;
	int tamDim1;
	int tamDim2;

    char* codigo;
} atributos;


