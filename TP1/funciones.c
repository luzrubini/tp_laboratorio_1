#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
double suma(double NumeroUno, double NumeroDos)
{
    float resultado;
    resultado=NumeroUno+NumeroDos;
    return resultado;
}
double resta(double NumeroUno, double NumeroDos)
{
    double resultado;
    resultado=NumeroUno-NumeroDos;
    return resultado;
}
double multiplicacion(double NumeroUno, double NumeroDos)
{
    double resultado;
    resultado=NumeroUno*NumeroDos;
    return resultado;
}
double division(double NumeroUno, double NumeroDos)
{
    while(NumeroDos==0)
    {
        printf("Error! Reingrese un divisor distinto a 0: ");
        scanf("%lf",&NumeroDos);
    }
    double resultado;
    resultado=NumeroUno/NumeroDos;
    return resultado;
}
int verificarNumEntero(double Numero)
{
    int BanderaNumEntero=0;
    int NumeroEntero;
    NumeroEntero=(int)Numero;
    if(NumeroEntero==Numero)
    {
        BanderaNumEntero=1;
    }
    return BanderaNumEntero;

}
long long int factorial(double Numero)
{
    long long int resultado;

    while(Numero>20 || Numero<0 || verificarNumEntero(Numero)==0)
    {
         resultado=printf("No se puede calcular el factorial, ingrese un numero entero mayor o igual a 0 y menor a 21: ");
         scanf("%lf",&Numero);
    }
    long long int Numero2=(long long int)Numero;
    if(Numero2==0)
    {
        resultado=1;
    }
    else
    {
    resultado=Numero2*factorial(Numero2-1);
    }

    return resultado;
}
