#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.txt (modo texto). //No tenia office instalado por eso lo lei desde un archivo de txt
     2. Cargar los datos de los empleados desde el archivo datos.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.txt (modo texto). //No tenia office instalado por eso lo guarde en un archivo de txt
     9. Guardar los datos de los empleados en el archivo datos.bin (modo binario).
    10. Salir
*****************************************************/
//**Hecho en Codeblocks**


int main()
{
    char seguir='s';
    char confirma;
    int flagAlta=0;
    int flagSeCargo=0;

    int nextId=1;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados==NULL)
    {
        printf("No se pudo cargar el linkedList\n");
        system("pause");
        exit(1);
    }

    do
    {
        switch(menuOpciones(listaEmpleados))
        {
        case 1:
            if(!controller_loadFromText("data.csv",listaEmpleados, &flagSeCargo, flagAlta, nextId))
            {
                printf("Hubo un problema al cargar el archivo\n");
            }
            else
            {
                printf("Se cargaron los datos desde el archivo 'data.csv' correctamente\n");
            }
            system("pause");
            break;
        case 2:
            if(!controller_loadFromBinary("datos.bin", listaEmpleados, &flagSeCargo, flagAlta, nextId))
            {
                printf("Hubo un problema al cargar los empleados del archivo binario\n");
            }
            else
            {
                printf("Se cargaron los datos desde el archivo 'datos.bin' correctamente\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            buscarMayorId(listaEmpleados, &nextId);
            if(!controller_addEmployee(listaEmpleados, &nextId, &flagAlta))
            {
                printf("Hubo un problema al dar de alta al empleado\n");
            }
            else
            {
                printf("Alta Exitosa!!\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(!controller_editEmployee(listaEmpleados))
            {
                printf("Hubo un problema al modificar al empleado\n");
            }
            else
            {
                printf("Modificacion exitosa!!\n");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(!controller_removeEmployee(listaEmpleados))
            {
                printf("Hubo un problema al dar de baja al empleado\n");
            }
            else
            {
                printf("Empleado dado de baja con exito!!\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(!controller_ListEmployee(listaEmpleados))
            {
                printf("No hay empleados en la lista\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(!controller_sortEmployee(listaEmpleados))
            {
                printf("Hubo un problema al ordenar los empleados\n");
            }
            else
            {
                printf("Empleados ordenados con exito!!\n");
            }
            system("pause");
            break;
        case 8:
            if(!controller_saveAsText("data.csv", listaEmpleados, flagAlta, &nextId, flagSeCargo))
            {
                printf("Hubo un problema al guardar los datos en el archivo de texto\n");
            }
            else
            {
                printf("Datos guardados en archivo de texto correctamente!!\n");
            }
            system("pause");
            break;
        case 9:
            if(!controller_saveAsBinary("datos.bin", listaEmpleados, flagAlta))
            {
                printf("Hubo un probleam al guardar los empleados en el archivo binario\n");
            }
            else
            {
                printf("Empleados guardados en archivo binario con exito!!\n");
            }
            system("pause");
            break;
        case 10:
            confirmacion(&confirma, "Seguro desea salir? s(si) / n(no): \n", "Error, ingrese opcion valida s(si) / n(no): \n", 3);
            if(confirma=='s')
            {
                seguir='n';
            }
            else
            {
                printf("Salida cancelada por el usuario!\n");
                system("pause");
                system("cls");
            }
            break;

        }
    }
    while(seguir=='s');

    ll_deleteLinkedList(listaEmpleados);

    return 0;

}

