#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARO STRUCTS
struct
{
    int dia;
    int mes;
    int anio;
}typedef Fecha;

struct
{
    char nombreArticulo[100];
    char destinatario[15];
    char nivel[20];
    char curso[20];
    char area[100];
    char descripcion[100];
    char datosControlador[100];
    Fecha fechaControl;
    char estadoControl[20];

}typedef Articulo;

//DECLARAR FUNCIONES

void cargarDatos(Articulo *articulo, int n);
void mostrarDatos(Articulo *articulo,int n);
void listarArticulosRobotica(Articulo *articulo,int n);
void articulosControlados(Articulo *articulo, int n);
//MAIN

int main(){
    int n;
    printf("cuantos articulos desea ingresar= ");
    scanf("%d", &n);
    Articulo *articulo = malloc(sizeof(Articulo) * n);
    
    cargarDatos(articulo,n);
    printf("\n");
    listarArticulosRobotica(articulo,n);
    printf("\n");
    articulosControlados(articulo,n);
    
    return 0;
}

//CREACION DE FUNCIONES

void cargarDatos(Articulo *articulo, int n){
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("ingrese el nombre del articulo:");
        gets(articulo->nombreArticulo);
        printf("ingrese el destinatario(Alumnos, Docentes, Directivos):");
        gets(articulo->destinatario);
        printf("ingrese el nivel(INICIAL,PRIMARIO,SECUNDARIO,SUPERIOR):");
        gets(articulo->nivel);
        printf("ingrese el area(Lengua,Mat,CienciaN/S,Robotica,Teatro,Musica,etc):");
        gets(articulo->area);
        printf("ingrese la descripcion del articulo:");
        gets(articulo->descripcion);
        printf("ingrese el nombre y apellido del controlador del articulo:");
        gets(articulo->datosControlador);
        fflush(stdin);
        printf("Ingrese la fecha de control dia/mes/anio:");
        scanf("%d", &articulo->fechaControl.dia);
        scanf("%d", &articulo->fechaControl.mes);
        scanf("%d", &articulo->fechaControl.anio);
        fflush(stdin);
        printf("Ingrese el estado del control(Cargado,Controlado,Publicado):");
        gets(articulo->estadoControl);
        articulo++;
    }
}

void mostrarDatos(Articulo *articulo,int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nombre Articulo:%s\n", articulo->nombreArticulo);
        printf("Destinatario:%s\n", articulo->destinatario);
        printf("Nivel:%s\n", articulo->nivel);
        printf("Area:%s\n", articulo->area);
        printf("Descripcion del Articulo:%s\n", articulo->descripcion);
        printf("Nombre y Apellido del controlador:%s\n", articulo->datosControlador);
        printf("Fecha del articulo: %d/%d/%d\n", articulo->fechaControl.dia,articulo->fechaControl.mes,articulo->fechaControl.anio);
        printf("estado de control: %s\n", articulo->estadoControl);
        articulo++;
    }
    
}

void listarArticulosRobotica(Articulo *articulo,int n){
    for (int i = 0; i < n; i++)
    {
        if (strcmp(articulo->area, "Robotica") == 0 && strcmp(articulo->destinatario, "Docentes") == 0)
        {
            printf("Nombre del Articulo: %s\n", articulo->nombreArticulo);
            printf("Area: %s\n", articulo->area); 
        }
        articulo++;
    }
    
}

void articulosControlados(Articulo *articulo, int n){
    for (int i = 0; i < n; i++)
    {
        if (strcmp(articulo->estadoControl, "Controlado") == 0)
        {
            printf("Nombre de el/los Articulos Controlado: %s\n", articulo->nombreArticulo);
        }
        articulo++;
    }
    
}
