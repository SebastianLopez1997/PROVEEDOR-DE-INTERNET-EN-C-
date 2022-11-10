#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "arbolClientes.h"
#include "Menu.h"
#include "Admin.h"
#include "Clientes.h"
#include "Facturas.h"
#include "Random.h"
#include "Utilidades.h"

int main()
{
    arbolClientes *Arbol = inicArbol();
    Menu(Arbol);
    return 0;
}
