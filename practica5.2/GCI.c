/* Fichero GCI.c */
#include "Semantico.c"
#include "GCI.h"

void abrirFicherosGCI(){
    principal = fopen("./salida/principal.c", "w");

    fputs("#include <stdio.h>\n", principal);
    fputs("#include <stdlib.h>\n", principal);
    fputs("#include <string.h>\n", principal);
}

void cerrarFicherosGCI(){
    fputs("\n", principal);

    fclose(principal);
}

char* tDatoAString(tDato e){
	if(e==ENTERO || e==BOOLEANO){
		return "int ";
	}
	else if(e==REAL){
		return "float ";
	}
	else if(e==CARACTER){
		return "char ";
	}
	else if(e==STRING){
		return "char* ";
	}
	return "";
}

int TF_AddEntrada(entradaTS ent) {
	if(LIMIT < MAX_ENTRADAS) {
		TF[LIMIT].entrada=ent.entrada;
		TF[LIMIT].lexema=ent.lexema;
		TF[LIMIT].tipoDato=ent.tipoDato;
		TF[LIMIT].nParam=ent.nParam;
		TF[LIMIT].numDim=ent.numDim;
		TF[LIMIT].tamDim1=ent.tamDim1;
		TF[LIMIT].tamDim2=ent.tamDim2;
		TF[LIMIT].descriptor=ent.descriptor;
		printf("ENT.DESCRIPTOR.ELSE: %s\n", ent.descriptor.EtiquetaElse);
		printf("TF[LIMIT].DESCRIPTOR.ELSE: %s\n", TF[LIMIT].descriptor.EtiquetaElse);
		LIMIT++;
		//imprimeTF();
		return 1;
	} else {
		printf("ERROR PILA LLENA");
		return 0;
	}
};

void GCI_DeclarPar(){
	int primero = 0;
	for(int i = 0; i < LIMIT; i++){
		if(TF[i].entrada==PAR_FORMAL){
			if(primero==0){
				if(TF[i].numDim>0){
					fprintf(principal, "Lista ");
				}
				fprintf(principal, "%s*%s", tDatoAString(TF[i].tipoDato), TF[i].lexema);
				primero++;
			}
			else{
				if(TF[i].numDim>0){
					fprintf(principal, ", Lista ");
				}
				else{
					fprintf(principal, ", ");
				}
				fprintf(principal, "%s*%s", tDatoAString(TF[i].tipoDato), TF[i].lexema);
			}
		}
	}
}

void generarEtiqueta(int type, entradaTS* dest){
	if(type==0){
		dest->descriptor.EtiquetaElse = (char*) malloc(200);
		sprintf(dest->descriptor.EtiquetaElse, "etiqueta_%d", etiqueta);
		printf("GENERADA ET.ELSE: %s\n", dest->descriptor.EtiquetaElse);
	}
	else if(type==1){
		dest->descriptor.EtiquetaEntrada = (char*) malloc(200);
		sprintf(dest->descriptor.EtiquetaEntrada, "etiqueta_%d", etiqueta);
	}
	else if(type==2){
		dest->descriptor.EtiquetaSalida = (char*) malloc(200);
		sprintf(dest->descriptor.EtiquetaSalida, "etiqueta_%d", etiqueta);
	}
	etiqueta++;
}

void generarUnario(atributos* dest, atributos op, atributos b){
	char * sent;
	char * nuevoLexema;
	sent = (char *) malloc(200);
	nuevoLexema = (char *) malloc(200);

	sprintf(sent, "int temp%d;\ntemp%d = %s%s;\n", temp, temp, op.lexema, b.lexema);
	sprintf(nuevoLexema, "temp%d", temp);
	temp++;
	fputs(sent,principal);

	dest->lexema = nuevoLexema;
}

void generarBinario(atributos* dest, atributos a, atributos op, atributos b){
	char * sent;
	char * nuevoLexema;
	sent = (char *) malloc(200);
	nuevoLexema = (char *) malloc(200);

	sprintf(sent, "int temp%d;\ntemp%d = %s %s %s;\n", temp, temp, a.lexema, op.lexema, b.lexema);
	sprintf(nuevoLexema, "temp%d", temp);
	temp++;
	fputs(sent,principal);

	dest->lexema = nuevoLexema;

}

void generaDecVar(atributos a){
	char * sent;
	sent = (char *) malloc(1000);
	if(tipoGlobal == ENTERO){
		sprintf(sent,"int %s;\n",a.lexema);
		fputs(sent,principal);
	}
	else if(tipoGlobal == REAL){
		sprintf(sent,"float %s;\n",a.lexema);
		fputs(sent,principal);
	}
	else if(tipoGlobal == CARACTER){
		sprintf(sent,"char %s;\n",a.lexema);
		fputs(sent,principal);
	}
	else if(tipoGlobal == BOOLEANO){
		entradaTS nuevaEntrada;

		nuevaEntrada.entrada = DESCRIPTOR;
		nuevaEntrada.lexema = a.lexema;
		//Asignamos el tipo desde la variable global
		nuevaEntrada.tipoDato = tipoGlobal;
		nuevaEntrada.nParam = 0;
		nuevaEntrada.numDim=listaGlobal;
		generarEtiqueta(2, &nuevaEntrada); // Salida
		TF_AddEntrada(nuevaEntrada);
		
		sprintf(sent,"int %s;\n",a.lexema);
		fputs(sent,principal);
	}
	free(sent);
}

void generaDecPar(atributos a){
	for(int j = LIMIT-1; j>=0 && paramInsertar!=0; j--){
		char * sent;
		sent = (char *) malloc(1000);
		if(tipoGlobal == ENTERO){
			sprintf(sent,"int %s,", TF[j].lexema);
			fputs(sent,principal);
		}
		else if(tipoGlobal == REAL){
			sprintf(sent,"float %s,", TF[j].lexema);
			fputs(sent,principal);
		}
		else if(tipoGlobal == CARACTER){
			sprintf(sent,"char %s,", TF[j].lexema);
			fputs(sent,principal);
		}
		else if(tipoGlobal == BOOLEANO){
			entradaTS nuevaEntrada;

			nuevaEntrada.entrada = DESCRIPTOR;
			nuevaEntrada.lexema = a.lexema;
			//Asignamos el tipo desde la variable global
			nuevaEntrada.tipoDato = tipoGlobal;
			nuevaEntrada.nParam = 0;
			nuevaEntrada.numDim=listaGlobal;
			generarEtiqueta(2, &nuevaEntrada); // Salida
			TF_AddEntrada(nuevaEntrada);

			sprintf(sent,"int %s;\n",a.lexema);
			fputs(sent,principal);
		}
		free(sent);
		paramInsertar--;
	}
}

void genera(int type,atributos dest,atributos a, atributos op, atributos b){
	char * sent;
	sent = (char *) malloc(200);
	if(type == 1){

		sprintf(sent,"int %s;\n%s = %s %s %s;\n",dest.lexema,dest.lexema,a.lexema,op.lexema,b.lexema);
		fputs(sent,principal);
	}
	else if(type == 4 ){
		sprintf(sent,"%s %s %s %s\n",dest.lexema,a.lexema,op.lexema,b.lexema);
		fputs(sent,principal);
	}
	free(sent);
}

/*	1. else y salida
	2. entrada y salida
*/
void insertaDesc(int type){
	entradaTS nuevaEntrada;
	nuevaEntrada.entrada = DESCRIPTOR;
	if(type == 1){
		generarEtiqueta(0, &nuevaEntrada); // Else
		generarEtiqueta(2, &nuevaEntrada); // Salida
		printf("ELSE: %s\tSALIDA: %s\n", nuevaEntrada.descriptor.EtiquetaElse, nuevaEntrada.descriptor.EtiquetaSalida);
	}else if(type == 2){
		generarEtiqueta(1, &nuevaEntrada); // Entrada
		generarEtiqueta(2, &nuevaEntrada); // Salida
		printf("ENTRADA: %s\tSALIDA: %s\n", nuevaEntrada.descriptor.EtiquetaEntrada, nuevaEntrada.descriptor.EtiquetaSalida);
	}
	TF_AddEntrada(nuevaEntrada);
}

void eliminaDesc(){
	LIMIT--;
}

/*	1.if con else
	2.while
	3.if sin else
*/
void insertaCond(int type){

	char * cadena, *sent;
	int topeTMP = LIMIT;
	cadena = (char *) malloc(20);
	sent = (char *) malloc(150);


	while(TF[topeTMP].entrada != DESCRIPTOR){
		topeTMP--;
		if(topeTMP<0){
			break;
		}
	}
	//if(topeTMP>=0){
		if(type == 1){
			sprintf(cadena, "temp%d",temp-1);
			TF[topeTMP].lexema = (char *) malloc(50);
			strcpy(TF[topeTMP].lexema,cadena);
			sprintf(sent,"if(!%s) goto %s;\n",cadena,TF[topeTMP].descriptor.EtiquetaElse);
		}
		else if(type == 2){
					sprintf(cadena, "temp%d",temp-1);
					sprintf(sent,"if(!%s) goto %s;\n",cadena,TF[topeTMP].descriptor.EtiquetaSalida);
				}
		fputs(sent,principal);
		free(sent);
		free(cadena);
	//}
}

void insertaEtiqElse(){
	int topeTMP = LIMIT-1;
	char * sent;
	sent = (char *) malloc(200);

	while(TF[topeTMP].entrada != DESCRIPTOR){
		printf("%d <-> 4\n", TF[topeTMP].entrada);
		topeTMP--;
		if(topeTMP<0){
			break;
		}
	}

	//if(topeTMP>=0){
		if(decElse == 1){
			printf("ELSE A ESCRIBIR[%d]: %s\n", topeTMP, TF[topeTMP].descriptor.EtiquetaElse);
			sprintf(sent,"goto %s;\n%s:\n",TF[topeTMP].descriptor.EtiquetaSalida,TF[topeTMP].descriptor.EtiquetaElse);
		}
		else{
			printf("ELSE A ESCRIBIR: %s\n", TF[topeTMP].descriptor.EtiquetaElse);
			sprintf(sent,"%s:",TF[topeTMP].descriptor.EtiquetaElse);
			}
		fputs(sent,principal);
	printf("FUERA_ELSE\n" );
	//}
}

void insertaEtiqSalida(){
	int topeTMP = LIMIT-1;
	char * sent;
	sent = (char *) malloc(200);
  printf("\nAntes\n");
	while(TF[topeTMP].entrada != DESCRIPTOR){
    	printf("\nDentro while %d\n", topeTMP);
		topeTMP--;
		if(topeTMP<0){
			break;
		}
	}
	//if(topeTMP>=0){
//printf("ETIQUETA SALIDA: %s\n", TF[topeTMP].descriptor.EtiquetaSalida);
	sprintf(sent,"%s:\n",TF[topeTMP].descriptor.EtiquetaSalida);

	fputs(sent,principal);
  printf("FUERA\n" );
	//}
}

void insertaEtiqEntrada(){
	int topeTMP = LIMIT;
	char * sent;
	sent = (char *) malloc(200);
	while(TF[topeTMP].entrada != DESCRIPTOR){
		topeTMP--;
		if(topeTMP<0){
			break;
		}
	}
	//if(topeTMP>=0){
		sprintf(sent,"%s:\n",TF[topeTMP].descriptor.EtiquetaEntrada);
		fputs(sent,principal);
	//}
}

void insertaGotoEntrada(){
	int topeTMP = LIMIT;
	char * sent;
	sent = (char *) malloc(200);
	while(TF[topeTMP].entrada != DESCRIPTOR){
		topeTMP--;
		if(topeTMP<0){
			break;
		}
	}

	//if(topeTMP>=0){
		
		sprintf(sent,"goto %s;\n",TF[topeTMP].descriptor.EtiquetaEntrada);
		fputs(sent,principal);
	//}
}

void generaEntSal(int type,atributos a){

	if(type == 1){
		fputs("scanf(\"%",principal);
		if(a.tipo == ENTERO) fputs("d",principal);
		else if(a.tipo == REAL) fputs("f",principal);
		else if(a.tipo == CARACTER) fputs("c",principal);
		else if(a.tipo == BOOLEANO) fputs("d",principal);
		fputs("\",&",principal);
		fputs(a.lexema,principal);
		fputs(");",principal);
		fputs("\n",principal);
	}
	else{
		if(a.tipo != NO_ASIG){
			fputs("printf(\"%",principal);
			if(a.tipo == ENTERO) fputs("d",principal);
			else if(a.tipo == REAL) fputs("f",principal);
			else if(a.tipo == CARACTER) fputs("c",principal);
			else if(a.tipo == BOOLEANO) fputs("d",principal);
			fputs("\",",principal);
			fputs(a.lexema,principal);
			fputs(");",principal);
		}else {
			fputs("printf(",principal);
			fputs(a.lexema,principal);
			fputs(");",principal);
		}
		fputs("\n",principal);
	}
}