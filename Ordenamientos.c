#include "stdio.h"
#include <stdlib.h>
#include <ctype.h>

int IngresoDatos (int list[]){
    int n=-1, i, temp, mini, maxi;

    while (n<1){
        printf("Ingrese un numero de datos valido: \n");
        scanf("%d", &n);
    }

    printf("\nIngrese el primer valor del rango: \n");
    scanf("%d", &mini);

    printf("\nIngrese el segundo valor del rango: \n");
    scanf("%d", &maxi);

    if(maxi<mini){
        temp = maxi;
        maxi = mini;
        mini = temp;
    }

    for (i=0; i<n; i++){
        list[i] = rand()%maxi+mini;
    }

    return n;
}

void OrdenarLista(int list[], int n){
    int temp, i, j;

    for(i=0;i<n;i++){
        for (j = 0; j < n; j++) {
            if (list[j]<list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

int BuscarDato(int dato, int n, int list[30]){
    int low = 0, high = n, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (list[mid] == dato)
            return mid;

        if (list[mid] > dato)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(){
    int option=0, list[30], n=0, i, valid = 0, position, dato;

    while (option == 0) {
        printf("\nIngrese una opcion\n (1) Ingreso de datos\n (2) Buscar datos\n (3) Listado de datos\n (4) Salir\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                n = IngresoDatos(list);
                valid = 1;
                option = 0;

                break;
            case 2:
                if (valid == 1){
                    OrdenarLista(list, n);
                    printf("\nIngrese el dato a buscar:\n");
                    scanf("%d", &dato);

                    position = BuscarDato(dato, n, list);

                    if(position != -1){
                        printf("\nEl numero %d esta en la posicion %d\n", dato, position);
                    } else {
                        printf("\nEl numero %d no esta en la lista\n", dato);
                    }
                    option = 0;

                } else {
                    printf("\nNo ha ingresado datos\n");
                    option = 0;
                }

                break;
            case 3:
                if (valid == 1){
                    OrdenarLista(list, n);
                    for (i=0;i<n;i++){
                        printf("%d ", list[i]);
                    }
                    option = 0;
                } else {
                    printf("\nNo ha ingresado datos\n");
                    option = 0;
                }
                break;
            case 4:
                printf("MUCHAS GRACIAS");
                break;
            default:
                printf("\nIngrese una opcion valida\n");
                option=0;
                break;
        }
    }
}