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

arbolClientes * buscarNodoCliente(arbolClientes * arbol, int DNI){
    arbolClientes * aux=inicArbol();
    int flag=1;
    if(arbol && flag==1){
        aux=buscarNodoCliente(arbol->izq, DNI);
        if(arbol->Cliente.Dato.DNI==DNI){
            aux=arbol;
            flag=0;
        }
        aux=buscarNodoCliente(arbol->der, DNI);
    }
    return aux;
}

arbolClientes * modificarDatosCliente(arbolClientes * arbol){
    char seguir='s';
    int opcion, flag=1, dniBuscado;
    arbolClientes * modificado=inicArbol();
    
    while(seguir=='s'){
        printf("Ingrese el DNI del cliente.\n");
        scanf("%i", &dniBuscado);
        modificado=buscarNodoCliente(arbol, dniBuscado);
        if(modificado!=NULL){
            seguir='n';
        }else{
            printf("El DNI ingresado no ha sido encontrado.\n");
            seguir=confirmacionBucle();
        }
    }

    seguir='s';

    while(seguir=='s'){
        
        printf("Que valor desea modificar?\n");
        /*printf de cada uno de los valores posibles a modificar*/
        scanf("%i", opcion);
        switch(opcion){
            case 1:
                printf("Ha seleccionado la opcion 1.\n");
                seguir=confirmacionBucle();
                if(seguir=='s'){
                    /*llamada a la función que modifica este valor.*/
                    flag=0;
                    system("cls");
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }

        seguir=confirmacionBucle();
        system("cls");
    }

    if(flag==0){        /*Hubo modifiación, entonces procede a la sustitución del nodo.*/
        
    }

    return arbol;
}

char confirmacionBucle(){
    char seguir;
    printf("Presione 's' para continuar.\n");
    fflush(stdin);
    scanf("%c", &seguir);
    return seguir;
}
