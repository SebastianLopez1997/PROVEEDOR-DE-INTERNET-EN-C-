#include <stdio.h>
#include <stdlib.h>
#include "Facturas.h"
#define INTERNET 1500
#define CABLE 500

/// ===Desarrollo funciones.
STFactura crearFactura(arbolClientes *Arbol, int fecha, char nombre[], char DNI[])
{
    STFactura nueva;
    strcpy(nueva.DNI, DNI);
    strcpy(nueva.Nombre, nombre);
    nueva.fecha = fecha;
    nueva.Total = SacarTotal(Arbol);
    return nueva;
}

nodoFactura *inicLista()
{
    return NULL;
}

nodoFactura *agregarAlPrincipio(nodoFactura *lista, nodoFactura *nuevoNodo)
{
    if (lista)
    {
        lista->sig = nuevoNodo;
        nuevoNodo->ante = lista;
    }
    lista = nuevoNodo;
    return lista;
}

nodoFactura *CrearFacturaNodo(STFactura factura)
{
    nodoFactura *nueva = (nodoFactura *)malloc(sizeof(nodoFactura));
    nueva->Factura = factura;
    nueva->sig = NULL;
    nueva->ante = NULL;
    return nueva;
}

int SacarTotal(arbolClientes *Arbol)
{
    int total = 0;
    int flag = 0;
    int cable = 1200;
    int internet = 1800;
    int descuento = 600;
    if (Arbol->Cliente.Servicio.Cable == 1)
    {
        total = total + cable;
        flag++;
    }
    if (Arbol->Cliente.Servicio.Internet == 1)
    {
        total += internet;
        flag++;
    }
    if (flag == 2)
    {
        total -= descuento;
    }
    return total;
}

void MuestraUnicaFactura(STFactura Factura)
{
    printf("\nDNI: %c\n", Factura.DNI);
    printf("\nNombre: %s\n", Factura.Nombre);
    printf("\nNombre: %i\n", Factura.fecha);
    printf("\nNombre: %i\n", Factura.Total);
    printf("<------------------------------>");
}

void MostrarTodasLasFacturasDeUnCliente(nodoFactura *Lista)
{
    while (Lista != NULL)
    {
        MuestraUnicaFactura(Lista->Factura);
        Lista = Lista->sig;
    }
    printf("\nNo se detectaron mas facturas para mostrar\n");
}

void mostrarFactura(arbolClientes *arbol)
{
    if (arbol)
    {
        mostrarArbol(arbol->izq);
        MostrarTodasLasFacturasDeUnCliente(arbol->Factura);
        mostrarArbol(arbol->der);
    }
}

/// === Nodo