#ifndef ARBOLCLIENTES_H_INCLUDED
#define ARBOLCLIENTES_H_INCLUDED
#include "Facturas.h"
#include "Clientes.h"

/// Estructuras.
typedef struct arbolClientes
{
    STCliente Cliente;
    STLogin login;
    nodoFactura *Factura;
    struct arbolClientes *izq;
    struct arbolClientes *der;
} arbolClientes;

/// Prototipados.
arbolClientes *inicArbol();
arbolClientes *crearNodoArbol(STCliente cliente);
arbolClientes *agregarNodoArbol(arbolClientes *arbol, arbolClientes *nuevoNodo);
void mostrarArbol(arbolClientes *arbol);
void mostrarNodoArbol(arbolClientes *nodo);
arbolClientes *borrarCliente(arbolClientes *arbol, arbolClientes *borrado);
arbolClientes *nodoMasDerecha(arbolClientes *arbol);
arbolClientes *nodoMasIzquierda(arbolClientes *arbol);
arbolClientes *buscarNodoCliente(arbolClientes *arbol, int DNI);
arbolClientes *modificarDatosPersonalesCliente(arbolClientes *arbol);

#endif
