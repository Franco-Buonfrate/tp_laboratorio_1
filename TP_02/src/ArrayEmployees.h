/*
 * ArrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: franc
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;


int menu();

int initEmployees(Employee* list, int len);

int dataEntry(Employee* list);

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee* list, int len,int id);

int employeeToModify(Employee* list, int len, int indice);

int removeEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

int printEmployees(Employee* list, int length);

int salary (Employee* list, int len);

int entryValidation(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
