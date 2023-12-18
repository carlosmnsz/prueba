/* Fichero GCI.h */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int etiqueta = 0;
int decElse = 0;
entradaTS TF[MAX_ENTRADAS];

void abrirFicherosGCI();

void cerrarFicherosGCI();

char* tDatoAString(tDato e);

void GCI_DeclarPar();

char* generarEtiqueta();

void generaDecVar(atributos a);
void genera(int type,atributos dest,atributos a, atributos op, atributos b);
/*	1. else y salida
	2. entrada y salida
*/
void insertaDesc(int type);
void eliminaDesc();
/*	1.if con else
	2.while
	3.if sin else
*/
void insertaCond(int type);
void insertaEtiqElse();

void insertaEtiqSalida();
void insertaEtiqEntrada();
void insertaGotoEntrada();
void generaEntSal(int type,atributos a);