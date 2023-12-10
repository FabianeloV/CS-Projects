#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "time.h"


void validarDia();
void mostrarDiagrama();
int temperaturaAcotada(int temperatura, int minimo, int maximo, int diferencias[7][24], int f, int c);
void generarMatrices(int temperaturas[7][24],int diferencias[7][24]);
int buscarMayorDiferencia(int diferencias[7][24]);

int temperaturaAcotada(int temperatura, int minimo, int maximo, int diferencias[7][24], int f, int c){
    int residuo=0;
    if(temperatura<minimo){
        //4   2   4 = 2 + 4-2
        residuo = minimo - temperatura;
        diferencias[f][c] = residuo;
        printf("%d", residuo);
        return minimo;
    }
    else if(temperatura>maximo) {
        //10  e:12   10= 12 + 10-12
        residuo = maximo - temperatura;
        diferencias[f][c] = -1*residuo;
        return  (maximo);
    }
    else{
        return temperatura;
    }
}
void generarMatrices(int temperaturas[7][24],int diferencias[7][24]){
    int f=0,c=0;
    int temp;
    for (f = 0; f < 7; ++f) {
        for (c = 0; c<24; ++c) {
            //Generar temperatura random
            temp = rand() % 22 + 1;
            //Rango 1:7
            if (c < 7) {
                temperaturas[f][c] = temperaturaAcotada(temp, 4, 12, diferencias, f, c);
            }

            //Rango 8:11
            if (c >= 7 && c < 11) {
                temperaturas[f][c] = temperaturaAcotada(temp, 12, 18, diferencias, f, c);
            }

            //Rango 12:14
            if (c >= 11 && c < 14) {
                temperaturas[f][c] = temperaturaAcotada(temp, 18, 22, diferencias, f, c);
            }

            //Rango 15:18
            if (c >= 14 && c < 18) {
                temperaturas[f][c] = temperaturaAcotada(temp, 14, 22, diferencias, f, c);
            }

            //Rango 19:21
            if(c>=18 && c<21){
                temperaturas[f][c] = temperaturaAcotada(temp,10, 14, diferencias, f ,c);
            }

            //Rango 19:21
            if(c>=21){
                temperaturas[f][c] = temperaturaAcotada(temp,6, 10, diferencias, f ,c);
            }
            printf(" %d ", temperaturas[f][c]);

        }
        printf("\n");
    }
}
int buscarMayorDiferencia(int diferencias[7][24]){

    int f=0,c=0, posicion;
    int anterior=0, maximo = 0;
    for (f = 0; f < 7; ++f) {
        maximo=0;
        for (c = 0; c < 24; ++c) {
            maximo= maximo + diferencias[f][c];
            //printf("%d \t", maximo);
        }

        //printf("pos: %d - max: %d \n", posicion,maximo);

        if(maximo>anterior){
            anterior=maximo;
            posicion=f;
        }
    }
    return posicion;


}
int main(){
    int temperaturas[7][24], diferencias[7][24];
    generarMatrices(temperaturas,diferencias);
    int diaMayorDiferencia = buscarMayorDiferencia(diferencias);
    for (int f = 0; f < 7; ++f) {
        for (int c = 0; c < 24; ++c) {
          //  printf("%d", diferencias[f][c]);
        }
        printf("\n");

    }
}


