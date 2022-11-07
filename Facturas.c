#include <stdio.h>
#include <stdlib.h>
#include "Facturas.h"

/// ===Desarrollo funciones.
STFactura crearFactura(int fecha, int total, char nombre[30], char DNI[15])
{
    STFactura nueva;
    strcpy(nueva.DNI, DNI);
    strcpy(nueva.Nombre, nombre);
    nueva.fecha = fecha;
    nueva.Total = total;
    return nueva;
}

void MuestraUnicaFactura(STFactura Factura)
{
    printf("\nDNI: %c\n", Factura.DNI);
    printf("Nombre: %s", Factura.Nombre);
    printf("Nombre: %i", Factura.fecha);
    printf("Nombre: %i", Factura.Total);
}

void MostrarTodasLasFacturas(nodoFactura *Lista)
{
    while (Lista != NULL)
    {
        MuestraUnicaFactura(Lista->Factura);
        Lista = Lista->sig;
    }
}
