#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}eEmployee;

/** \brief Presenta el menu de opciones
 *
 * \param lista LinkedList*
 * \return int opcion elegida por el usuario
 *
 */
int menuOpciones(LinkedList* lista);

/** \brief Imprime la lista de empleados en pantalla
 *
 * \param lista LinkedList* Puntero a linkedList
 * \return int 1 exito, 0 error
 *
 */
int mostrarEmpleados(LinkedList* lista);

/** \brief Imprime 1 empleado en pantalla
 *
 * \param unEmpleado eEmployee* Puntero a estructura de un empleado
 * \return int 1 exito, 0 error
 *
 */
int mostrarEmpleado(eEmployee* unEmpleado);

/** \brief Construye un empleado en memoria dinamica con sus campos inicializados en 0 o " "
 *
 * \return eEmployee* Un empleado inicializado
 *
 */
eEmployee* employee_new();

/** \brief Construye un empleado en memoria dinamica con sus campos parametrizados
 *
 * \param idStr char* Parametro 1
 * \param nombreStr char* Parametro 2
 * \param horasTrabajadasStr char* Parametro 3
 * \param sueldoStr char* Parametro 4
 * \return eEmployee* Empleado con sus campos parametrizados
 *
 */
eEmployee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Destruye una estructura eEmployee
 *
 * \param pEmpleado eEmployee* Estructura a destruir
 * \return int 1 exito, 0 error
 *
 */
int employee_delete(eEmployee* pEmpleado);

/** \brief Setea el campo Id del empleado
 *
 * \param this eEmployee* Puntero a empleado
 * \param id int ID a setear en el campo
 * \return int 1 exito, 0 error
 *
 */
int employee_setId(eEmployee* this,int id);

/** \brief Obtiene el campo Id del empleado
 *
 * \param this eEmployee* Puntero a empleado
 * \param id int* Variable donde se guarda el campo obtenido
 * \return int 1 exito, 0 error
 *
 */
int employee_getId(eEmployee* this,int* id);

/** \brief Setea el campo Nombre del empleado
 *
 * \param this eEmployee* Puntero a empleado
 * \param nombre char* Nombre a setear en el campo
 * \return int 1 exito, 0 error
 *
 */
int employee_setNombre(eEmployee* this,char* nombre);

/** \brief Obtiene el campo Nombre del empleado
 *
 * \param employee eEmployee* Puntero a empleado
 * \param nombre char* Variable donde se guarda el campo obtenido
 * \return int 1 exito, 0 error
 *
 */
int employee_getNombre(eEmployee* employee,char* nombre);

/** \brief Setea el campo HorasTrabajadas del empleado
 *
 * \param this eEmployee* Puntero a empleado
 * \param horasTrabajadas int horasTrabajadas a setear en el campo
 * \return int 1 exito, 0 error
 *
 */
int employee_setHorasTrabajadas(eEmployee* this,int horasTrabajadas);

/** \brief Obtiene el campo horasTrabajadas del empleado
 *
 * \param employee eEmployee* Puntero a empleado
 * \param horasTrabajadas int* Variable donde se guarda el campo obtenido
 * \return int 1 exito, 0 error
 *
 */
int employee_getHorasTrabajadas(eEmployee* employee,int* horasTrabajadas);

/** \brief Setea el campo Sueldo del empleado
 *
 * \param this eEmployee* Puntero a empleado
 * \param sueldo int Sueldo a setear en el campo
 * \return int 1 exito, 0 error
 *
 */
int employee_setSueldo(eEmployee* this,int sueldo);

/** \brief Obtiene el campo Sueldo del empleado
 *
 * \param employee eEmployee* Puntero a empleado
 * \param sueldo int* Variable donde se guarda el campo obtenido
 * \return int 1 exito, 0 error
 *
 */
int employee_getSueldo(eEmployee* employee,int* sueldo);

/** \brief Ordena los empleados por id
 *
 * \param a void* Puntero a void
 * \param b void* Puntero a void
 * \return int 1 exito, 0 error
 *
 */
int employeeCmpId(void* a, void* b);

/** \brief Ordena los empleados por Nombre
 *
 * \param a void* Puntero a void
 * \param b void* Puntero a void
 * \return int 1 exito, 0 error
 *
 */
int employeeCmpNombre(void* a, void* b);

/** \brief Ordena los empleados por HorasTrabajadas
 *
 * \param a void* Puntero a void
 * \param b void* Puntero a void
 * \return int 1 exito, 0 error
 *
 */
int employeeCmpHorasTrabajadas(void* a, void* b);

/** \brief Ordena los empleados por Sueldo
 *
 * \param a void* Puntero a void
 * \param b void* Puntero a void
 * \return int 1 exito, 0 error
 *
 */
int employeeCmpSueldo(void* a, void* b);

/** \brief Busca el id mayor en la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a linkedList
 * \param nextId int* variable que contiene el id actual
 * \return int 1 exito, 0 error
 *
 */
int buscarMayorId(LinkedList* pArrayListEmployee, int* nextId);

#endif // employee_H_INCLUDED
