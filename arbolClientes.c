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
    mostrarCliente(nodo->Cliente); //<-Falta definir esta funcion
}

arbolClientes * borrarCliente(arbolClientes * arbol, arbolClientes * borrado){
    if(arbol){
        if(borrado->Cliente.Dato.DNI == arbol->Cliente.Dato.DNI){
            if(arbol->izq){
                arbolClientes * masDerecha=nodoMasDerecha(arbol->izq);
                arbol=masDerecha;
                arbol->izq=borrarCliente(arbol->izq, masDerecha);
            }else if(arbol->der){
                arbolClientes * masIzquierda=nodoMasIzquierda(arbol->izq);
                arbol=masIzquierda;
                arbol->der=borrarCliente(arbol->der, masIzquierda);
            }else{              //En caso de que sea hoja.
                free(arbol);
                arbol=NULL;
            }
        }else if(borrado->Cliente.Dato.DNI  > arbol->Cliente.Dato.DNI){
            arbol->der=borrarCliente(arbol->der, borrado);
        }else{
            arbol->izq=borrarCliente(arbol->izq, borrado);
        }
    }
    return arbol;
}

arbolClientes * nodoMasDerecha(arbolClientes * arbol){
    if(arbol->der){
        arbol=nodoMasDerecha(arbol->der);
    }
    return arbol;
}
arbolClientes * nodoMasIzquierda(arbolClientes * arbol){
    if(arbol->izq){
        arbol=nodoMasIzquierda(arbol->izq);
    }
    return arbol;
}