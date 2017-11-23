#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#define MAX 20

int main()
{
    system("color 0f");
    int cantidadPeliculas=0;
    int opcion;
    char seguir='s';
    EMovie movie[MAX];

    while(seguir=='s')
    {

            printf("\nHay %d peliculas cargadas.\n\n",cantidadPeliculas);
            printf("1-Agregar pelicula\n2-Borrar pelicula\n3-Modificar Pelicula.\n4-Generar pagina web\n5-Salir\n\nIngrese una opcion:");
            scanf("%d",&opcion);
            while(opcion<1 || opcion>5)
            {
                printf("Error! Ingrese una opcion valida: ");
                scanf("%d",&opcion);
            }
            while(opcion>=2 && opcion<=4 &&cantidadPeliculas==0)
            {
                printf("No se puede ingresar esta opcion si tener peliculas cargadas, reingrese: ");
                scanf("%d",&opcion);
            }
        switch(opcion)
        {
        case 1:
            if(cargarPelicula(movie,MAX)==1)
            {
                printf("Pelicula cargada con exito!");
                cantidadPeliculas++;
            }
            else
            {
                printf("No se pudo cargar la película!");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            borrarPelicula(movie,MAX);
             break;
        case 3:
            modificarPelicula(movie,MAX);
            break;
        case 4:
            crearPagina(movie,cantidadPeliculas);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    return 0;
}
