#include "Admin.h"
#include <string.h>

int ComprobarAdmin(char usuario[20], char contraseña[20])
{
    int flag = 0;
    if ((strcmpi(usuario, "Administrador") == 0) && (strcmpi(contraseña, "Administrador") == 0))
    {
        flag = 1;
    }
    return flag;
}

void menuAdministrador(){
    int opcion;
    printf("Bienvenido.\n");
    printf("Ingrese el nombre de usuario.\n");

}

