#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "Facturas.h"

/// Estructuras.
typedef struct{
    STCliente Cliente;
    struct arbolClientes * izq;
    struct arbolClientes * der;
}arbolClientes;

/// Prototipados. 
arbolClientes * inicArbol();
arbolClientes * crearNodoArbol(STCliente cliente);
arbolClientes * agregarNodoArbol(arbolClientes * arbol, arbolClientes * nuevoNodo);
void mostrarArbol(arbolClientes * arbol);
void mostrarNodoArbol(arbolClientes * nodo);
arbolClientes * borrarCliente(arbolClientes * arbol, arbolClientes * borrado);
arbolClientes * nodoMasDerecha(arbolClientes * arbol);
arbolClientes * nodoMasIzquierda(arbolClientes * arbol);
arbolClientes * buscarNodoCliente(arbolClientes * arbol, int DNI);
arbolClientes * modificarDatosPersonalesCliente(arbolClientes * arbol);
char confirmacionBucle();
