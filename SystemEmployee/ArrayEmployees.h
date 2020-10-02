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
 * \param opcion int muestra el combo del menu
 * \return void solo muestra por pantalla
 *
 */
void MostrarMenu();
/** \brief
 *
* \param sEmployee[] recivo una estructura
 * \param can int la cantidad de elementos de la estructura
 * \param id int el id se autoincremente a medida se van cargando los daatos
 * \return int
 *
 */
int addEmployees(sEmployee[],int can,int id);
/** \brief
 *
* \param sEmployee[] recivo una estructura e inicializo la estructura
 * \param can int la cantidad de elementos de la estructura
 * \return int
 *
 */
int initEmployees(sEmployee miEmpleado[],int cant);
/** \brief
 *
* \param sEmployee[] recivo una estructura ordeno tanto de mayor a menor y viceversa
 * \param can int la cantidad de elementos de la estructura
 * \return void
 *
 */
void Ordenamiento(sEmployee miEmpleado[],int cant);
/** \brief
 *
* \param sEmployee[] recivo una estructura remuevo un empleado logicamente
 * \param can int la cantidad de elementos de la estructura
 * \return int
 *
 */
int removeEmployee(sEmployee miEmpleado[], int cant);
/** \brief
 *
* \param sEmployee[] recivo una estructura y muestro  la lista de empleados llamando a la funcion printEmployee
 * \param can int la cantidad de elementos de la estructura
 * \return void
 *
 */
void printEmployees(sEmployee miEmpleado[], int cant);
/** \brief
 *
 * \param miEmpleado sEmployee Imprime la funcion a un empleado por pantalla
 * \return void no retorna nada
 *
 */
void printEmployee(sEmployee miEmpleado);
/** \brief
 *
* \param sEmployee[] recivo una estructura  recorre el array para encontrar si hay lugar en la entructura para cargar datos
 * \param can int la cantidad de elementos de la estructura
 * \return int
 *
 */
int LugarLibre(sEmployee miEmpleado[], int cant);
/** \brief
 *
* \param sEmployee[] recivo una estructura busca al empleado por id y retorna si se encontro o no dicho id
 * \param can int la cantidad de elementos de la estructura
 * \param pedido int
 * \return int
 *
 */
int findEmployeeById(sEmployee miEmpleado[], int cant,int pedido);
/** \brief
 *
 * \param miEmpleado[] sEmployee modifica a un empleado los datos
 * \param cant int
 * \return void
 *
 */
void ModificarDatoPorId(sEmployee miEmpleado[],int cant);
/** \brief
 *
 * \param cant int pido el tamaño y le hago un autoincremento para la generacion de un id autoincremental
 * \param id int
 * \return int
 *
 */
int GenereID(int cant,int id);
/** \brief
 *
* \param sEmployee[] recivo una estructura recivo una estructura ordeno tanto de A a Z y viceversa
 * \param can int la cantidad de elementos de la estructura
 * \param order int
 * \return void
 *
 */
void sortEmployees(sEmployee miEmpleado[], int cant, int order);
/** \brief
 *
 * \param miEmpleado[] sEmployee muestro el total y promedio de los salarios y los que superan al promedio de los empleados cargdos
 * \param cant int
 * \return void
 *
 */
void PromedioSalarios(sEmployee miEmpleado[],int cant);

/** \brief
 *
 * \param name[] char mando por parametro el nombre me lo retorna la primera en mayusculas y el resto en minusculas
 * \param lastName[] char mando por parametro el apellido me lo retorna la primera en mayusculas y el resto en minusculas
 * \return void
 *
 */
void TolowerToupperName(char name[],char lastName[]);
