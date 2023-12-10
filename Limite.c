#include <stdio.h>
#include <string.h>
#include <ctype.h>

void getPhrase(char frase[80]){
    printf("Ingrese una frase: \n");

    fgets(frase, 80, stdin);
}

int vocalsCount(char frase[80]){
    int counter=0, i;
    char actualLetter;

    for (i=0; i< strlen(frase); i++){
        actualLetter = tolower(frase[i]);

        if (actualLetter == 'a' || actualLetter == 'e' || actualLetter == 'i' || actualLetter == 'o' || actualLetter == 'u'){
            counter++;
        }
    }
    return counter;
}

int consonantsCount(char frase[80]){
    int counter=0, i;
    char actualLetter;

    for (i=0; i< strlen(frase); i++){
        actualLetter = tolower(frase[i]);

        if (isalpha(actualLetter) && actualLetter != 'a' && actualLetter != 'e' && actualLetter != 'i' && actualLetter != 'o' && actualLetter != 'u' && actualLetter != ' ' && actualLetter != '\n'){
            counter++;
        }
    }
    return counter;
}

int spaceCount(char frase[80]){
    int counter=0, i;
    for (i=0; i < strlen(frase); i++){
        if (frase[i] == ' '){
            counter++;
        }
    }
    return counter;
}

int digitCount(char frase[80]){
    int counter=0, i;
    for (i=0; i < strlen(frase); i++){
        if (isdigit(frase[i])){
            counter++;
        }
    }
    return counter;
}

void phraseMatrix(char matrix[80][80], char frase[80]){
    char temp [80];
    const char delim[3] = " \n";
    int i=0;
    char *test;

    strcpy(temp, frase);

    test = strtok(temp, delim);

    while( test != NULL ) {
        strcpy(matrix[i++], test);

        test = strtok(NULL, delim);
    }
}

int main(){
    char frase[80], matrix[80][80];
    int lenght, vocals, consonants, spaces, digits, i;

    getPhrase(frase);

    lenght = strlen(frase);

    vocals = vocalsCount(frase);

    consonants = consonantsCount(frase);

    spaces = spaceCount(frase);

    digits = digitCount(frase);

    phraseMatrix(matrix, frase);

    printf("\nDe la frase:\n%s", frase);

    printf("\nSu longitud es: %d", lenght);

    printf("\nSus vocales en total son: %d", vocals);

    printf("\nSus consonantes en total son: %d", consonants);

    printf("\nSus espacios en total son: %d", spaces);

    printf("\nSus digitos en total son: %d\n", digits);

    for (i=0; i<spaces+1 ; i++){
        printf(" %s ||", matrix[i]);
    }
}