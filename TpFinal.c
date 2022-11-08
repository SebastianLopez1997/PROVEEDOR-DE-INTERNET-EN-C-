#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "Clientes.h"
#include "Facturas.h"
#include "arbolClientes.h"
#include "Utilidades.h"
#include "random.h"
#include "Admin.h"
#include "Menu.h"

int main()
{
    arbolClientes *Arbol = inicArbol();
    
    Menu();

    return 0;
}
