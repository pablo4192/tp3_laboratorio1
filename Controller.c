#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parse.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int* flagSeCargo, int flagAlta, int nextId)
{
    int todoOk=0;
    int mayor;

    eEmployee* auxEmpleado=NULL;

    if(*flagSeCargo)
    {
        printf("Ya se realizo la carga de los datos\n");
    }

    if(pArrayListEmployee!=NULL && path!=NULL && *flagSeCargo==0)
    {
        FILE* f=fopen(path, "r");
        if(f!=NULL)
        {

            if(parser_EmployeeFromText(f, pArrayListEmployee))
            {
                *flagSeCargo=1;
                todoOk=1;
            }
        }
        fclose(f);

        if(flagAlta==1) //si doy de alta antes de cargar los datos:
        {
            buscarMayorId(pArrayListEmployee, &mayor); //busco el id mayor en el linkedList para sumarlo al id que se dio de alta manualmente y queden actualizados
            for(int i=0; i<nextId-1; i++)              //por ejemplo: di de alta 1 empleado (va a tener id 1), le sumo 1000 (que es el mayor id), me queda ese empleado con el id 1001
            {
                auxEmpleado= (eEmployee*) ll_get(pArrayListEmployee, i);
                if(auxEmpleado!=NULL)
                {
                    auxEmpleado->id+=(mayor-1);         //para que el id quede correcto le resto 1 a mayor por que la funcion buscarMayorId me da el id actualizado (id++)
                    ll_set(pArrayListEmployee, i, auxEmpleado);

                }
            }
            printf("Se actualizaron los id de los empleados cargados manualmente antes de cargar los datos desde el archivo\n\n");

        }
    }

    return todoOk;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int* flagSeCargo, int flagAlta, int nextId)
{
    int retorno=0;
    int mayor;
    eEmployee* auxEmpleado=NULL;

    if(*flagSeCargo)
    {
        printf("Ya se realizo la carga de los datos\n");
    }

    if(path!=NULL && pArrayListEmployee!=NULL && *flagSeCargo==0)
    {
        FILE* f=fopen(path, "rb");
        if(f==NULL)
        {
            printf("No existe un archivo binario con el nombre especificado\n");
        }
        else
        {
            parser_EmployeeFromBinary(f, pArrayListEmployee);
            *flagSeCargo=1;
            retorno=1;
        }

        fclose(f);

        if(flagAlta==1 && *flagSeCargo==1) //si doy de alta antes de cargar los datos:
        {
            buscarMayorId(pArrayListEmployee, &mayor); //busco el id mayor en el linkedList para sumarlo al id que se dio de alta manualmente y queden actualizados
            for(int i=0; i<nextId-1; i++)              //por ejemplo: di de alta 1 empleado (va a tener id 1), le sumo 1000 (que es el mayor id), me queda ese empleado con el id 1001
            {
                auxEmpleado= (eEmployee*) ll_get(pArrayListEmployee, i);
                if(auxEmpleado!=NULL)
                {
                    auxEmpleado->id+=(mayor-1);         //para que el id quede correcto le resto 1 a mayor por que la funcion buscarMayorId me da el id actualizado (id++)
                    ll_set(pArrayListEmployee, i, auxEmpleado);

                }
            }
            printf("Se actualizaron los id de los empleados cargados manualmente antes de cargar los datos desde el archivo\n\n");

        }
    }
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* id, int* flagAlta)
{
    int todoOk=0;

    int idAux=*id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    eEmployee* auxEmpleado=NULL;

    printf("***Alta de empleado***\n\n");


    if(pArrayListEmployee !=NULL)
    {
        auxEmpleado=employee_new();
        if(auxEmpleado!=NULL)
        {
            if(!employee_setId(auxEmpleado, idAux))
            {
                printf("Hubo un problema al asignar el id al empleado\n");
            }


            printf("Se le asigno el legajo: %d\n", auxEmpleado->id);

            if(utn_getStringChar(nombre, "Ingrese Nombre: \n", "Error ingrese Nombre: \n", 3, 20, 3))
            {
                if(!employee_setNombre(auxEmpleado, nombre))
                {
                    printf("Hubo un error al guardar el Nombre\n");
                }
                else
                {
                    utn_getNumero(&horasTrabajadas, "Ingrese horas trabajadas: \n", "Error ingrese horas trabajadas: \n", 0, 1000, 3);
                    if(!employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas))
                    {
                        printf("Hubo un error al guardar las horas trabajadas\n");
                    }
                    else
                    {
                        utn_getNumero(&sueldo, "Ingrese sueldo: \n", "Error ingrese sueldo: \n", 0, 1000000, 3);
                        if(!employee_setSueldo(auxEmpleado, sueldo))
                        {
                            printf("Hubo un error al guardar el sueldo\n");
                        }
                        else
                        {
                            (*id)++;
                            *flagAlta=1;
                            ll_add(pArrayListEmployee, auxEmpleado);

                            auxEmpleado=NULL;
                            todoOk=1;
                        }
                    }
                }
            }
        }
    }

    return todoOk;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int legajoIngresado;
    int legajoAux;
    int opcion;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int flag=0;
    eEmployee* empleadoAmodificar;

    if(pArrayListEmployee!=NULL)
    {
        printf("***Modificar datos del empleado****\n");

        if(mostrarEmpleados(pArrayListEmployee))
        {
            utn_getNumero(&legajoIngresado, "Ingrese el legajo del empleado que desea modificar: \n", "Error ingrese legajo valido: \n", 0, 10000, 3);
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                empleadoAmodificar= (eEmployee*) ll_get(pArrayListEmployee, i);
                employee_getId(empleadoAmodificar, &legajoAux);
                if(legajoAux==legajoIngresado)
                {
                    flag=1;
                    break;
                }

            }

            if(flag)
            {
                system("cls");
                printf("Legajo       Nombre  HorasTrabajadas     Sueldo\n");
                mostrarEmpleado(empleadoAmodificar);
                printf("1. Nombre\n");
                printf("2. Horas trabajadas\n");
                printf("3. Sueldo\n");
                utn_getNumero( &opcion, "Escoja el campo a modificar: \n", "Error escoja opcion valida (1,2,3): \n", 1, 3, 3);
                switch(opcion)
                {
                case 1:
                    utn_getStringChar(nombre, "Ingrese nombre: \n", "Error ingrese nombre valido: \n", 2, 20, 2);
                    employee_setNombre(empleadoAmodificar, nombre);
                    break;
                case 2:
                    utn_getNumero(&horasTrabajadas, "Ingrese horas trabajadas: \n", "Error ingrese horas trabajadas: \n", 0, 1000, 2);
                    employee_setHorasTrabajadas(empleadoAmodificar, horasTrabajadas);
                    break;
                case 3:
                    utn_getNumero(&sueldo, "Ingrese sueldo: \n", "Error ingrese sueldo: \n", 0, 1000000, 2);
                    employee_setSueldo(empleadoAmodificar, sueldo);
                    break;
                }
                todoOk=1;
            }
            else
            {
                printf("No se encontro empleado con el numero de legajo seleccionado\n");
            }

        }
        else
        {
            printf("No hay empleados en la lista\n");
        }
    }



    return todoOk;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int legajo;
    int flag=0;
    char confirma;
    int indice;
    eEmployee* empleadoAeliminar;

    if(pArrayListEmployee!=NULL)
    {
        printf("***Baja de empleado***\n");

        if(mostrarEmpleados(pArrayListEmployee))
        {
            utn_getNumero(&legajo, "Ingrese id del empleado a eliminar: \n", "Error ingrese un legajo valido: \n", 0, 10000, 2);
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                empleadoAeliminar= (eEmployee*) ll_get(pArrayListEmployee, i);
                if(legajo==empleadoAeliminar->id)
                {
                    indice=i;
                    flag=1;
                    break;
                }
            }

            if(flag)
            {
                printf("Legajo       Nombre  HorasTrabajadas     Sueldo\n");
                mostrarEmpleado(empleadoAeliminar);
                confirmacion(&confirma, "Seguro desea dar de baja al empleado seleccionado? \nIngrese s para eliminar o n para cancelar: \n", "Error Ingrese s para eliminar o n para cancelar: \n", 2);
                if(confirma=='s')
                {
                    ll_remove(pArrayListEmployee, indice);
                    todoOk=1;
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }
            else
            {
                printf("No hay un empleado con el legajo seleccionado\n");
            }

        }
        else
        {
            printf("No hay empleados en la lista\n");
        }

    }

    return todoOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    if(pArrayListEmployee!=NULL)
    {
        if(mostrarEmpleados(pArrayListEmployee))
        {
            todoOk=1;
        }

    }

    return todoOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int opcion;
    int orden;

    if(pArrayListEmployee!=NULL)
    {
        printf("***Ordenar empleados***\n");

        if(!mostrarEmpleados(pArrayListEmployee))
        {
            printf("No hay empleados para ordenar\n");
        }
        else
        {
            printf("*Opciones de criterio de ordenamiento*\n");
            printf("1. Ordenar por id\n");
            printf("2. Ordenar por Nombre\n");
            printf("3. Ordenar por Horas Trabajadas\n");
            printf("4. Ordenar por Sueldo\n");
            utn_getNumero(&opcion, "Ingrese criterio de ordenamiento: \n", "Error, ingrese criterio valido (1,2,3,4): \n", 1, 4, 2);

            printf("*Opciones sentido de ordenamiento*\n");
            printf("0. Orden descendente \n");
            printf("1. Orden ascendente \n");
            utn_getNumero(&orden, "Ingrese sentido de ordenamiento: \n", "Error, Ingrese sentido de ordenamiento valido (0,1): \n", 0, 1, 2);


            switch(opcion)
            {
            case 1:
                printf("Ordenando empleados, espere unos segundos por favor...\n");
                if(ll_sort(pArrayListEmployee, employeeCmpId, orden)==-1)
                {
                    printf("Hubo un problema al ordenar los empleados por id\n");
                }
                else
                {

                    todoOk=1;
                }
                break;
            case 2:
                printf("Ordenando empleados, espere unos segundos por favor...\n");
                if(ll_sort(pArrayListEmployee, employeeCmpNombre, orden)==-1)
                {
                    printf("Hubo un problema al ordenar los empleados por nombre\n");
                }
                else
                {

                    todoOk=1;
                }
                break;
            case 3:
                printf("Ordenando empleados, espere unos segundos por favor...\n");
                if(ll_sort(pArrayListEmployee, employeeCmpHorasTrabajadas, orden)==-1)
                {
                    printf("Hubo un problema al ordenar los empleados por horas trabajadas\n");
                }
                else
                {

                    todoOk=1;
                }
                break;
            case 4:
                printf("Ordenando empleados, espere unos segundos por favor...\n");
                if(ll_sort(pArrayListEmployee, employeeCmpSueldo, orden)==-1)
                {
                    printf("Hubo un problema al ordenar los empleados por Sueldo\n");
                }
                else
                {

                    todoOk=1;
                }
                break;
            }

        }



    }

    return todoOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee, int flagAlta, int* nextId, int flagSeCargo)
{
    int retorno=0;
    char confirma;
    eEmployee* auxEmpleado=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if(flagAlta==1 || flagSeCargo==1)
        {
            confirmacion(&confirma, "Atencion se van a sobreescribir los datos del archivo 'data.csv', verifique si asi lo desea de haber cargado el archivo con la opcion 1\nDesea sobrescribir el archivo? s(si) / n(no): \n", "Error", 1);
        }

        if(confirma=='s')
        {
            FILE* f=fopen(path, "w");
            if(f!=NULL)
            {
                fprintf(f, "id, Nombre, HorasTrabajadas, Sueldo\n");
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    auxEmpleado=ll_get(pArrayListEmployee, i);
                    if(auxEmpleado!=NULL)
                    {
                        if(fprintf(f, "%d, %s, %d, %d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo)<4)
                        {
                            printf("Hubo un problema al guardar los datos en el archivo de texto\n");
                            employee_delete(auxEmpleado);

                            break;
                        }
                        else
                        {
                            auxEmpleado=NULL;
                            retorno=1;
                        }
                    }

                }
                fclose(f);

            }
            else
            {
                printf("No se pudo abrir el archivo\n");
            }
        }
        else if(confirma=='n')
        {
            printf("Guardado de datos cancelado por el usuario\n");
        }

        buscarMayorId(pArrayListEmployee, nextId);
    }

    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee, int flagAlta)
{
    int retorno=0;
    int cant;
    int flag;
    char confirma;
    eEmployee* auxEmpleado=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        cant=ll_len(pArrayListEmployee);
        if(flagAlta || cant>0)
        {
            confirmacion(&confirma, "Atencion se van a sobreescribir los datos del archivo 'datos.bin', verifique si asi lo desea de haber cargado el archivo con la opcion 2\nDesea sobrescribir el archivo? s(si) / n(no): \n", "Error", 1);
        }

        if(confirma=='s')
        {
            FILE* f=fopen(path, "wb");
            if(f!=NULL)
            {
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    auxEmpleado=ll_get(pArrayListEmployee, i);

                    cant=fwrite(auxEmpleado, sizeof(eEmployee), 1, f);
                    if(cant<1)
                    {
                        employee_delete(auxEmpleado);
                        flag=0;
                        break;
                    }
                    else
                    {
                        auxEmpleado=NULL;
                        retorno=1;
                    }
                }
                if(!flag)
                {
                    printf("Hubo un problema al guardar los empleados\n");
                }
            }
            fclose(f);
        }
        else if(confirma=='n')
        {
            printf("Guardado de datos cancelado por el usuario\n");
        }


    }


    return retorno;
}

