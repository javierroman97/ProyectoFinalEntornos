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


    return 0;
}
