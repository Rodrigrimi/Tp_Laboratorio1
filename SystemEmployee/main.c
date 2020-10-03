<<<<<<< HEAD
#include<stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define tam 1000
int main()
{
    sEmployee miEmpleado[tam];  /*= {{10,"rodrigo","grimalt",30000,1,-1},
        {11,"mariana","cardozo",20000,2,-1},
        {12,"gedra","grimalt",24001,1,-1},
        {13,"goto","grimalt",20008,2,-1},
        {14,"garco","gepe",25002,1,-1},
        {15,"garco","gntonio",35000,2,-1}
    };*/
    // HARCODEO DATOS
    int idValor;
    int retorno;
    int opcion;
    int orden;
    int retornoRemove;
    idValor=1;
    do
    {
        system("cls");
        MostrarMenu(opcion);
        scanf("%d", &opcion);
        while(opcion!=1&&opcion!=10&&idValor==1)
        {
            system("cls");
            MostrarMenu(opcion);
            fflush(stdin);
            scanf("%d", &opcion);
        }
        switch(opcion)
        {
        case 1:
            system("cls");
            retorno = addEmployees(miEmpleado,tam,idValor);
            if(retorno!=-1)
            {
                idValor++;
                printf("Carga del empleado exitosa...\n");
            }
            else
            {
                printf("No hay mas espacio!!!\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            ModificarDatoPorId(miEmpleado,tam);
            break;
        case 3:
            system("cls");
            retornoRemove=removeEmployee(miEmpleado,tam);
            if(retornoRemove==-1)
            {
                printf("Se elimino correctamente\n");
            }
            else
            {
                printf("No se pudo eliminar el empleado");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            Ordenamiento(miEmpleado,tam);
            printEmployees(miEmpleado,tam);
            printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
            printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
            fflush(stdin);
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                system("cls");
                printf("1- Orden ascendente\n");
                printf("2- Orden descendente\n");
                scanf("%d",&orden);
                sortEmployees(miEmpleado,tam,orden);
                break;
            case 2:
                system("cls");
                PromedioSalarios(miEmpleado,tam);
                system("pause");
                break;
            }
            break;
        }
    }
    while(opcion!=10);
    printf("Salio, usted no quiere cargar mas empleados");
    return 0;
}
=======
#include<stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define tam 1000
int main()
{
    sEmployee miEmpleado[tam] ;  /* = {{10,"rodrigo","grimalt",30000,1,-1},
        {11,"mariana","cardozo",20000,2,-1},
        {12,"gedra","grimalt",24001,1,-1},
        {13,"goto","grimalt",20008,2,-1},
        {14,"garco","gepe",25002,1,-1},
        {15,"garco","gntonio",35000,2,-1}
    };*/
    // HARCODEO DATOS
    int idValor;
    int retorno;
    int opcion;
    int orden;
    int retornoRemove;
    idValor=1;
    do
    {
        system("cls");
        MostrarMenu(opcion);
        scanf("%d", &opcion);
        while(opcion!=1&&idValor==1)
        {
            system("cls");
            MostrarMenu(opcion);
            fflush(stdin);
            scanf("%d", &opcion);
        }
        switch(opcion)
        {
        case 1:
            system("cls");
            retorno = addEmployees(miEmpleado,tam,idValor);
            if(retorno!=-1)
            {
                idValor++;
                printf("Carga del empleado exitosa...\n");
            }
            else
            {
                printf("No hay mas espacio!!!\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            ModificarDatoPorId(miEmpleado,tam);
            break;
        case 3:
            retornoRemove=removeEmployee(miEmpleado,tam);
            if(retornoRemove==-1)
            {
                printf("Se elimino correctamente\n");
            }
            else
            {
                printf("No se pudo eliminar el empleado");
            }
            break;
        case 4:
            system("cls");
            Ordenamiento(miEmpleado,tam);
            printEmployees(miEmpleado,tam);
            printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
            printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
            fflush(stdin);
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("1- Orden ascendente\n");
                printf("2- Orden descendente\n");
                scanf("%d",&orden);
                sortEmployees(miEmpleado,tam,orden);
                break;
            case 2:
                PromedioSalarios(miEmpleado,tam);
                system("pause");
                break;
            }
            break;
        }
    }
    while(opcion!=10);
    printf("Salio, usted no quiere cargar mas empleados");
    return 0;
}
>>>>>>> a7acae5382e7669053650a145d727c14b0fafb1c
