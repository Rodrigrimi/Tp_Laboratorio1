#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>


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
      //   if(employee_setId(unEmpleado,auxId)==1 &&
                //    employee_setNombre(unEmpleado,aNombre)==1 &&
                 //   employee_setHorasTrabajadas(unEmpleado,aHorasTrab)==1 &&
                 //   employee_setSueldo(unEmpleado,asueldo)==1)
    }

    return aux;
}
/*void employee_delete()
{
}*/

int employee_setId(Employee* employList,int id)
{
    int setteo=0;
    if(employList!=NULL&& id>0)
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
        strcpy(nombre,employList->nombre);
        getter=1;
    }
    return getter;
}

int employee_setHorasTrabajadas(Employee* employList,int horasTrabajadas)
{
    int setteo=0;
    if(employList!=NULL&& horasTrabajadas>0)
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
    if(employList!=NULL&& sueldo>0)
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

int employee_CompareById(void* e1, void* e2)
{
    int compare=0;
    Employee* emp1;
    Employee* emp2;
    int id1;
    int id2;
    if(e1!=NULL && e2!=NULL)
    {
        emp1=(Employee*)e1;
        emp2=(Employee*)e2;
        employee_getId(emp1,&id1);
        employee_getId(emp2,&id2);

        if(id1>id2)
        {

            compare=1;
        }
        else
        {
            if(id1<id2)
            {
                compare=-1;
            }
        }
    }
    return compare;
}
/*int employee_CompareByHT(void* e1, void* e2)
{
    int compare=0;
    Employee* emp1;
    Employee* emp2;
    int HT1;
    int HT2;
    if(e1!=NULL && e2!=NULL)
    {
        emp1=(Employee*)e1;
        emp2=(Employee*)e2;
        employee_getHorasTrabajadas(emp1,&HT1);
        employee_getHorasTrabajadas(emp2,&Ht2);

        if(id1>id2)
        {

            compare=1;
        }
        else
        {
            if(id1<id2)
            {
                compare=-1;
            }
        }
    }
    return compare;
}
*/
int employee_CompareByName(void* e1, void* e2)
{
    int returnValue;
    Employee* emp1;
    Employee* emp2;
    char nombre1[100];
    char nombre2[100];
    if(e1!=NULL && e2!=NULL)
    {
        emp1=(Employee*)e1;
        emp2=(Employee*)e2;
        employee_getNombre(emp1,nombre1);
        employee_getNombre(emp2,nombre2);

        returnValue = strcmp(nombre1, nombre2);
    }

    return returnValue;
}
int employee_FindById(LinkedList* pArrayListEmployee, int id)
{
    Employee* employee;
    int auxId;
    int i;
    int index=-1;
    int size;

    if(pArrayListEmployee != NULL)
    {
        size=ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);
            auxId=employee->id;
            employee_getId(employee, &auxId);

            if(id == auxId)
            {
                index=i;
                break;
            }
        }
    }
    return index;

}
int GenereID(int cant,int id)
{
    int generoId;
    generoId=cant+id;
    return generoId;
}

int ModificarDatoPorId(Employee* miEmpleado)
{
    int opcion;
    char auxNomb[51];
    int auxHorasTrab;
    int auxSueldo;
    do
    {
        printf("Que desea modificar?: ");
        printf("\n 1) Nombre.\n 2)Horas trabajadas.\n 3)Sueldo.\n 4)Salir \n Ingrese opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre del empleado: ");
            scanf("%s",auxNomb);
            employee_setNombre(miEmpleado,auxNomb);
            system("clear");
            break;
        case 2:
            printf("Ingrese nuevas horas trabajadas del empleado: ");
            scanf("%d",&auxHorasTrab);
            employee_setHorasTrabajadas(miEmpleado,auxHorasTrab);
            system("clear");
            break;
        case 3:
            printf("Ingrese nuevo sueldo del empleado: ");
            scanf("%d",&auxSueldo);
            employee_setSueldo(miEmpleado,auxSueldo);
            system("clear");
            break;
        }
    }
    while(opcion!=4);
    return opcion;
}

void TolowerToupperName(char name[],char* nombres)
{
    char nombre[51];//19

    int i;
    int len;
    printf("ingrese su %s ",name);
    __fpurge(stdin);
    scanf("%s",nombre);

    strcpy(nombres,nombre);
    strdup(nombres);
    len = strlen(nombres);
    nombres[0]=toupper(nombres[0]);
    for(i=0; i<len; i++)
    {
        if(isspace(nombre[i]))
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }
    strcpy(nombres,nombre);
}
int validNumber(char* number)
{
    int i;
    for(i=0; i<strlen(number); i++)
    {
        if(!(isdigit(number+i)))
        {
            printf("\nINGRESA SOLO NUMEROS\n");
            getchar();
            return 0;
        }
    }

    return 1;
}

