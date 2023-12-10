#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define maxNombres 30
#define MAXLENNOMBRES 50

int main()
{   
    //Opcion que escoja el usuario, y el numero de nombres
    int opcion, numNombres;
    // Aun no se han ingresado datos
    bool datosExisten = false;
    // Matrices y vectores para los nombres
    char nombreTemp[MAXLENNOMBRES], nombres[maxNombres][MAXLENNOMBRES], nombresPorApellido[maxNombres][MAXLENNOMBRES];
    // Auxiliares para impresion de datos
    int longitudNombre, espacios = 0, contadorNombre, posicionApellido;
    //String que contiene primero los apellidos y luego los nombres
    char apellidoNombre[MAXLENNOMBRES];

    do
    {
        // Ingreso de la opcion del menu
        // printf("Escriba una opcion de las siguientes:\n");
        printf("\n1. Ingreso de datos\n");
        printf("2. Listar datos por nombre\n");
        printf("3. Listar datos por apellido\n");
        printf("4. Salir\nDigite su opcion:");
        scanf("%d", &opcion);

        switch (opcion)
        {

        // Ingreso de datos:
        case 1:
            printf("------------------------\n\n");
            // Ingreso de la cantidad de nombres:
            do
            {
                printf("Digite el numero de nombres a ingresar:");
                scanf("%d", &numNombres);
                if (numNombres < 1 || numNombres > maxNombres)
                {
                    printf("El numero debe estar en el rango [1:%d]", maxNombres);
                }
            } while (numNombres < 1 || numNombres > maxNombres);


            // Validación de cada uno de los nombres ingresados;
            for (int i = 0; i < numNombres; i++)
            {
                fflush(stdin);
                printf("\n### - Usario %d - ####:\n", i + 1);
                printf("Ingrese 2 nombres y 2 apellidos: ");

                // Nombre y apellido del n usuario
                do
                {   
                    gets(nombreTemp);
                    longitudNombre = strlen(nombreTemp);
                    //printf("Longitud nombre: %d : \"%c\" ",longitudNombre, nombreTemp);
                
                    //Si es un espacio en blanco, pedirá de nuevo
                    if ((longitudNombre <= 1 || longitudNombre > MAXLENNOMBRES) && longitudNombre!=0)
                    {
                        printf("Valor ingresado no valido, debe tener de 2 a %d caracteres\n", MAXLENNOMBRES);
                    }

                } while (longitudNombre <= 1 || longitudNombre > MAXLENNOMBRES);

                // Una vez validado, ingresamos el nombre y apellido dentro de la matriz
                strcpy(nombres[i], nombreTemp);
                datosExisten = true;
            }

            printf("------------------------\n\n");

            break;

        // Listado por nombre
        case 2:

            // Revisa que se hayan ingresado datos anteriormente
            printf("------------------------\n\n");
            if (datosExisten)
            {
                printf("## Total de nombres: %d ###\n", numNombres);
                for (int i = 0; i < numNombres; i++)
                {
                    printf("\n%s ", nombres[i]);
                }
                
            }

            else
            {
                printf("No se han ingresado datos\n");
            }
            printf("\n------------------------\n\n");

            break;

        // Listado por apellido
        case 3:
            printf("------------------------\n\n");
            // Revisa que se hayan ingresado datos
            if (datosExisten)
            {
                printf("## Total de nombres: %d ###\n", numNombres);
                // Buscamos los espacios en cada uno de los nombres
                //nombres|["Julio Iglesias Criollo Romero"]  | i=0
                //       |        ["a a a a"]]               | i=1
                //          nombres[i][contadorNombre]                                  
                //apellidoNombre = "Criollo Romero "
                for (int i = 0; i < numNombres; i++)
                {
                    // Variables para el recorrido del n Nombre
                    longitudNombre = strlen(nombres[i]);
                    espacios = contadorNombre = 0;
                    //Vaciado del string
                    memset(apellidoNombre, 0, strlen(apellidoNombre));

                    //Busca el 2do Espacio
                    while (espacios < 2)
                    {
                        //printf("Caracter: %c - ", nombres[i][contadorNombre]);
                        //printf("Espacios %d \n", espacios);
                        
                        // Se encuentran espacios en el n nombre " " 
                        espacios += (nombres[i][contadorNombre] == 32); 
                        //Es lo mismo que if(nombres[i][cN] == " "): espacios++
                
                        contadorNombre++;
                    }

                    posicionApellido = contadorNombre;
                    
                    //Concatenamos el string desde el 2do espacio hasta su final (Apellidos)
                    for (int j = posicionApellido; j < longitudNombre; j++)
                    {
                        char nApellido[2] = {nombres[i][j], '\0'};
                        strcat(apellidoNombre, nApellido);
                    }
                    //Añadimos un espacio para separar apellidos y nombres
                    char espacio[2] = {32, '\0'};
                    strcat(apellidoNombre, espacio);
                    
                    // Concatenamos el inicio del string hasta el 2do espacio (Nombres)
                    for (int j = 0; j < posicionApellido; j++)
                    {
                        char nNombre[2] = {nombres[i][j], '\0'};
                        strcat(apellidoNombre, nNombre);
                    }

                    //Añadimos el nuevo string a la matriz
                    strcpy(nombresPorApellido[i], apellidoNombre); 
                }

                //Imprimimos la Matriz
                for (int i = 0; i < numNombres; i++)
                {
                    printf("%s \n", nombresPorApellido[i]);
                }
                
            }

            //Todavía no existen registros en nombres
            else
            {
                printf("No se han ingresado datos\n");
            }

            printf("\n------------------------\n\n");
            break;

        // Salir
        case 4:
            printf("\nEjecucion Finalizada");
            printf("\n------------------------\n\n");

            return 0;

        // Opcion no valida
        default:
            printf("Opcion no valida, ingrese un numero del 1 al 4\n");
            break;
        }

    } while (opcion != 4);

    return 0;
}
