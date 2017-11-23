typedef struct{
    char titulo[51];
    char genero[41];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char imagen[500];
    int estado;
}EMovie;
/**
 *  Agrega una pelicula al archivo
 *  @param estructura EMovie a agregar
 *  @param char con el titulo
 *  @param char con el genero
 *  @param int con la duracion
 *  @param char con la descripcion
 *  @param int con el puntaje
 *  @param char link de la imagen
 *  @param tamaño del puntero.
 *
 */
void agregarPelicula(EMovie*,char[],char[],int,char[],int,char[],int);
/**
 *  Inicializa los estados de la estructura
 *  @param estructura EMovie a agregar
 *  @param tamaño del puntero.
 */
void inicializarEstados(EMovie*,int);
/**
 *  Pide los datos a cargar en la estructura y en el archivo
 *  @param estructura EMovie a agregar
 *  @param tamaño del puntero.
 */
int cargarPelicula(EMovie*,int);
/**
 *  Crea el archivo
 *  @param estructura EMovie a agregar
 *  @param tamaño del puntero.
 */
void crearArchivo(EMovie*,int);
/**
 *  Elimina una pelicula
 *  @param estructura EMovie cob la pelicula a eliminar
 *  @param tamaño del puntero.
 */
void borrarPelicula(EMovie*,int);
/**
 *  Modifica una pelicula
 *  @param estructura EMovie con la pelicula a modificar
 *  @param tamaño del puntero.
 */
void modificarPelicula(EMovie*,int);
/**
 *  Crea una página web
 *  @param estructura EMovie con la que se creara la pagina
 *  @param tamaño del puntero.
 */
void crearPagina(EMovie*,int);
