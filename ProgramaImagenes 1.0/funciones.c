#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* leer(char* nombreArchivo)
{
    return fopen(nombreArchivo, "r");
}

FILE* escribir(char* nombreArchivo)
{
    return fopen(nombreArchivo, "w");
}

void limpiarpantalla(char *OS)
{
    if(strcmp(OS,"Linux")==0)
    {
        printf("\033[H\033[J");
    }
    else
    {
        system("cls");
    }
}
