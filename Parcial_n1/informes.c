#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "ventas.h"
#define COBRADO 1
#define A_COBRAR 2

int clientes_MasVentasCobrar(Venta* arrayVenta,int limite, Cliente* array, int limiteCliente, int idCliente)
{
    int retorno = -1;
    int clienteBuscarId;
    int contador = 0;
    int ventasBuscarId;
    int maximo = 0;

     if(limiteCliente > 0 && array != NULL)
    {

        clienteBuscarId = buscarClienteId(array,limiteCliente, idCliente);

            if(clienteBuscarId > 0)
            {

                ventasBuscarId = buscarVentaId(arrayVenta, limite, idCliente);

                if (ventasBuscarId > 0)
                {

                            if(arrayVenta[clienteBuscarId].idCliente == array[ventasBuscarId].id && arrayVenta[ventasBuscarId].estado == 2)
                            {
                                contador++;
                            }

                            if(contador > maximo)
                            {
                                maximo = contador;
                                retorno = 0;
                            }

                        }

                    }

                }


    printf("El cliente con mas ventas a cobrar es: %s, con %d ventas", array[clienteBuscarId].nombre, maximo);
    return retorno;
}

int clientes_MasVentasCobradas(Venta* arrayVenta,int limite, Cliente* array, int limiteCliente, int idCliente)
{
    int retorno = -1;
    int i;
    int clienteBuscarId;
    int j;
    int contador;
    int ventasBuscarId;
    int maximo;

     if(limiteCliente > 0 && array != NULL)
    {

        clienteBuscarId = buscarClienteId(array,limiteCliente, idCliente);

            if(clienteBuscarId > 0)
            {

                ventasBuscarId = buscarVentaId(arrayVenta, limite, idCliente);

                if (ventasBuscarId > 0)
                {

                    for(i=0;i < limite;i++)
                    {
                        for(j=0; j < limiteCliente; j++)
                        {

                            if(arrayVenta[clienteBuscarId].idCliente == array[ventasBuscarId].idCliente && arrayVenta[i].estado == 1)
                            {
                                contador++;
                            }

                            if(contador > maximo)
                            {
                                maximo = contador;
                                retorno = 0;

                            }

                        }

                    }

                }

            }

    }
    printf("El cliente con mas ventas cobradas es: %s, con %d ventas", array[ventasBuscarId].nombre, maximo);
    return retorno;
}

int clientes_MasVentas(Venta* arrayVenta,int limite, Cliente* array, int limiteCliente, int idCliente)
{
    int retorno = -1;
    int i;
    int clienteBuscarId;
    int j;
    int contador;
    int ventasBuscarId;
    int maximo;

     if(limiteCliente > 0 && array != NULL)
    {

        clienteBuscarId = buscarClienteId(array,limiteCliente, idCliente);

            if(clienteBuscarId > 0)
            {

                ventasBuscarId = buscarVentaId(arrayVenta, limite, idCliente);

                if (ventasBuscarId > 0)
                {

                    for(i=0;i < limite;i++)
                    {
                        for(j=0; j < limiteCliente; j++)
                        {

                            if(arrayVenta[clienteBuscarId].idCliente == array[ventasBuscarId].idCliente)
                            {
                                contador++;
                            }

                            if(contador > maximo)
                            {
                                maximo = contador;
                                retorno = 0;

                            }

                        }

                    }

                }

            }

    }
    printf("El cliente con mas ventas es: %s", array[ventasBuscarId].nombre);
    return retorno;
}

int clientes_MenosMilAfiches(Venta* arrayVenta,int limite, Cliente* array, int limiteCliente, int idCliente)
{
    int retorno = -1;
    int i;
    int clienteBuscarId;
    int ventasBuscarId;
    int afichesMenorMil = 0;

     if(limiteCliente > 0 && array != NULL)
    {

        clienteBuscarId = buscarClienteId(array,limiteCliente, idCliente);

            if(clienteBuscarId > 0)
            {

                ventasBuscarId = buscarVentaId(arrayVenta, limite, idCliente);

                if (ventasBuscarId > 0)
                {

                    for(i=0;i < limite;i++)
                    {
                            if(arrayVenta[clienteBuscarId].cantAfiches < 1000)
                            {
                                afichesMenorMil++;
                            }

                        }

                    }

                }

            }

        printf("\n La cantidad de clientes que compraron menos de 1000 afiches es: %d", arrayVenta[clienteBuscarId].cantAfiches);
        return retorno;
    }




