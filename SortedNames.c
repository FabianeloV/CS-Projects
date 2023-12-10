#include <stdio.h>
#include <string.h>

int main() {
    int n = 0, i, spaces = 0, option = 0;
    char delim[] = " \n";
    char temp[30][30];
    char persons[30][30];
    char names[30][30];
    char lastNames[30][30];

    while (option == 0) {
        printf("\nIngrese una opcion\n (1) Ingreso de datos\n (2) Listado de Nombres\n (3) Listado de Apellidos\n (4) Salir\n");
        scanf("%d", &option);

        switch (option) {
            case 1:

                printf("Ingrese el numero de personas que desea agregar: ");
                scanf("%d", &n);

                while (n < 1) {
                    printf("Ingrese un numero valido: ");
                    scanf("%d", &n);
                }
                fflush(stdin);

                for (i = 0; i < n; i++) {
                    fflush(stdin);
                    printf("Ingrese el nombre de la persona %d: \n", i + 1);
                    fgets(persons[i], 30, stdin);
                    fflush(stdin);

                    while (strlen(persons[i]) <= 1) {
                        printf("Ingrese un nombre valido: \n");
                        fgets(persons[i], 30, stdin);
                        fflush(stdin);
                    }
                }

                option = 0;

                break;

            case 2:
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

                /*
                for(i=0;i<n;i++)
                    for(j=0; j < n; j++)
                        if(strcmp(persons[j], persons [j+1])>0) {
                            strcpy(temp, persons[j]);
                            strcpy(persons[j], persons[j+1]);
                            strcpy(persons[j+1], temp);
                        }

                printf("\nLas personas ingresadas son: \n");
                for (i=0; i<30; i++){
                    printf("%s", persons[i]);
                }
                */

                spaces = 0;
                option = 0;
                break;

            case 3:
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

                spaces = 0;
                option = 0;
                break;

            case 4:
                printf("\nGracias\n");
        }
    }
}
