#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "Facturas.h"

/// modificar datos clientes.
void modificarNombre(char nombre[])
{
    char nom[30];
    printf("Ingrese nombre.\n");
    fflush(stdin);
    gets(nom);
    strcpy(nombre, nom);
}
void modificarApellido(char apellido[])
{
    char ape[30];
    printf("Ingrese el apellido.\n");
    fflush(stdin);
    gets(ape);
    strcpy(apellido, ape);
}
void modificarTelefono(char telefono[])
{
    char tel[20];
    printf("Ingrese el telefono.\n");
    fflush(stdin);
    gets(tel);
    strcpy(telefono, tel);
}
void modificarBarrio(char barrio[])
{
    char ba[20];
    printf("Ingrese el barrio.\n");
    fflush(stdin);
    gets(barrio);
    strcpy(barrio, ba);
}
void modificarCalle(char calle[])
{
    char direccion[20];
    printf("Ingrese la calle.\n");
    fflush(stdin);
    gets(direccion);
    strcpy(calle, direccion);
}
void modificarAltura(char altura[])
{ /// REVISAR EL TEMA PUNTEROS
    char alt[5];
    printf("Ingrese la altura.\n");
    fflush(stdin);
    gets(alt);
    strcpy(altura, alt);
}

void modificarDireccion(char direccion[])
{
    char calle[20];
    char altura[5];
    modificarCalle(calle);
    modificarAltura(altura);
    direccion[25] = strcat(calle, altura);
}

void cambiarPassword(char password[])
{
    char pass[8];
    printf("Ingrese la nueva password.\n");
    fflush(stdin);
    gets(pass);
    strcpy(password, pass);
}

/// === CARGA CLIENTE
STCliente CargarUnCliente()
{
    STCliente ClienteNuevo;
    ClienteNuevo.Dato = cargaDatosPersonales();
    ClienteNuevo.Servicio = CargaServicio();
    
    return ClienteNuevo;
}

STPersonal cargaDatosPersonales()
{
    STPersonal dato;
    printf("Ingrese el DNI.\n");
    fflush(stdin);
    gets(dato.DNI);
    modificarNombre(dato.Nombre);
    modificarApellido(dato.Apellido);
    modificarTelefono(dato.NumeroCel);
    modificarDomicilio(dato.direccion);
    return dato;
}

STLogin cargaLogin(STPersonal cliente){
    STLogin login;
    login.id=cliente.id;
    strcpy(login.pass, cliente.DNI);

    return login;
}

STServicio CargaServicio()
{
    STServicio Servicio;
    char corte;
    printf("\nDesea contratar el servicio de internet s/n\n");
    fflush(stdin);
    scanf("%c", &corte);
    if (strcmpi(corte, "s") == 0)
    {
        Servicio.Internet = 1;
    }
    printf("\nDesea contratar el servicio de cable s/n\n");
    fflush(stdin);
    scanf("%c", &corte);
    if (strcmpi(corte, "s") == 0)
    {
        Servicio.Cable = 1;
    }
    return Servicio;
}


