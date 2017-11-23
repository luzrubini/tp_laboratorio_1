#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
int cargarPelicula(EMovie* movie,int max)
{
    int returnAux=0;
    char titulo[51];
    char genero[41];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char imagen[500];
    int estado;
    int i;
    int bandera=1;

    if(bandera==0)
    {
        inicializarEstados(movie,max);
        bandera=1;
    }
    if(bandera==1)
    {
        printf("Ingrese titulo: ");
        fflush(stdin);
        gets(titulo);
        printf("Ingrese genero: ");
        fflush(stdin);
        gets(genero);
        printf("Ingrese duracion (minutos): ");
        scanf("%d",&duracion);
        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(descripcion);
        printf("Ingrese puntaje: ");
        scanf("%d",&puntaje);
        printf("ingrese el Link a la imagen: ");
        fflush(stdin);
        gets(imagen);
        estado=1;
        for(i=0;i<max;i++)
        {
            if((movie+i)->estado==0)
            {
                agregarPelicula((movie+i),titulo,genero,duracion,descripcion,puntaje,imagen,estado);
                crearArchivo(movie,max);
                returnAux=1;
                break;
            }
        }
    }
    return returnAux;
}
void inicializarEstados(EMovie* movie,int max)
{
    int i;
    for(i=0;i<max;i++)
    {
        (movie+i)->estado=0;
    }
}
void agregarPelicula(EMovie* movie,char titulo[],char genero[],int duracion,char descripcion[],int puntaje,char imagen[],int estado)
{
    strcpy(movie->titulo,titulo);
    strcpy(movie->genero,genero);
    movie->duracion=duracion;
    strcpy(movie->descripcion,descripcion);
    movie->puntaje=puntaje;
    strcpy(movie->imagen,imagen);
    movie->estado=estado;
}
void crearArchivo(EMovie* movie,int max)
{
    FILE* pFile;
    int i;

            pFile=fopen("peliculas.dat","wb");
            if(pFile!=NULL)
            {
                for(i=0;i<max;i++)
                {
                    if((movie+i)->estado==1)
                    {
                        fwrite((movie+i),sizeof(EMovie),1,pFile);
                    }
                }
            }
            else
            {
                printf("No se pudo generar el archivo.\n");
                system("pause");
            }
            fclose(pFile);

}
void borrarPelicula(EMovie* movie,int max)
{
    int i;
    int returnAux=0;
    char titulo[51];
    char opcion;

        for(i=0;i<max;i++)
        {
            if((movie+i)->estado==1)
            {
                printf("PELICULAS:\n\n");
                for(i=0;i<max;i++)
                {
                    if((movie+i)->estado==1)
                    {
                        printf("Titulo:  %s\n",(movie+i)->titulo);
                    }
                }

                printf("\n\nIngrese el titulo: ");
                fflush(stdin);
                gets(titulo);
                for(i=0;i<max;i++)
                {
                    if(strcmp((movie+i)->titulo,titulo)==0)
                    {
                        printf("Pelicula:  %s\n\n",(movie+i)->titulo);
                        printf("Desea Borrar la pelicula (s/n): ");
                        fflush(stdin);
                        opcion = tolower(getch());

                        if(opcion=='s')
                        {
                            (movie+i)->estado=0;
                            printf("\nTitulo eliminado con exito!.\n\n");

                        }
                        else
                        {
                            printf("\n\nse cancelo la baja.\n\n");
                            system("pause");
                        }
                        returnAux=1;
                        break;
                    }
                }
            break;
            }
        }

        if (returnAux==1)
        {
            crearArchivo(movie,max);
        }
}
void modificarPelicula(EMovie* movie,int max)
{
    int i;
    int returnAux=0;
    char tituloModificar[51];
    char opcion;
    char titulo[51];
    char genero[41];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char imagen[500];
    int estado;

        for(i=0;i<max;i++)
        {
            if((movie+i)->estado==1)
            {
                printf("PELICULAS:\n\n");
                for(i=0;i<max;i++)
                {
                    if((movie+i)->estado==1)
                    {
                        printf("Titulo: %s\n",(movie+i)->titulo);
                    }
                }

                printf("\n\nIngrese el titulo: ");
                fflush(stdin);
                gets(tituloModificar);
                for(i=0;i<max;i++)
                {
                    if(strcmp((movie+i)->titulo,tituloModificar)==0)
                    {
                        printf("Pelicula:  %s\n\n",(movie+i)->titulo);
                        printf("Desea modificar la pelicula (s/n): ");
                        fflush(stdin);
                        opcion = tolower(getch());

                        if(opcion=='s')
                        {
                            printf("Ingrese titulo: ");
                            fflush(stdin);
                            gets(titulo);
                            printf("Ingrese genero: ");
                            fflush(stdin);
                            gets(genero);
                            printf("Ingrese duracion (minutos): ");
                            scanf("%d",&duracion);
                            printf("Ingrese descripcion: ");
                            fflush(stdin);
                            gets(descripcion);
                            printf("Ingrese puntaje: ");
                            scanf("%d",&puntaje);
                            printf("ingrese el Link a la imagen: ");
                            fflush(stdin);
                            gets(imagen);
                            estado=1;
                            agregarPelicula((movie+i),titulo,genero,duracion,descripcion,puntaje,imagen,estado);
                            returnAux=1;
                            crearArchivo(movie,max);
                            printf("\nTitulo modificado con exito!.\n\n");

                        }
                        else
                        {
                            printf("\n\nse cancelo la modificacion.\n\n");
                            system("pause");
                        }
                        returnAux=1;
                        break;
                    }
                }
            break;
            }
        }

        if (returnAux==1)
        {
            crearArchivo(movie,max);
        }
}
void crearPagina(EMovie* movie, int cantidadPeliculas)
{
    FILE* miArchivoHTML;
    char nombre[20];
    int i;
    int j,q;
    int auxInt=0;
    char auxCadena[268];
    char segundoAuxiliarCadena[268];
    printf("Ingrese nombre de la pagina: ");
    fflush(stdin);
    gets(nombre);
    strcat(nombre,".html");
    miArchivoHTML=fopen(nombre,"w");
    if(miArchivoHTML==NULL)
    {
        printf("La pagina no se va a poder generar.");
    }
    else
    {

        for(i=0;i<cantidadPeliculas;i++)
        {
            //imagen class='img-responsive img rounded'
            fprintf(miArchivoHTML,"<img  src=%s alt=%s style=width:200px;hight:200px>",(movie+i)->imagen,(movie+i)->titulo);

            //titulo
            fprintf(miArchivoHTML,"<h2><a href=#>%d)%s</a></h2>",i+1,(movie+i)->titulo);

            //otros aspectos

            fprintf(miArchivoHTML,"<h4><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>               </h4>",(movie+i)->genero,(movie+i)->puntaje,(movie+i)->duracion);
            fprintf(miArchivoHTML,"<pre>");
            strcpy(auxCadena,(movie+i)->descripcion);
            q=0;
            for(j=0;j<268;j++)
            {
                segundoAuxiliarCadena[j]=auxCadena[q];
                q++;
                if(j==60||j==124||j==188)
                {
                    j++;
                    segundoAuxiliarCadena[j]='<';
                    j++;
                    segundoAuxiliarCadena[j]='b';
                    j++;
                    segundoAuxiliarCadena[j]='r';
                    j++;
                    segundoAuxiliarCadena[j]='>';

                }
            }
            auxInt=strlen(segundoAuxiliarCadena);
            fwrite(&segundoAuxiliarCadena,sizeof(char),auxInt,miArchivoHTML);
            fprintf(miArchivoHTML,"</pre>");
        }
        fprintf(miArchivoHTML,"</html> </body>");
    }
    fclose(miArchivoHTML);
    printf("La pagina se genero correctamente.\n");
}

