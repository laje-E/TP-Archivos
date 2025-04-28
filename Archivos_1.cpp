#include <stdio.h>
#include <string.h>
void ingreso_datos (char apellido [20], char nombre [20], char DNI [9], int coincidencia);
void buscar_DNI (char apellido [20], char nombre [20], char DNI [9]);
void bus_nombre_apellido (char apellido [20], char nombre [20], char DNI [9]);
void validacion (char DNI [9], int *coincidencia);
void mostrar_datos (char apellido [20], char nombre [20], char DNI [9]);
void orden_nomb_ape (char apellido [20], char nombre [20], char DNI [9]);
void orden_DNI (char apellido [20], char nombre [20], char DNI [9]);
void contador(int *contador);
int main (int argc, char **argv) {
    char apellido [20];
	char nombre [20];
	char DNI [8];
	int coincidencia = 0;
    int opcion;
    printf ("ingrese que opcion quiere efectuar: 0= salir | 1= ingresar datos | 2= buscar DNI | 3= buscar nombre o apellido | 4= mostrar datos ordenados");
    scanf ("%d", &opcion);
    while (opcion != 0){
        switch (opcion){
    
            case 0:
                return 0;
                break;
    
            case 1:
                ingreso_datos(apellido, nombre, DNI, coincidencia);
                break;
    
            case 2:
                buscar_DNI(apellido, nombre, DNI);
                break;
            
            case 3:
                bus_nombre_apellido(apellido, nombre, DNI);
                break;
            
            case 4:
                mostrar_datos(apellido, nombre, DNI);
                break;
        }
        
        printf ("ingrese que opcion quiere efectuar: 0= salir | 1= ingresar datos | 2= buscar DNI | 3= buscar nombre o apellido");
	    scanf ("%d", &opcion);
    }
    return 0;
}
    void ingreso_datos (char apellido [20], char nombre [20], char DNI [9], int coincidencia){
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
	    do {
    	    printf ("ingrese el numero de su DNI ");
    	    scanf ("%s", DNI);
    	    validacion (DNI, &coincidencia);
	    }while(coincidencia != 0);
	    
	    
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
    
    void buscar_DNI (char apellido [20], char nombre [20], char DNI [9]) {
	
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
    fclose (buscar_datos);
	}
}
	void bus_nombre_apellido (char apellido [20], char nombre [20], char DNI [9]) {
	    char busqueda [9];
	    printf ("ingrese un nombre o apellido que quiera buscar");
	    scanf ("%s", busqueda);
	    FILE *buscar_datos;
	    buscar_datos = fopen("archivo.txt", "r");
	    if (buscar_datos == NULL){
	        printf ("error al abrir el archivo");
	    }
	    else {
	        char linea [50];
	        int encontrado = 0;
	        while (fgets(linea, sizeof(linea), buscar_datos) != NULL){
	            char temp_apellido [20], temp_nombre [20], temp_DNI [9];
	            sscanf (linea, "%s %s %s",temp_apellido, temp_nombre, temp_DNI);
	            if (strcmp(temp_nombre, busqueda) == 0 || strcmp(temp_apellido, busqueda) == 0){
	                printf ("los datos del cliente seleccionado son: apellido = %s, nombre = %s, DNI = %s ", temp_apellido, temp_nombre, temp_DNI);
	                printf ("\n");
	                encontrado = 1;
	                break;
	            }
	        }
	        if (encontrado == 0){
	            printf ("no se pudo encontrar al cliente");
	        }
	   }
	   fclose (buscar_datos);
	}

    void validacion (char DNI [9], int *coincidencia) {
        char aux_DNI [9];
        strcpy(aux_DNI, DNI);
        FILE* buscar_datos;
        buscar_datos = fopen("archivo.txt", "r");
        if (buscar_datos == NULL){
            printf ("ERROR");
            return;
        }
        
        else {
            char linea [50];
            *coincidencia = 0;
            while (fgets(linea, sizeof(linea), buscar_datos) != NULL){
                char temp_apellido[20], temp_nombre[20], temp_DNI[9];;
                sscanf(linea, "%s %s %s", temp_apellido, temp_nombre, temp_DNI);
                if (strcmp(aux_DNI, temp_DNI) == 0){
                    *coincidencia = 1;
                    printf ("ERROR. este numero de dni ya existe. ingrese otro /n");
                    break;
                }
            }    
        }
        fclose(buscar_datos);
    }
    void mostrar_datos (char apellido [20], char nombre [20], char DNI [9]) {
        int opcion;
        printf ("de que forma quiere ordenar el archivo? 1= por nombre y apellido | 2= por DNI ");
        scanf ("%d", &opcion);
        switch(opcion){
            case 1:
                orden_nomb_ape(apellido, nombre, DNI);
                break;
            
            case 2:
                orden_DNI (apellido, nombre, DNI);
                break;
            
            default:
                printf ("la opcion ingresada no es valida ");
                break;
        }
    }
    void orden_nomb_ape (char apellido [20], char nombre [20], char DNI [9]){
        FILE *ordenar_datos;
        ordenar_datos = fopen("archivo.txt", "a+");
        if (ordenar_datos == NULL){
            printf ("ERROR");
        }
        else{
            char linea [50];
            while (fgets(linea, sizeof(linea), ordenar_datos) != NULL){
                char temp_apellido [20], temp_nombre [20], temp_DNI[9];
                sscanf(linea, "%s %s %s", temp_apellido, temp_nombre, temp_DNI);
            }
        }
        fclose (ordenar_datos);
    }
    void orden_DNI (char apellido [20], char nombre [20], char DNI [9]){
        FILE *ordenar_datos;
        ordenar_datos = fopen("archivo.txt", "a+");
        if (ordenar_datos == NULL){
            printf ("ERROR");
        }
        else{
            char linea [50];
            while (fgets(linea, sizeof(linea), ordenar_datos) != NULL){
                char temp_apellido [20], temp_nombre [20], temp_DNI[9];
                sscanf(linea, "%s %s %s", temp_apellido, temp_nombre, temp_DNI);
            }
        }
        fclose (ordenar_datos);
    }
    
    void contador(int *contador){
        FILE *contar_filas;
        contar_filas = fopen("archivo.txt", "r");
        if (contar_filas == NULL){
            printf ("ERROR");
        }
        else{
            *contador = 0;
            char linea [50];
            while (fgets(linea, sizeof(linea), contar_filas) != NULL) {
                contador ++;
            }
        }
        fclose (contar_filas);
    }
