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
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* aux;
    char id[5];
    char nombre[51];
    char horasTr[10];
    char sueldo[10];
    int cuantos;
    int retorno=0;
    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTr,sueldo);
        while(!feof(pFile))
        {
            cuantos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTr,sueldo);
            if(cuantos==4)
            {
                aux=employee_newParametros(id,nombre,horasTr,sueldo);
                ll_add(pArrayListEmployee,aux);
            }
        }
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int retorno=0;
    int banderaLecturaOk;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            aux=employee_new();
            banderaLecturaOk=fread(&aux,sizeof(Employee),1,pFile);
            while(banderaLecturaOk==1)
            {

                ll_add(pArrayListEmployee,aux);
            }
        }
        retorno=1;
    }
    return retorno;
}
