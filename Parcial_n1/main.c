#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "ventas.h"
#include "informes.h"
#define CLIENTES 100
#define VENTAS 1000


int main()
{
    int menu;
    int auxiliarId;

    Cliente array[CLIENTES];
    Venta arrayVenta[VENTAS];

    initCliente(array, CLIENTES);
    initVenta(arrayVenta, VENTAS);


    altaForzadaCliente(array, CLIENTES, "Nicolas", "Fischetti", "23371841792");
    altaForzadaCliente(array, CLIENTES, "Juan", "Gonzalez", "244562346");
    altaForzadaCliente(array, CLIENTES, "Gustavo", "Perez", "244462346");

    altaForzadaVenta(arrayVenta,VENTAS,array, CLIENTES,0,"Zona Oeste","Archivo Prueba", 3);
    altaForzadaVenta(arrayVenta,VENTAS,array, CLIENTES,0,"Zona Sur","Archivo de Prueba 2", 4);
    altaForzadaVenta(arrayVenta,VENTAS,array, CLIENTES,0,"CABA","Archivo de Prueba 3", 5);

    do
    {
        getValidInt("\n\n1.Alta Cliente\n2.Baja Cliente\n3.Modificar Cliente\n4.Vender Afiches\n5.Editar Ventas\n6.Cobrar Ventas\n7.Lista clientes, ventas a cobrar\n8.Cliente mas ventas a cobrar\n9. Cliente mas ventas cobradas\n10.Cliente mas ventas\n11. Cant. Cliente compras menos de mil\n.13. Salir\n","\nNo valida\n",&menu,1,11,1);

        switch(menu)
        {
            case 1:
                cliente_alta(array, CLIENTES);
                break;
            case 2:
                cliente_mostrar(array,CLIENTES);
                venta_mostrar(arrayVenta,VENTAS);
                getValidInt("ID?","\nNumero no valido\n",&auxiliarId,0,200,2);
                cliente_baja(array,CLIENTES,auxiliarId);
                venta_borrar(arrayVenta,VENTAS, auxiliarId);
                break;
            case 3:
                cliente_mostrar(array,CLIENTES);
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(array,CLIENTES,auxiliarId);
                break;
            case 4:
                getValidInt("ID del cliente?","\nNumero valida\n",&auxiliarId,0,200,2);
                venta_alta(arrayVenta,VENTAS, array, CLIENTES, auxiliarId);
                break;
            case 5:
                venta_mostrar(arrayVenta,VENTAS);
                getValidInt("Ingrese su id para modificar venta\n","\nNumero valida\n",&auxiliarId,0,200,2);
                venta_modificacion(arrayVenta,VENTAS,auxiliarId);
                break;
            case 6:
                venta_mostrar(arrayVenta,VENTAS);
                getValidInt("ID de cliente?","\nNumero valida\n",&auxiliarId,0,200,2);
                ventaInfoCliente(arrayVenta,VENTAS, auxiliarId, array);
                break;
            case 7:
                ventas_cobradas(arrayVenta, VENTAS);
                break;
            case 8:
                clientes_MasVentasCobrar(arrayVenta,VENTAS, array, CLIENTES, auxiliarId);
                break;
            case 9:
                clientes_MasVentasCobradas(arrayVenta,VENTAS, array, CLIENTES, auxiliarId);
                break;
            case 10:
                clientes_MasVentas(arrayVenta,VENTAS, array, CLIENTES, auxiliarId);
                break;
            case 11:
                clientes_MenosMilAfiches(arrayVenta,VENTAS, array, CLIENTES, auxiliarId);
                break;
            case 12:
                break;
            case 13:
                break;
        }

    }while(menu != 13);

    return 0;
}

