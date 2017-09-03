#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/** \brief Realiza una suma entre dos flotantes ingresados por el usuario
 *
 * \param Valor del tipo double
 * \param Valor del tipo double
 * \return Resultado de la suma ambos, valor del tipo double.
 *
 */
double suma(double, double);
/** \brief Realiza una resta entre dos flotantes ingresados por el usuario
 *
 * \param Valor del tipo double
 * \param Valor del tipo double
 * \return Resultado de la resta entre ambos, valor del tipo double.
 *
 */
double resta(double, double);
/** \brief Realiza una multiplicacion entre dos flotantes ingresados por el usuario
 *
 * \param Valor del tipo double
 * \param Valor del tipo double
 * \return Resultado de la multiplicacion entre ambos, valor del tipo double.
 *
 */
double multiplicacion(double, double);
/** \brief Realiza una division entre dos flotantes ingresados por el usuario
 *
 * \param Valor del tipo double
 * \param Valor del tipo double
 * \return Resultado de la division entre ambos, valor del tipo double.
 *
 */
double division(double, double);
/** \brief Verifica que el valor ingresado sea un entero.
 *
 * \param Valor del tipo double.
 * \return Valor del tipo int:  0 si el valor ingresado es decimal.
                                1 si el valor ingresado es entero.
 *
 */
int verificarNumEntero(double);
/** \brief Calcula el factorial del primer valor ingresado.
 *
 * \param Valor del tipo double
 * \return Resultado del factorial, valor del tipo long long int.
 *
 */
long long int factorial(double);


#endif // FUNCIONES_H_INCLUDED
