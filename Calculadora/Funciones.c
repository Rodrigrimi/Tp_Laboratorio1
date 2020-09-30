#include "Nuebo.h"
void MostrarMenu(float numeroIngradoA,float numeroIngradoB)
{
    printf("1. Ingresar 1er operando (A=%.2f) \n",numeroIngradoA);
    printf("2. Ingresar 2do operando (B=%.2f) \n",numeroIngradoB);
    printf("3- Calcular todas las operaciones \n");
    printf("4- Informar resultados \n");
    printf("5- Salir \n");
    printf("\n");
}
float CargarNumeros(float numeros)
{
    printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%f", &numeros);
    printf("\n");
    return numeros;
}
long int CalcularFactorial (float numero)
{

    long int resultado;

    if(numero == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = numero * CalcularFactorial(numero - 1);
    }

    return resultado;

}

float Divission(float numero,float divisor)
{
    float resultado;
    resultado=numero/divisor;
    return resultado;
}
float SumarTotales(float numero, float acum)
{
    float suma;
    suma=numero+acum;
    return suma;
}
float RestarTotales(float numero, float acum)
{
    float resta;
    resta=numero-acum;
    return resta;
}
float MultiplicarTotales(float numero, float acum)
{
    long int multiplicaNumero;
    multiplicaNumero=numero*acum;
    return multiplicaNumero;
}
