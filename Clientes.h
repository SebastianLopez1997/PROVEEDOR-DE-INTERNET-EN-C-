#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Facturas.h"

typedef struct
{
    char Direccion[20];
    int Altura;
    char Barrio[20];
} STDireccion;

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

typedef struct {
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

