#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo=(FILE*) malloc(sizeof(FILE));
    int retorno=0;
    if(path!=NULL)
    {
        pArchivo=fopen(path,"r");
        if(pArchivo!=NULL)
        {
            retorno=parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        }

    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo=(FILE*) malloc(sizeof(FILE));
    if(path!=NULL)
    {
        pArchivo=fopen(path,"rb");
        if(pArchivo!=NULL)
        {
            parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        }
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    empleado=employee_new();
    char auxId;
    char auxNombre;
    char auxHorasTra;
    char auxSueldo;
    if(pArrayListEmployee!=NULL)
    {
        if(employee_setId(empleado,auxId)==1 &&
                        employee_setNombre(empleado,auxNombre)==1 &&
                        employee_setHorasTrabajadas(empleado,auxHorasTra)==1 &&
                        employee_setSueldo(empleado,auxSueldo)==1)
        {
            employee_setId(empleado,atoi(auxId));
            employee_setNombre(empleado,auxNombre);
            employee_setHorasTrabajadas(empleado,atoi(auxHorasTra));
            employee_setSueldo(empleado,atoi(auxSueldo));
        }
        ll_add(pArrayListEmployee,empleado);
    }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    Employee* aux;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            aux= (Employee*)ll_get(pArrayListEmployee,i);
            printf("%5d %15s %5d %5d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

