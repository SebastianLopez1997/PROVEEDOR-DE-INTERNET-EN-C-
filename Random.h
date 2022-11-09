#pragma once


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
    char Barrio[20];
    /// Servicios
    int Internet;
    int Cable;
} STRegistroCliente;


