#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char Direccion[20];
    int Altura;
    char Barrio[20];
} STDireccion;

typedef struct
{
    int fecha;
    int Total;
    char Nombre[30];
    char DNI[15];
} STFactura;

typedef struct
{
    int id;
    int DNI;
    char Nombre[30];
    char Apellido[30];
    char NumeroCel[20];
    STDireccion direccion;
} STPersonal;

typedef struct
{
    int Internet;
    int Cable;
} STServicio;

typedef struct
{
    STPersonal Dato;
    STServicio Servicio;
} STCliente;

typedef struct
{
    STFactura Factura;
    nodoFactura *sig;
    nodoFactura *ante;
} nodoFactura;

typedef struct
{
    STCliente Cliente;
    struct arbolClientes *izq;
    struct arbolClientes *der;
} arbolClientes;

typedef struct
{
    /// Datos personales
    int id;
    int DNI;
    char Nombre[30];
    char Apellido[30];
    char NumeroCel[20];
    /// Direccion
    char Direccion[20];
    int Altura;
    char Barrio[20];
    /// Servicios
    int Internet;
    int Cable;
} STRegistroCliente;