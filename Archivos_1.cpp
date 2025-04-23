#include <stdio.h>
#include <string.h>
void ingreso_datos (char apellido [20], char nombre [20], char DNI [9]);
void buscar_datos (char apellido [20], char nombre [20], char DNI [9]);
int main (int argc, char **argv) {
    char apellido [20];
	char nombre [20];
	char DNI [8];
    int opcion;
    printf ("ingrese que opcion quiere efectuar: 0= salir | 1= ingresar datos | 2= buscar DNI ");
    scanf ("%d", &opcion);
    while (opcion != 0){
        switch (opcion){
    
        case 0:
            return 0;
            break;
    
        case 1:
            ingreso_datos(apellido, nombre, DNI);
            break;
    
        case 2:
            buscar_datos(apellido, nombre, DNI);
            break;
    
        }
        
        printf ("ingrese que opcion quiere efectuar: 0= salir | 1= ingresar datos | 2= buscar DNI ");
	    scanf ("%d", &opcion);
    }
    return 0;
}
    void ingreso_datos (char apellido [20], char nombre [20], char DNI [9]){
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
	    
	    fprintf (ingresar_datos, "%s %s %s\n", apellido, nombre, DNI);
	    
	    /*
	    fputs(apellido,ingresar_datos);
	    fputs (" ", ingresar_datos);
	    fputs(nombre,ingresar_datos);
	    fputs (" ", ingresar_datos);
	    fputs(DNI,ingresar_datos);
	    fputs ("\n", ingresar_datos);
	    fputs ("\n", ingresar_datos);
	    */
	}
	
	fclose(ingresar_datos);
	
    }
    
    void buscar_datos (char apellido [20], char nombre [20], char DNI [9]) {
	
	char busqueda [9];
	printf ("ingrese un DNI que quiera buscar");
	scanf ("%s", busqueda);
	
	FILE *buscar_datos;
	buscar_datos = fopen ("archivo.txt", "r");
	if (buscar_datos == NULL){
		printf ("error al abrir el archivo ");
	}
	
	else {
	    char linea [50];
	    int encontrado = 0;
	    while (fgets(linea, sizeof(linea), buscar_datos) != NULL){
	        char temp_apellido[20], temp_nombre[20], temp_DNI[9];
	        sscanf (linea, "%s %s %s", temp_apellido, temp_nombre, temp_DNI);
	         if (strcmp (temp_DNI, busqueda) == 0){
	             printf ("el nombre del dni buscado es: %s ", temp_nombre);
	             printf (" y el apellido es: %s ", temp_apellido);
	             printf ("\n");
	             encontrado = 1;
	             break;
    	     }
    	     
	    }
	    if (encontrado == 0){
	        printf ("no se encontro el DNI seleccionado");
	    }

	}
}
