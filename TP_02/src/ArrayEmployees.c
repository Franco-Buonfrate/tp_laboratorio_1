/*
 * ArrayEmployees.c
 *
 *  Created on: 16 oct. 2021
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int menu()
{
    int opcion;

    system("cls");
    printf("\t*** MENU DE OPCIONES ***\t\n");
    printf("---------------------------------------------\n");
    printf("1- ALTA\n");
    printf("2- MODIFICAR\n");
    printf("3- BAJA\n");
    printf("4- INFORMAR\n");
    printf("0- Salir\n");


    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee* list, int len)
{
    int validation=-1;
    if(list!=NULL && len>0)
    {
        for (int i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        validation=0;
    }
    return validation;
}

int dataEntry(Employee* list)
{
    int validation=0;
    if(list!=NULL)
    {

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(list[0].name);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(list[0].lastName);

        printf("Ingrese salario: ");
        scanf("%f", &list[0].salary);
        while(list[0].salary<1)
        {
            printf("Error, ingrese salario valido: ");
            scanf("%f", &list[0].salary);
        }

        printf("Ingrese sector: ");
        scanf("%d", &list[0].sector);
        while(list[0].sector<1)
        {
            printf("Error, ingrese sector valido: ");
            scanf("%d", &list[0].sector);
        }

        validation=1;
    }
    return validation;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int validation=-1;
    int indice=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0;i<len; i++)
        {
           if(list[i].isEmpty)
           {
               indice=i;
               break;
           }
        }
    }

    if(indice==-1)
    {
        printf("No hay espacio disponible para ingresar un usuario\n");
    }
    else
    {
        list[indice].isEmpty=0;
        list[indice].id=id;
        strcpy(list[indice].name, name);
        strcpy(list[indice].lastName, lastName);
        list[indice].salary=salary;
        list[indice].sector=sector;
        validation=0;
    }

    return validation;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int indice=-1;

    if(list!=NULL && len>0)
    {
       for(int i=0; i<len; i++)
       {
           if(list[i].id==id)
           {
               indice=i;
               break;
           }
       }
    }
    return indice;
}

int employeeToModify(Employee* list, int len, int indice)
{
    int validation=0;
    int option;
    int seguir='s';
    if(list!=NULL && len>0 && indice>=0)
    {
        system("cls");

        printf("\t*** MENU DE MODIFICACION ***\n");
        printf("---------------------------------------------\n");
        printf("1- Nombre\n");
        printf("2- Apellido\n");
        printf("3- Salario\n");
        printf("4- Sector\n");
        printf("0- Cancelar\n");

        printf("\n%d     %s   %s      %.2f         %d\n", list[indice].id,
                                                   list[indice].name,
                                                   list[indice].lastName,
                                                   list[indice].salary,
                                                   list[indice].sector);

        printf("\nIngresar opcion: ");
        scanf("%d", &option);

        do{
            switch(option)
            {
                case 1:
                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(list[indice].name);
                    break;
                case 2:
                    printf("Ingrese apellido: ");
                    fflush(stdin);
                    gets(list[indice].lastName);
                    break;
                case 3:
                    printf("Ingrese salario: ");
                    scanf("%f", &list[indice].salary);
                    while(list[indice].salary<1)
                    {
                        printf("Error, ingrese salario valido: ");
                        scanf("%f", &list[indice].salary);
                    }
                    break;
                case 4:
                    printf("Ingrese sector: ");
                    scanf("%d", &list[indice].sector);
                    while(list[indice].sector<1)
                    {
                        printf("Error, ingrese sector valido: ");
                        scanf("%d", &list[indice].sector);
                    }
                    break;
                case 0:
                    seguir='n';
                    break;
            }
        }while(seguir=='n');

        validation=1;
    }
    return validation;
}

int removeEmployee(Employee* list, int len, int id)
{
    int validation=-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id)
            {
                list[i].isEmpty=1;
                validation=0;
                printf("Se ha realizado la baja de forma correcta.\n");
                break;
            }
        }
    }
    return validation;
}

int sortEmployees(Employee* list, int len, int order)
{
    int validation=-1;
    Employee auxEmployee;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if((order==1 && (list[i].sector<list[j].sector || (list[i].sector==list[j].sector && strcmp(list[i].lastName, list[j].lastName)>0)))
                  ||
                   (order==0 && (list[i].sector>list[j].sector || (list[i].sector==list[j].sector && strcmp(list[i].lastName, list[j].lastName)<0))))
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                }
            }
        }
        validation=0;
    }

    return validation;
}

int printEmployees(Employee* list, int length)
{
  int validation=-1;
  int flag=0;

  if(list!=NULL && length>0)
  {
      sortEmployees(list,length,1);
      system("cls");
      printf("       *** Listado de Empleados ***      \n");
      printf("   Id     Nombre    Apellido       Salario   Sector\n");
      printf("---------------------------------------------\n");
      for(int i=0; i<length; i++)
      {
          if(!list[i].isEmpty)
          {
              flag=1;
              printf("%d     %s   %s      %.2f         %d\n", list[i].id,
                                                   list[i].name,
                                                   list[i].lastName,
                                                   list[i].salary,
                                                   list[i].sector);
          }
      }
      printf("\n");

      if(!flag)
      {
         printf("No se encontraron empleados\n");
      }

      validation=0;
  }


  return validation;
}


int salary (Employee* list, int len)
{
    int validation=0;
    int accumSalary=0;
    int counterEmployee=0;
    float averageSalary;
    int aboveAverageWageAccountant=0;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty)
            {
                accumSalary+=list[i].salary;
                counterEmployee++;
            }
        }

        averageSalary=(float) accumSalary / counterEmployee;
        printf("Cantidad de empleados activos: %d\n", counterEmployee);
        printf("Promedio de salarios: %.1f\n", averageSalary);

        for(int i=0; i<len; i++)
        {
            if(list[i].salary>averageSalary)
            {
                aboveAverageWageAccountant++;
            }
        }

        printf("Cantidad de salarios por encima del promedio: %d\n", aboveAverageWageAccountant);
        validation=1;
    }

    return validation;
}

int entryValidation(Employee* list, int len)
{
    int validation=-1;

    if(list!=NULL && len>0)
    {
        validation=0;
        for(int i=0; i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                validation=1;
            }
        }
    }
    return validation;
}




