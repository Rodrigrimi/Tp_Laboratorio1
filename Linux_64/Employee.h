#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* employList,int id);
int employee_getId(Employee* employList,int* id);

int employee_setNombre(Employee* employList,char* nombre);
int employee_getNombre(Employee* employList,char* nombre);

int employee_setHorasTrabajadas(Employee* employList,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* employList,int* horasTrabajadas);

int employee_setSueldo(Employee* employList,int sueldo);
int employee_getSueldo(Employee* employList,int* sueldo);


int employee_CompareByHT(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);
int employee_CompareByName(void* emp1, void* emp2);
int employee_FindById(LinkedList* pArrayListEmployee, int id);
int removeEmployee(Employee* miEmpleado, int cant);
int ModificarDatoPorId(Employee* miEmpleado);
int GenereID(int cant,int id);
void TolowerToupperName(char name[],char* nombres);
int validNumber(char* number);
#endif // employee_H_INCLUDED
