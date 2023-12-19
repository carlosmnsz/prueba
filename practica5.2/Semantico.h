#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ED.h"

#define YYSTYPE atributos
#define MAX_ENTRADAS 500

extern long int TOPE;

extern entradaTS ts[MAX_ENTRADAS];
// Variable que almacena la linea actual por la cual se va analizando	
extern int lineaActual;
//1 si estamos declarando 0 si estamos utilizando la variable
extern int declarVar;
// Variable que indica el comienzo de una declaracion de un subprograma o funcion
// 1 si estoy en cabec_subprog 0 si estoy en bloque
extern int subProg;
//Variable que indica si se estan declarando parametros formales dentro
//de la definicion de una funcion
extern int declarPar;
// Variable global para almacenar el tipo en las declaraciones
extern tDato tipoGlobal;
//Variable que cuenta el numero de parametros formales de una funcion
extern int numParam;
// Almacena el indice de la TS de la funcion que se esta analizando
extern int funcionActual;
extern int listaGlobal;
extern int paramCambiar;

FILE * principal;

extern int paramInsertar;


/**
 * Indica si el atributo es un array o no
 */
int esArray(atributos e);

/**
 * Indica que si siendo arrays los dos entradaTS tienen el mismo tamanyo.
 */
int igualTam(atributos e1, atributos e2);

/**
 * Almacena en la variable global tipo el tipo de la variable
 */
void asignaTipoGlobal(atributos elem);




//------------  Funciones de manejo de la Tabla de Simbolos  ------------------------
/**
  * Inserta una entrada a la tabla de simbolos e incrementa el TOPE en 1
**/
int TS_AddEntrada(entradaTS ent);

/**
  * Elimina el elemento TOPE de tabla de simbolos y decrementa el TOPE en 1
**/
int TS_DelEntrada();

/**
 * Elimina de la tabla de simbolos todas las entradas hasta la ultima marca de inicio de bloque, tambien incluida
 */
void TS_VaciarEntradas();

/**
  * Busca un identificador en la TS para comprobar que ha sido declarado
**/
int TS_BuscarIdent(atributos elem);

/**
  * Busca una entrada dado su nombre:
  * Si la encuentra devuelve el indice donde se encuentra la entrada
  * Si no la encuentra devuelve -1
**/
int TS_BuscarFuncion(atributos elem);

/**
 * Inserta un nuevo identificador en la tabla de simbolos
 */
void TS_InsertaIdent(atributos elem);

/**
 * Inserta una marca de comienzo de un bloque
 */
void TS_InsertaMarca();

/**
 * Inserta una entrada de subprograma en la tabla de simbolos
*/
void TS_InsertaSubprog(atributos elem);

/**
 * Inserta una entrada de parametro formal de un subprograma en la tabla de simbolos
 */
void TS_InsertaParamFormal(atributos elem);

/**
 * Actualiza el numero de parametros de la funcion que estamos declarando
 */
void TS_ActualizaNparam(atributos elem);




//------------  Funciones para las comprobaciones semanticas ------------------------
/**
 * Busca la entrada de tipo Funcion mas proxima desde el tope de la tabla de simbolos
 * y devuelve el indice
 */
int TS_GetFuncionProxima();

/**
 * Busca el identificador en la tabla de simbolos y lo rellena en el atributo de salida
 */
void TS_GetIdent(atributos identificador, atributos* res);

/**
 * Comprobacion semantica de la operacion NOT
 */
void TS_OpUnario(atributos operador, atributos o, atributos* res);

/**
 * Comprobacion semantica de los operadores unarios + y -
 */
void TS_OpSumResUnario(atributos operador, atributos o, atributos* res);

/**
 * Comprobacion semantica de las operaciones * y /
 */
void TS_OpMulDiv(atributos o1, atributos operador, atributos o2, atributos* res);

/**
 * Comprobacion semantica de las operaciones || y XOR
 */
void TS_OpOrXor(atributos o1, atributos operador, atributos o2, atributos* res);

/**
 * Comprobacion semantica de la operacion **
 */
void TS_OpPot(atributos o1, atributos operador, atributos o2, atributos* res);

/**
 * Comprobacion semantica de las operaciones <, >, <= y >=
 */
void TS_OpRel(atributos o1, atributos operador, atributos o2, atributos* res);

/**
 * Comprobacion semantica de las operaciones == y !=
 */
void TS_OpIgual(atributos o1, atributos operador, atributos o2, atributos* res);

/**
 * Comprobacion semantica de las operaciones &&
 */
void TS_OpAnd(atributos o1, atributos operador, atributos o2, atributos* res);

/**
 * Comprobacion semantica de las operaciones binarias + y -
 */
void TS_OpSumRes(atributos o1, atributos operador, atributos o2, atributos* res);

/**
 * Comprobacion semantica de la llamada a subprograma
 */
void TS_LlamadaFuncion(atributos identificador, atributos* res);

/**
 * Comprobacion semantica de cada parametro en una llamada a una funcion
 */
void TS_CompruebaParametro(atributos parametro, int parametroAComprobar);

void TS_OpBinListas(atributos at1, atributos operador, atributos at2, atributos* res);

void TS_OpBinArroba(atributos at1, atributos operador, atributos at2, atributos* res);

void TS_OpTerciario(atributos at1, atributos at2, atributos at3, atributos* res);
//----------------------  Funciones de Impresion --------------------------------------

/**
 * Imprime como una cadena de caracteres una entrada de la tabla de simbolos dada
 */
void imprimeEntrada(int indice);

/**
  * Imprime como cadena el tipo de entrada dado
**/
void imprimeTipoEntrada(tEntrada tipo);

/**
  * Imprime como cadena el tipo de dato dado
**/ 
void imprimeTipoDato(tDato tipo);

/**
 * Imprime por pantalla la tabla de simbolos a continuacion del mensaje dado
 */
void imprimeTS();

/**
 * Imprime por pantalla un atributo dado
 */
void imprimeAtributo(atributos e, char *msj);
