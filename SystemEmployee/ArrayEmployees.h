#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;
void MostrarMenu(int opcion);
int addEmployees(sEmployee[],int can);
int initEmployees(sEmployee miEmpleado[],int cant);
void sortEmployees(sEmployee miEmpleado[],int cant);
int removeEmployee(sEmployee miEmpleado[], int cant, int id);
void printEmployees(sEmployee miEmpleado[], int cant);
int LugarLibre(sEmployee miEmpleado[], int cant);
int findEmployeeById(sEmployee miEmpleado[], int cant,int pedido);
void ModificarDatoPorId(sEmployee miEmpleado[],int cant);
