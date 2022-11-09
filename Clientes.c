#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"
#include "arbolClientes.h"

/// MODIFICAR CLIENTES
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

STLogin cargaLogin(STPersonal cliente)
{
    STLogin login;
    login.id = cliente.id;
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

int crearRegistroArchiRand(char archivo[])
{
    FILE *archi = fopen(archivo, "wb");
    STRegistroCliente a;
    int cant, i = 1;
    if (archi)
    {
        printf("\nIngrese cantidad de registros random que desea crear:");
        scanf("%d", &cant);
        cant++;
        while (i < cant)
        {
            a = crearRegistroRand(i, archivo);
            fwrite(&a, sizeof(STRegistroCliente), 1, archivo);
            i++;
        }
        fclose(archivo);
    }
    return i;
}

STRegistroCliente crearRegistroRand(int id, char archivo[])
{
    STRegistroCliente a;
    a.id = id;
    nombreRandom(a.Nombre);
    apellidoRandom(a.Apellido);
    movilRandom(a.NumeroCel);
    domicilioRandom(a.Direccion);
    barrioRandom(a.Barrio);
    cableRandom(a.Cable);
    internetRandom(a.Internet); // Hay que modificar para que tome el servicio en conjunto y no por separado(cable e internet));
    dniRandom(a.DNI);
    while (funcionComprobarDNI(a.DNI, archivo) == 1)
    {
        dniRandom(a.DNI);
    }
    return a;
}

void PersistirCliente(arbolClientes *cliente, FILE *fp)
{
    if (fp)
    {
        STRegistroCliente aux;
        aux = crearRegistroCliente(cliente);
        fwrite(&aux, sizeof(STRegistroCliente), 1, fp);
    }
}

STRegistroCliente crearRegistroCliente(arbolClientes *cliente)
{
    STRegistroCliente aux;
    strcpy(aux.Nombre, cliente->Cliente.Dato.Nombre);
    strcpy(aux.Apellido, cliente->Cliente.Dato.Apellido);
    strcpy(aux.DNI, cliente->Cliente.Dato.DNI);
    strcpy(aux.Direccion, cliente->Cliente.Dato.direccion.Direccion);
    strcpy(aux.Barrio, cliente->Cliente.Dato.direccion.Barrio);
    strcpy(aux.NumeroCel, cliente->Cliente.Dato.NumeroCel);
    aux.id = cliente->login.id;
    strcpy(aux.pass, cliente->login.pass);
    aux.Cable = cliente->Cliente.Servicio.Cable;
    aux.Internet = cliente->Cliente.Servicio.Internet;
    return aux;
}

void persistirArbol(char archivo[], arbolClientes *arbol)
{
    FILE *fp = fopen(archivo, "ab");
    if (fp)
    {

        close(fp);
    }
}

void recorrerYGuardar(arbolClientes *arbol, FILE *fp)
{
    if (arbol)
    {
        recorrerYGuardar(arbol->izq, &*fp);
        PersistirCliente(arbol, &*fp);
        recorrerYGuardar(arbol->der, &*fp);
    }
}

/// Mostrar CLiente

void MostrarUncliente(STCliente aux)
{
    printf("\nNombre: %s\n", aux.Dato.Nombre);
    printf("\nApellido: %s\n", aux.Dato.Apellido);
    printf("\nDireccion: %s\n", aux.Dato.direccion);
    printf("\nDNI: %s\n", aux.Dato.DNI);
    printf("\nID: %i\n", aux.Dato.id);
    printf("\nNumero de contacto: %s\n", aux.Dato.NumeroCel);
    printf("\n--------------------------\n");
}

/// Comprobar estado del cliente
STCliente DarmeLaBaja(STCliente aux)
{
    aux.Servicio.Cable = 0;
    aux.Servicio.Internet = 0;
    printf("\n Usted fue dado de baja \n");
    return aux;
}

int EstadoClienteServicios(STCliente Aux)
{
    int flag = 0;
    if (Aux.Servicio.Cable == 1 || Aux.Servicio.Internet == 1)
    {
        flag = 1;
    }
    return flag;
}