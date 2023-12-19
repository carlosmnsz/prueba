#include "Semantico.h"

entradaTS TS[MAX_ENTRADAS];
int lineaActual = 1;
long int TOPE = 0;
int declarVar = 0;
int declarPar = 0;
int subProg = 0;
tDato tipoGlobal = DESC;
int numParam = 0;
int funcionActual = -1;
int listaGlobal = 0;
int paramCambiar = 0;
int paramInsertar = 0;

/**
 * Indica si el atributo es un array o no
 */
int esArray(atributos e) {
	return (e.numDim!=0);
}

/**
 * Indica que si siendo arrays los dos entradaTS tienen el mismo tamanyo.
 */
int igualTam(atributos e1, atributos e2) {
	return (e1.numDim==e2.numDim && e1.tamDim1==e2.tamDim1 && e1.tamDim2==e2.tamDim2);
}

/**
 * Almacena en la variable global tipo el tipo de la variable
 */
void asignaTipoGlobal(atributos elem) {
	tipoGlobal = elem.tipo;
}




//------------  Funciones de manejo de la Tabla de Simbolos  ------------------------
/**
  * Inserta una entrada a la tabla de simbolos 
**/
int TS_AddEntrada(entradaTS ent) {
	if(TOPE < MAX_ENTRADAS) {
		TS[TOPE].entrada=ent.entrada;
		TS[TOPE].lexema=ent.lexema;
		TS[TOPE].tipoDato=ent.tipoDato;
		TS[TOPE].nParam=ent.nParam;
		TS[TOPE].numDim=ent.numDim;
		TS[TOPE].tamDim1=ent.tamDim1;
		TS[TOPE].tamDim2=ent.tamDim2;
		TS[TOPE].descriptor=ent.descriptor;
		printf("ENT.DESCRIPTOR.ELSE: %s\n", ent.descriptor.EtiquetaElse);
		printf("TS[TOPE].DESCRIPTOR.ELSE: %s\n", TS[TOPE].descriptor.EtiquetaElse);
		TOPE++;
		//imprimeTS();
		return 1;
	} else {
		printf("ERROR PILA LLENA");
		return 0;
	}
};

/**
  * Elimina el elemento TOPE de tabla de simbolos 
**/
int TS_DelEntrada() {
	// Si la pila no está vacía. 
	if(TOPE > 0){
		TOPE--;
		return 1;
	}else{
		printf("ERROR: PILA VACIA");
		return 0;
	}
};

/**
 * Elimina de la tabla de simbolos todas las entradas hasta la ultima marca de inicio de bloque, tambien incluida
 */
void TS_VaciarEntradas() {
	while (TS[TOPE-1].entrada != MARCA && TOPE > 0) { 
		TOPE--; 
	} 
	if (TS[TOPE-1].entrada == MARCA) { 
		TOPE--; 
	}
}

/**
  * Busca un identificador en la TS para comprobar que ha sido declarado
**/
int TS_BuscarIdent(atributos elem) {

	int i = TOPE - 1;
	int encontrado = 0;
	printf("=====================\n");
	while (i > 0 && !encontrado && TS[i].entrada != MARCA) {
		printf("TS[%d]: %d\n", i, TS[i].entrada);
		if ((TS[i].entrada == VARIABLE || TS[i].entrada == PAR_FORMAL) && strcmp(elem.lexema, TS[i].lexema) == 0) {
			encontrado = 1;
		} else{
			i--;
		}
	}
	
	if(!encontrado) {
		//printf("Error linea %d. Identificador no declarado: %s\n", lineaActual, elem.lexema);
		return -1;
	} else {
		return i;
	}
}

/**
  * Busca una entrada dado su nombre:
  * Si la encuentra devuelve el indice donde se encuentra la entrada
  * Si no la encuentra devuelve -1
**/
int TS_BuscarFuncion(atributos elem) {
	int i = TOPE - 1;
	int encontrado = 0;
	
	while (i > 0 && !encontrado && TS[i].entrada != MARCA) {
		if (TS[i].entrada == FUNCION && strcmp(elem.lexema, TS[i].lexema) == 0) {
			encontrado = 1;
		} else{
			i--;
		}
	}
	
	if(!encontrado) {
		//printf("Error linea %d. Identificador no declarado: %s\n", lineaActual, elem.lexema);
		return -1;
	} else {
		return i;
	}
}




/**
 * Inserta un nuevo identificador en la tabla de simbolos
 */
void TS_InsertaIdent(atributos elem){
	//Se comprueba que no hemos llegado al tope de la pila, que el identificador no esta ya 
	//declarado previamente y que estamos declarando variables
	int j = TOPE-1;
	int encontrado = 0;
   
	if(j >= 0 && declarVar == 1) {
		//Se busca la marca de comienzo de bloue
		while((TS[j].entrada != MARCA) && (j >= 0) && !encontrado) {
			if(strcmp(TS[j].lexema, elem.lexema) != 0) {
				j--;
			}
			else {
				encontrado = 1;
				printf("Error linea %d. Identificador duplicado: %s\n", lineaActual, elem.lexema);
	 		}
		}

		//Si no hemos encontrado el identificador lo insertamos en la TS
		if(tipoGlobal==DESC){
			printf("ERROR [Lina %d]: TIPO INCORRECTO\n", lineaActual);
		}
		else{
		if(!encontrado) {
			entradaTS nuevaEntrada;
			nuevaEntrada.entrada = VARIABLE;
			nuevaEntrada.lexema = elem.lexema;
			//Asignamos el tipo desde la variable global
			nuevaEntrada.tipoDato = tipoGlobal;
			nuevaEntrada.nParam = 0;
			nuevaEntrada.numDim=listaGlobal;
			nuevaEntrada.tamDim1=elem.tamDim1;
			nuevaEntrada.tamDim2=elem.tamDim2;
			TS_AddEntrada(nuevaEntrada);
		}
		}
	}
};

/**
 * Inserta una marca de comienzo de un bloque
 */
void TS_InsertaMarca(){
	entradaTS entradaInicioBloque;

	entradaInicioBloque.entrada = MARCA;
	//strcpy(entradaInicioBloque.lexema, "{");
	entradaInicioBloque.lexema = "{";
	entradaInicioBloque.tipoDato = DESC;
	entradaInicioBloque.nParam = 0;
	entradaInicioBloque.numDim = 0;
	entradaInicioBloque.tamDim1 = 0;
	entradaInicioBloque.tamDim2 = 0;

	TS_AddEntrada(entradaInicioBloque);
	
	//Se insertan los parametros formales de la funcion como variables locales a esta
	if(subProg == 1){
		int j = TOPE - 2, marca = 0, funcion = 0;

		while(j > 0 && TS[j].entrada == PAR_FORMAL){
			//printf("\n\n");
			//imprimeEntrada(j);
			//printf("\n\n");
			if(TS[j].entrada == PAR_FORMAL) {
				entradaTS nuevaEntrada;
				nuevaEntrada.entrada = VARIABLE;
				nuevaEntrada.lexema = TS[j].lexema;
				nuevaEntrada.tipoDato = TS[j].tipoDato;
				nuevaEntrada.nParam = TS[j].nParam;
				nuevaEntrada.numDim = TS[j].numDim;
				nuevaEntrada.tamDim1 = TS[j].tamDim1;
				nuevaEntrada.tamDim2 = TS[j].tamDim2;
				TS_AddEntrada(nuevaEntrada);
			}
			j--;
		}
	}
	
}

/**
 * Inserta una entrada de subprograma en la tabla de simbolos
*/
void TS_InsertaSubprog(atributos elem) {
	entradaTS entradaSubProg;

	entradaSubProg.entrada = FUNCION;
	entradaSubProg.lexema = elem.lexema;
	entradaSubProg.nParam = 0;
	entradaSubProg.numDim = 0;
	entradaSubProg.tamDim1 = 0;
	entradaSubProg.tamDim2 = 0;
	entradaSubProg.tipoDato = NO_ASIG;

	funcionActual = TOPE;
	TS_AddEntrada(entradaSubProg);
}

/**
 * Inserta una entrada de parametro formal de un subprograma en la tabla de simbolos
 */
void TS_InsertaParamFormal(atributos elem) {
	int j = TOPE - 1, encontrado = 0;

	while((j != funcionActual)  && (!encontrado) ) {
		if(strcmp(TS[j].lexema, elem.lexema) != 0) {
			j--;
		}
		else {
			encontrado = 1;
			printf("Error linea %d. Parametro duplicado: %s\n", lineaActual, elem.lexema);
 		}
	}
	if(!encontrado) {
		entradaTS nuevaEntrada;
		nuevaEntrada.entrada = PAR_FORMAL;
		nuevaEntrada.lexema = elem.lexema;
		//Asignamos el tipo desde la variable global
		nuevaEntrada.tipoDato = tipoGlobal;
		nuevaEntrada.nParam = 0;
		nuevaEntrada.numDim = elem.numDim;
		nuevaEntrada.tamDim1 = elem.tamDim1;
		nuevaEntrada.tamDim2 = elem.tamDim2;
		TS_AddEntrada(nuevaEntrada);
		paramCambiar++;
		paramInsertar++;
	}
	
}

/**
 * Actualiza el numero de parametros de la funcion que estamos declarando
 */
void TS_ActualizaNparam(atributos elem) {
	TS[funcionActual].nParam = numParam;
	TS[funcionActual].numDim=elem.numDim;
	TS[funcionActual].tamDim1=elem.tamDim1;
	TS[funcionActual].tamDim2=elem.tamDim2;
}

void actualizarTipo(){
	for(int j = TOPE-1; j>=0 && paramCambiar!=0; j--){
		//printf("LISTASGLOBALES = %d\n", listasGlobales);
		TS[j].numDim = listaGlobal;
		TS[j].tipoDato = tipoGlobal;
		paramCambiar--;
	}
}


//------------  Funciones para las comprobaciones semanticas ------------------------

/**
 * Busca la entrada de tipo Funcion mas proxima desde el tope de la tabla de simbolos
 * y devuelve el indice
 */
int TS_GetFuncionProxima() {
	int i = TOPE - 1;
	int encontrado = 0;
	while (i > 0 && !encontrado) {
		if (TS[i].entrada == FUNCION) {
			encontrado = 1;
		} else {
			i--;
		}
	}
	
	if(!encontrado) {
		return -1;
	} else {
		return i;
	}
}

/**
 * Busca el identificador en la tabla de simbolos y lo rellena en el atributo de salida
 */
void TS_GetIdent(atributos identificador, atributos* res) {
	int indice = TS_BuscarIdent (identificador);
	//printf("%d\n", indice);
	//printf("%s %d %d\n", TS[indice].lexema, TS[indice].entrada, TS[indice].tipoDato);
	if(indice==-1) {
		printf("ERROR [Linea %d]: NO EXISTE EL IDENTIFICADOR %s.\n", lineaActual, identificador.lexema);
	}
	else{
		res->lexema = strdup(TS[indice].lexema);
		res->tipo = TS[indice].tipoDato;
		res->numDim = TS[indice].numDim;
		res->tamDim1 = TS[indice].tamDim1;
		res->tamDim2 = TS[indice].tamDim2;
	}
}

/**
 * Comprobacion semantica de la operacion NOT
 */
void TS_OpUnario(atributos operador, atributos o, atributos* res) {
	if(operador.atrib==0){
		if (o.tipo != BOOLEANO || esArray(o)) {
			printf("ERROR SINTÁCTICO [Linea %d]: LA VARIABLE %s NO ES DE TIPO LÓGICO (NOT)\n", lineaActual, o.lexema);
			//hay_error=1;
		}
		res->tipo = BOOLEANO ;
		res->numDim = 0;
	}
	else if(operador.atrib==1){
		if(o.numDim==0){
			printf("ERROR SINTÁCTICO [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, o.lexema);
		}
		res->tipo = ENTERO ;
		res->numDim = 0;
	}
	else if(operador.atrib==2){
		if(o.numDim==0){
			printf("ERROR SINTÁCTICO [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, o.lexema);
		}
		res->tipo = o.tipo ;
		res->numDim = 0;
	}
	//char* nuevoLexema;
	//strcpy(nuevoLexema, operador.lexema);
	//strcat(nuevoLexema, o.lexema);
	//res->lexema=nuevoLexema;

}

/**
 * Comprobacion semantica de los operadores unarios + y -
 */
void TS_OpSumResUnario(atributos operador, atributos o, atributos* res) {
	if ((o.tipo != REAL && o.tipo != ENTERO) || esArray(o)) {
		printf("ERROR SINTÁCTICO [Linea %d]: EL OPERADOR %s ESPERABA UNA VARIABLE DE TIPO ENTERO\n", lineaActual, operador.lexema);
		//hay_error=1;
	}
	res->tipo = o.tipo;
	res->numDim = 0;
	res->tamDim1 = 0;
	res->tamDim2 = 0;
	//char* nuevoLexema;
	//strcpy(nuevoLexema, operador.lexema);
	//strcat(nuevoLexema, o.lexema);
	//res->lexema=nuevoLexema;
}

/**
 * Comprobacion semantica de las operaciones * y /
 */
void TS_OpMulDiv(atributos o1, atributos operador, atributos o2, atributos* res) {

	if (o1.tipo != o2.tipo) {
		printf("Error muldiv linea %d: El operador * o / espera que los tipos de los operandos sean iguales.\n", lineaActual);
		//hay_error=1;
		return;
	}
	if (o1.tipo != ENTERO && o1.tipo != REAL) { // O bien son enteros, o bien reales
		printf("Error muldiv linea %d: Tipo invalido de los operandos. Se esperaba Entero o Real para los dos operandos.\n", lineaActual);
		//hay_error=1;
		return;
	}
	
	if (esArray(o1) && esArray(o2)) { // Si ambos son array
		if(igualTam(o1,o2)) { // Si tienen el mismo tamanyo
			res->tipo = o1.tipo;
			res->numDim = o1.numDim;
			res->tamDim1 = o1.tamDim1;
			res->tamDim2 = o1.tamDim2;
		} else { // Si no tienen el mismo tamanyo, error
			printf("Error muldiv linea %d: Los arrays no son de distinto tamanyo.", lineaActual);	
			//hay_error=1;
			return;
		}
	} else { // Si ambos no son array
		if (esArray(o1) && !esArray(o2)) { // Si el primero es array, pero el segundo no, es válido tanto para multi como división
			res->tipo = o1.tipo;
			res->numDim = o1.numDim;
			res->tamDim1 = o1.tamDim1;
			res->tamDim2 = o1.tamDim2;
		} 
		if (!esArray(o1) && esArray(o2)) { // Si el primero no es array, pero el segundo sí
			if (strcmp(operador.lexema,"/")==0) { // En el caso de la división no es válido
				printf("Error muldiv linea %d: No se puede dividir un valor con un array.", lineaActual);
				//hay_error=1;
				return;
			} else { // Pero en el caso de la multiplicación, sí
				res->tipo = o2.tipo;
				res->numDim = o2.numDim;
				res->tamDim1 = o2.tamDim1;
				res->tamDim2 = o2.tamDim2;
			}
		}
	}
}

/**
 * Comprobacion semantica de las operaciones || y XOR
 */
void TS_OpOrXor(atributos o1, atributos operador, atributos o2, atributos* res) {
	if (o1.tipo != o2.tipo) {
		printf("Error or linea %d: El operador OR o XOR espera que los tipos de los operandos sean iguales.", lineaActual);
		//hay_error=1;
		return;
	}
	if (o1.tipo != BOOLEANO || esArray(o1) || esArray(o2)) {
		printf("Error or linea %d: Tipo invalido de los operandos. Se esperaba Logico para los dos operandos.", lineaActual);
		//hay_error=1;
		return;
	}
	
	res->tipo = BOOLEANO;
	res->numDim = 0;
	res->tamDim1 = 0;
	res->tamDim2 = 0;
}

/**
 * Comprobacion semantica de la operacion **
 */
void TS_OpPot(atributos o1, atributos operador, atributos o2, atributos* res) {
	if (o1.tipo != o2.tipo) {
		printf("Error pot linea %d: El operador ** espera que los tipos de los operandos sean iguales.", lineaActual);
		//hay_error=1;
		return;
	}
	if (o1.tipo != ENTERO && o1.tipo != REAL) {
		printf("Error pot linea %d: Tipo invalido de los operandos. Se esperaba Entero o Real para los dos operandos.\n", lineaActual);
		//hay_error=1;
		return;
	}
	
	if (esArray(o1) && esArray(o2)) { // Si ambos son array
		if (o1.tamDim1 == o2.tamDim2) { // Si tienen el mismo tamanyo
			res->tipo = o1.tipo;
			res->tamDim1 = o2.tamDim1;
			res->tamDim2 = o1.tamDim2;
			res->numDim = (res->tamDim2 > 0) ? 2 : 1;
		} else { // Si no tienen el mismo tamano
			printf("Error pot linea %d: No puede realizarse la multiplicacion de matrices porque los tamanyos de los arrays son invalidos.\n", lineaActual);
			//hay_error=1;
			return;
		}
	} else if (esArray(o1) || esArray(o2)) { // Si uno de los dos es array
		printf("Error linea pot %d: Operandos invalidos para el operador **.\n", lineaActual);
		//hay_error=1;
		return;
	}
}

/**
 * Comprobacion semantica de las operaciones <, >, <= y >=
 */
void TS_OpRel(atributos o1, atributos operador, atributos o2, atributos* res) {
	if (o1.tipo != o2.tipo) {
		printf("Error rel linea %d: El operador <,>,<= o >= espera que los tipos de los operandos sean iguales.", lineaActual);
		//hay_error=1;
		return;
	}
	if ((o1.tipo != ENTERO && o1.tipo != REAL) || esArray(o1) || esArray(o2)) {
		printf("Error rel linea %d: Tipo %s invalido de los operandos %s y %s. Se esperaba Entero o Real para los dos operandos.", lineaActual, operador.lexema, o1.lexema, o2.lexema);
		//hay_error=1;
		return;
	}
	
	res->tipo = BOOLEANO;
	res->numDim = 0;
	res->tamDim1 = 0;
	res->tamDim2 = 0;
}

/**
 * Comprobacion semantica de las operaciones == y !=
 */
void TS_OpIgual(atributos o1, atributos operador, atributos o2, atributos* res) {
	if (o1.tipo != o2.tipo) {
		printf("Error igual linea %d: El operador == o != espera que los tipos de los operandos sean iguales.", lineaActual);
		//hay_error=1;
		return;
	}
	if (esArray(o1) || esArray(o2)) {
		printf("Error igual linea %d: Tipo invalido de los operandos. Se esperaba Entero o Real para los dos operandos.", lineaActual);
		//hay_error=1;
		return;
	}
	
	res->tipo = BOOLEANO;
	res->numDim = 0;
	res->tamDim1 = 0;
	res->tamDim2 = 0;
}

/**
 * Comprobacion semantica de las operaciones &&
 */
void TS_OpAnd(atributos o1, atributos operador, atributos o2, atributos* res) {
	if (o1.tipo != o2.tipo) {
		printf("Error and linea %d: El operador AND espera que los tipos de los operandos sean iguales.", lineaActual);
		//hay_error=1;
		return;
	}
	if (o1.tipo != BOOLEANO || esArray(o1) || esArray(o2)) {
		printf("Error and linea %d: Tipo invalido de los operandos. Se esperaba Logico para los dos operandos.", lineaActual);
		//hay_error=1;
		return;
	}
	
	res->tipo = BOOLEANO;
	res->numDim = 0;
	res->tamDim1 = 0;
	res->tamDim2 = 0;
}

/**
 * Comprobacion semantica de las operaciones binarias + y -
 */
void TS_OpSumRes(atributos o1, atributos operador, atributos o2, atributos* res) {
	if (o1.tipo != o2.tipo) {
		printf("Error sumres linea %d: El operador + o - espera que los tipos de los operandos sean iguales.", lineaActual);
		//hay_error=1;
		return;
	}
	if (o1.tipo != ENTERO && o1.tipo != REAL) {
		printf("Error sumres linea %d: Tipo invalido de los operandos. Se esperaba Entero o Real para los dos operandos.", lineaActual);
		//hay_error=1;
		return;
	}
	
	if (esArray(o1) && esArray(o2)) { // Si ambos son array
		if(igualTam(o1,o2)) { // Si tienen el mismo tamanyo
			res->tipo = o1.tipo;
			res->lexema = o1.lexema;
			res->numDim = o1.numDim;
			res->tamDim1 = o1.tamDim1;
			res->tamDim2 = o1.tamDim2;
		} else { // Si no tienen el mismo tamanyo, error
			printf("Error sumres linea %d: Los arrays son de distinto tamanyo.", lineaActual);
			//hay_error=1;
			return;
		}
	} else {
		if (esArray(o1) && !esArray(o2)) { // Si el primero es array y el segundo no
			res->tipo = o1.tipo;
			res->lexema = o1.lexema;
			res->numDim = o1.numDim;
			res->tamDim1 = o1.tamDim1;
			res->tamDim2 = o1.tamDim2;
		}
		if (!esArray(o1) && esArray(o2)) { // Si el primero no es array, pero el segundo si
			if (strcmp(operador.lexema,"-")==0) { // Caso de que el operador sea -, es invalido
				printf("Error linea %d: No se puede restar un valor con un array.", lineaActual);
				//hay_error=1;
				return;
			} else { // Si es +, es valido
				res->tipo = o2.tipo;
				res->lexema = o2.lexema;
				res->numDim = o2.numDim;
				res->tamDim1 = o2.tamDim1;
				res->tamDim2 = o2.tamDim2;
			}
		}
	}
}

/**
 * Comprobacion semantica de la llamada a subprograma
 */
void TS_LlamadaFuncion(atributos identificador, atributos* res) {
	
	int indice = TS_BuscarFuncion (identificador);
	if(indice==-1) {
		funcionActual = -1;
		printf("Error linea %d: No se ha encontrado el identificador %s.\n", lineaActual, identificador.lexema);
	}
	else {
		if (numParam != TS[indice].nParam) { 
			printf("Error, numero de parametros incorrecto\n"); 
		} else {
			funcionActual = indice;
			res->lexema = strdup(TS[indice].lexema);
			res->tipo = TS[indice].tipoDato;
			res->numDim = TS[indice].numDim;
			res->tamDim1 = TS[indice].tamDim1;
			res->tamDim2 = TS[indice].tamDim2;
		}
	}
}

/**
 * Comprobacion semantica de cada parametro en una llamada a una funcion
 */
void TS_CompruebaParametro(atributos parametro, int parametroAComprobar) {

	int posicionParametro = (funcionActual + TS[funcionActual].nParam) - (parametroAComprobar - 1);
	
	int errorRealmente = TS[funcionActual].nParam - parametroAComprobar + 1;
	//printf("%d, %d", parametro.tipo, TS[posicionParametro].tipoDato);
	//printf("voy a comprobar el parametro %d\n", parametroAComprobar);
	//imprimeAtributo(parametro, "a Comprobar");
	//imprimeEntrada(posicionParametro);
	if (parametro.tipo != TS[posicionParametro].tipoDato) {
		printf("Error linea %d. %s El tipo del parametro esperado en el parametro %d no es el correcto\n",  lineaActual, parametro.lexema, errorRealmente);
		return;
	}
	if (parametro.numDim != TS[posicionParametro].numDim || parametro.tamDim1 != TS[posicionParametro].tamDim1  || parametro.tamDim2 != TS[posicionParametro].tamDim2) {
		printf("Error linea %d. El tamanyo esperado en el parametro %d no es el correcto\n", lineaActual, errorRealmente);
		return;
	}
	
}

void TS_OpBinListas(atributos at1, atributos operador, atributos at2, atributos* res){
	if(operador.atrib==0 || operador.atrib==1){
		if(at1.numDim==0){
			printf("ERROR [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, at1.lexema);
			return;
		}
		else if(at2.numDim>0){
			printf("ERROR [Linea %d]: %s NO DEBE SER UNA LISTA\n", lineaActual, at2.lexema);
			return;
		}
		else if(at2.tipo!=ENTERO){
			printf("ERROR SINTÁCTICO [Linea %d]: %s DEBE SER UN ENTERO\n", lineaActual, at2.lexema);
			return;
		}
	}
	if(operador.atrib==2){
		if(at1.numDim==0){
			printf("ERROR [Linea %d]: %s NO ES UNA LISTA\n", lineaActual, at1.lexema);
			return;
		}
		else if(at2.numDim==0){
			printf("ERROR [Linea %d]: %s DEBE SER UNA LISTA\n", lineaActual, at2.lexema);
			return;
		}
		else if(at1.tipo!=at2.tipo){
			printf("ERROR [Linea %d]: %s Y %s NO TIENEN EL MISMO TIPO\n", lineaActual, at1.lexema, at2.lexema);
			return;
		}
	}
	//char* nuevoLexema;
	//strcpy(nuevoLexema, at1.lexema);
	//strcat(nuevoLexema, operador.lexema);
	//strcat(nuevoLexema, at2.lexema);
	res->tipo = at1.tipo;
	res->numDim = at1.numDim;
	//res->lexema = nuevoLexema;
}

void TS_OpBinArroba(atributos at1, atributos operador, atributos at2, atributos* res){
	if(at1.numDim<=0){
		printf("ERROR SINTÁCTICO [Linea %d]: LA VARIABLE %s NO ES UNA LISTA\n", lineaActual, at1.lexema);
		return;
	}
	else if(at2.numDim>0 || at2.tipo!=ENTERO){
		printf("ERROR SINTÁCTICO [Linea %d]: LA VARIABLE %s DEBE SER UN ENTERO\n", lineaActual, at1.lexema);
		return;
	}
	char* nuevoLexema;
	strcpy(nuevoLexema, at1.lexema);
	strcat(nuevoLexema, "@");
	strcat(nuevoLexema, at2.lexema);
	res->tipo = at2.tipo;
	res->numDim = at2.numDim;
	res->lexema = nuevoLexema;
}

void TS_OpTerciario(atributos at1, atributos at2, atributos at3, atributos* res){
	if(at1.numDim<=0){
		printf("ERROR SINTÁCTICO [Linea %d]: LA VARIABLE %s NO ES UNA LISTA\n", lineaActual, at1.lexema);
		return;
	}
	else if(at2.numDim>0 || at2.tipo!=ENTERO){
		printf("ERROR SINTÁCTICO [Linea %d]: LA VARIABLE %s DEBE SER UN ENTERO\n", lineaActual, at2.lexema);
		return;
	}
	else if(at3.numDim>0 || at3.tipo!=at1.tipo){
		printf("ERROR SINTÁCTICO [Linea %d]: LA VARIABLE %s DEBE SER DEL TIPO DE %s\n", lineaActual, at3.lexema, at1.lexema);
		return;
	}
	char* nuevoLexema;
	strcpy(nuevoLexema, at1.lexema);
	strcat(nuevoLexema, "@");
	strcat(nuevoLexema, at2.lexema);
	strcat(nuevoLexema, "++");
	strcat(nuevoLexema, at3.lexema);
	res->tipo = at1.tipo;
	res->numDim = at1.numDim;
	res->lexema = nuevoLexema;
}

//----------------------  Funciones de Impresion --------------------------------------

/**
 * Imprime como una cadena de caracteres una entrada de la tabla de simbolos dada
 */
void imprimeEntrada(int indice) {
	entradaTS e = TS[indice];
	printf("\n\nTipo Entrada: %d\nLexema: %s\nTipo Dato: %d\nNum Parametros: %d\nDimensiones[i][j]: %d[%d][%d]\n", 
		e.entrada, e.lexema, e.tipoDato, e.nParam, e.numDim, e.tamDim1, e.tamDim2);
}

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
void imprimeTS() { 
	int j = 0; 
	char *t, *e;

	printf("--------------------------------\n"); 
	while(j <= TOPE-1) {
		if(TS[j].entrada == 0) { e = "MARCA"; }
		if(TS[j].entrada == 1) { e = "FUNCION"; }
		if(TS[j].entrada == 2) { e = "VARIABLE"; }
		if(TS[j].entrada == 3) { e = "PAR_FORMAL"; }

		if(TS[j].tipoDato == 0) { t = "NO_ASIG"; }
		if(TS[j].tipoDato == 1) { t = "ENTERO"; }
		if(TS[j].tipoDato == 2) { t = "REAL"; }
		if(TS[j].tipoDato == 3) { t = "CARACTER"; }
		if(TS[j].tipoDato == 4) { t = "BOOLEANO"; }
		if(TS[j].tipoDato == 5) { t = "STRING"; }
		if(TS[j].tipoDato == 6) { t = "DESC"; }
		printf("----ELEMENTO %d-----------------\n", j); 
		printf("-Entrada: %-12s", e); 
		printf("-Lexema: %-12s", TS[j].lexema);
		printf("-tipoDato:" );
		for(int i = 0; i < TS[j].numDim; i++){
			printf("LISTA ");
		}
		printf("%-10s", t); 
		printf("-nParam: %-4d", TS[j].nParam); 
		printf("-numDim: %-4d", TS[j].numDim); 
		printf("-tamDim1: %-4d", TS[j].tamDim1); 
		printf("-tamDim2: %-4d\n", TS[j].tamDim2);
		j++; 
	} 
	printf("--------------------------------\n"); 
}

/**
 * Imprime por pantalla un atributo dado
 */
void imprimeAtributo(atributos elem, char *msj){
	char *t;

	if(elem.tipo == 0) { t = "NO_ASIG"; }
	if(elem.tipo == 1) { t = "ENTERO"; }
	if(elem.tipo == 2) { t = "REAL"; }
	if(elem.tipo == 3) { t = "CARACTER"; }
	if(elem.tipo == 4) { t = "BOOLEANO"; }
	if(elem.tipo == 5) { t = "STRING"; }
	if(elem.tipo == 6) { t = "MATRIZ"; }
	if(elem.tipo == 7) { t = "DESC"; }
	printf("------%s-------------------------\n", msj);
	printf("-Atributos: %-4d", elem.atrib); 
	printf("-Lexema: %-12s", elem.lexema); 
	printf("-tipoDato: %-10s", t); 
	printf("-numDim: %-4d", elem.numDim); 
	printf("-tamDim1: %-4d", elem.tamDim1); 
	printf("-tamDim2: %-4d\n", elem.tamDim2);
	printf("-------------------------------\n");
}
