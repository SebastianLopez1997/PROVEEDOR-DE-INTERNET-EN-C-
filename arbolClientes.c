#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "Facturas.h"
#include "arbolClientes.h"
#include "Menu.h"
#include "Admin.h"

arbolClientes *inicArbol()
{
    return NULL;
}

arbolClientes *crearNodoArbol(STCliente cliente)
{
    arbolClientes *nuevo = malloc(sizeof(arbolClientes));
    nuevo->Cliente= cliente;

    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
}

arbolClientes *agregarNodoArbol(arbolClientes *arbol, arbolClientes *nuevoNodo)
{
    if (arbol == NULL)
    {
        arbol = nuevoNodo;
    }
    else
    {
        if (arbol->Cliente.Dato.DNI < nuevoNodo->Cliente.Dato.DNI)
        {
            arbol->izq = agregarNodoArbol(arbol->izq, nuevoNodo);
        }
        else
        {
            arbol->der = agregarNodoArbol(arbol->der, nuevoNodo);
        }
    }
}

void mostrarArbol(arbolClientes *arbol)
{
    if (arbol)
    {
        mostrarArbol(arbol->izq);
        mostrarNodoArbol(arbol);
        mostrarArbol(arbol->der);
    }
}

void mostrarNodoArbol(arbolClientes *nodo)
{
    mostrarCliente(nodo->Cliente); //<-Falta definir esta funcion
}

arbolClientes *borrarCliente(arbolClientes *arbol, arbolClientes *borrado)
{
    if (arbol)
    {
        if (borrado->Cliente.Dato.DNI == arbol->Cliente.Dato.DNI)
        {
            if (arbol->izq)
            {
                arbolClientes *masDerecha = nodoMasDerecha(arbol->izq);
                arbol = masDerecha;
                arbol->izq = borrarCliente(arbol->izq, masDerecha);
            }
            else if (arbol->der)
            {
                arbolClientes *masIzquierda = nodoMasIzquierda(arbol->izq);
                arbol = masIzquierda;
                arbol->der = borrarCliente(arbol->der, masIzquierda);
            }
            else
            { // En caso de que sea hoja.
                free(arbol);
                arbol = NULL;
            }
        }
        else if (borrado->Cliente.Dato.DNI > arbol->Cliente.Dato.DNI)
        {
            arbol->der = borrarCliente(arbol->der, borrado);
        }
        else
        {
            arbol->izq = borrarCliente(arbol->izq, borrado);
        }
    }
    return arbol;
}

arbolClientes *nodoMasDerecha(arbolClientes *arbol)
{
    if (arbol->der)
    {
        arbol = nodoMasDerecha(arbol->der);
    }
    return arbol;
}

arbolClientes *nodoMasIzquierda(arbolClientes *arbol)
{
    if (arbol->izq)
    {
        arbol = nodoMasIzquierda(arbol->izq);
    }
    return arbol;
}

arbolClientes *buscarNodoCliente(arbolClientes *arbol, int idCliente)
{
    arbolClientes *aux = inicArbol();
    if (arbol)
    {
        if (idCliente == arbol->login.id)
        {
            if (arbol->login.id == idCliente)
            {
                aux = arbol;
            }
            else
            {
                if (idCliente> arbol->login.id)
                {
                    aux = buscarNodoCliente(arbol->izq, idCliente);
                }
                else
                {
                    aux = buscarNodoCliente(arbol->der, idCliente);
                }
            }
        }
    }
    return aux;
}

arbolClientes *modificarDatosPersonalesCliente(arbolClientes *arbol)
{
    char seguir = 's';
    int opcion, flag = 1, idBuscado;
    arbolClientes *modificado = inicArbol();
    STCliente nuevo;

    while (seguir == 's')
    {
        printf("Ingrese el ID del cliente.\n");
        scanf("%i", &idBuscado);
        modificado = buscarNodoCliente(arbol, idBuscado);
        if (modificado != NULL)
        {
            nuevo = modificado->Cliente;
            seguir = 'n';
        }
        else
        {
            printf("El DNI ingresado no ha sido encontrado.\n");
            seguir = confirmacionBucle();
        }
    }

    seguir = 's';

    while (seguir == 's')
    {

        printf("Que valor desea modificar?\n");
        printf("1. Nombre.\n");
        printf("2. Apellido.\n");
        printf("3. Telefono.\n");
        printf("4. Barrio.\n");
        printf("5. Calle.\n");
        printf("6. Altura.\n");
        printf("7. Contrasena.\n");

        scanf("%i", opcion);
        switch (opcion)
        {
        case 1:
            printf("Ha seleccionado la opcion 1.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarNombre(nuevo.Dato.Nombre);
                flag = 0;
                system("cls");
            }
            break;
        case 2:
            printf("Ha seleccionado la opcion 2.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarApellido(nuevo.Dato.Apellido);
                flag = 0;
                system("cls");
            }
            break;
        case 3:
            printf("Ha seleccionado la opcion 3.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarTelefono(nuevo.Dato.NumeroCel);
                flag = 0;
                system("cls");
            }
            break;
        case 4:
            printf("Ha seleccionado la opcion 4.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarBarrio(nuevo.Dato.direccion.Barrio);
                flag = 0;
                system("cls");
            }
            break;
        case 5:
            printf("Ha seleccionado la opcion 5.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarCalle(nuevo.Dato.direccion.Direccion);
                flag = 0;
                system("cls");
            }
            break;
        case 6:
            printf("Ha seleccionado la opcion 6.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                cambiarPassword(nuevo.login.pass);
                flag = 0;
                system("cls");
            }
            break;
        case 7:
            printf("Ha seleccionado la opcion 7.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {

                flag = 0;
                system("cls");
            }
            break;
        }
        seguir = confirmacionBucle();
        system("cls");
    }

    if (flag == 0)
    { /*Hubo modifiación, entonces procede a la sustitución de la estructura.*/
        modificado->Cliente = nuevo;
    }

    return arbol;
}
