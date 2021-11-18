#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int validacion=0;
    int cant;
    char buffer[4][128];
    Employee* empleado=NULL;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        rewind(pFile);
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        do{
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant<4)
            {
                break;
            }

            empleado=employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

            if(ll_add(pArrayListEmployee, empleado))
            {
                validacion=0;
                break;
            }
            else
            {
                validacion=1;
            }

        } while(!feof(pFile));
    }
    return validacion;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int validacion=0;
    Employee* auxEmpleado;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            auxEmpleado=employee_new();
            fread(auxEmpleado, sizeof(Employee), 1, pFile);

            if(!feof(pFile))
            {
                if(ll_add(pArrayListEmployee, auxEmpleado)!=0)
                {
                    employee_delete(auxEmpleado);
                    validacion=0;
                    break;
                }
                else
                {
                    validacion=1;
                }
            }
            else
            {
                break;
            }

        } while(!feof(pFile));
    }

    return validacion;
}
