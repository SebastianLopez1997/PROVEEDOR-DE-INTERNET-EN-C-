#pragma once
typedef struct
{
    char Direccion[20];
    char Barrio[20];
} STDireccion;

typedef struct
{
    int id;
    char pass[8];
} STLogin;

typedef struct
{
    int id;
    char DNI[20];
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
    /// Datos personales
    int id;
    char DNI[8];
    char pass[8];
    char Nombre[30];
    char Apellido[30];
    char NumeroCel[20];
    /// Direccion
    char Direccion[20];
    char Altura[5];
    char Barrio[20];
    /// Servicios
    int Internet;
    int Cable;
} STRegistroCliente;

/// MODIFICAR DATOS CLIENTE.
void modificarNombre(char nombre[]);
void modificarApellido(char apellido[]);
void modificarTelefono(char telefono[]);
void modificarBarrio(char barrio[]);
void modificarCalle(char calle[]);
void modificarAltura(char altura[]);
void modificarDomicilio();
void cambiarPassword(char password[]);

/// CARGA CLIENTE.
STCliente CargarUnCliente();
STPersonal cargaDatosPersonales();
STServicio CargaServicio();
STRegistroCliente crearRegistroRand(int id, char archivo[]);
 /// ESTAS?