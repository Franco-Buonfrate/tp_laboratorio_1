/*
 * miBiblioteca.c
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>

int menu(int x, int y, int seHizo1, int seHizo2){
    int opcion;

    system("cls");
    printf("Menu de Opciones \n");
    if(seHizo1)
    {
    	printf("1. Ingresar 1er operador (A=%d)\n", x);

    }
    else
    {
    	printf("1. Ingresar 1er operador (A=x)\n");
    }

    if(seHizo2)
    {
    	printf("2. Inresar 2do operador (B=%d)\n", y);
    }
    else
    {
    	printf("2. Inresar 2do operador (B=y)\n");
    }

    printf("3. Calcular todas las operaciones \n");
    printf("4. Informar resultados \n");
    printf("5. Salir \n");

    printf("\n Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int setFlag(int* seHizo, int valor)
{
    int validacion=0;
    if(seHizo!=NULL)
    {
	*seHizo=valor;
	validacion=1;
    }
    return validacion;
}


int sumar(int a, int b, int* suma){
	int validacion=0;
	if(suma!=NULL){
    *suma= a + b;
    validacion=1;
	}
    return validacion;
}

int restar(int a, int b, int* resta){
    int validacion=0;
    if(resta!=NULL){
    *resta=a-b;
    validacion=1;
    }
    return validacion;
}

int dividir(int a, int b, float* division){
	int validacion=0;
    if(b>0)
    {
    	if(division!=NULL)
    	{
        *division=(float) a/b;
        validacion=1;
    	}
    }
    return validacion;
}

int multiplicar(int a, int b, int* multiplicar)
{
    int validacion=0;
    if(multiplicar!=NULL){
    *multiplicar=a*b;
    validacion=1;
    }
    return validacion;
}

int factorialRecursivo(int a, int* factorial)
{
	int validacion=0;
	int factoreo=1;
    if(a>0)
    {
    	if(a==0 || a==1)
		{
			*factorial=1;
		}
		else
		{
			for(int i=1; i<=a; i++)
			{
				factoreo*=i;
			}
			*factorial=factoreo;
		}
		validacion=1;
    }
    return validacion;
}
