#include <stdio.h>
#include <math.h>

float leerCoeficientes(char coeficiente){
    float cof;
    printf("Ingrese el coeficiente %c: ", coeficiente);
    scanf("%f", &cof);

    return cof;
}

float calcularDiscriminate(float a, float b, float c){
    float discriminante;

    discriminante = pow(b,2) - 4*a*c;
    return discriminante;
}

float calcularEcuacionUno(float a, float b, float discriminante){
    float resultado_uno;
    resultado_uno = (-b + sqrt(discriminante))/2*a;
    return resultado_uno;
}

float calcularEcuacionDos(float a, float b, float discriminante){
    float resultado_dos;
    resultado_dos = (-b - sqrt(discriminante))/2*a;
    return resultado_dos;
}

int main(){
    float a,b,c;
    float discriminante, resultado_uno, resultado_dos;
    int option=0;

    while (option==0){
        printf("Escoja una opcion \n(1) Ingresar coesficientes \n(2) Calcular raices\n(3) Salir\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                a = leerCoeficientes('a');
                b = leerCoeficientes('b');
                c = leerCoeficientes('c');
                option = 0;
                break;
            case 2:
                discriminante = calcularDiscriminate(a, b, c);
                resultado_uno = calcularEcuacionUno(a, b, discriminante);
                resultado_dos = calcularEcuacionDos(a, b, discriminante);

                printf("De los valores %f, %f y %f obtenemos: \n", a, b, c);

                printf("Valor del discriminante = %f\n", discriminante);

                printf("Valor del resultado 1 = %f\n", resultado_uno);

                printf("Valor del resultado 2 = %f\n", resultado_dos);
                option = 0;
                break;
            case 3:
                printf("Gracias");
                break;
        }
    }
}

