#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/

/** \brief
 *
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \param reintentos int
 * \return int
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int getInt(int* pResultado);

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
int esNumerica(char* cadena);

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/

int myGets(char* cadena, int longitud);

/** \brief Solicita un caracter al usuario, despues de verificarlo devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo char Es la letra maxima a ser aceptada
 * \param maximo char Es la letra minima a ser aceptada
 * \param reintentos int Numero de reintentos
 * \return int 0 Exito, -1 Error
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


/** \brief Funcion usada para verificar el ingreso de caracteres.Chequea para que solo sean admitidas las letras S o N.
 *
 * \param void
 * \return int 0 si se ingreso la N, 1 si se ingreso la S
 *
 */
int verifica(void);

/** \brief
 *
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \param reintentos int
 * \return int
 *
 */
//int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/** \brief
 *
 * \param pResultado float*
 * \return int
 *
 */
//int getFloat(float* pResultado);


/** \brief Solicita un string al usuario, despues de verificarlo copia el resultado en la variable indicada
 *
 * \param pResultado[] char Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimoCaracteres char Es el minimo de caracteres aceptado
 * \param maximoCaracteres char Es el maximo de caracteres aceptado
 * \param reintentos int Numero de reintentos
 * \return int 1 Exito, 0 Error
 *
 */
int utn_getStringChar(char pResultado[], char* mensaje, char* mensajeError, char minimoCaracteres, char maximoCaracteres, int reintentos);

/** \brief Solicita el sexo al usuario validando que sea m, f, o
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param reintentos int Numero de reintentos
 * \return int 1 Exito, 0 Error
 *
 */
int utn_getSexo(char* pResultado, char* mensaje, char* mensajeError, int reintentos);

/** \brief Solicita numero de telefono al usuario tomandolo como un string, valida la cantidad de caracteres del mismo
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param maximoCaracteres int Maximo de caracteres permitidos
 * \param reintentos int Numero de reintentos
 * \return int 1 Exito, 0 Error
 *
 */
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int maximoCaracteres, int reintentos);

int confirmacion(char* pResultado, char* mensaje, char* mensajeError, int reintentos);

