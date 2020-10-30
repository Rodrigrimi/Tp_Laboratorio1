#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* aux;
    aux= (Employee*) malloc(sizeof(Employee));

    return aux;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* aux;
    aux = employee_new();

    if(aux!=NULL)
    {
        employee_setId(aux,atoi(idStr));
        employee_setNombre(aux,nombreStr);
        employee_setHorasTrabajadas(aux,atoi(horasTrabajadasStr));
        employee_setSueldo(aux,atoi(sueldoStr));
    }

    return aux;
}
/*void employee_delete()
{
}*/

int employee_setId(Employee* employList,int id)
{
    int setteo=0;
    if(employList!=NULL)
    {
        employList->id=id;
        setteo=1;
    }
    return setteo;
}
int employee_getId(Employee* employList,int* id)
{
    int getter=0;
    if(employList!=NULL&&id!=NULL)
    {
        *id=employList->id;
        getter=1;
    }
    return getter;
}
int employee_setNombre(Employee* employList,char* nombre)
{
    int setteo=0;
    if(employList!=NULL)
    {
        strcpy(employList->nombre,nombre);
        setteo=1;
    }
    return setteo;
}
int employee_getNombre(Employee* employList,char* nombre)
{
    int getter=0;
    if(employList!=NULL&&nombre!=NULL)
    {
        strcpy(*nombre,employList->nombre);
        getter=1;
    }
    return getter;
}

int employee_setHorasTrabajadas(Employee* employList,int horasTrabajadas)
{
    int setteo=0;
    if(employList!=NULL)
    {
        employList->horasTrabajadas=horasTrabajadas;
        setteo=1;
    }
    return setteo;
}
int employee_getHorasTrabajadas(Employee* employList,int* horasTrabajadas)
{
    int getter=0;
    if(employList!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=employList->horasTrabajadas;
        getter=1;
    }
    return getter;
}

int employee_setSueldo(Employee* employList,int sueldo)
{
    int setteo=0;
    if(employList!=NULL)
    {
        employList->sueldo=sueldo;
        setteo=1;
    }
    return setteo;
}
int employee_getSueldo(Employee* employList,int* sueldo)
{
    int getter=0;
    if(employList!=NULL&&sueldo!=NULL)
    {
        *sueldo=employList->sueldo;
        getter=1;
    }
    return getter;
}
int employee_CompareByName(Employee* e1, Employee* e2)
{
    return strcmp(e1->nombre,e2->nombre);
}
int employee_CompareById(Employee* e1, Employee* e2)
{
    int compare=0;
    if(e1->id>e2->id)
    {
        compare=1;
    }
    else
    {
        if(e1->id<e2->id)
        {
            compare=-1;
        }
    }
    return compare;
}


int GenereID(int cant,int id)
{
    int generoId;
    generoId=cant+id;
    return generoId;
}
