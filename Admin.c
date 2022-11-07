#include <string.h>
#include "Admin.h"
#include "Utilidades.c"
#include "arbolClientes.c"
#include "Clientes.c"


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
    int flag=0;
    char user[20];
    char password[20];
    char seguir='s';

    while(seguir=='s' && flag==0){
            printf("Bienvenido.\n");
        printf("Ingrese el nombre de usuario.\n");
        gets(user);
        printf("Ingrese la contraseña.\n");
        gets(password);
        if(ComprobarAdmin(user, password) == 1){
            funcionesAdministrador();
        }else{
            printf("Los datos ingresados son incorrectos.\n");
            seguir=confirmacionBucle();
        }
    }


}

void funcionesAdministrador(){
    char seguir='s';
    int opcion;
    printf("Bienvenido Administrador.\n");
    while(seguir=='s'){
        printf("Ingrese la opcion que desea realizar.\n");
        printf("1. Mostrar clientes.\n");
        printf("2. Buscar cliente.\n");
        printf("3. Modificar datos cliente.\n");
        printf("4. Alta Cliente.\n");
        printf("5. Baja Cliente.\n");
        printf("6. Finalizar sesion.\n");
        scanf("%i", opcion);
    }
    switch(opcion){
        case 1:
            ///Llamada a la función despersistirRegistros en Arboles de listas.
            ///Llamada a la función mostrar Arbol.
            break;
        case 2:
            int idCliente;
            nodoArbol * buscado=buscarNodoCliente(/*ARBOL*/, idCliente);{
                if(buscado){
                    mostrarNodoArbol(buscado);
                    /// FUNCION MOSTRAR FACTURAS
                }else{
                    printf("Cliente no encontrado.\n");
                }
            }
            break;
        case 3:
            /*arbol*/=modificarDatosPersonalesCliente(/*arbol*/);
            break;
        case 4:

    }

}