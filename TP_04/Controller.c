#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "miBiblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int validacion=0;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL && parser_EmployeeFromText(pFile, pArrayListEmployee))
        {
            printf("\nSe cargaron los archivos de forma exitosa\n");
            validacion=1;
        }
        else
        {
            printf("\nError al cargar los datos\n");
        }
        fclose(pFile);
    }
    return validacion;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile=NULL;
    int validacion=0;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path, "rb");
        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile, pArrayListEmployee);
            printf("empleados cargados con exito\n");
            validacion=1;
        }
        else
        {
            printf("No se pudo abrir el archivo\n");
        }

    }
    return validacion;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int validacion=0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int indice;
    Employee* auxEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        auxEmpleado=employee_new();
        if(auxEmpleado!=NULL)
        {
            printf("---------------Alta empleado---------------\n\n");

            id=employee_id(pArrayListEmployee);
            employee_setId(auxEmpleado, id);


            ingresarStr("nombre del empleado", nombre, 127);
            employee_setNombre(auxEmpleado, nombre);

            ingresarIntPos("horas trabajadas", &horasTrabajadas,0, 350);
            employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);

            ingresarIntPos("sueldo", &sueldo, 0, 100000);
            employee_setSueldo(auxEmpleado, sueldo);

            ingresarIntPos("indice (-1 indice final)", &indice, -2, ll_len(pArrayListEmployee)-1);

            if(indice==-1)
            {
                ll_add(pArrayListEmployee,auxEmpleado);
            }
            else
            {
                ll_push(pArrayListEmployee, indice, auxEmpleado);
            }
        }
        else
        {
            printf("Error. Mal ingreso de parametros\n");
        }

        if(ll_contains(pArrayListEmployee, auxEmpleado))
        {
            printf("Alta exitosa\n");
        }
        else
        {
            printf("No se pudo realizar el alta\n");
        }

        validacion=1;
    }

    return validacion;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int validacion=0;
    int opcion;
    Employee* empleadoModificar=NULL;
    Employee* auxEmpleado=NULL;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int indice;

    empleadoModificar=employee_findById(pArrayListEmployee);
    auxEmpleado=employee_new();

    if(empleadoModificar!=NULL && auxEmpleado!=NULL)
    {
        system("cls");

        printf("-------------Menu modificar-------------\n");
        printf("1- Nombre\n");
        printf("2- Horas trabajadas\n");
        printf("3- Sueldo\n");
        employee_showEmployee(empleadoModificar);
        printf("\n");
        ingresarIntPos("opcion", &opcion, 0,4);

        employee_getId(empleadoModificar,&id);
        employee_getNombre(empleadoModificar,nombre);
        employee_getHorasTrabajadas(empleadoModificar,&horasTrabajadas);
        employee_getSueldo(empleadoModificar,&sueldo);

        switch(opcion)
        {
        case 1:
            ingresarStr("nombre", nombre, 128);
            break;
        case 2:
            ingresarIntPos("horas trabajadas", &horasTrabajadas, 1,350);
            break;
        case 3:
            ingresarIntPos("sueldo", &sueldo, 1,100000);
            break;
        default:
            printf("Ingrese una opcion valida\n");
            break;
        }

        indice=ll_indexOf(pArrayListEmployee, empleadoModificar);
        employee_delete(empleadoModificar);

        employee_setId(auxEmpleado,id);
        employee_setNombre(auxEmpleado,nombre);
        employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas);
        employee_setSueldo(auxEmpleado,sueldo);

        ll_set(pArrayListEmployee, indice, auxEmpleado);

        printf("\n");
        employee_showEmployee(auxEmpleado);
        validacion=1;
    }
    else
    {
        printf("No se encontro el empleado\n");
    }
    return validacion;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int validacion=0;
    Employee* empleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        printf("-------------Listar Empleados------------\n");
        printf("ID      NOMBRE             HORAS TRABAJADAS      SUELDO\n");

        for (int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee, i);
            if(empleado!=NULL)
            {
                employee_showEmployee(empleado);
            }
        }
        validacion=1;
    }
    return validacion;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int validacion=0;
    int indice;
    Employee* empleadoBorrar = NULL;
    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        controller_ListEmployee(pArrayListEmployee);
        printf("\n-------------Borrar Empleado-------------\n");
        empleadoBorrar=employee_findById(pArrayListEmployee);
        indice=ll_indexOf(pArrayListEmployee, empleadoBorrar);
        printf("Se Borro el siguiente emplado.\n");
        employee_showEmployee(ll_pop(pArrayListEmployee, indice));
        validacion=1;
    }
    return validacion;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int validacion=0;
    int criterioDeOrdenamiento;

    LinkedList* listClone=NULL;
    listClone=ll_clone(pArrayListEmployee);


    if(listClone!=NULL)
    {
        printf("-------------Menu ordenar-------------\n");
        printf("1- Id\n");
        printf("2- Nombre\n");
        printf("3- Horas trabajadas\n");
        printf("4- Sueldo\n");
        printf("0- Cancelar\n");
        printf("\n");
        ingresarIntPos("opcion", &opcion, -1,5);
        switch(opcion)
        {
        case 1:
            ingresarIntPos("criterio de ordenamiento (1=ascendente / 0=descendente)", &criterioDeOrdenamiento, -1,2);
            ll_sort(listClone, Employee_sortById, criterioDeOrdenamiento);
            break;
        case 2:
            ingresarIntPos("criterio de ordenamiento (1=ascendente / 0=descendente)", &criterioDeOrdenamiento, -1,2);
            ll_sort(listClone, Employee_sortByname, criterioDeOrdenamiento);
            break;
        case 3:
            ingresarIntPos("criterio de ordenamiento (1=ascendente / 0=descendente)", &criterioDeOrdenamiento, -1,2);
            ll_sort(listClone, Employee_sortByHorasTrabajadas, criterioDeOrdenamiento);
            break;
        case 4:
            ingresarIntPos("criterio de ordenamiento (1=ascendente / 0=descendente)", &criterioDeOrdenamiento, -1,2);
            ll_sort(listClone, Employee_sortBySueldo, criterioDeOrdenamiento);
            break;
        case 0:
            break;
        default:
            printf("Ingrese una opcion valida.\n");
            break;
        }
        system("cls");

        if(ll_containsAll(listClone, pArrayListEmployee))
        {
            controller_ListEmployee(listClone);
        }
        else
        {
            printf("Error al ordenar");
        }

        ll_deleteLinkedList(listClone);

        validacion=1;
    }

    return validacion;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int validacion=0;
    FILE* pFile=NULL;
    Employee empleado;
    Employee* pEmpleado;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path, "w");
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmpleado=ll_get(pArrayListEmployee, i);
            employee_getId(pEmpleado , &empleado.id);
            employee_getNombre(pEmpleado, empleado.nombre);
            employee_getHorasTrabajadas(pEmpleado, &empleado.horasTrabajadas);
            employee_getSueldo(pEmpleado, &empleado.sueldo);
            fprintf(pFile,"%d,%s,%d,%d\n", empleado.id, empleado.nombre, empleado.horasTrabajadas, empleado.sueldo);
            validacion=1;
        }
        fclose(pFile);
    }
    return validacion;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int validacion=0;
    FILE* pFile=NULL;
    int tam;

    Employee* empleado=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");
        tam=ll_len(pArrayListEmployee);
        for(int i=0;i<tam;i++)
        {
            empleado= ll_get(pArrayListEmployee, i);
            fwrite(empleado, sizeof(Employee),1, pFile);
        }
        validacion=1;
    }


    return validacion;
}

/** \brief Moestra los empleados en el rango ingresado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployeeRank(LinkedList* pArrayListEmployee)
{
    int validacion=0;
    int desde;
    int hasta;
    LinkedList* subLista;

    if(pArrayListEmployee!=NULL)
    {
        ingresarIntPos("indice DESDE donde quiere mostrar", &desde, -1, ll_len(pArrayListEmployee)-1);
        ingresarIntPos("indice HASTA donde quiere mostrar", &hasta, desde, ll_len(pArrayListEmployee));
        subLista=ll_subList(pArrayListEmployee, desde, hasta);
        controller_ListEmployee(subLista);
        ll_deleteLinkedList(subLista);
        validacion=1;
    }

    return validacion;
}

