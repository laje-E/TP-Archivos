#include <stdio.h>
#include <string.h>


int main (int argc, char **argv) {
    char apellido [20] = "";
	
	char nombre [20];
	
	char DNI [8];
    
    int opcion;
    
    printf ("ingrese que opcion quiere efectuar: 0= salir | 1= ingresar datos | 2= buscar DNI ");
    scanf ("%d", &opcion);
    
    while (opcion != 0){
    
        if (opcion == 1){
    
	FILE *ingresar_datos;
	ingresar_datos = fopen("archivo.txt", "a+");
	if (ingresar_datos == NULL){
		printf ("error al abrir el archivo ");
	}
	else {
        
        /*no usamos fscanf porque con el fputs ya es suficiente*/
    	printf ("ingrese su apellido ");
    	scanf ("%s", apellido);
    	
	
	    printf ("ingrese su nombre ");
	    scanf ("%s", nombre);
	    
	    /*es mas simple hacer el DNI como string*/
	    printf ("ingrese el numero de su DNI ");
	    scanf ("%s", DNI);
	    
	    
	    
	    /* pero si queremos utilizar el DNI como int hay que hacer esto
	    fscanf (ingresar_datos, "%d", &DNI);
	    printf ("ingrese el numero de su DNI ");
	    
	    sprintf(DNI_str, "%d", DNI); 
	    */
	    
	    /*convertir el DNI en string para que asi se pueda leer en el fputs*/
	    
	    fputs(apellido,ingresar_datos);
	    fputs (" ", ingresar_datos);
	    fputs(nombre,ingresar_datos);
	    fputs (" ", ingresar_datos);
	    fputs(DNI,ingresar_datos);
	    fputs ("\n", ingresar_datos);
	    fputs ("\n", ingresar_datos);
	    
	}
	
	fclose(ingresar_datos);
	
    }
	
	if (opcion == 2){
	char busqueda [9];
	printf ("ingrese un DNI que quiera buscar");
	scanf ("%s", busqueda);
	
	FILE *buscar_datos;
	buscar_datos = fopen ("archivo.txt", "r");
	
	if (buscar_datos == NULL){
		printf ("error al abrir el archivo ");
	}
	
	else {
	    if (strcmp (DNI, busqueda) == 0){
	        printf ("el nombre del dni buscado es: %s ", nombre);
	        printf (" y el apellido es: %s ", apellido);
	    }
	    else if (strcmp (DNI, busqueda) != 0){
	        printf ("el numero de DNI buscado no esta almacenado en este archivo ");
	    }
	}
	}
	printf ("ingrese que opcion quiere efectuar: 0= salir | 1= ingresar datos | 2= buscar DNI ");
	scanf ("%d", &opcion);
    }
	return 0;
}
