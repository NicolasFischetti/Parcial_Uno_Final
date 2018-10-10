
typedef struct
{
 int id;
 int idCliente;
 char nombre[51];
 char apellido[51];
 char cuit[51];
 int isEmpty;
}Cliente;

int initCliente(Cliente* array, int limite);
int cliente_alta(Cliente* array,int limite);
int cliente_modificacion(Cliente* array,int limite, int id);
int cliente_baja(Cliente* array,int limite, int id);
int cliente_buscarPorId(Cliente* array,int limite, int id);
int recibeIdCliente(Cliente* array, int limite, int id);
int cliente_mostrar(Cliente* array,int limite);
int buscarClienteId(Cliente* array,int limite, int id);
int altaForzadaCliente(Cliente* array, int limite, char* nombre, char* apellido, char* cuit);


