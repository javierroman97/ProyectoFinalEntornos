#include <stdio.h>
#include "funciones.h"
#include <string.h>
#include <stdlib.h>



int main()
{
    //aquí tenemos la declaración de variables
    struct Img img;
    struct Img res; //struct resultado

    int variableSwitch = 0;
    char OS[7];
    char* p1 ;
    int total;
    int gRelleno;
    int x,y,x2,y2;
    int f_m=0;
    int c_m=0;
    char ubicacion[255];
    int temp;
    char tempc[255];
    int grosor=0;
    int g=0;
    p1=(char*)malloc(255 * sizeof(char));
    img.nfilas = 0;


    //Aquí preguntamos al usuario que sistema operativo usa, ya que la función limpiarpantalla depende del sistema operativo
    while((strcmp(OS,"Linux")&&strcmp(OS,"Windows"))!=0)
    {
        printf("¿Que sistema operativo usas, Linux o Windows? \n\nEscribelo tal cual aparece en el programa\n");
        scanf("%s", OS);
    }
    limpiarpantalla(OS);

    //img.f y res.f hacen referencia a los archivos de cada struct, por tanto le decimos que el archivo de img lo vamos a leer y se llama pepper.ascii.pgm
    strcpy(ubicacion,"pepper.ascii.pgm");
    img.f=leer(ubicacion);
    //aquí hacemos lo mismo pero en vez de leer, lo que queremos es escribir, por tanto me he hecho otra funcioncilla que se llama escribir
    strcpy(ubicacion,"resultado.pgm");
    res.f = escribir(ubicacion);

    //Comprobamos que le hemos asignado bien el archivo
    if (img.f == NULL)
    {
        printf("No se pudo abrir el archivo de origen");
    }
    if (img.f == NULL)
    {
        printf("No se pudo abrir el archivo de resultado");
    }

    //Le decimos al programa que lea la primera linea del archivo de img(y así de paso le quitamos la cabecera), para saber si funciona
    if (fgets(p1, 255, img.f) == NULL)
    {
        printf("No funciono");
    }
    //leemos la siguiente linea del archivo, si es un comentario se meterá en el while siguiente, si no seguira el programa sin más
    fgets(p1, 255, img.f);

    //Como las imagenes que .pgm pueden llevar comentarios que empiezan por #, lo que hacemos es leer lineas hasta que las lineas que leamos dejen de comenzar por #
    while (p1[0] == '#')
    {
        fgets(p1, 255, img.f);

    }

    //La siguiente línea del programa nos dice las filas y columnas de píxeles que tiene la imagen
    //strtok parte en cachillos la cadena de carácteres si tenemos por ejemplo 45 80, nos devolverá 45, y si hacemos otro strtok nos devolverá 80
    //El  atoi sirve para convertir un caracter en un número entero, cuando lea el 45 del ejemplo anterior el atoi convertira el 45 tipo char a 45 tipo int
    img.ncols = atoi(strtok(p1, " "));
    img.nfilas = atoi(strtok(0, " "));


    //Reservamos de manera dinámica las columnas de la imagen
    img.valores = (int**)malloc(img.ncols * sizeof(int*));

    if (img.valores == NULL)
    {
        printf("Error al asignar memoria de filas");
    }

    fgets(p1, 255, img.f); //valores de gris
    img.g=atoi(p1);

    for (int i = 0; i < img.ncols; i++)
    {
        //para cada columna de la imagen reservamos la memoria de las filas
        img.valores[i] = (int*)malloc(img.nfilas * sizeof(int));
        if (img.valores[i] == NULL)
        {
            printf("Error al asignar memoria de cols");
        }
    }

    //Escribimos en el archivo del struct resultado(res) la cabecerade la imagen, las columnas, filas y los valores de gris
    fprintf(res.f, "P2 \n");
    fprintf(res.f, "#PGM generado por er meho grupillo \n");
    fprintf(res.f, "%d %d \n", img.ncols, img.nfilas);
    fprintf(res.f, "%d \n", img.g);


}
