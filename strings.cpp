#include <stdio.h>
#include <string.h>

int main() {
    int n=0, i, j, option=0;
    char person[30];
    char temp[30];
    char persons[30][30];
    
    while(option == 0){
        printf("\nIngrese una opcion\n (1) Ingreso de datos\n (2) Listado de Nombres\n (3) Listado de apellidos\n (4) Salir\n");
        scanf("%d", &option);
        
        switch(option){
            case 1:
            
            printf("Ingrese el numero de personas que desea agregar: ");
	        scanf("%d", &n);
	
	        while (n<1){
		        printf("Ingrese un numero valido: ");
		        scanf("%d", &n);
	        }
	        fflush(stdin);
	
	        for (i=0; i<n; i++){
	            fflush(stdin);
		        printf("Ingrese el nombre de la persona %d: \n", i+1);
		        fgets(person, 30, stdin);
		        fflush(stdin);
		        strcat(persons[i], person);
		
		        while(strlen(person)<=1){
			        printf("Ingrese un nombre valido: \n");
			        fgets(person, 30, stdin);
			        fflush(stdin);
			        strcat(persons[i], person);
		        }
            }
            
            option = 0;
            
            break;
            
            case 2:
                for(i=0;i<30;i++) 
  		            for(j=0; j < 30; j++) 
    		            if(strcmp(persons[j], persons [j+1])>0) {
        		            strcpy(temp, persons[j]);
        		            strcpy(persons[j], persons[j+1]); 
        		            strcpy(persons[j+1], temp);
    	                }
            
            printf("\nLas personas ingresadas son: \n");
            for (i=0; i<30; i++){
	    	printf("%s", persons[i]);
	        }
            
            option = 0;
            break;
            
            case 3:
                for(i=0;i<n;i++) 
  		            for(j=0; j < n-i; j++) 
    		            if(strcmp(persons[j], persons [j+1])>0) {
        		            strcpy(temp, persons[j]);
        		            strcpy(persons[j], persons[j+1]); 
        		            strcpy(persons[j+1], temp);
    	                }
            
            printf("\nLas personas ingresadas son: \n");
            for (i=0; i<30; i++){
	    	printf("%s", persons[i]);
	        }
            
            option = 0;
            break;
            
            case 4:
            printf("\nGracias\n");
            
        }
    }
}
