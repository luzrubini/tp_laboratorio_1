#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
https://mega.nz/#!NTgEDYhT!-pmRR3J2PhYqpHXFgImzzFuU9F4E1iQTFKxgnXtvUWU

int main()
{
    system("color 0f");
    char seguir='s';
    int opcion=0;
    double PrimerOperando;
    double SegundoOperando;
    int BanderaPrimerOperando=0;
    int BanderaSegundoOperando=0;

    while(seguir=='s')
    {
        if(BanderaPrimerOperando==1)
        {
            printf("1- Ingresar 1er operando (A=%f)\n",PrimerOperando);
            printf("2- Ingresar 2do operando (B=y)\n",SegundoOperando);

            if(BanderaSegundoOperando==1)
            {
                system("cls");
                printf("1- Ingresar 1er operando (A=%f)\n",PrimerOperando);
                printf("2- Ingresar 2do operando (B=%f)\n",SegundoOperando);
            }
        }

        else
        {
            printf("1- Ingresar 1er operando (A=x)\n",PrimerOperando);
            printf("2- Ingresar 2do operando (B=y)\n",SegundoOperando);
        }

                printf("3- Calcular la suma (A+B)\n");
                printf("4- Calcular la resta (A-B)\n");
                printf("5- Calcular la division (A/B)\n");
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operaciones\n");
                printf("9- Salir\n");


        scanf("%d",&opcion);
        while(opcion<1 || opcion>9)
        {
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando: ");
                scanf("%lf",&PrimerOperando);
                BanderaPrimerOperando=1;
                break;
            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%lf",&SegundoOperando);
                BanderaSegundoOperando=1;
                break;
            case 3:
                if(BanderaPrimerOperando==1 && BanderaSegundoOperando==1)
                {
                    printf("Resultado de la suma: %f\n",suma(PrimerOperando,SegundoOperando));
                }
                else
                {
                    printf("No se puede calcular sin ambos operandos. \n");
                }
                break;
            case 4:
                if(BanderaPrimerOperando==1 && BanderaSegundoOperando==1)
                {
                    printf("Resultado de la resta: %f\n",resta(PrimerOperando,SegundoOperando));
                }
                else
                {
                    printf("No se puede calcular sin ambos operandos. \n");
                }
                break;
            case 5:
                if(BanderaPrimerOperando==1 && BanderaSegundoOperando==1)
                {
                printf("Resultado de la division: %f\n",division(PrimerOperando,SegundoOperando));
                }
                else
                {
                    printf("No se puede calcular sin ambos operandos. \n");
                }

                break;
            case 6:
                system("cls");
                if(BanderaPrimerOperando==1 && BanderaSegundoOperando==1)
                {
                    printf("Resultado de la multiplicacion: %f\n",multiplicacion(PrimerOperando,SegundoOperando));
                }
                else
                {
                    printf("No se puede calcular sin ambos operandos. \n");
                }
                break;
            case 7:
                if(BanderaPrimerOperando==1)
                {
                    printf("Resultado del factorial: %lld \n",factorial(PrimerOperando));
                }
                else
                {
                    printf("No se puede calcular sin el primer operando. \n");
                }
                break;
            case 8:
                if(BanderaPrimerOperando==1 && BanderaSegundoOperando==1)
                {
                    printf("Resultado de la suma: %f\n",suma(PrimerOperando,SegundoOperando));
                    printf("Resultado de la resta: %f\n",resta(PrimerOperando,SegundoOperando));
                    printf("Resultado de la division: %f\n",division(PrimerOperando,SegundoOperando));
                    printf("Resultado de la multiplicacion: %f\n",multiplicacion(PrimerOperando,SegundoOperando));
                    printf("Resultado del factorial: %lld \n",factorial(PrimerOperando));
                }
                else
                {
                    printf("No se puede calcular sin ambos operandos. \n");
                }
                break;
            case 9:
                seguir = 'n';
                break;

        }
        system("pause");
        system("cls");
    }
    return 0;
}
