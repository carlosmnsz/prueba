#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dec_fun.c"
int n;
int curr;
int ultim;
int cuenta;
int primer;
int main(){
curr = 2 ;

ultim = 0 ;

cuenta = 0 ;

primer = 1 ;

printf("%s","Introduce un numero: ");

scanf("%d",&n);

printf("%s","n == ");
printf("%d",n);
printf("%s","\n");

curr = 2 ;

etiqueta_0:
{
int temp0;
temp0 = curr <= n;
if(!temp0) goto etiqueta_1;
int d;
int temp1;
temp1 = n / curr;
d = temp1 ;

printf("%d",d);
printf("%s","*");
printf("%d",curr);
printf("%s","==");
printf("%d",n);
printf("%s","\n");

int temp2;
temp2 = d * curr;
int temp3;
temp3 = temp2 == n;
if(!temp3) goto etiqueta_2;
{
printf("%d",curr);
printf("%s","!=");
printf("%d",ultim);
printf("%s","\n");

int temp4;
temp4 = curr != ultim;
if(!temp4) goto etiqueta_4;
{
ultim = curr ;

cuenta = 1 ;

}
goto etiqueta_5;
etiqueta_4:
{
int temp5;
temp5 = cuenta + 1;
cuenta = temp5 ;

}
etiqueta_5:
{}

int temp6;
temp6 = n / curr;
n = temp6 ;

}
goto etiqueta_3;
etiqueta_2:
{
printf("%s","SINO\n");

int temp7;
temp7 = cuenta > 0;
if(!temp7) goto etiqueta_6;
{
int temp8;
temp8 = primer == 0;
if(!temp8) goto etiqueta_8;
{
printf("%s"," *");

}
etiqueta_8:{}

primer = 0 ;

printf("%d",curr);

int temp9;
temp9 = cuenta > 1;
if(!temp9) goto etiqueta_10;
{
printf("%s","^");
printf("%d",cuenta);

}
etiqueta_10:{}

}
etiqueta_6:{}

int temp10;
temp10 = curr + 1;
curr = temp10 ;

cuenta = 0 ;

}
etiqueta_3:
{}

}
goto etiqueta_0;
etiqueta_1:
{}

int temp11;
temp11 = cuenta > 0;
if(!temp11) goto etiqueta_6;
{
int temp12;
temp12 = primer == 0;
if(!temp12) goto etiqueta_10;
{
printf("%s"," *");

}
etiqueta_14:{}

primer = 0 ;

printf("%d",curr);

int temp13;
temp13 = cuenta > 1;
if(!temp13) goto etiqueta_10;
{
printf("%s","^");
printf("%d",cuenta);

}
etiqueta_16:{}

}
etiqueta_12:{}

printf("%s","\n");


}

