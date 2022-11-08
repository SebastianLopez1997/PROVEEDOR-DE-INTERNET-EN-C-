#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "Facturas.h"




///modificar datos clientes.
void modificarNombre(char nombre[]){
    char nom[30];
    printf("Ingrese nombre.\n");
    fflush(stdin);
    gets(nom);
    strcpy(nombre, nom);
}
void modificarApellido(char apellido[]){
    char ape[30];
    printf("Ingrese el apellido.\n");
    fflush(stdin);
    gets(ape);
    strcpy(apellido, ape);
}
void modificarTelefono(char telefono[]){
    char tel[20];
    printf("Ingrese el telefono.\n");
    fflush(stdin);
    gets(tel);
    strcpy(telefono, tel);
}
void modificarBarrio(char barrio[]){
    char ba[20];
    printf("Ingrese el barrio.\n");
    fflush(stdin);
    gets(barrio);
    strcpy(barrio, ba);
}
void modificarCalle(char calle[]){
    char direccion[20];
    printf("Ingrese la calle.\n");
    fflush(stdin);
    gets(direccion);
    strcpy(calle, direccion);

}
void modificarAltura(char altura[]){ /// REVISAR EL TEMA PUNTEROS 
    char alt[5];
    printf("Ingrese la altura.\n");
    fflush(stdin);
    gets(alt);
    strcpy(altura, alt);
}
void cambiarPassword(char password[]){
    char pass[8];
    printf("Ingrese la nueva password.\n");
    fflush(stdin);
    gets(pass);
    strcpy(password, pass);
}