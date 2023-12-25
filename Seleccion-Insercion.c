#include "stdio.h"
#include "stdlib.h"
#include "MyFunctions.h"
#include "time.h"

int main() {
    int n, num;

    n = validPositiveNumbers();

    clock_t tiempo_inicio, tiempo_final;
    double segundos;

    int list1[n], list2[n], list3[n];

    for (int i = 0; i < n; ++i) {
        num = rand() % 100 + 1;
        list1[i] = num;
        list2[i] = num;
        list3[i] = num;
    }

    tiempo_inicio = clock();
    BubbleSort(list1, n);
    tiempo_final = clock();

    segundos = (double) (tiempo_inicio - tiempo_final) / CLOCKS_PER_SEC;
    printf("\nTIEMPO BUBBLE SORT: %f", segundos);

    tiempo_inicio = clock();
    OrdBySelection(list2, n);
    tiempo_final = clock();

    segundos = (double) (tiempo_inicio - tiempo_final) / CLOCKS_PER_SEC;
    printf("\nTIEMPO SELECTION SORT: %f", segundos);

    tiempo_inicio = clock();
    OrdByInsertion(list3, n);
    tiempo_final = clock();

    segundos = (double) (tiempo_inicio - tiempo_final) / CLOCKS_PER_SEC;
    printf("\nTIEMPO INSERTION SORT: %f", segundos);
}