/*
 ============================================================================
 Name        : TP_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define TAM 1000

int main(void) {
    char seguir='s';
    int id=1000;
    int indiceModificar;
    int idModificar;
    int idBaja;

    Employee auxEmpleados[1];
    Employee empleados[TAM];

    if(initEmployees(empleados, TAM)==-1)
    {
        printf("Ocurrio un error al inicializar los empleados\n");
    }

    do{
        system("cls");
        switch(menu())
        {
            case 1:
                dataEntry(auxEmpleados);
                if(addEmployee(empleados, TAM, id, auxEmpleados[0].name, auxEmpleados[0].lastName, auxEmpleados[0].salary, auxEmpleados[0].sector)==0)
                {
                    id++;
                }
                break;
            case 2:
                if(entryValidation(empleados,TAM))
                {
                    system("cls");
                    printEmployees(empleados,TAM);
                    printf("Ingrese ID de empleado a modificar: ");
                    scanf("%d", &idModificar);
                    indiceModificar=findEmployeeById(empleados, TAM, idModificar);
                    if(indiceModificar==-1)
                    {
                        printf("No se encontro empleado con ese ID\n");
                    }
                    else
                    {
                        employeeToModify(empleados, TAM, indiceModificar);
                    }
                }
                else
                {
                    printf("Debe cargar un emplaeado antes de modificar\n");
                }
                break;
            case 3:
                if(entryValidation(empleados, TAM))
                {
                    system("cls");
                    printEmployees(empleados,TAM);
                    printf("Ingrese ID de empleado a dar de baja: ");
                    scanf("%d", &idBaja);
                    if(removeEmployee(empleados, TAM, idBaja)==-1)
                    {
                        printf("No se encontro usuario\n");
                    }
                }
                else
                {
                    printf("Debe cargar un emplaeado antes de dar de baja\n");
                }
                break;
            case 4:
                if(entryValidation(empleados, TAM))
                {
                printEmployees(empleados,TAM);
                salary(empleados,TAM);
                }
                else
                {
                    printf("Debe cargar un emplaeado antes de informar\n");
                }
                break;
            case 0:
                seguir='n';
                break;
            default:
                printf("Ingrese una opcion valida\n");
        }
        system("pause");
    }while(seguir=='s');
    return 0;
}
