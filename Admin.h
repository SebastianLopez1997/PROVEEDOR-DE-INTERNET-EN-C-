<<<<<<< HEAD
/// === ESTRUCTURAS.
typedef struct{
    char username[20];
    char password[20];
    int permisos;
}Admin;

/// === PROTOTIPADOS.
=======
#pragma once
#include "arbolClientes.h"

/// === Prototipados.
int ComprobarAdmin(char usuario[20], char contrasena[20]);
void menuAdministrador();
int LoginDeUsuario(arbolClientes *Arbol);
>>>>>>> main
