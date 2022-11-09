#pragma once
#include "arbolClientes.h"

/// === Estructuras.
typedef struct
{
    int id;
    int fecha;
    int Total;
    char Nombre[30];
    char DNI[8];
} STFactura;

typedef struct
{
    int id;
    STFactura Factura;
    struct nodoFactura *sig;
    struct nodoFactura *ante;
} nodoFactura;

/// === Prototipados.
STFactura crearFactura(arbolClientes *Arbol, int fecha, char nombre[], char DNI[]);
void MostrarTodasLasFacturas(nodoFactura *Lista);
void MuestraUnicaFactura(STFactura Factura);
void mostrarFactura(arbolClientes *arbol);
void MostrarTodasLasFacturasDeUnCliente(nodoFactura *Lista);
nodoFactura *inicLista();
nodoFactura *agregarAlPrincipio(nodoFactura *lista, nodoFactura *nuevoNodo);
void PersistenciaDeFactura(char ArchiFacturas[], arbolClientes *Arbol);
void AbrirArchiFacturasYleer(char ArchiFacturas[]);