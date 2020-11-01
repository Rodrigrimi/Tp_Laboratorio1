#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    LinkedList* lista;
    lista = ll_newLinkedList();
    int opcion;
    int remover;
    do
    {
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            controller_loadFromText("data.csv",lista);
            break;
        case 2:
            controller_loadFromBinary("data.csv",lista);
            break;
        case 3:
            controller_addEmployee(lista);
            break;
        case 4:
            // controller_editEmployee(lista);
            break;
        case 5:
            //controller_removeEmployee(lista);
            break;
        case 6:
            controller_ListEmployee(lista);
            break;
        case 7:
            //   controller_sortEmployee();
            break;
        case 8:
            //controller_saveAsText("data.txt",lista);
            break;
        case 9:
            // controller_saveAsBinary("data.dat",lista);
            break;
        }
    }
    while(opcion!=10);
    return 0;
}
