#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define tam 7
int main()
{
    sEmployee miEmpleado[4];
    int retorno;
    int opcion;
    do
    {
        MostrarMenu(opcion);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            retorno = addEmployees(miEmpleado,tam);


            if(retorno!=-1)
            {
                printf("Carga del empleado exitosa...\n");
            }
            else
            {
                printf("No hay mas espacio!!!\n");
            }
            break;
        case 2:
                sortEmployees(miEmpleado,tam);
            break;
            case 3:

                ModificarDatoPorId(miEmpleado,tam);
            break;
        case 4:
            printEmployees( miEmpleado,tam);
            break;
        }
    }
    while(opcion!=10);

    return 0;
}

