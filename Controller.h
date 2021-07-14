#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero  LinkedList
 * \return int 1 exito, 0 error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* flagYaSeCargo, int flagAlta, int nextId);

/** \brief Carga los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero  LinkedList
 * \return int 1 exito, 0 error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* flagYaSeCargo, int flagAlta, int nextId);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero  LinkedList
 * \param id int* Puntero a id a asignar
 * \param flagAlta int* Puntero a flag que indica si ya se dio alta a algun empleado
 * \return int 1 exito, 0 error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id, int* flagAlta);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero  LinkedList
 * \return int 1 exito, 0 error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*  Puntero  LinkedList
 * \return int 1 exito, 0 error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero  LinkedList
 * \return int 1 exito, 0 error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero  LinkedList
 * \return int 1 exito, 0 error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero  LinkedList
 * \return int 1 exito, 0 error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee, int flagAlta, int* nextId, int flagSeCargo);

/** \brief Guarda los datos de los empleados en el archivo datos.bin (modo binario).
 *
 * \param path char* Ruta del archivo
 * \param pArrayListEmployee LinkedList* Puntero  LinkedList
 * \return int 1 exito, 0 error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee, int flagAlta);

#endif
