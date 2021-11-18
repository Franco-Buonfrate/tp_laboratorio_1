#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado;
    nuevoEmpleado= (Employee*) malloc(sizeof(Employee));
    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->id=0;
        strcpy(nuevoEmpleado->nombre,"nn");
        nuevoEmpleado->horasTrabajadas=0;
        nuevoEmpleado->sueldo=0;
    }
    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr )
{
    Employee* nuevoEmpleado=NULL;
    nuevoEmpleado=employee_new();
    if(nuevoEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr)) &&
           employee_setNombre(nuevoEmpleado, nombreStr)&&
           employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))&&
           employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado=NULL;
        }
    }

    return nuevoEmpleado;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int validacion=0;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        validacion=1;
    }
    return validacion;
}

int employee_getId(Employee* this,int* id)
{
    int validacion=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        validacion=1;
    }
    return validacion;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int validacion=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre, nombre);
        strlwr(this->nombre);
        this->nombre[0]=toupper(this->nombre[0]);
        validacion=1;
    }
    return validacion;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int validacion=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        validacion=1;
    }
    return validacion;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int validacion=0;
    if(this!=NULL && horasTrabajadas>-1)
    {
        this->horasTrabajadas=horasTrabajadas;
        validacion=1;
    }
    return validacion;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int validacion=0;
    if(this !=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        validacion=1;
    }
    return validacion;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int validacion=0;
    if(this!=NULL && sueldo>-1)
    {
        this->sueldo=sueldo;
        validacion=1;
    }
    return validacion;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int validacion=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        validacion=1;
    }
    return validacion;
}

void employee_showEmployee(Employee* this)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL)
    {
        employee_getId(this,&id);
        employee_getNombre(this, nombre);
        employee_getHorasTrabajadas(this, &horasTrabajadas);
        employee_getSueldo(this, &sueldo);

        printf("%4d    %-20s     %5d      %10d \n", id, nombre, horasTrabajadas, sueldo);
    }

}

Employee* employee_findById (LinkedList* pArrayListEmployee)
{
    Employee* empleadoBuscado;
    int id;

    if(pArrayListEmployee!=NULL)
    {
        printf("Ingrese id: ");
        scanf("%d", &id);
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {

            empleadoBuscado=ll_get(pArrayListEmployee, i);
            if(empleadoBuscado->id==id)
            {
                break;
            }
            empleadoBuscado=NULL;
        }
    }
    return empleadoBuscado;
}

int Employee_sortByname(void* empleadoI, void* empleadoJ)
{
    char nombreI[128];
    char nombrej[128];

    employee_getNombre(empleadoI, nombreI);
    employee_getNombre(empleadoJ, nombrej);

    if(strcmp(nombreI, nombrej)>0)
    {
        return 1;
    }

    if(strcmp(nombreI, nombrej)<0)
    {
        return -1;
    }
    return 0;
}

int Employee_sortById(void* empleadoI, void* empleadoJ)
{
    int ipI;
    int ipJ;

    employee_getId(empleadoI, &ipI);
    employee_getId(empleadoJ, &ipJ);

    if(ipI>ipJ)
    {
        return 1;
    }
    if(ipJ>ipI)
    {
        return -1;
    }

    return 0;
}

int Employee_sortByHorasTrabajadas(void* empleadoI, void* empleadoJ)
{
    int horasTrabajadasI;
    int horasTrabajadasJ;

    employee_getHorasTrabajadas(empleadoI, &horasTrabajadasI);
    employee_getHorasTrabajadas(empleadoJ, &horasTrabajadasJ);

    if(horasTrabajadasI>horasTrabajadasJ)
    {
        return 1;
    }
    if(horasTrabajadasJ>horasTrabajadasI)
    {
        return -1;
    }

    return 0;
}

int Employee_sortBySueldo(void* empleadoI, void* empleadoJ)
{
    int sueldoI;
    int sueldoJ;

    employee_getSueldo(empleadoI, &sueldoI);
    employee_getSueldo(empleadoJ, &sueldoJ);

    if(sueldoI>sueldoJ)
    {
        return 1;
    }
    if(sueldoJ>sueldoI)
    {
        return -1;
    }

    return 0;
}

int employee_id (LinkedList* pArrayListEmployee)
{
    Employee* ultimoEmpleado;
    int tam;
    int id=0;

    if(pArrayListEmployee!=NULL)
    {
        tam=ll_len(pArrayListEmployee);
        if(tam==0)
        {
            id=1;
        }
        else
        {
            ultimoEmpleado=ll_get(pArrayListEmployee, tam-1);
            employee_getId(ultimoEmpleado, &id);
        }
        id++;
    }

    return id;
}

