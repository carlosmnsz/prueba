/* Fichero GCI.h */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int etiqueta = 0;
int paramInsertar = 0;
int temp = 0;
int decIf = 0;
int decElse = 0;
entradaTS TF[MAX_ENTRADAS];
int LIMIT = 0;
int tabulacion = 0;
int leer = 0;
int escribir = 0;
char* listaActual;
int cont_bloque = 0;

void abrirFicherosGCI();

void cerrarFicherosGCI();

void tabular();

char* tDatoAString(tDato e);

int TF_AddEntrada(entradaTS ent);

void GCI_DeclarPar();

void generarEtiqueta(int type, entradaTS* dest);
void generarUnario(atributos* dest, atributos op, atributos b);
void generarBinario(atributos* dest, atributos a, atributos op, atributos b);
void generarTerciario(atributos* dest, atributos a, atributos op1, atributos b, atributos op2, atributos c);

void generaDecVar(atributos a);
void generaDecPar(atributos a);
void genera(int type,atributos dest,atributos a, atributos op, atributos b);
void generaArroba(atributos* dest, atributos a, atributos b);
void generaArrobaMasMas(atributos dest, atributos a, atributos b, atributos c);
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

void GCI_Loopback();