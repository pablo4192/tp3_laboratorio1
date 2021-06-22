#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include <string.h>


int menuOpciones(LinkedList* lista)
{
    int opcion;

    system("cls");


    printf("***Menu de opciones***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.txt (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo datos.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.txt (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo datos.bin (modo binario).\n");
    printf("10. Salir\n");
    utn_getNumero(&opcion, "Escoja una opcion (1 al 10): \n", "Error, escoja una opcion valida (1 al 10): \n", 1, 10, 3);

    return opcion;
}

eEmployee* employee_new()
{
    eEmployee* newEmployee= (eEmployee*) malloc(sizeof(eEmployee));
    if(newEmployee!=NULL)
    {
        newEmployee->id=0;
        strcpy(newEmployee->nombre, " " );
        newEmployee->horasTrabajadas=0;
        newEmployee->sueldo=0;
    }
    return newEmployee;
}

int mostrarEmpleados(LinkedList* lista)
{
    int todoOk=0;
    if(lista!=NULL)
    {
        printf("Legajo       Nombre  HorasTrabajadas     Sueldo\n");
        for(int i=0; i<ll_len(lista); i++)
        {
            mostrarEmpleado( (eEmployee*) ll_get(lista,i)); //a mostrar empleado le paso la direcion de memoria que me devuelve ll_get casteada a eEmployee
            todoOk=1;
        }
        printf("\n\n");

    }

    return todoOk;
}

int mostrarEmpleado(eEmployee* unEmpleado)
{
    int todoOk=0;
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    if(unEmpleado!=NULL)
    {
        if(employee_getId(unEmpleado, &id) && employee_getNombre(unEmpleado, nombre) && employee_getHorasTrabajadas(unEmpleado, &horasTrabajadas) && employee_getSueldo(unEmpleado, &sueldo))
        {
            printf("%4d     %10s              %3d      %5d\n", id, nombre, horasTrabajadas, sueldo);
            todoOk=1;
        }
    }

    return todoOk;
}

int employee_setId(eEmployee* lista,int id)
{
    int todoOk=0;

    if(lista!=NULL && id>0)
    {
        lista->id=id;
        todoOk=1;
    }

    return todoOk;
}

int employee_setNombre(eEmployee* lista,char* nombre)
{
    int todoOk=0;

    if(lista!=NULL && nombre!=NULL && strlen(nombre)>0 && strlen(nombre)<20)
    {
        strcpy(lista->nombre,nombre);
        todoOk=1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(eEmployee* lista,int horasTrabajadas)
{
    int todoOk=0;

    if(lista!=NULL && horasTrabajadas>0)
    {
        lista->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }

    return todoOk;
}

int employee_setSueldo(eEmployee* lista, int sueldo)
{
    int todoOk=0;

    if(lista!=NULL && sueldo>0)
    {
        lista->sueldo=sueldo;
        todoOk=1;
    }

    return todoOk;
}

int employee_getId(eEmployee* employee,int* pId)
{
    int todoOk=0;

    if(employee!=NULL && pId!=NULL)
    {
        *pId=employee->id;
        todoOk=1;

    }
    return todoOk;
}

int employee_getNombre(eEmployee* employee,char* nombre)
{
    int todoOk=0;

    if(employee!=NULL && nombre!=NULL)
    {
        strcpy(nombre, employee->nombre);
        todoOk=1;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(eEmployee* employee,int* horasTrabajadas)
{
    int todoOk=0;

    if(employee!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=employee->horasTrabajadas;
        todoOk=1;
    }

    return todoOk;
}

int employee_getSueldo(eEmployee* employee,int* sueldo)
{
    int todoOk=0;

    if(employee!=NULL && sueldo!=NULL)
    {
        *sueldo=employee->sueldo;
        todoOk=1;
    }

    return todoOk;
}

int employee_delete(eEmployee* pEmpleado)
{
    int todoOk=0;

    if(pEmpleado!=NULL)
    {
        free(pEmpleado);
        todoOk=1;
    }

    return todoOk;
}

int employeeCmpId(void* a, void* b)
{
    int retorno=0;
    eEmployee* emp1=NULL; //creo un puntero a estructura eempleado
    eEmployee* emp2=NULL;

    if(a!=NULL && b!=NULL)
    {
        emp1= (eEmployee*) a;
        emp2= (eEmployee*) b;
        if(emp1->id>emp2->id)
        {
            retorno=1;
        }
        else if(emp1->id<emp2->id)
        {
            retorno=-1;
        }

    }

    return retorno;
}

int employeeCmpNombre(void* a, void* b)
{
    int retorno=0;

    eEmployee* emp1=NULL;
    eEmployee* emp2=NULL;
    if(a!=NULL && b!=NULL)
    {
        emp1=(eEmployee*)a;
        emp2=(eEmployee*)b;
        retorno=strcmp(emp1->nombre, emp2->nombre); //strcmp devuelve 1 o -1 en la resta de los campos
    }

    return retorno;
}

int employeeCmpHorasTrabajadas(void* a, void* b)
{
    int retorno=0;
    eEmployee* emp1=NULL;
    eEmployee* emp2=NULL;

    if(a!=NULL && b!=NULL)
    {
        emp1= (eEmployee*) a;
        emp2= (eEmployee*) b;
        if(emp1->horasTrabajadas>emp2->horasTrabajadas)
        {
            retorno=1;
        }
        else if(emp1->horasTrabajadas<emp2->horasTrabajadas)
        {
            retorno=-1;
        }
    }

    return retorno;
}

int employeeCmpSueldo(void* a, void* b)
{
    int retorno=0;
    eEmployee* emp1=NULL;
    eEmployee* emp2=NULL;

    if(a!=NULL && b!=NULL)
    {
        emp1= (eEmployee*) a;
        emp2= (eEmployee*) b;
        if(emp1->sueldo>emp2->sueldo)
        {
            retorno=1;
        }
        else if(emp1->sueldo<emp2->sueldo)
        {
            retorno=-1;
        }
    }

    return retorno;

}

eEmployee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    eEmployee* nuevoEmpleado=employee_new();

    if(nuevoEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr)) &&
                employee_setNombre(nuevoEmpleado, nombreStr) &&
                employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) &&
                employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)))
          )
        {
            employee_delete(nuevoEmpleado);  //si sale mal la carga de algun campo borro el espacio en memoria dinamica y apunto a null el puntero a estructura
            nuevoEmpleado=NULL;

        }
    }

    return nuevoEmpleado;
}

int buscarMayorId(LinkedList* pArrayListEmployee, int* nextId)
{
    int retorno=0;
    eEmployee* auxEmpleado=NULL;
    int mayor;
    int cant;


    if(pArrayListEmployee!=NULL && nextId!=NULL)
    {
        cant=ll_len(pArrayListEmployee);
        if(cant>0)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado= (eEmployee*) ll_get(pArrayListEmployee, i);

                if(i==0 || auxEmpleado->id>mayor)
                {
                    mayor=auxEmpleado->id;
                    retorno=1;
                }
            }
            *nextId=mayor+1;
        }

    }

    return retorno;
}













