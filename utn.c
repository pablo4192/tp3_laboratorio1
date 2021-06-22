#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int ret;
    int num;

    while(reintentos>0)
    {
        printf("%s", mensaje);
        fflush(stdin);
        if(getInt(&num)==1)
        {
            if(num<=maximo && num>=minimo)
            {
                break;
            }

        }
        fflush(stdin); //EN LINUX UTILIZAR __fpurge(stdin)
        reintentos--;
        printf(mensajeError);
    }

    if(reintentos==0)
    {
        ret=0;
    }
    else
    {
        ret=1;
        *pResultado = num;
    }

    return ret;

}
/*
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    int ret;
    float num;

    while(reintentos>0)
    {
        printf(mensaje);
        if(getFloat(&num)==1)
        {
            if(num<=maximo && num>=minimo)
            {
                break;
            }

        }
        fflush(stdin); //EN LINUX UTILIZAR __fpurge(stdin)
        reintentos--;
        printf(mensajeError);
    }

    if(reintentos==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        *pResultado = num;
    }

    return ret;


}
*/
/*
int getFloat(float* pResultado)
{
    int ret=-1;
    char buffer[64];

    myGets(buffer, sizeof(buffer));
    if(esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        ret=1;
    }

    return ret;

}
*/
int getInt(int* pResultado)
{
    int ret=-1;
    char buffer[64];

    myGets(buffer, sizeof(buffer));
    if(esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        ret=1;
    }

    return ret;

}

int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int myGets(char* cadena, int longitud)
{
    int retorno=-1;
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin); // fflush o __fpurge
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        retorno=0;
    }
    return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
    int retorno=-1;
    char buffer;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && maximo>=minimo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &buffer);
            if(buffer>=minimo && buffer<=maximo)
            {
                *pResultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;

            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int verifica(void)
{
    char letra;
    printf("\nIngrese opcion...S/N?");
    letra=toupper(getche());
    while(!((letra=='S')||(letra=='N')))
    {
        printf("\nHa ingresado opcion no valida...Reintente el ingreso(S/N)... ");
        letra=toupper(getche());
    }
    return (letra=='S');
}

int utn_getStringChar(char pResultado[], char* mensaje, char* mensajeError, char minimoCaracteres, char maximoCaracteres, int reintentos)
{
    int retorno=0;
    char buffer[50];
    int longitud;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimoCaracteres<=maximoCaracteres && maximoCaracteres>=minimoCaracteres && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%s", buffer);

            longitud=strlen(buffer); //mido cantidad de caracteres y le asigno el valor a longitud
            retorno=1;  //inicializo el retono cada vez que inicia el bucle, por si hay reintentos!!


            for(int i=0; i<longitud; i++) //itero hasta que i sea menor a la longitud, hasta el ultimo caracter que se ingreso (No todo el vector entero)
            {
                if(!isalpha(buffer[i])) //si buffer en el indice i no es una letra, retorna 0, algo salio mal y rompe hasta el primer if de abajo
                {
                    retorno=0;
                    break;
                }

            }
            if(retorno==1 && longitud>=minimoCaracteres && longitud<=maximoCaracteres) //si todo esta bien copio
            {
                strcpy(pResultado,buffer);
                break;
            }
            else //sino descuento un intento
            {
                printf("%s", mensajeError);
                reintentos--;

            }
        }
        while(reintentos>=0);

    }

    return retorno;
}

int utn_getSexo(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int todoOk=0;
    char buffer;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &buffer);

            if(buffer=='f' || buffer=='m' || buffer=='o')
            {
                *pResultado=buffer;
                todoOk=1;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;

            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}

int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int maximoCaracteres, int reintentos)
{
    int todoOk=0;
    char buffer[30];
    int longitud;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
    {
        do
        {

            printf("%s", mensaje);
            fflush(stdin);
            scanf("%s", buffer);
            longitud=strlen(buffer);

            if(longitud<=maximoCaracteres)
            {
                strcpy(pResultado, buffer);
                todoOk=1;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }

        }
        while(reintentos>=0);

    }


    return todoOk;
}

int confirmacion(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int todoOk=0;
    char opcion;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL &&  reintentos>0)
    {
        while(reintentos>0)
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &opcion);


            if(opcion=='s' || opcion=='n')
            {
                *pResultado=opcion;
                todoOk=1;
                reintentos=0;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;

            }

        }
    }

    return todoOk;
}



