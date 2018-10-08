#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
typedef struct
{
 int idCliente;
 int idVenta;
 int cantAfiches;
 char nombreArchivoImagen[51];
 char zona[51];
 int estado;
 int isEmpty;
}Venta;



#endif // VENTAS_H_INCLUDED
int initVenta(Venta* arrayVenta,int limite);
int venta_alta(Venta* arrayVenta,int limite, Cliente* array, int limiteCliente, int idCliente);
int venta_mostrar(Venta* arrayVenta,int limite);
int venta_modificacion(Venta* arrayVenta,int limite, int id);
int buscarVentaId(Venta* arrayVenta,int limite, int id);
int venta_borrar(Venta* arrayVenta, int limite, int idCliente);
int ventaInfoCliente(Venta* arrayVenta, int limite, int idVenta, Cliente* array);
int buscarIdClienteVenta(Venta* arrayVenta, int limite, int id);
int ventas_cobradas(Venta* arrayVenta, int limite);
int altaForzadaVenta(Venta* arrayVenta,int limite, Cliente* array, int limClientes, int idCliente, char* zona, char* archivoImagen, int cantAfiches);

