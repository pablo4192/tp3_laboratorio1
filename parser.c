#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char buffer[4][128];
    eEmployee* auxEmpleado=NULL;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {


        do
        {

            if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3])==4)
            {
                auxEmpleado=employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(auxEmpleado!=NULL)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    todoOk=1;
                }
                else
                {
                    employee_delete(auxEmpleado);
                    auxEmpleado=NULL;
                }
            }
            else
            {
                printf("Hubo un problema al leer los datos del archivo\n");
            }



        }
        while(!feof(pFile));

    }


    return todoOk;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int cant;
    eEmployee* auxEmpleado=NULL;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            auxEmpleado=employee_new();
            if(auxEmpleado!=NULL)
            {
                cant=fread(auxEmpleado, sizeof(eEmployee), 1, pFile);
                if(cant==1)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    auxEmpleado=NULL;
                    retorno=1;
                }
                else
                {
                    employee_delete(auxEmpleado);
                    break;
                }
            }




        }
        while(!feof(pFile));


    }

    return retorno;
}
