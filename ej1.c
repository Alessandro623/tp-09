#include <stdio.h>
#include <stdlib.h>

/*DECLARACION STRUCTS*/

struct
{
    char Nombre[100];
    int telefono;
} typedef PROVEEDOR;

struct 
{
    int dia;
    int mes;
    int anio;
} typedef fecha;

struct
{
    char nombreProducto[100];
    float precioUnitario;
    PROVEEDOR proveedor1;
    fecha fecha1;
    int cantVentaMes[11];
    int fechaInicioVenta;
    char catalogo[];
} typedef PRODUCTO;


/*FUNCIONES*/

PRODUCTO CargarDatos();
void MostrarDatos(PRODUCTO producto);
PRODUCTO ModificarPrecio(PRODUCTO producto);


/*CODIGO*/

int main(){
    int n;
    printf("Ingrese la cantidad de productos= ");
    scanf("%d", &n);
    PRODUCTO *CATALOGO = malloc(n*sizeof(PRODUCTO));
    
    PRODUCTO producto[1];

    float montoTotal = 0;
    int mesTopVenta = 0;

    for (int i = 0; i < n; i++)
    {
        CATALOGO[i]= CargarDatos();
    }
    for (int i = 0; i < 1; i++)
    {
        if (producto[i].fecha1.anio == 2023)
        {
            MostrarDatos(producto[i]);
            
        }
        producto[i] = ModificarPrecio(producto[i]);
        printf("nuevo precio de producto %.2f\n", producto[i].precioUnitario);
        for (int j = 0; j < 12; j++)
        {
            if (producto[i].cantVentaMes[j] > mesTopVenta)
            {
                mesTopVenta = producto[i].cantVentaMes[j];
            }
        }
    }
    printf("mes con mas venta: %d", mesTopVenta);
    return 0;
}

/*CREACION FUNCIONES*/

PRODUCTO CargarDatos(){
    PRODUCTO producto;
    printf("Ingrese el nombre producto: ");
    scanf("%s", &producto.nombreProducto);
    printf("Ingrese el precio unitario: ");
    scanf("%f", &producto.precioUnitario);
    printf("Ingrese el nombre del Proveedor: ");
    scanf("%s", &producto.proveedor1.Nombre);
    fflush(stdin);

    printf("Ingrese la cantidad vendida del producto:\n");
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &producto.cantVentaMes[i]);
    }
    printf("Ingrese la fecha de inicio de venta,dia mes anio: ");
    scanf("%d", &producto.fecha1.dia);
    scanf("%d", &producto.fecha1.mes);
    scanf("%d", &producto.fecha1.anio);

    return producto;
}

 void MostrarDatos(PRODUCTO producto){
    printf("nombre producto: %s\n", producto.nombreProducto);
    printf("precio unitario: %.2f\n", producto.precioUnitario);
    printf("cantidad vendidas: %d\n", producto.cantVentaMes);
    printf("fecha inicio de venta: %d/%d/%d", producto.fecha1.dia,producto.fecha1.mes,producto.fecha1.anio);
 }

PRODUCTO ModificarPrecio(PRODUCTO producto){
    printf("modifique el precio unitario del producto: ");
    scanf("%f", &producto.precioUnitario);
    return producto;
}