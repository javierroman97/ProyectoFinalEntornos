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
int rellenar(struct Img, int x, int y, int x2, int y2, int g);
void limpiarpantalla(char *OS);
void GuardarImagenes(struct Img, char* p1, int f_m, int c_m, int total);


#endif //IMAGENES_LION_FUNCIONES_H
