#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void altaPersona(EPersona listaPersonas[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(obtenerEspacioLibre(listaPersonas,tam)==i)
        {
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(listaPersonas[i].nombre);
            printf("Ingrese edad: ");
            scanf("%d",&listaPersonas[i].edad);
            printf("Ingrese DNI (sin puntos)");
            scanf("%d",&listaPersonas[i].dni);
            listaPersonas[i].estado=1;

            break;
        }

    }
    if(tam==i && obtenerEspacioLibre(listaPersonas,tam)==-1)
    {
        printf("No hay mas espacio");
    }
}
void inicializarEstado(EPersona listaPersonas[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        listaPersonas[i].estado=0;
    }
}
void mostrarPersona(EPersona listaPersonas[],int tam)
{
    ordenarPersonas(listaPersonas,tam);

    int i;
    printf("\tNOMBRE\t\t\tEDAD\t\tDNI\n");
    for(i=0;i<tam;i++)
    {
        if(listaPersonas[i].estado==1)
        {
            printf("%20s\t\t%d\t\t%d\n",listaPersonas[i].nombre,listaPersonas[i].edad,listaPersonas[i].dni);
        }
    }
}
void ordenarPersonas(EPersona listaPersonas[], int tam)
{
    EPersona    AuxEstructura;
    int i,j;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(listaPersonas[i].nombre,listaPersonas[j].nombre)>0)
            {
                AuxEstructura=listaPersonas[i];
                listaPersonas[i]=listaPersonas[j];
                listaPersonas[j]=AuxEstructura;
            }
        }
    }
}
void borrarPersona(EPersona listaPersonas[],int tam)
{
    int dni;
    int i;
    printf("Ingrese DNI:");
    scanf("%d",&dni);
    char respuesta;
    for(i=0;i<tam;i++)
    {
        if(listaPersonas[i].estado==1 && buscarPorDni(listaPersonas,dni,tam)==listaPersonas[i].dni)
        {
            printf("%s--%d--%d\n",listaPersonas[i].nombre,listaPersonas[i].edad,listaPersonas[i].dni);
            printf("Desea eliminar a esta persona? s/n");
            respuesta=tolower(getche());
            if(respuesta=='s')
            {
                listaPersonas[i].estado=0;
                printf("\nOperacion realizada exitosamente!\n");
            }
            else if(respuesta=='n')
            {
                printf("\nNo se han realizado modificaciones.\n");
            }
        }
    }
    if(buscarPorDni(listaPersonas,dni,tam)==-1)
    {
        printf("Esa persona no existe");
    }
}
int buscarPorDni(EPersona listaPersonas [],int dni,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(listaPersonas[i].dni==dni)
        {
            return listaPersonas[i].dni;
        }
    }
    return -1;
}
int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==0)
        {
            return i;
        }
    }
    return -1;

}
void ContarPersonas(EPersona lista[],int tam)
{
    int contMenor19=0;
    int cont19a35=0;
    int contmayor35=0;
    int i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            if(lista[i].edad<19)
            {
                contMenor19++;
            }
            else
            {
                if(lista[i].edad>=19 && lista[i].edad<=35)
                {
                    cont19a35++;
                }
                else
                {
                    contmayor35++;
                }
            }
        }
    }
    graficarPersonas(contMenor19,cont19a35,contmayor35);
}
void graficarPersonas(int menor19,int entre19y35,int mayor35)
{
   int filas [3] = {menor19,entre19y35,mayor35};
   int i;
   int j;
   int maximo=0;

   for(i=0;i<3;i++)
   {
        if(filas[i]>maximo)
        {
            maximo=filas[i];
        }
   }


    for(i=maximo;i>0;i--)
    {
          for(j=0;j<3;j++)
          {
                if(filas[j]>=i)
                {
                    printf("\t%c",158);
                }

                else
                {
                    printf("\t ");
                }
          }
          printf("\n");
   }
    printf("\t<18\t19-35\t>35\n");
}
