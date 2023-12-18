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

void GCI_DeclarPar(){
	int primero = 0;
	for(int i = 0; i < TOPE; i++){
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

char* generarEtiqueta(){
	char* temporal;
	temporal = (char*) malloc(20);
	sprintf(temporal, "temp%d", etiqueta);
	etiqueta++;
    return temporal;
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
		TOPE++;
		TS[TOPE].entrada = DESCRIPTOR;
		TS[TOPE].descriptor.EtiquetaSalida = generarEtiqueta();
		sprintf(sent,"int %s;\n",a.lexema);
		fputs(sent,principal);
	}
	free(sent);
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
	TOPE++;
	TF[TOPE].entrada = DESCRIPTOR;
	if(type == 1){
		TF[TOPE].descriptor.EtiquetaElse = generarEtiqueta();
		TF[TOPE].descriptor.EtiquetaSalida = generarEtiqueta();
	}else if(type == 2){
		TF[TOPE].descriptor.EtiquetaEntrada = generarEtiqueta();
		TF[TOPE].descriptor.EtiquetaSalida = generarEtiqueta();
	}
}
void eliminaDesc(){
	TOPE--;
}
/*	1.if con else
	2.while
	3.if sin else
*/
void insertaCond(int type){

	char * cadena, *sent;
	int topeTMP = TOPE;
	cadena = (char *) malloc(20);
	sent = (char *) malloc(150);


	while(TF[topeTMP].entrada != DESCRIPTOR){
		topeTMP--;
	}
	if(type == 1){
		sprintf(cadena, "temp%d",etiqueta-1);
		TF[topeTMP].lexema = (char *) malloc(50);
		strcpy(TF[topeTMP].lexema,cadena);
		sprintf(sent,"if(!%s) goto %s;\n",cadena,TF[topeTMP].descriptor.EtiquetaElse);
	}
	else if(type == 2){
				sprintf(cadena, "temp%d",etiqueta-1);
				sprintf(sent,"if(!%s) goto %s;\n",cadena,TF[topeTMP].descriptor.EtiquetaSalida);
			}

	fputs(sent,principal);
	free(sent);
	free(cadena);
}
void insertaEtiqElse(){
	int topeTMP = TOPE-1;
	char * sent;
	sent = (char *) malloc(200);

	while(TF[topeTMP].entrada != DESCRIPTOR && topeTMP>0){

		topeTMP--;
	}
	if(decElse == 1){
		sprintf(sent,"goto %s;\n%s:\n",TF[topeTMP].descriptor.EtiquetaSalida,TF[topeTMP].descriptor.EtiquetaElse);
	}
	else{
		sprintf(sent,"%s:",TF[topeTMP].descriptor.EtiquetaElse);
		}
	fputs(sent,principal);
  printf("FUERA_ELSE\n" );
}

void insertaEtiqSalida(){
	int topeTMP = TOPE-1;
	char * sent;
	sent = (char *) malloc(200);
  printf("\nAntes\n");
	while(TF[topeTMP].entrada != DESCRIPTOR && topeTMP>0){
    printf("\nDentro while %d\n", topeTMP);
		topeTMP--;
	}

	sprintf(sent,"%s:\n",TF[topeTMP].descriptor.EtiquetaSalida);

	fputs(sent,principal);
  printf("FUERA\n" );
}
void insertaEtiqEntrada(){
	int topeTMP = TOPE;
	char * sent;
	sent = (char *) malloc(200);
	while(TF[topeTMP].entrada != DESCRIPTOR){
		topeTMP--;
	}

	sprintf(sent,"%s:\n",TF[topeTMP].descriptor.EtiquetaEntrada);
	fputs(sent,principal);
}
void insertaGotoEntrada(){
	int topeTMP = TOPE;
	char * sent;
	sent = (char *) malloc(200);
	while(TF[topeTMP].entrada != DESCRIPTOR){
		topeTMP--;
	}

	sprintf(sent,"goto %s;\n",TF[topeTMP].descriptor.EtiquetaEntrada);
	fputs(sent,principal);
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