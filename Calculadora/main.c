#include "Nuebo.h"
int main()
{
    float resDivision;
    float resSuma;
    float resResta;
    float resMultiplicacion;
    long int resFactorial;
    long int factorialB;
    float numeroIngresadoA=0;
    float numeroIngresadoB=0;
    int opcionA;
    do
    {
        MostrarMenu(numeroIngresadoA,numeroIngresadoB);
        opcionA=CargarNumeros(opcionA);

        switch(opcionA)
        {
        case 1:

            numeroIngresadoA=CargarNumeros(numeroIngresadoA);
            break;
        case 2:
            numeroIngresadoB=CargarNumeros(numeroIngresadoB);
            break;
        case 3:
            if(numeroIngresadoB<=0&&numeroIngresadoA<=0)
            {
                printf("No se puede Calcular si no ha cargado datos\n");
            }
            else
            {

                printf("\t\tExito al calcular las operaciones\n\n\n");
                resDivision=Divission(numeroIngresadoA,numeroIngresadoB);
                resSuma=SumarTotales(numeroIngresadoA,numeroIngresadoB);
                resResta=RestarTotales(numeroIngresadoA,numeroIngresadoB);
                resMultiplicacion=MultiplicarTotales(numeroIngresadoA,numeroIngresadoB);
                if(numeroIngresadoA>=0 && numeroIngresadoA == (int) numeroIngresadoA)
                {
                    resFactorial=CalcularFactorial(numeroIngresadoA);
                }
                if(numeroIngresadoB>=0 && numeroIngresadoB==(int) numeroIngresadoB)
                {
                    factorialB=CalcularFactorial(numeroIngresadoB);
                }
            }
            break;
        case 4:
            printf ("\nEl resultado de A+B es:: %.2f\n",resSuma);
            printf ("\nEl resultado de A+B es:: %.2f\n",resSuma);
            printf ("\nEl resultado de A-B es:  %.2f\n",resResta);
            printf ("\nEl resultado de la A*B es: %.2f\n",resMultiplicacion);
            if(numeroIngresadoB==0)
            {
                printf("\nNo es posible dividir por cero\n");
            }
            else
            {
                printf ("\nEl resultado de A/B es: %.2f\n",resDivision);
            }

            if(numeroIngresadoA== (int) numeroIngresadoA && numeroIngresadoA>=0)
            {
                printf ("\nEl factorial de A es: %ld ",resFactorial);
            }
            else
            {
                printf("\nNo se puede realizar el factorial de un numero negativo y decimal\n");
            }
            if(numeroIngresadoB== (int) numeroIngresadoB && numeroIngresadoB>=0)
            {
                printf ("y El factorial de B es: %d \n",factorialB);
            }
            else
            {
                printf("\nNo se puede realizar el factorial de un numero negativo y decimal\n");
            }
            break;
        case 5:
            printf("\t\tGracias por usar la calculadora\n");
            break;
        default:
            printf("\t\tSe genero un error ingrese nuevamente\n");
            MostrarMenu(numeroIngresadoA,numeroIngresadoB);
            break;
        }
    }
    while(opcionA!=5);
    return 0;
}
