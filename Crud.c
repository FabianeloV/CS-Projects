// CRUD
// cedula, nombre, apellidos, profesion, ciudad -> validar cedula: suma de los primeros 8 multiplicados por 2121... division entre 10 - % debe = ultimo numero
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void ingresoDatos(int datos, char persons[30][500], char cedula[30][10]){

    char spacer []=" | ", nombres[30][30], apellidos[30][30], profesion[30][30], ciudad[30][30];

    if (strlen(cedula[datos]) <= 1){
        fflush(stdin);
        printf("Ingrese la cedula de la persona %d: \n", datos + 1);
        gets(cedula[datos]);
        strcat(persons[datos], cedula[datos]);
        strcat(persons[datos], spacer);
    }

    fflush(stdin);
    printf("Ingrese el nombre de la persona %d: \n", datos + 1);
    gets(nombres[datos]);
    strcat(persons[datos], nombres[datos]);
    strcat(persons[datos], spacer);

    fflush(stdin);
    printf("Ingrese el apellido de la persona %d: \n", datos + 1);
    gets(apellidos[datos]);
    strcat(persons[datos], apellidos[datos]);
    strcat(persons[datos], spacer);

    fflush(stdin);
    printf("Ingrese la profesion de la persona %d: \n", datos + 1);
    gets(profesion[datos]);
    strcat(persons[datos], profesion[datos]);
    strcat(persons[datos], spacer);

    fflush(stdin);
    printf("Ingrese la ciudad de la persona %d: \n", datos + 1);
    gets(ciudad[datos]);
    strcat(persons[datos], ciudad[datos]);
    strcat(persons[datos], spacer);
}

int buscarPorCedula(char cedula[30][10]){
    int i, result=0;
    char id[10];
    printf("Ingrese el numero de cedula del usuario que desea buscar: ");

    fflush(stdin);
    gets(id);

    for (i = 0; i < 30; ++i) {
        if (strcmpi(id, cedula[i]) == 0){
            result = i;
        }
    }

    return result;
}

void modificarDatos(int datos, char persons[30][500]){
    char temp[30][500], cedula[30][10];



    ingresoDatos(datos, temp, cedula);

    strcpy(persons[datos], temp[datos]);

    printf ("Datos modificados");
}

int agregarDatos(int datos, char persons[30][500], char cedula[30][10]){
    int select=0, nDatos = datos ;

    while (select==0){
        printf("Ingrese una opcion: \n1. Ingresar un nuevo dato\n2. Salir\n");
        scanf("%d", &select);

        while (select<0 || select>2){
            printf("Ingrese una opcion valida: \n1. Ingresar un nuevo dato\n2. Salir\n");
            scanf("%d", &select);
        }

        switch (select) {
            case 1:
                ingresoDatos(nDatos, persons, cedula);

                nDatos++;
                select=0;
                break;
            case 2:
                break;
        }
    }
    return nDatos;
}



bool cedulaValida(char cedula[10]){

    if(strlen(cedula)!=10){
        return false;
    }

    int validador[10] = {2,1,2,1,2,1,2,1,2,1}, cedulaEnteros[10], resultante[10];
    int sumaResultante = 0;
    //Convertir la cedula a enteros
    for(int i=0;i<10;i++){
        char digito[2] = {cedula[i], '\0'};
        cedulaEnteros[i] = atoi(digito);
    }


    //Vector resultante
    for(int i=0;i<10;i++){
        resultante[i] = cedulaEnteros[i] * validador[i];
        //Restar 9 si lo sobrepasa
        if(resultante[i]>9){
            resultante[i] = resultante[i] - 9;
        }
        //Sumar todos menos el ultimo
        if(i!=9){
            sumaResultante+=resultante[i];
        }
    }

    sumaResultante = 10 - sumaResultante%10;
    //Revisa que el ultimo digito sea igual a la suma y 10 - residuo de la suma
    return (sumaResultante == cedulaEnteros[9]);

}


int main(){
    int option=0, i, buscador, nDatos=0;
    char persons[30][500], cedula[30][10];

    while (option==0){
        printf("\nIngrese una opcion: \n1. Ingreso\n2. Modificar\n3. Buscar\n4. Eliminar\n5. Listar\n6. Salir\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                nDatos = agregarDatos(nDatos, persons, cedula);
                option = 0;
                break;
            case 2:
                buscador = buscarPorCedula(cedula);

                modificarDatos(buscador, persons);

                option = 0;
                break;
            case 3:
                buscador = buscarPorCedula(cedula);

                printf("CEDULA | NOMBRE | APELLIDO | PROFESION | CIUDAD \n");
                printf("%s", persons[buscador]);

                option = 0;
                break;
            case 4:
                option = 0;
                break;
            case 5:
                printf("\nEl listado de personas es: \n");

                printf("CEDULA | NOMBRE | APELLIDO | PROFESION | CIUDAD \n");

                for (i = 0; i < nDatos; i++) {
                    printf("%s\n", persons[i]);
                }
                option = 0;
                break;
            case 6:
                printf("MUCHAS GRACIAS");
                break;
        }
    }
}