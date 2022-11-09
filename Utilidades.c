#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"

char confirmacionBucle()
{
    char seguir;
    printf("Presione 's' para continuar.\n");
    fflush(stdin);
    scanf("%c", &seguir);
    return seguir;
}

int solicitarIdCliente()
{
    int idCliente; /// SOLICITAR ID CLIENTE
    printf("\nIngrese ID de cliente a buscar");
    scanf("%d", idCliente);
    return idCliente;
}

int funcionComprobarDNI(char dni[], char archivo[]){
    FILE* fp=fopen(archivo, "rb");
    int flag=0;
    STRegistroCliente a;   
    if(fp){
        while(fread(&a, sizeof(STRegistroCliente),1 , fp)>0 && flag==0){
            if(strcmpi(a.DNI, dni)==0){
                flag=1; /// El dni ya está en uso.
            }
        }
        fclose(fp);
    }
    return flag;
}

