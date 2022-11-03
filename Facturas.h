#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// === Estructuras.
typedef struct
{
    int fecha;
    int Total;
    char Nombre[30];
    char DNI[15];
} STFactura;

typedef struct{
    STFactura Factura;
    struct nodoFactura * sig;
    struct nodoFactura * ante;
}nodoFactura;

/// === Prototipados.
STFactura crearFactura(int fecha, int total, char nombre[30], char DNI[15]);

