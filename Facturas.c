
#include <stdio.h>
#include <stdlib.h>
#include "arbolClientes.h"
#include "Clientes.h"
#include "Facturas.h"
#define INTERNET 1500
#define CABLE 500

/// ===Desarrollo funciones.
STFactura crearFactura(arbolClientes *Arbol, int fecha, char nombre[], char DNI[])
{
    STFactura nueva;
    nueva.id = Arbol->Cliente.Dato.id;
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
/// mostrar facturas
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

/// === Nodob

void PersistenciaDeFactura(char ArchiFacturas[], arbolClientes *Arbol)
{
    arbolClientes *aux = NULL;
    aux = Arbol;
    nodoFactura *listaAux = NULL;
    listaAux = Arbol->Factura;

    FILE *BUFFER = fopen(ArchiFacturas, "ab");

    while (listaAux != NULL)
    {
        fwrite(&listaAux, sizeof(STFactura), 1, BUFFER);
        listaAux = listaAux->sig;
    }
    fclose(BUFFER);
}

void AbrirArchiFacturasYleer(char ArchiFacturas[])
{
    FILE *BUFFER = fopen(ArchiFacturas, "rb");
    STFactura Aux;
    while (fread(&Aux, sizeof(STFactura), 1, BUFFER) > 0)
    {
        MuestraUnicaFactura(Aux);
    }
    fclose(BUFFER);
}

void DespersistenciaDeFacturas(char ArchiFacturas[], arbolClientes *arbol)
{
    STFactura aux;
    FILE *fp = fopen(ArchiFacturas, "rb");
    if (fp)
    {
        while (fread(&aux, sizeof(STFactura), 1, fp) > 0)
        {
            nodoFactura *nuevo = CrearFacturaNodo(aux);
            arbolClientes *arbolAux = buscarNodoCliente(arbol, nuevo->id);
            if (arbolAux)
            {
                arbolAux->Factura = agregarAlPrincipio(arbolAux->Factura, nuevo);
            }
        }
        fclose(fp);
    }
}

void DespersistirFacturasClienteEspecifico(char ArchiFacturas[], arbolClientes *cliente)
{
    STFactura aux;
    FILE *fp = fopen(ArchiFacturas, "rb");
    if (fp)
    {
        while (fread(&aux, sizeof(STFactura), 1, fp) > 0)
        {
            if (aux.id == cliente->login.id)
            {
                nodoFactura *nuevo = CrearFacturaNodo(aux);
                cliente->Factura = agregarAlPrincipio(cliente->Factura, nuevo);
            }
        }
        fclose(fp);
    }
}
