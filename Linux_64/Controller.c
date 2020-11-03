#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
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
int controller_addEmployee(LinkedList* pArrayListEmployee,int addId)
{
    Employee* unEmpleado;
    int auxId;
    char aNombre[128];
    int aHorasTrab;
    int asueldo;
    int retorno=0;
    if(pArrayListEmployee!=NULL)
    {
        unEmpleado=employee_new();
        if(unEmpleado!=NULL)
        {
            auxId=GenereID(1000,addId);
            printf("ID Nuevo empleado: %d\n",auxId);
            TolowerToupperName("nombre", aNombre);
            __fpurge(stdin);
            printf("Ingrese horas trabajadas: ");
            scanf("%d",&aHorasTrab);
            printf("Ingrese sueldo:  ");
            scanf("%d",&asueldo);

            if(employee_setId(unEmpleado,auxId)==1 &&
                    employee_setNombre(unEmpleado,aNombre)==1 &&
                    employee_setHorasTrabajadas(unEmpleado,aHorasTrab)==1 &&
                    employee_setSueldo(unEmpleado,asueldo)==1)
            {
                ll_add(pArrayListEmployee, unEmpleado);
                retorno=1;
            }
        }
    }
    return retorno;
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
    int retorno=-1;
    int auxID;
    int index=-1;
    int opcion;
    Employee* auxEmployee;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Elije el empleado desea modificar?: ");
        scanf("%d",&auxID);
        index=employee_FindById(pArrayListEmployee,auxID);
        if(index != -1)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,index);
            opcion=ModificarDatoPorId(auxEmployee);
            if(opcion==4)
            {
                printf("modicado con exito");
            }
            else
            {
                printf("No se pudo modificar");
            }
            retorno=1;
        }
    }
    else
    {
        retorno=0;
    }
    return retorno;
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
    int auxID;
    Employee* auxEmployee;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("Que empleado desea eliminar?");
        scanf("%d",&auxID);

        //ll_remove(pArrayListEmployee,auxID-1);
        auxEmployee=ll_pop(pArrayListEmployee,auxID-1);
        printf("EMPLEADO ELIMINADO");
        printf("%4d %15s %4d %4d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
    }

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
    LinkedList* aux;
    aux=ll_clone(pArrayListEmployee);

    if (aux!=NULL)
    {
        ll_sort(aux,employee_CompareById,0);
        controller_ListEmployee(aux);
    }

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
    FILE* pFile;
    Employee* miEmpleado;
    int len;
    int retorno=0;
    int id;
    char nomb[51];
    int horast;
    int sueld;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {

            fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
            len=ll_len(pArrayListEmployee);

            for(int i=0; i<len; i++)
            {

                miEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
                if(employee_getId(miEmpleado,&id)==1&&employee_getNombre(miEmpleado,nomb)==1&&employee_getHorasTrabajadas(miEmpleado,&horast)==1&&employee_getSueldo(miEmpleado,&sueld)==1)
                {
                    fprintf(pFile, " %d, %s, %d, %d\n",id,nomb,horast,sueld);
                }
            }
        }
        ll_clear(pArrayListEmployee);
        fclose(pFile);
        retorno=1;

    }

    return retorno;
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
    int i;
    int retorno;
    int len;
    len= ll_len(pArrayListEmployee);
    FILE *punteroArchivoW=fopen(path,"wb");
    Employee* Listado;
    for(i=0;i<len;i++)
    {
        Listado=pArrayListEmployee+i;
        fwrite(&Listado,sizeof(Employee),1,punteroArchivoW);
    }
    fclose(punteroArchivoW);
    retorno=1;
    return retorno;
}

