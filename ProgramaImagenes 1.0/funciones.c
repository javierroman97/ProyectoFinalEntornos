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
