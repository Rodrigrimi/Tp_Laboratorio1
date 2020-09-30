#include "ArrayEmployees.h"
#define libre 0
void MostrarMenu(int opcion)
{
    printf("1. ALTAS: \n");
    printf("2. MODIFICAR: \n");
    printf("3. BAJA:  \n");
    printf("4. INFORMAR: \n");
    printf("\t1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("\t2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n\n\n");
    printf("10. Salir\n");
    printf("Elija una opcion: \n");

}
int removeEmployee(sEmployee miEmpleado, int cant, int id)
{
     int i;
    int varControl;
    int aux;
    printEmployees( miEmpleado,cant);
    int option;
    char opcion;
    printf("Ingrese el numero de id a eliminar: \n");
    scanf("%d",&aux);
    varControl=findEmployeeById(miEmpleado,cant,aux);
    if (varControl==1)
    {
        for(i=0; i<cant; i++)
        {
            if(miEmpleado[i].id==aux)
            {
               miEmpleado[i].isEmpty=-1;

            }
        }
    }
    return -1;
}
int addEmployees(sEmployee miEmpleado[],int cant)
{
    int index;
    int auxReturno=-1;
    int id=100;
    index=LugarLibre(miEmpleado,cant);
    if(index!=-1)
    {

        miEmpleado[index].id=id++;
        printf("Ingrese el nombre del empleado: ");
        fflush(stdin);
        scanf("%s",miEmpleado[index].name);
        printf("Ingrese el apellido del empleado: ");
        fflush(stdin);
        scanf("%s",miEmpleado[index].lastName);
        printf("Ingrese la salario del Empleado: ");
        scanf("%f",&miEmpleado[index].salary);
        while (miEmpleado[index].salary < 0 )
        {
            printf("Reingrese el salario del empleado: ");
            scanf("%f",&miEmpleado[index].salary);
        }
        printf("Ingrese el sector del empleado: ");
        scanf("%d",&miEmpleado[index].sector);
        while (miEmpleado[index].sector <0 || miEmpleado[index].sector > 11)
        {
            printf("Reingrese el sector del empleado: ");
            scanf("%d",&miEmpleado[index].sector);
        }
        miEmpleado[index].isEmpty=-1;
        auxReturno=1;
    }
    return auxReturno;
}
void ModificarDatoPorId(sEmployee miEmpleado[],int cant)
{
    int i;
    int varControl;
    int aux;
    printEmployees( miEmpleado,cant);
    int option;
    char opcion;
    printf("Ingrese el numero de id");
    scanf("%d",&aux);
    varControl=findEmployeeById(miEmpleado,cant,aux);
    if (varControl==1)
    {
        for(i=0; i<cant; i++)
        {
            if(miEmpleado[i].id==aux)
            {
                do
                {

                    printf("ingrese la opcion a modificar");
                    scanf("%d",&option);
                    switch(option)
                    {
                    case 1:

                        printf("Ingrese el nombre del empleado: ");
                        fflush(stdin);
                        scanf("%s",miEmpleado[i].name);
                        break;

                    case 2:
                        printf("Ingrese el apellido del empleado: ");
                        fflush(stdin);
                        scanf("%s",miEmpleado[i].lastName);
                        break;
                    case 3:

                        printf("Ingrese la salario del Empleado: ");
                        scanf("%f",&miEmpleado[i].salary);
                        while (miEmpleado[i].salary < 0 )
                        {
                            printf("Reingrese el salario del empleado: ");
                            scanf("%f",&miEmpleado[i].salary);
                        }
                        break;
                    case 4:

                        printf("Ingrese el sector del empleado: ");
                        scanf("%d",&miEmpleado[i].sector);
                        while (miEmpleado[i].sector <0 || miEmpleado[i].sector > 11)
                        {
                            printf("Reingrese el sector del empleado: ");
                            scanf("%d",&miEmpleado[i].sector);
                        }
                        break;
                    case 5:
                        printf("desea seguir modificando? s/n");
                        scanf("%c",&opcion);
                        break;
                    }


                    miEmpleado[i].isEmpty=-1;
                }
                while(opcion=='n');
            }
        }
    }
}
int initEmployees(sEmployee miEmpleado[],int cant)
{
    int i;
    int auxReturn=-1;
    for(i=0; i<cant; i++)
    {
        miEmpleado[i].isEmpty=libre;
        auxReturn=0;
    }
    return auxReturn;
}
int findEmployeeById(sEmployee miEmpleado[], int cant, int pedido)
{
    int i;
    int indice = -1;
    for(i=0; i<cant; i++)
    {
        if(miEmpleado[i].id==pedido&&miEmpleado[i].isEmpty==-1)
        {
            indice =  1;

            break;
        }

    }
    return indice;
}
void printEmployees(sEmployee miEmpleado[],int cant)
{
    int i;
    printf("\tListado de Empleados    \n");
    for(i=0; i<cant; i++)
    {
        if(miEmpleado[i].isEmpty==-1)
        {
            printf("%4d \t%20s\t%20s\t%10f\t%8d\t\n", miEmpleado[i].id,
                   miEmpleado[i].name,
                   miEmpleado[i].lastName,
                   miEmpleado[i].salary,
                   miEmpleado[i].sector);
        }

    }
}

void sortEmployees(sEmployee miEmpleado[],int cant)
{
    int i;
    int j;
    sEmployee auxString;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(miEmpleado[i].lastName,miEmpleado[j].lastName)>0)
            {
                auxString=miEmpleado[i];
                miEmpleado[i]=miEmpleado[j];
                miEmpleado[j]=auxString;
            }
            else
            {
                if(strcmp(miEmpleado[i].lastName,miEmpleado[j].lastName)==0&&
                        miEmpleado[i].sector<miEmpleado[j].sector)

                {
                    auxString=miEmpleado[i];
                    miEmpleado[i]=miEmpleado[j];
                    miEmpleado[j]=auxString;

                }
            }


        }
    }
}
int LugarLibre(sEmployee miEmpleado[], int cant)
{
    int i;
    int indice = -1;

    for(i=0; i<cant; i++)
    {
        if(miEmpleado[i].isEmpty==0)
        {
            indice =  i;
            break;
        }
    }
    return indice;
}

