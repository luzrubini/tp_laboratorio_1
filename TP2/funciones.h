#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int);

/**void inicializarEstado(EPersona listaPersonas[],int tam)
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int,int);
/** \brief da de alta a una persona
 *
 * \param la variable Epersona que quiero dar de alta
 * \param una variable entera que define el tamaño del vector
 * \return la variable EPersona modificada
 */
void altaPersona(EPersona[],int);
/** \brief modifica el estado de una variable de tipo Epersona
 *
 * \param la variable Epersona que quiero modificar el estado
 * \param una variable del tipo int que define el tamaño del vector
 * \return la variable modificada EPersona
 */
void inicializarEstado(EPersona[],int);
/** \brief muestra una lista de personas
 *
 * \param la variable Epersona que quiero mostrar
 * \param una variable del tipo int que define el tamaño del vector
 * \return la variable EPersona
 */
void mostrarPersona(EPersona[],int);
/** \brief ordena el vector por nombre
 *
 * \param el vector de EPersona
 * \param el tamaño del vector
 * 
 */
void ordenarPersonas(EPersona[],int);
/** \brief borra o da de baja a una persona
 *
 * \param la variable Epersona que quiero eliminar
 * \param una variable entera que define el tamaño del vector
 * \return la variable EPersona dada de baja
 */
void borrarPersona(EPersona[],int);
/** \brief Cuenta la cantidad de personas que hay en cada grupo de edad
 *
 * \param la variable Epersona que quiero contar
 * \param una variable entera que define el tamaño del vector
 * \return los contadores por edad y a la funcion graficarPersonas 
 */
void ContarPersonas(EPersona[],int);
/** \brief Grafica personas dependiendo su rango de edad
 *
 * \param variable entera que almacena la cantidad de personas con el primer rango de edad
 * \param variable entera que almacena la cantidad de personas con el segundo rango de edad
 * \param variable entera que almacena la cantidad de personas con el tercer rango de edad
 * \return un grafico con la cantidad de personas dependiendo el rango de edad 
 */
void graficarPersonas(int,int,int);


#endif // FUNCIONES_H_INCLUDED
