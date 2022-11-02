#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "Facturas.h"
#include "arbolClientes.h"

arbolClientes * inicArbol(){
    return NULL;
}
arbolClientes * crearNodoArbol(STCliente cliente){
    arbolClientes * nuevo=malloc(sizeof(arbolClientes));
    nuevo->Cliente=cliente;
    nuevo->der=NULL;
    nuevo->izq=NULL;
    return nuevo;
}
arbolClientes * agregarNodoArbol(arbolClientes * arbol, arbolClientes * nuevoNodo){
    if(arbol==NULL){
        arbol=nuevoNodo;
    }else{
        if(arbol->Cliente.Dato.DNI<nuevoNodo->Cliente.Dato.DNI){
            arbol->izq=agregarNodoArbol(arbol->izq, nuevoNodo);
        }else{
            arbol->der=agregarNodoArbol(arbol->der, nuevoNodo);
        }
    }

}
void mostrarArbol(arbolClientes * arbol){
    if(arbol){
        mostrarArbol(arbol->izq);
        mostrarNodoArbol(arbol);
        mostrarArbol(arbol->der);
    }
}
void mostrarNodoArbol(arbolClientes * nodo){
    mostrarCliente(nodo->Cliente);
}
