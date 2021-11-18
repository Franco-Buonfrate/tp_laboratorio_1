#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_showEmployee(Employee* this);
Employee* employee_findById (LinkedList* pArrayListEmployee);

int Employee_sortByname(void* empleadoI, void* empleadoJ);
int Employee_sortById(void* empleadoI, void* empleadoJ);
int Employee_sortByHorasTrabajadas(void* empleadoI, void* empleadoJ);
int Employee_sortBySueldo(void* empleadoI, void* empleadoJ);

int employee_id (LinkedList* pArrayListEmployee);

#endif // employee_H_INCLUDED
