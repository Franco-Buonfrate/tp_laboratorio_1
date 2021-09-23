/*
 * miBiblioteca.h
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_


int menu(int x, int y, int seHizo1, int seHizo2);

int setFlag(int* seHizo,int valor);

int sumar(int a, int b, int* suma);

int restar(int a, int b, int* resta);

int dividir(int a, int b, float* division);

int multiplicar(int a, int b, int* multiplicar);

int factorialRecursivo(int a, int* rdo);

#endif /* MIBIBLIOTECA_H_ */
