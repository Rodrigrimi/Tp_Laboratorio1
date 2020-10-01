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
 * \param opcion int
 * \return void
 *
 */
void MostrarMenu(int opcion);
/** \brief
 *
 * \param sEmployee[]
 * \param can int
 * \param id int
 * \return int
 *
 */
int addEmployees(sEmployee[],int can,int id);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \return int
 *
 */
int initEmployees(sEmployee miEmpleado[],int cant);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \return void
 *
 */
void Ordenamiento(sEmployee miEmpleado[],int cant);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \return int
 *
 */
int removeEmployee(sEmployee miEmpleado[], int cant);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \return void
 *
 */
void printEmployees(sEmployee miEmpleado[], int cant);
/** \brief
 *
 * \param miEmpleado sEmployee
 * \return void
 *
 */
void printEmployee(sEmployee miEmpleado);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \return int
 *
 */
int LugarLibre(sEmployee miEmpleado[], int cant);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \param pedido int
 * \return int
 *
 */
int findEmployeeById(sEmployee miEmpleado[], int cant,int pedido);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \return void
 *
 */
void ModificarDatoPorId(sEmployee miEmpleado[],int cant);
/** \brief
 *
 * \param cant int
 * \param id int
 * \return int
 *
 */
int GenereID(int cant,int id);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \param order int
 * \return void
 *
 */
void sortEmployees(sEmployee miEmpleado[], int cant, int order);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \return void
 *
 */
void PromedioSalarios(sEmployee miEmpleado[],int cant);
/** \brief
 *
 * \param miEmpleado[] sEmployee
 * \param cant int
 * \return void
 *
 */
void ValidoString(char miEmpleado,int cant);
