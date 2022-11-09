#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "arbolClientes.h"
#include "Menu.h"

int main()
{
    arbolClientes *Arbol = inicArbol();
    Menu(Arbol);
    return 0;
}
