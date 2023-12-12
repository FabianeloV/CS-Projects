#define C_PROJECTS_MYFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int chooseBiOption(char options[]){
    int opt=0;

    printf("%s", options);

    scanf("%d", &opt);

    while (opt!=1 && opt !=2){
        printf("\nIngrese una opcion valida\n");
        scanf("%d", &opt);
    }

    return opt;
}

int AddNamesToMatrix(char persons[30][500]){
    int n, i;
    printf("Ingrese el numero de personas que desea agregar: ");
    scanf("%d", &n);

    while (n < 1) {
        printf("Ingrese un numero valido: ");
        scanf("%d", &n);
    }

    fflush(stdin);

    for (i = 0; i < n; i++) {
        fflush(stdin);
        printf("Ingrese el nombre y apellido de la persona %d: \n", i + 1);
        gets(persons[i]);
        fflush(stdin);

        while (strlen(persons[i]) <= 1) {
            printf("Ingrese un nombre y apellido valido: \n");
            gets(persons[i]);
            fflush(stdin);
        }
    }
    return n;
}

void PrintPersonsByName(int n, char persons[30][500], char names[30][500], char lastNames[30][500]){
    char temp[30][500], delim[] = " \n";
    int i, spaces=0;

    printf("\nEl listado de personas por su nombre es: \n");

    for (i = 0; i < strlen(persons[0]); i++) {
        if (persons[0][i] == ' ') {
            spaces++;
        }
    }

    if (spaces == 1) {
        for (i = 0; i < n; i++) {
            strcpy(temp[i], persons[i]);
            strcpy(names[i], strtok(temp[i], delim));
            strcpy(lastNames[i], strtok(NULL, delim));
            printf("%s %s\n", names[i], lastNames[i]);
        }
    } else{
        for (i = 0; i < n; i++) {
            strcpy(temp[i], persons[i]);
            strcpy(names[i], strtok(temp[i], delim));
            strcat(names[i], " ");
            strcat(names[i], strtok(NULL, delim));
            strcpy(lastNames[i], strtok(NULL, delim));
            strcat(lastNames[i], " ");
            strcat(lastNames[i], strtok(NULL, delim));
            printf("%s %s\n", names[i], lastNames[i]);
        }
    }
}

void PrintPersonsByLastname(int n, char persons[30][500], char names[30][500], char lastNames[30][500]){
    char temp[30][500], delim[] = " \n";
    int i, spaces=0;

    printf("\nEl listado de personas por su apellido es: \n");

    for (i = 0; i < strlen(persons[0]); i++) {
        if (persons[0][i] == ' ') {
            spaces++;
        }
    }
    if (spaces==1) {
        for (i = 0; i < n; i++) {
            strcpy(temp[i], persons[i]);
            strcpy(names[i], strtok(temp[i], delim));
            strcpy(lastNames[i], strtok(NULL, delim));
            printf("%s %s\n", lastNames[i], names[i]);
        }
    } else{
        for (i = 0; i < n; i++) {
            strcpy(temp[i], persons[i]);
            strcpy(names[i], strtok(temp[i], delim));
            strcat(names[i], " ");
            strcat(names[i], strtok(NULL, delim));
            strcpy(lastNames[i], strtok(NULL, delim));
            strcat(lastNames[i], " ");
            strcat(lastNames[i], strtok(NULL, delim));
            printf("%s %s\n", lastNames[i], names[i]);
        }
    }
}