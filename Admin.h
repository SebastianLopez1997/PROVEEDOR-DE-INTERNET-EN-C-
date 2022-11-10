#pragma once
#include "arbolClientes.h"

/// === Prototipados.
int ComprobarAdmin(char usuario[20], char contrasena[20]);
void menuAdministrador();
int LoginDeUsuario(arbolClientes *Arbol);
