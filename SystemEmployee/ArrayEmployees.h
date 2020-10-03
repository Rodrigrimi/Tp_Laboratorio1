#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;
/** \brief
 *
* \ param option int shows the menu combo
 * \ return void only display per screen
 *
 */
void MostrarMenu();
/** \brief
 *
* \ param sEmployee [] I receive a structure
 * \ param can int the number of elements in the structure
 * \ param id int the id is autoincrement as the data is loaded
 * \ return int
 *
 */
int addEmployees(sEmployee[],int can,int id);
/** \brief
 *
* \ param sEmployee [] I receive a structure and initialize the structure
 * \ param can int the number of elements in the structure
 * \ return int
 *
 */
int initEmployees(sEmployee miEmpleado[],int cant);
/** \brief
 *
* \ param sEmployee [] I receive a structure sorted from highest to lowest and vice versa
 * \ param can int the number of elements in the structure
 * \ return void
 *
 */
void Ordenamiento(sEmployee miEmpleado[],int cant);
/** \brief
 *
* \ param sEmployee [] I receive a structure I remove an employee logically
 * \ param can int the number of elements in the structure
 * \ return int
 *
 */
int removeEmployee(sEmployee miEmpleado[], int cant);
/** \brief
 *
* \ param sEmployee [] I receive a structure and show the list of employees by calling the function printEmployee
 * \ param can int the number of elements in the structure
 * \ return void
 *
 */
void printEmployees(sEmployee miEmpleado[], int cant);
/** \brief
 *
 * \ param myEmployee sEmployee Print the function to an employee on the screen
 * \ return void does not return anything
 *
 */
void printEmployee(sEmployee miEmpleado);
/** \brief
 *
* \ param sEmployee [] I receive a structure traverses the array to find if there is room in the structure to load data
 * \ param can int the number of elements in the structure
 * \ return int
 *
 */
int FindFree(sEmployee miEmpleado[], int cant);
/** \brief
 *
* \ param sEmployee [] I receive a structure that looks for the employee by id and returns if said id was found or not
 * \ param can int the number of elements in the structure
 * \ param int request
 * \ return int
 *
 */
int findEmployeeById(sEmployee miEmpleado[], int cant,int pedido);
/** \brief
 *
 * \ param myEmployee [] sEmployee modifies an employee's data
 * \ param cant int
 * \ return void
 *
 */
void ModificarDatoPorId(sEmployee miEmpleado[],int cant);
/** \brief
 *
 * \ param cant int I ask for the size and I do an autoincrement for the generation of an autoincremental id
 * \ param id int
 * \ return int
 *
 */
int GenereID(int cant,int id);
/** \brief
 *
* \ param sEmployee [] I receive a structure I receive a structure I order from A to Z and vice versa
 * \ param can int the number of elements in the structure
 * \ param order int
 * \ return void
 *
 */
void sortEmployees(sEmployee miEmpleado[], int cant, int order);
/** \brief
 *
 * \ param myEmployee [] sEmployee show the total and average salaries and those that exceed the average of the loaded employees
 * \ param cant int
 * \ return void
 *
 */
void PromedioSalarios(sEmployee miEmpleado[],int cant);

/** \brief
 *
 * \ param name [] char command by parameter the name is returned to me first in uppercase and the rest in lowercase
 * \ param lastName [] char command by parameter the last name returns the first one in uppercase and the rest in lowercase
 * \ return void
 *
 */
void TolowerToupperName(char name[],char* nombres);
/** \brief
 *
 * \param numero[] char
 * \return int
 *
 */
int validNumber(char number[]);
