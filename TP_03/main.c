#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "miBiblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int load=0;
    char seguir='s';
    LinkedList* listaEmpleados = ll_newLinkedList();
    char rta;
    do{
        switch(menu())
        {
            case 1:
                if(load)
                {
                    printf("Ya se cargo el archivo\n");
                }
                else
                {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        load=1;
                    }

                }
                break;
            case 2:
                if(load)
                {
                    printf("Ya se cargo el archivo");
                }
                else
                {
                    if(controller_loadFromBinary("data.bin", listaEmpleados))
                    {
                        load=1;
                    }
                }
                break;
            case 3:
                if(!load)
                {
                    printf("Para dar un Alta, primero debe cargar el archivo\n");
                }
                else
                {
                    controller_addEmployee(listaEmpleados);
                }
                break;
            case 4:
                if(!load)
                {
                    printf("Para modificar, primero debe cargar el archivo\n");
                }
                else
                {
                    controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                if(!load)
                {
                    printf("Para dar una baja, primero debe cargar el archivo\n");
                }
                else
                {
                    controller_removeEmployee(listaEmpleados);
                }
                break;
            case 6:
                if(!load)
                {
                    printf("Para listar los empleados, primero debe cargar el archivo\n");
                }
                else
                {
                    controller_ListEmployee(listaEmpleados);
                }
                break;
            case 7:
                if(!load)
                {
                    printf("Para ordenar los empleados, primero debe cargar el archivo\n");
                }
                else
                {
                    controller_sortEmployee(listaEmpleados);
                }
                break;
            case 8:
                if(!load)
                {
                    printf("Para guardar el archivo, primero debe cargar el archivo\n");
                }
                else
                {
                    printf("Al guardar se sobreescribiran los datos\n");
                    ingresarChar("confirmacion (s/n)", &rta,'s','n');
                    if(rta=='s')
                    {
                        controller_saveAsText("data.csv", listaEmpleados);
                    }
                    else
                    {
                        printf("Se cancelo la subida de datos\n");
                    }
                }
                break;
            case 9:
                if(!load)
                {
                    printf("Para guardar el archivo, primero debe cargar el archivo\n");
                }
                else
                {
                    printf("Al guardar se sobreescribiran los datos\n");
                    ingresarChar("confirmacion (s/n)", &rta, 's','n');
                    if(rta=='s')
                    {
                        controller_saveAsBinary("data.bin", listaEmpleados);
                    }
                    else
                    {
                        printf("Se cancelo la subida de datos\n");
                    }
                }
                break;
            case 10:
                seguir='n';
                break;
            default:
                printf("Ingrese una opcion valida\n");
                break;
        }
        system("pause");
    }while(seguir=='s');
    return 0;
}
