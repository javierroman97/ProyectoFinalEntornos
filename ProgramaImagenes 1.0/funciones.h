#ifndef IMAGENES_LION_FUNCIONES_H
#define IMAGENES_LION_FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
struct Img
{
    int nfilas, ncols; //num. filas y columnas
    int** valores; //almacena dinámicamente la matriz de puntos
    FILE* f; //fichero en disco asociado
    int g;
};
FILE* leer(char* nombreArchivo);
FILE* escribir(char* nombreArchivo);
void limpiarpantalla(char *OS);


#endif //IMAGENES_LION_FUNCIONES_H
