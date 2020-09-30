#include <stdlib.h>
#include "ArrayEmployees.h"
#define tam 7

int main()
{
    sEmployee miEmpleado[tam]={{10,"Rodrigo","Grimalt",30000,1,-1},
                                                    {11,"Mariana","Cardozo",20000,2,-1},
                                                    {12,"Pedra","Grimalt",20001,1,-1},
                                                    {13,"Toto","Grimalt",20008,2,-1},
                                                    {14,"Marco","Pepe",20002,1,-1},
                                                    {15,"Marco","Antonio",35000,2,-1}};
                                                            // HARCODEO DATOS
    int idValor;
    int retorno;
    int opcion;
    int orden;
    idValor=1;
    do
    {
        system("cls");
        MostrarMenu(opcion);
        scanf("%d", &opcion);
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
            break;
        case 2:
            system("cls");
            ModificarDatoPorId(miEmpleado,tam);
            break;
        case 3:


            break;
        case 4:
            system("cls");
            Ordenamiento(miEmpleado,tam);
            printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
            printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
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

                break;

            }

            break;
        }
    }
    while(opcion!=10);

    return 0;
}

