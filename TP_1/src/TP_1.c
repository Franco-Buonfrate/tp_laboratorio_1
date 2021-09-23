/*
 ============================================================================
 Name        : TP_1.c
 Author      : Franco Buonfrate
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

int main(void)
{
	setbuf(stdout, NULL);
	int seHizo1=0;
	int seHizo2=0;
	int seHizo3=0;
	int seHizo4=0;
	int primerOperador;
	int segundoOperador;
	char respuesta='n';
	int suma;
	int resta;
	float division;
	int multiplicacion;
	int factorial1;
	int factorial2;
	do
	{
		system("cls");

		switch(menu(primerOperador , segundoOperador, seHizo1, seHizo2))
		{
		case 1:
			if(!seHizo1)
			{
				printf("Ingrese 1er operador: ");
				scanf("%d", &primerOperador);
				setFlag(&seHizo1, 1);
			}
			else
			{
				printf("Ya se ingreso el primer operador\n");
			}

			break;
		case 2:
			if(!seHizo2)
			{
				if(seHizo1)
				{
					printf("Ingrese 2do operador: ");
					scanf("%d", &segundoOperador);
					setFlag(&seHizo2, 1);
				}
				else
				{
					printf("Debe ingresar el primer operador antes.\n");
				}
			}
			else
			{
				printf("Ya se ingreso segundo operador.\n");
			}

			break;
		case 3:
			if(!seHizo3)
			{
				if(seHizo2)
				{
					sumar(primerOperador, segundoOperador, &suma);
					restar(primerOperador, segundoOperador, &resta);
					dividir(primerOperador, segundoOperador, &division);
					multiplicar(primerOperador, segundoOperador, &multiplicacion);
					factorialRecursivo(primerOperador, &factorial1);
					factorialRecursivo(segundoOperador, &factorial2);

					printf("Calcular la suma (A+B)\n");
					printf("Calcular la resta (A-B)\n");
					printf("Calcular la division (A/B)\n");
					printf("Calcular la multiplicacion (A*B)\n");
					printf("Calcular el factorial (A!)\n");
					printf("Calcular el factorial (B!)\n");

					setFlag(&seHizo3, 1);
				}
				else
				{
					printf("Antes debe igresar el segundo operador. \n");
				}
			}
			else
			{
				printf("Ya se realizaron las operaciones.\n");
			}

			break;
		case 4:
			if(!seHizo4)
			{
				if(seHizo3)
				{
					printf("El resultado de la suma es: %d\n", suma);
					printf("El resultado de la resta es: %d\n", resta);
					if(dividir(primerOperador, segundoOperador, &division))
					{
						printf("El resultado de la division es: %.2f\n", division);
					}
					else
					{
						printf("No se puede dividir por cero.\n");
					}
					printf("El resultado de la multiplicacion es: %d\n", multiplicacion);\

					if(factorialRecursivo(primerOperador, &factorial1))
					{
						printf("El factorial del primer operador es: %d\n", factorial1);
					}
					else
					{
						printf("No se puedo hacer el factorial del primer operador.\n");
					}

					if(factorialRecursivo(segundoOperador, &factorial2))
					{
						printf("El factorial del primer operador es: %d\n", factorial2);
					}
					else
					{
						printf("No se puedo hacer el factorial del segundo operador.\n");
					}

					setFlag(&seHizo4, 1);

				}
			}
			else
			{
				printf("Ya se mostraron los resultados\n");
			}
			break;
		case 5:
			printf("Adios!\n");
			respuesta='s';
			break;
		default:
			printf("Ingrese una opcion valida. \n");
			break;
		}

	system("pause");
	}while(respuesta=='n');

	return 0;
}



