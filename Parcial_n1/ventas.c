#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "ventas.h"
#define COBRADO 2
#define A_COBRAR 1

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Venta* arrayVenta,int limite);
//__________________



/** \brief  Indica que todas las posiciones en el array estan libres, esta funcion pone la bandera isEmpty
 * \param array Venta*
 * \param limite int largo del array
 * \return int return (-1) es error  - (0) OK
 */
int initVenta(Venta* arrayVenta,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayVenta != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayVenta[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Agrega un venta a la posicion del cliente
 * \param arrayVenta Venta*
* \param int limite
* \param array Cliente*
* \param int limiteCliente
 * \param int id
 * \return int return -1 si hay un error
free */

int venta_alta(Venta* arrayVenta,int limite, Cliente* array, int limiteCliente, int idCliente)
{
    int retorno = -1;
    int indice;
    int cantAfiches;
    char nombreArchivoImagen[51];
    char zona[51];
    int posCliente;

    if(limite > 0 && arrayVenta != NULL)
    {
        indice = buscarLugarLibre(arrayVenta,limite);

        if(indice >= 0)
        {
            posCliente = buscarClienteId(array, limiteCliente, idCliente);

            if(posCliente >= 0)
            {

                if(!getValidInt("\nCantidad de afiches?\n","\nEso no es un afiches",&cantAfiches,0,1000,2))
                {
                    if(!getValidString("\nNombre del archivo?\n","\nEso no es un nombre","El maximo es 50",nombreArchivoImagen,50,2))
                    {
                        if(!getValidString("\nElija una zona para pegar sus afiches: CABA, ZONA SUR o ZONA OESTE\n","\n Zona no valida\n", "El maximo es 50",zona,50,1))
                        {

                            retorno = 0;
                            arrayVenta[indice].cantAfiches = cantAfiches;
                            strcpy(arrayVenta[indice].nombreArchivoImagen,nombreArchivoImagen);
                             strcpy(arrayVenta[indice].zona,zona);
                             arrayVenta[indice].idCliente = idCliente;
                            //------------------------------
                            //------------------------------
                            arrayVenta[indice].idVenta = proximoId();
                            arrayVenta[indice].isEmpty = 0;
                            arrayVenta[indice].estado = 2;
                            printf("\nSu numero id de venta es: %d", arrayVenta[indice].idVenta);

                        }
                    }
                }
            }
        }
    }
    return retorno;

}

/**
* \brief Se modifica los datos de una venta
* \param arrayVenta Venta*
* \param int limite
* \param int id
* \return int return -1 si no modifica los datos - 0 modificacion correcta
*/

int venta_modificacion(Venta* arrayVenta,int limite, int id)
{
    int index;
    int retorno=-1;
    int cantAfiches;
    char zona[51];


    if(limite > 0 && arrayVenta != NULL)
    {

        index = buscarVentaId(arrayVenta, limite, id);

        if(index >= 0 && arrayVenta[index].estado == 2)
        {

            retorno = -2;


            if(!getValidInt("Ingrese una nueva cantidad de afiches\n","Error, cantidad no valida\n", &cantAfiches,0, 1000,2))
                {

                 if(!getValidString("Ingrese una nueva zona\n","Error, zona no valida\n","Overflow", zona,51,2))
                    {
                                retorno = 0;

                                arrayVenta[index].cantAfiches = cantAfiches;
                                strcpy(arrayVenta[index].zona ,zona);
                    }
                }
        }
    }

    return retorno;
}

/**
* \brief Elimina una venta
* \param arrayVenta Venta*
* \param int limite
* \param int idCliente
* \return int return -1 si no da baja - 0 si la baja es correcta
*/

int venta_borrar(Venta* arrayVenta, int limite, int idCliente)
{
    int retorno = -1;
    int i;
    int borrarVentas;

    borrarVentas = buscarVentaId(arrayVenta, limite, idCliente);

    if(arrayVenta != NULL && limite >= 0)
    {

     if(borrarVentas >= 0) {
            for(i=0; i<limite; i++)
        {
            if(idCliente == arrayVenta[borrarVentas].idCliente)
            {
                arrayVenta[borrarVentas].isEmpty = 1;
                retorno = 0;
            }
        }
     }

    }
    else
    {
        printf("\nIngreso un ID invalido!");
    }

    return retorno;
}

/**
* \brief Muestra la informacion del cliente que realizo una determinada venta
* \param arrayVenta Venta*
* \param int limite
* \param int idCliente
* \param array Cliente*
* \return int return -1 si no da baja - 0 si la baja es correcta
*/

int ventaInfoCliente(Venta* arrayVenta, int limite, int idVenta, Cliente* array) {

    int retorno = -1;
    int infoCliente;
    int menu;

     if(arrayVenta != NULL && limite >= 0)
    {

             infoCliente = buscarIdClienteVenta(arrayVenta, limite, idVenta);

             if(infoCliente >= 0)
             {

                 printf("\nInformacion del cliente que pertenece la venta: ID: %d - NOMBRE: %s - APELLLIDO: %s - CUIT: %s\n",array[infoCliente].id,array[infoCliente].nombre,array[infoCliente].apellido,array[infoCliente].cuit);

             }

            getValidInt("\n\n1.Desea cobrar las ventas?\n2.Salir\n","\nNo valida\n",&menu,1,2,1);

            if(menu > 0) {

                if(menu == 1) {

                    arrayVenta[infoCliente].estado = 2;
                    retorno = 0;
                    printf("\n Usted a cobrado");
            }

            else {

                }
            }
    }

    return retorno;

}

/** \brief Muestra el array de ventas
 * \param arrayVenta Venta*
 * \param limite int
 * \return int return (-1) es error  - (0) OK
 */

int venta_mostrar(Venta* arrayVenta,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayVenta != NULL)
    {
        printf("\n Estas son las siguientes ventas:\n");

        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(arrayVenta[i].isEmpty == 0)
                printf(" ID: %d - ID CLIENTE: %d - CANTIDAD DE AFICHES: %d - ARCHIVO CON IMAGEN: %s - ZONA: %s\n",arrayVenta[i].idVenta, arrayVenta[i].idCliente, arrayVenta[i].cantAfiches, arrayVenta[i].nombreArchivoImagen, arrayVenta[i].zona);
        }
    }
    return retorno;
}

/** \brief Muestra el array de ventas cobradas
 * \param arrayVenta Venta*
 * \param limite int
 * \return int return (-1) es error  - (0) OK
 */

int ventas_cobradas(Venta* arrayVenta, int limite)
{
    int retorno = -1;
    int i;

    if(arrayVenta != NULL && limite >= 0)
    {
        printf("\nEstas son las ventas cobradas:\n");

        for(i=0; i<limite; i++)
        {
            if(arrayVenta[i].isEmpty == 0 && arrayVenta[i].estado == 1)
            {
                printf("ID: %d - ID CLIENTE: %d - ARCHIVO DE IMAGEN : %s - ZONA: %s\n", arrayVenta[i].idVenta, arrayVenta[i].idCliente, arrayVenta[i].nombreArchivoImagen, arrayVenta[i].zona);
            }
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief  Devuelve una posición del array de venta que tenga la bandera isEmpty
 * \param arrayVenta Cliente*
 * \param int limite
 * \return int return (-1) es error - (0) OK
 */

static int buscarLugarLibre(Venta* arrayVenta,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayVenta != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayVenta[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
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
* \brief compara un venta pasado por id y devuelve el indice si encontro la venta
* \param  arrayVenta Venta*
* \param int limite
* \param int id
* \return int return -1 no encontro, sino encontro la posicion (i)
*/

int buscarVentaId(Venta* arrayVenta,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayVenta != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayVenta[i].isEmpty && arrayVenta[i].idVenta ==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Obtiene el id de la venta
* \param arrayVenta Venta*
* \param int limite
* \param int id
* \return int return -1 si no da de alta - 0 alta correcta
*/

int buscarIdClienteVenta(Venta* arrayVenta, int limite, int id)
{
    int i;
    int retorno = -1;

    if(arrayVenta != NULL && limite >= 0 && id >= 0)
    {
        for(i=0; i<limite; i++)
        {
            if(arrayVenta[i].idCliente == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Da de alta una venta de forma forzada
* \param arrayVenta Venta*
* \param int limite
* \param array Cliente*
* \param int limClientes
* \param int idCliente
* \param char* zona
* \param char* archivoImagen
* \param int cantImagen
* \return int return -1 si no da de alta - 0 alta correcta
*/

int altaForzadaVenta(Venta* arrayVenta,int limite, Cliente* array, int limClientes, int idCliente, char* zona, char* archivoImagen, int cantAfiches)
{
    int retorno = -1;
    int indice;
    int posCliente;
    if(limite > 0 && arrayVenta != NULL)
    {
        indice = buscarLugarLibre(arrayVenta,limite);
        if(indice >= 0)
        {
            posCliente = buscarClienteId(array,limClientes,idCliente);

            if(posCliente>=0)
            {
                strcpy(arrayVenta[indice].zona, zona);
                strcpy(arrayVenta[indice].nombreArchivoImagen,archivoImagen);
                arrayVenta[indice].cantAfiches = cantAfiches;
                arrayVenta[indice].idCliente = idCliente;

                arrayVenta[indice].isEmpty= 0;
                arrayVenta[indice].idVenta = proximoId();
            }
        }
        retorno = 0;
    }
    return retorno;
}
