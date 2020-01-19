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

int rellenar(struct Img img,int x,int y,int x2,int y2, int g)
{
    printf("Ha seleccionado usted la herramienta rellenar\n");
    printf("A continuacion escriba el nivel de gris con el que desea rellenar la imagen\n");
    scanf("%d", &g);
    printf("A continuacion escriba las coordenadas que quiere rellenar del valor de gris (x, y)\n");
    printf("Coordenada 1: ");
    scanf("%d %d", &x,&y);
    printf("\nCoordenada 2: ");
    scanf("%d %d",&x2,&y2);

    for(int i = y; i < y2; i++)
    {
        for(int j = x; j < x2; j++)
        {
            img.valores[i][j]=g;
        }
    }
    if((img.valores[y+1][x+1] == g) && img.valores[y2-1][x2-1] == g)
    {
        return 0;
    }
    else
    {
        return 1;
    }

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

void GuardarImagenes(struct Img img, char* p1, int f_m, int c_m, int total)
{
    while(total>0)
    {
        char tempc[255];
        int temp;
        fgets(p1,255,img.f);
        strcpy(tempc,strtok(p1," "));
        temp= atoi(tempc);
        img.valores[c_m][f_m]=temp;
        c_m++;
        total--;

        for(int i=0; i<img.ncols-1; i++)
        {
            strcpy(tempc,p1);
            strcpy(tempc, strtok(NULL, " "));
            if((f_m==475)&&(c_m==349))
            {
                printf("mi gato tiene un cascabel");
            }
            if((strcmp(tempc,"\r\n")==0)||(strcmp(tempc,"\n")==0)||(strcmp(tempc,"\r")==0))
            {
                fgets(p1,255,img.f);
                strcpy(tempc,strtok(p1," "));
            }



            temp= atoi(tempc);
            img.valores[c_m][f_m]=temp;
            total--;
            c_m++;
        }
        f_m++;
        c_m=0;
    }
}
