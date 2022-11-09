#include <string.h>
#include "Menu.h"
#include "Clientes.h"
#include "Admin.h"
#include "arbolClientes.h"
#include "Facturas.h"
#include "Utilidades.h"

arbolClientes * Menu(arbolClientes *arbolPrincipal)
{
    int opcion = 0;
    char seguir='s';

    while (opcion != 1 || opcion != 2 || opcion != 3)
    {
        {
            printf("Seleccione 1 para ingresar a panel de usuario\nPrecione 2 para ingresar como administrador (Solo personal autorizado)\nPrecione 3 para crear un nuevo usuario");
            scanf("%i", &opcion);
        }
    }

    while(seguir=='s'){

    switch (opcion)
    {
    case 1:
        /// Login usuario.
        int opcionCliente = 0;
        while (opcionCliente > 0 && opcionCliente < 5)
        {
            printf("Seleccione 1_Para ver sus datos\nSeleccione 2_Para ver las facturas\nSeleccione 3_Para modificar datos personales\nSeleccione 4_Para solicitar labaja");
            scanf("%i", &opcionCliente);
            /// FUNCION LOGIN DE USUARIO
            switch (opcionCliente)
            {
            case 1:


                break;
            case 2:
                /// FUNCION PARA VER TODAS LAS FACURAS DEL USUARIO
                break;
            case 3:
                /// FUNCION PARA MODIFICAR LOS DATOS DEL USUARIO
                break;
            case 4:
                /// FUNCION PARA PEDIR LA BAJA AL ADMINISTRADOR
                break;
            default:
                printf("\nSelecciono una opcion invalida\n");
                break;

                printf("Presione 0 para salir o 1 para volver al menu");
                scanf("%i", &opcionCliente);
            }
        }
    case 2:
        printf("Un gusto verlo nuevamente, ingrese los datos personales solicitados");
        /// Comprobacion de usuario y contraseña para el ADMINISTRADOR
        /// Funciones de baja de usuario, realizar envios de facturas, mensajes de soporte
        break;
    case 3:
        printf("Bienvenido, te deseamos que tengas la mejor experiencia con nuestro servicios, a continuacion se te ofrecera servicios y planes para que puedas solicitar el que desee, al finalizar se le solocitara sus datos personales para poder realizar la instalacion de los servicios");
        STCliente nuevoCliente = CargarUnCliente();
        arbolClientes *Nuevo = crearNodoArbol(nuevoCliente);
        arbolPrincipal = agregarNodoArbol(arbolPrincipal, Nuevo);
        /// ACA IRIA EL ALTA USUARIO.

        break;
    default:
        printf("\nOpcion invalida\n");
        seguir=confirmacionBucle();
        break;
    }
    }
    return arbolPrincipal;
}