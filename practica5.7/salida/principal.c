#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_fun.c"
listOfInt* a;
listOfInt* b;
int c;
int d;
int main(){
arrayInit(&a);
arrayInit(&b);
c = 0 ;

d = 0 ;

etiqueta_0: 
{
int temp0;
temp0 = c != 10;
if(!temp0) goto etiqueta_1; 
insertaInt(a, c, c);

int temp1;
temp1 = c * 2;
insertaInt(b, c, temp1);

int temp2;
temp2 = c + 1;
c = temp2 ;

}
goto etiqueta_0; 
etiqueta_1: 
{}

insertaInt(a, 3, 100);

etiqueta_2: 
{
int temp3;
temp3 = d != 10;
if(!temp3) goto etiqueta_3; 
int temp4;
temp4=getItem(a, d);
printf("%d",temp4);
printf("%s","\n");

int temp5;
temp5 = d + 1;
d = temp5 ;

}
goto etiqueta_2; 
etiqueta_3: 
{}

printf("%s","\n");

d = 0 ;

etiqueta_4: 
{
int temp6;
temp6 = d != 10;
if(!temp6) goto etiqueta_5; 
int temp7;
temp7=getItem(b, d);
printf("%d",temp7);
printf("%s","\n");

int temp8;
temp8 = d + 1;
d = temp8 ;

}
goto etiqueta_4; 
etiqueta_5: 
{}

int temp9;
temp9 = getSize(a);
printf("%d",temp9);


}

