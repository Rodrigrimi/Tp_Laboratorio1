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
int addEmployees(sEmployee miEmpleado[],int cant,int id)
{
    int index;
    int auxReturno=-1;
    index=LugarLibre(miEmpleado,cant);
    if(index!=-1)
    {
        miEmpleado[index].id=GenereID(0,id);
        //ValidoString(miEmpleado[index].name,cant);
        //ValidoString(miEmpleado[index].lastName,cant);
        printf("Ingrese el nombre del empleado:  ");
        fflush(stdin);
        scanf("%s",miEmpleado[index].name);
        printf("Ingrese el apellido del empleado: ");
        fflush(stdin);
        scanf("%s",miEmpleado[index].lastName);
        printf("Ingrese la salario del empleado: ");
        scanf("%f",&miEmpleado[index].salary);
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
/*
void ValidoString(char miEmpleado[],int cant)
{
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(miEmpleado.name);
    while(strlen(miEmpleado.name)>51)
    {
        printf("Reingrese su nombre: ");
        fflush(stdin);
        gets(miEmpleado.name);
    }
    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(miEmpleado.lastName);
    while(strlen(miEmpleado.lastName)>51)
    {
        printf("Reingrese su apellido: ");
        fflush(stdin);
        gets(miEmpleado.lastName);
    }
    strlwr(miEmpleado.name);
    for(i=0; i<cant; i++)
    {
        if(isspace(miEmpleado.name[i]))
        {
            miEmpleado.name[i+1]=toupper(miEmpleado.name[i+1]);
        }
    }
    puts(miEmpleado.name);
    strlwr(miEmpleado.lastName);
    for(i=0; i<cant; i++)
    {
        if(isspace(miEmpleado.lastName[i]))
        {
            miEmpleado.lastName[i+1]=toupper(miEmpleado.lastName[i+1]);
        }
    }
    puts(miEmpleado.lastName);
    return 0;
}
*/
void PromedioSalarios(sEmployee miEmpleado[],int cant)
{
    int i;
    float auxSalario;
    float totalpromedio;
    auxSalario=0;
    for(i=0; i<cant; i++)
    {
        if(miEmpleado[i].isEmpty==-1)
        {
            auxSalario=auxSalario+miEmpleado[i].salary;
        }
    }
    if(i==cant)
    {
        totalpromedio=auxSalario/cant;
        printf(" El Tota de los salarios es: \t%f\n  El promedio de los salarios: \t%f\n\n Y los empleados superan el salario promedio  \n\n",auxSalario,totalpromedio);
        for(i=0; i<cant; i++)
        {
            if(miEmpleado[i].salary>totalpromedio)
            {
                printEmployee(miEmpleado[i]);
            }
        }
    }
}
int removeEmployee(sEmployee miEmpleado[], int cant)
{
    int i;
    int varControl;
    int aux;
    int  retorno;
    retorno=0;
    printEmployees( miEmpleado,cant);
    printf("Ingrese el numero de id");
    scanf("%d",&aux);
    varControl=findEmployeeById(miEmpleado,cant,aux);
    if (varControl==1)
    {
        for(i=0; i<cant; i++)
        {
            if(miEmpleado[i].id==aux)
            {
                miEmpleado[i].isEmpty=libre;
                retorno=-1;
            }
        }
    }
    return retorno;
}
void ModificarDatoPorId(sEmployee miEmpleado[],int cant)
{
    int i;
    int varControl;
    int aux;
    printEmployees( miEmpleado,cant);
    int option;
    printf("Ingrese el numero de id : \t");
    scanf("%d",&aux);
    varControl=findEmployeeById(miEmpleado,cant,aux);
    if (varControl==1)
    {
        for(i=0; i<cant; i++)
        {
            if(miEmpleado[i].id==aux&&miEmpleado[i].isEmpty==-1)
            {
                do
                {
                    system("cls");
                    printEmployee(miEmpleado[i]);
                    printf("Ingrese la opcion a modificar\n");
                    printf("1- Modifica el Nombre\n");
                    printf("2- Modifica el Apellido\n");
                    printf("3- Modifica el Salario \n");
                    printf("4- Modifica el sector\n");
                    printf("5- salir de las modificaciones");
                    scanf("%d",&option);
                    while(option<1||option>5)
                    {
                        printf("Reingrese la opcion a modificar\n");
                        printf("1- Modifica el Nombre\n");
                        printf("2- Modifica el Apellido\n");
                        printf("3- Modifica el Salario \n");
                        printf("4- Modifica el sector\n");
                        scanf("%d",&option);
                    }
                    switch(option)
                    {
                    case 1:
                        printf("Ingrese el nombre del empleado: \n");
                        fflush(stdin);
                        scanf("%s",miEmpleado[i].name);
                        system("pause");
                        break;
                    case 2:
                        printf("Ingrese el apellido del empleado: \n");
                        fflush(stdin);
                        scanf("%s",miEmpleado[i].lastName);
                        system("pause");
                        break;
                    case 3:
                        printf("Ingrese la salario del Empleado: \n");
                        scanf("%f",&miEmpleado[i].salary);
                        while (miEmpleado[i].salary < 0 )
                        {
                            printf("Reingrese el salario del empleado: \n");
                            scanf("%f",&miEmpleado[i].salary);
                        }
                        system("pause");
                        break;
                    case 4:
                        printf("Ingrese el sector del empleado: \n");
                        scanf("%d",&miEmpleado[i].sector);
                        while (miEmpleado[i].sector <0 || miEmpleado[i].sector > 11)
                        {
                            printf("Reingrese el sector del empleado: \n");
                            scanf("%d",&miEmpleado[i].sector);
                        }
                        system("pause");
                        break;
                    case 5:
                        printf("salio");
                        system("pause");
                        break;
                    }
                }
                while(option!=5);

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
            printEmployee(miEmpleado[i]);
        }

    }
}

void Ordenamiento(sEmployee miEmpleado[],int cant)
{
    int i;
    int j;
    sEmployee auxString;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(miEmpleado[i].lastName,miEmpleado[j].lastName)>0&&miEmpleado[i].isEmpty==-1)
            {
                auxString=miEmpleado[i];
                miEmpleado[i]=miEmpleado[j];
                miEmpleado[j]=auxString;
            }
            else
            {
                if(strcmp(miEmpleado[i].lastName,miEmpleado[j].lastName)==0&&
                        miEmpleado[i].sector<miEmpleado[j].sector&&miEmpleado[i].isEmpty==-1)

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
int GenereID(int cant,int id)
{
    int generoId;
    generoId=cant+id;
    return generoId;
}
void sortEmployees(sEmployee miEmpleado[], int cant, int order)
{
    int i;
    switch(order)
    {
    case 1:
        for(i=0; i<cant; i++)
        {
            if(miEmpleado[i].isEmpty==-1)
            {
                printEmployee(miEmpleado[i]);

            }

        }
        system("pause");
        break;
    case 2:
        for(i=cant-1; i>=0; i--)
        {
            if(miEmpleado[i].isEmpty==-1)
            {
                printEmployee(miEmpleado[i]);
            }
        }
        system("pause");
        break;
    }
}

void printEmployee(sEmployee miEmpleado)
{
    if(miEmpleado.isEmpty==-1)
    {
        printf("%4d \t%20s\t%20s\t%10f\t%8d\t\n", miEmpleado.id,
               miEmpleado.name,
               miEmpleado.lastName,
               miEmpleado.salary,
               miEmpleado.sector);
    }

}
