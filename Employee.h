#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}eEmployee;

/** \brief
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int menuOpciones(LinkedList* lista);

/** \brief
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int mostrarEmpleados(LinkedList* lista);

/** \brief
 *
 * \param unEmpleado eEmployee*
 * \return int
 *
 */
int mostrarEmpleado(eEmployee* unEmpleado);

eEmployee* employee_new();

/** \brief
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return eEmployee*
 *
 */
eEmployee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief
 *
 * \param pEmpleado eEmployee*
 * \return int
 *
 */
int employee_delete(eEmployee* pEmpleado);

/** \brief
 *
 * \param this eEmployee*
 * \param id int
 * \return int
 *
 */
int employee_setId(eEmployee* this,int id);

/** \brief
 *
 * \param this eEmployee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(eEmployee* this,int* id);

/** \brief
 *
 * \param this eEmployee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(eEmployee* this,char* nombre);

/** \brief
 *
 * \param employee eEmployee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(eEmployee* employee,char* nombre);

/** \brief
 *
 * \param this eEmployee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(eEmployee* this,int horasTrabajadas);

/** \brief
 *
 * \param employee eEmployee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(eEmployee* employee,int* horasTrabajadas);

/** \brief
 *
 * \param this eEmployee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(eEmployee* this,int sueldo);

/** \brief
 *
 * \param employee eEmployee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(eEmployee* employee,int* sueldo);

/** \brief
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employeeCmpId(void* a, void* b);

/** \brief
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employeeCmpNombre(void* a, void* b);

/** \brief
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employeeCmpHorasTrabajadas(void* a, void* b);

/** \brief
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employeeCmpSueldo(void* a, void* b);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \param nextId int*
 * \return int
 *
 */
int buscarMayorId(LinkedList* pArrayListEmployee, int* nextId);

#endif // employee_H_INCLUDED
