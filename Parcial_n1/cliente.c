#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "ventas.h"


//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Cliente* array,int limite);
//__________________



/** \brief  Indica que todas las posiciones en el array estan libres, esta funcion pone la bandera isEmpty
 * \param Cliente* Puntero al array de empleados
 * \param limite int largo del array
 * \return int return (-1) es error  - (0) OK
 */
int initCliente(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief  Devuelve una posición del array de clientes que tenga la bandera isEmpty
 * \param Cliente* Puntero al array de clientes
 * \param limite int largo del array
 * \return int return (-1) es error - (0) OK
 */

static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Imprime el array de clientes
 * \param  Cliente* array
 * \param limite int
 * \return int return (-1) es error - (0) OK
 */

int cliente_mostrar(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == 0)
                printf("ID: %d - NOMBRE: %s - APELLIDO: %s - CUIT: %s\n",array[i].id, array[i].nombre, array[i].apellido, array[i].cuit);
        }
    }
    return retorno;
}

/** \brief Agrega un cliente a la posicion primera que se encuentra libre
 * \param array employee*
 * \param limite int
 * \return int return -1 si hay un error
free */

int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    int indice;
    char nombre[51];
    char apellido[51];
    char Auxcuit[51];

    if(limite > 0 && array != NULL)
    {
        indice = buscarLugarLibre(array,limite);

        if(indice >= 0)
        {

            if(!getValidString("\nNombre?\n","\nEso no es un nombre","El maximo es 50",nombre,50,2))
            {
                if(!getValidString("\nApellido?\n","\nEso no es un apellido","El maximo es 50",apellido,50,2))
                {
                        if(!pedirCUIT(Auxcuit, "\nIngrese su CUIT?\n", "Error", 2))
                        {
                            retorno = 0;
                            strcpy(array[indice].nombre,nombre);
                            strcpy(array[indice].apellido,apellido);
                            strcpy(array[indice].cuit,Auxcuit);
                            //------------------------------
                            //------------------------------
                            array[indice].id = proximoId();
                            array[indice].isEmpty = 0;
                            printf("\n El id generado para el cliente es: %d\n", array[indice].id);
                        }

                }
            }

        }
    }
    return retorno;

}

/**
* \brief Elimina un cliente
* \param array Cliente*
* \param int limite
* \param int id
* \return int return -1 si no da baja - 0 si la baja es correcta
*/


int cliente_baja(Cliente* array,int limite, int id)
{
    int retorno=-1;
    int menu;
    int indice;

    getValidInt("\n\n1.Confirmar baja de cliente y venta\n2.No quiere dar de baja\n","\nNo valida\n",&menu,1,2,1);

    indice = buscarClienteId(array, limite, id);

        if(indice >= 0)
        {
            if(menu == 1) {

                array[indice].isEmpty = 1;
                retorno = 0;
                printf("\n Su cliente ha sido borrado");
            }

            else {

                printf("\n Salir");
            }

        }

      return retorno;
   }



/**
* \brief Se modifica los datos de un cliente
* \param array Cliente*
* \param int indice
* \return int return -1 si no modifica los datos - 0 modificacion correcta
*/

int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[51];


    indiceAModificar = buscarClienteId(array,limite,id);

    if(indiceAModificar>=0)
    {
         if(!getValidString("\nIngrese un nuevo nombre?\n","\nEso no es un nombre","El maximo es 50",auxNombre,50,2))
            {
                if(!getValidString("\n Ingrese un nuevo apellido?\n","\nEso no es un apellido","El maximo es 50",auxApellido,50,2))
                {
                        if(!pedirCUIT(auxCuit, "\nCUIT?\n", "Error", 2))
                        {
                            retorno = 0;
                            strcpy(array[indiceAModificar].nombre,auxNombre);
                            strcpy(array[indiceAModificar].apellido,auxApellido);
                            strcpy(array[indiceAModificar].cuit,auxCuit);
                            //------------------------------
                            //------------------------------
                            array[indiceAModificar].isEmpty = 0;
                        }

                }
            }
    }

    else {
        printf("\n El id es incorrecto\n");
    }

    return retorno;
}

/** \brief Asigna un id en 0
 * \param void
 * \return int la primera devaluacion es 0, luego va incrementando
 */

static int proximoId(void)
{
    static int proximoId = 0;
    proximoId++;
    return proximoId;
}

/**
* \brief compara un ciente pasado por id y devuelve el indice si encontro el cliente
* \param  Cliente* array de clientes
* \param int limite
* \param int id
* \return int return -1 no encontro, sino encontro la posicion (i)
*/

int buscarClienteId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].id ==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/**
* \brief Da de alta un cliente de forma forzada
* \param array Cliente*
* \param int limite
* \param char* nombre
* \param char* apellido
* \param char* cuit
* \return int return -1 si no da de alta - 0 alta correcta
*/

int altaForzadaCliente(Cliente* array, int limite, char* nombre, char* apellido, char* cuit)
{
    int retorno = -1;
    int indice;

    if(limite > 0 && array != NULL)
    {
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = 0;
            strcpy(array[indice].nombre,nombre);
            strcpy(array[indice].apellido,apellido);
            strcpy(array[indice].cuit,cuit);
            array[indice].id = proximoId();
            array[indice].isEmpty = 0;
        }

        retorno = 0;
    }
    return retorno;
}
