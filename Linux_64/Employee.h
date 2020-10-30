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
int GenereID(int cant,int id);
#endif // employee_H_INCLUDED
