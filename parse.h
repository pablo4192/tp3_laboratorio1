#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int 1 exito, 0 error
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero a LinkedList
 * \return int 1 exito, 0 error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
#endif // PARSE_H_INCLUDED
