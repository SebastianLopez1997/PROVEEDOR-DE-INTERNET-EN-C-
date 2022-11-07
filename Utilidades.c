#include <stdlib.h>
#include <stdio.h>
#include "Utilidades.h"

char confirmacionBucle(){
    char seguir;
    printf("Presione 's' para continuar.\n");
    fflush(stdin);
    scanf("%c", &seguir);
    return seguir;
}