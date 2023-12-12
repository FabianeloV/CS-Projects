#include <stdio.h>
#include "string.h"
#include "MyFunctions.h"

void SecuencialSearch(int n, char persons[30][500], char names[30][500], char lastNames[30][500]){
    int i, found=0;
    char temp[30][500], delim[] = " \n", search[500];

    for (i = 0; i < n; i++) {
        strcpy(temp[i], persons[i]);
        strcpy(names[i], strtok(temp[i], delim));
        strcpy(lastNames[i], strtok(NULL, delim));
    }

    printf("Ingrese el nombre que desea buscar;\n");
    fflush(stdin);
    gets(search);

    for (i = 0; i < n; ++i) {
        if (strcmpi(names[i], search) == 0){
            printf("\nEl usuario %s se encuentra en la posicion %d\n", persons[i], i);
            found = 1;
        }
    }
    if (found == 0){
        printf("\nEl usuario %s no se encuentra\n", search);
    }
}

void SecuencialSearchLastName(int n, char persons[30][500], char names[30][500], char lastNames[30][500]){
    int i, found=0;
    char temp[30][500], delim[] = " \n", search[500];

    for (i = 0; i < n; i++) {
        strcpy(temp[i], persons[i]);
        strcpy(names[i], strtok(temp[i], delim));
        strcpy(lastNames[i], strtok(NULL, delim));
    }

    printf("Ingrese el apellido que desea buscar;\n");
    fflush(stdin);
    gets(search);

    for (i = 0; i < n; ++i) {
        if (strcmpi(lastNames[i], search) == 0){
            printf("\nEl usuario %s se encuentra en la posicion %d\n", persons[i], i);
            found = 1;
        }
    }
    if (found == 0){
        printf("\nEl usuario %s no se encuentra\n", search);
    }
}

int main(){
    int n, option=0, opt2, opt4;
    char persons[30][500], names[30][500], lastnames[30][500];

    while (option==0){
        printf("\nIngrese una opcion\n (1) Ingreso de datos\n (2) Busqueda secuencial\n (3) Busqueda binaria\n (4) Listado de usuarios\n (5) Salir\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                n = AddNamesToMatrix(persons);
                option = 0;
                break;
            case 2:
                opt2 = chooseBiOption("\nIngrese una opcion\n(1) Buscar por nombres\n(2) Buscar por apellidos\n");
                if (opt2==1){
                    SecuencialSearch(n, persons, names, lastnames);
                } else {
                    SecuencialSearchLastName(n, persons, names, lastnames);
                }
                option = 0;
                break;
            case 3:
                option = 0;
                break;
            case 4:
                opt4 = chooseBiOption("\nIngrese una opcion\n(1) Listar por nombres\n(2) Listar por apellidos\n");
                if (opt4==1){
                    PrintPersonsByName(n, persons, names, lastnames);
                } else {
                    PrintPersonsByLastname(n, persons, names, lastnames);
                }
                option = 0;
                break;
            case 5:
                printf("MUCHAS GRACIAS");

                break;
            default:
                printf("\nIngrese una opcion valida\n");
                option=0;
                break;
        }
    }
}