#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct
{
    char nombre[MAX];
    char categoria[MAX];
    char nombreVulgar[MAX];
    int stock;
    float precio;
}typedef Arbol;

typedef struct {
    char razon_social[MAX];
    char telefono[MAX];
    char empleado[MAX];
    int cantidad;
} Pedido;

void ingresarStock(Arbol *arbol, int numArboles);
void mostrarArbolDisponible(Arbol *arbol, int numArboles);
void mostrarStockSegunEspecie(Arbol *arbol, int numArboles);
void actualizarStock(Arbol *arbol, int numArboles);
void actualizarPrecio(Arbol *arbol, int numArboles);

int main(){

    int numArboles;
    printf("Cuantos arboles desea ingresar?: ");
    scanf("%d", &numArboles);
    
    fflush(stdin);

    Arbol *arbol = malloc(numArboles *(sizeof(Arbol)));

    ingresarStock(arbol, numArboles);
    mostrarArbolDisponible(arbol, numArboles);
    mostrarStockSegunEspecie(arbol, numArboles);
    actualizarStock(arbol, numArboles);
    actualizarPrecio(arbol, numArboles);

    free(arbol);
    return 0;
}

void ingresarStock(Arbol *arbol, int numArboles){
    printf("Ingrese los stock de los arboles\n");
    for (int i = 0; i < numArboles; i++)
    {
        printf("Ingrese el nombre: ");
        gets(arbol->nombre);
        printf("Ingrese la categoria: ");
        gets(arbol->categoria);
        printf("Ingrese el nombre Vulgar: ");
        gets(arbol->nombreVulgar);
        fflush(stdin);
        printf("Ingrese el stock: ");
        scanf("%d", &arbol->stock);
        printf("Ingrese el precio: ");
        scanf("%f", &arbol->precio);
        fflush(stdin);
        arbol++;
    }
}

void mostrarArbolDisponible(Arbol *arbol, int numArboles){
    printf("--Arboles Disponibles--\n");

    for (int i = 0; i < numArboles; i++)
    {
        printf("Nombre: %s\n", arbol->nombre);
        arbol++;
    }
}

void mostrarStockSegunEspecie(Arbol *arbol, int numArboles){
    if (numArboles >= 1)
    {
        char ingresarNombre[MAX];
        printf("De que especie quisiera saber el stock?\n");
        fflush(stdin);
        gets(ingresarNombre);
        for (int i = 0; i < numArboles; i++)
        {
            if (strcmp(ingresarNombre, (arbol+i)->nombre) == 0)
            {
                printf("El stock de %s es = %d\n", (arbol + i)->nombre, (arbol + i)->stock);
                break;
            }
        }
    }
}

void actualizarStock(Arbol *arbol, int numArboles){
    int pregunta;
    printf("Desea actualizar el stock de algun arbol?(1:SI-2:NO)\n");
    scanf("%d", &pregunta);
    fflush(stdin);
    if (pregunta == 1)
    {
        printf("De que arbol desea actualizar el stock?(Nombre del arbol)\n");
        char nombreArbol[MAX];
        gets(nombreArbol);
        fflush(stdin);
        for (int i = 0; i < numArboles; i++)
        {
            if (strcmp(nombreArbol,(arbol + i)->nombre) == 0)
            {
                int nuevoStock;
                printf("Actualice el stock\n");
                scanf("%d", &nuevoStock);
                (arbol + i)->stock = nuevoStock;
                fflush(stdin);
            }
        }        
    }
}

void actualizarPrecio(Arbol *arbol, int numArboles){
    int pregunta;
    printf("Desea actualizar el precio de alguna Especie?(1:SI-2:NO)\n");
    scanf("%d", &pregunta);
    fflush(stdin);
    if (pregunta == 1)
    {
        printf("De que arbol desea actualizar el precio?(Nombre del arbol)\n");
        char nombreArbol[MAX];
        gets(nombreArbol);
        fflush(stdin);
        for (int i = 0; i < numArboles; i++)
        {
            if (strcmp(nombreArbol,(arbol + i)->nombre) == 0)
            {
                int nuevoPrecio;
                printf("Actualice el Precio\n");
                scanf("%d", &nuevoPrecio);
                (arbol + i)->precio = nuevoPrecio;
                fflush(stdin);
            }
        }
    }
    
}
