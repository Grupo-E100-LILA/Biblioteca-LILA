#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char titulo[100];
	char autor[100];
	char isbn[100];
	char editorial[100];
	char fechapublicacion[100];
	char fechacompra[100];
}libro;

void FPresentacion (void); // Función de presentación.
char FEleccion (void); //Función para elegir.
char FRepetir (void); // Función para volver a ejecutar el programa, o no.
void LimpiarBufer (void); // Función que evita usar 'fflush' para limpiar el bufer de teclado.
void FCierre (void); //Cerrar el programa
void FAcceso(void);

int menu();
void registro_libros();
void leer_libros();
int contador();
void eliminar_libro(int a);
void consulta();
void modificar_libros();

int main()
{
	// Presentación:
	FPresentacion ();
	//Acceso con clave
	int pass;
	do{
			printf("Clave de acceso: ");
			scanf("%d",&pass);
			LimpiarBufer ();
			if(pass==2345) printf("\nClave correcta.\n\n");
			else printf("\nClave incorrecta.\n\n");
		}while(pass!=2345);
	menu();
	return 0;
}
//Fin de la funcion main

int menu()
{
	// Variables
	int a;
//	FILE *pf;
//	libro c;
	char opcion;
	
	// Protocolo de repetición
	do {
		// Proceso
		//Presentacion de la funcion
		printf("\n MENU PRINCIPAL\n");
		// La elección:
		opcion = FEleccion ();
		
		switch (opcion)
		{
			case'1'://Registro de los libros
				registro_libros();
			break;
			
			case'2'://Listado de los libros
				leer_libros();
			break;
			
			case'3'://Consulta de datos de un libro
				consulta();
			break;
			
			case'4'://Modificar los datos de un libro
				leer_libros();
				printf("Elija el numero correspondiente al libro que desea modificar: ");
				scanf("%d",&a);
				LimpiarBufer ();
				eliminar_libro(a);
				modificar_libros();
				printf("\n\n\tLIBRO MODIFICADO CORRECTAMENTE\n");
			break;	
			
			case'5'://Eliminar un libro
				leer_libros();
				printf("Elija el numero correspondiente al libro que desea eliminar de la lista: ");
				scanf("%d",&a);
				LimpiarBufer ();
				eliminar_libro(a);
				printf("\n\n\tLIBRO ELIMINADO CORRECTAMENTE\n");
			break;
			default: printf ("Opcion no valida\n");
		}
		
	// Repetición
	opcion = FRepetir ();
		
	} while ((opcion == 's')  || (opcion == 'S'));
	
	return 123;
}
//Fin funcion menu
void FPresentacion(void)
{
	puts ("Bienvenido a Biblioteca-LILA \n");
}
char FEleccion (void)
{
	char opcion;
	puts ("Elija que quiere realizar: \n");
	puts ("1. Registro de libro.\n");
	puts ("2. Listado de libros.\n");
	puts ("3. Consulta de datos de un libro.\n");
	puts ("4. Modificar datos de un libro.\n");
	puts ("5. Eliminar libro.\n");
	scanf ("%c", &opcion);
	LimpiarBufer ();
	return opcion;
}
char FRepetir (void)
{
	char letra;
	puts ("\n\n\250Desea volver a ejecutar el programa?");
	scanf ("%c", &letra);
	LimpiarBufer ();
	return letra;
}
void LimpiarBufer (void)
{
	char c;
	while((c = getchar())!= EOF && c!= '\n');
}
void FCierre (void)
{
	puts ("\n\nPulse \256retorno de carro\257 para cerrar la ventana...");
	getchar ();
}

void registro_libros()
{
	FILE*pf;
	libro c;
//    int i ;
//    int longitud;
//   int x=0;
    
        printf ("Nombre del libro: ");
    	gets (c.titulo);
    
        printf ("Nombre del autor: ");
    	gets (c.autor);
    
        printf ("Numero de ISBN: ");
    	gets (c.isbn);
    
    	printf ("Editorial del libro: ");
    	gets (c.editorial);
    
	    printf ("Fecha del libro: ");
	    gets(c.fechapublicacion);
	    
	    printf ("Fecha de compra del libro: ");
	    gets (c.fechacompra);
	    
	    pf=fopen ("libros.txt","a");
        
        fprintf(pf,"%s  ",c.titulo);
        fprintf(pf,"%s  ",c.autor);
		fprintf(pf,"%s  ",c.isbn);
		fprintf(pf,"%s  ",c.editorial);    
	    fprintf(pf,"%s  ",c.fechapublicacion);
		fprintf(pf,"%s  \n",c.fechacompra);
		
		fclose(pf);
		
}

//Fin funcion de pedir libro

void leer_libros()
{
	FILE* pf;
	libro c;
	int i=1;
	int cont=contador();
	
	printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("#:   %-20s %-20s %-20s %-20s %-25s %-10s\n","TITULO","AUTOR","ISBN","EDITORIAL","FECHA DE PUBLICACION","FECHA DE COMPRA");
	printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
	
	pf=fopen ("libros.txt","r");
	for (i=1; i<cont; i++)
	{
		fscanf(pf,"%s",c.titulo);
		fscanf(pf,"%s",c.autor);
		fscanf(pf,"%s",c.isbn);
		fscanf(pf,"%s",c.editorial);
		fscanf(pf,"%s",c.fechapublicacion);
		fscanf(pf,"%s",c.fechacompra);
		
	printf("%d",i);
    printf("    %-20s %-20s %-20s %-20s %-25s %-10s\n",c.titulo,c.autor,c.isbn,c.editorial,c.fechapublicacion,c.fechacompra);
	}
	printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(pf); 
}

//Fin funcion ver libro

int contador ()
{
	FILE*pf;
	pf=fopen ("libros.txt","r");
	
	char basur[100];
//	int cont=0,N;
	int cont=1;
	
	while (!feof(pf))
	{
		fgets(basur,100,pf);
		
		cont++;
	}
	
	fclose(pf);
	
	return (--cont);
}

//FIN FUNCION CONTADOR

void eliminar_libro (int a)
{
  FILE*pf=fopen("libros.txt","r");
  FILE*temp=fopen("temp.txt","a");
  libro c;
  int i=1;
  int cont=contador();
  
  for(i=1;i<cont;i++)
        {
        fscanf(pf,"%s", c.titulo);
        fscanf(pf,"%s", c.autor);
        fscanf(pf,"%s", c.isbn);
        fscanf(pf,"%s", c.editorial);
        fscanf(pf,"%s", c.fechapublicacion);
        fscanf(pf,"%s", c.fechacompra);
        
        if(i!=a)
        {
        	fprintf(temp,"%s ",c.titulo);
        	fprintf(temp,"%s ",c.autor);
        	fprintf(temp,"%s ",c.isbn);
        	fprintf(temp,"%s ",c.editorial);
        	fprintf(temp,"%s ",c.fechapublicacion);
        	fprintf(temp,"%s \n",c.fechacompra);
	}
}
fclose(pf);
fclose(temp);

remove("libros.txt");
rename("temp.txt","libros.txt");	
}

//FIN FUNCION ELIMINAR LIBRO

void consulta()
{
	FILE *pf=fopen("libros.txt","r");
	libro c;
	char buscanm[100];
	char buscanom[100];
	int i=1,j=0,op=0;
	int cont=contador();
	printf("\n......TIPO DE BUSQUEDA......\n\n");
	printf("1. Titulo \n");
	printf("2. ISBN \n\n");
	printf("Elija una opcion \n");
	scanf("%d",&op);
		LimpiarBufer ();
	switch(op)
	{
		case 1:
			
		printf("Introduzca el titulo de libro que quiera buscar:   ");
		gets(buscanom);
		
		printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
		
        printf("#:   %-20s %-20s %-20s %-20s %-25s %-10s\n","TITULO","AUTOR","ISBN","EDITORIAL","FECHA DE PUBLICACION","FECHA DE COMPRA");
		
		printf("-------------------------------------------------------------------------------------------------------------------------------------\n");		
      for(i=1;i<cont;i++)
    {
        fscanf(pf,"%s", c.titulo);
        fscanf(pf,"%s", c.autor);
        fscanf(pf,"%s", c.isbn);
        fscanf(pf,"%s", c.editorial);
        fscanf(pf,"%s", c.fechapublicacion);
        fscanf(pf,"%s", c.fechacompra);
			 
	  	if (strcmp(c.titulo,buscanom)==0)
	  	{
	  	
	  	printf("%d:",i);
	  	printf("    %-20s %-20s %-20s %-20s %-25s %-10s \n",c.titulo,c.autor,c.isbn,c.editorial,c.fechapublicacion,c.fechacompra);
		  
		i++;
		j++;
		}	 
	}
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n\n");
      if(i==0) printf("\nNo se ha encontrado el libro. \n");
      else printf("Se han encontrado %d coincidencias. \n",j);
      
         break;
         
       
	   
	   
	   case 2:
	  
	  	printf("Introduzca el ISBN del libro que quiera buscar:   ");
	  	gets(buscanm);
	  
	  	printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
		
        printf("#:   %-20s %-20s %-20s %-20s %-25s %-10s\n","TITULO","AUTOR","ISBN","EDITORIAL","FECHA DE PUBLICACION","FECHA DE COMPRA");
		
		printf("-------------------------------------------------------------------------------------------------------------------------------------\n");	

	for(i=1;i<cont;i++)
		{
			fscanf(pf, "%s", c.titulo);
			fscanf(pf, "%s", c.autor);
			fscanf(pf, "%s", c.isbn);
			fscanf(pf, "%s", c.editorial);
			fscanf(pf, "%s", c.fechapublicacion);
			fscanf(pf, "%s", c.fechacompra);
		
			if(strcmp(c.isbn, buscanm)==0)
				{
					printf("%d:",i);
	  				printf("    %-20s %-20s %-20s %-20s %-25s %-10s \n",c.titulo,c.autor,c.isbn,c.editorial,c.fechapublicacion,c.fechacompra);
		  
					i++;
					j++;			
				}
		}
			printf("-----------------------------------------------------------------------------------------------------------------------------------\n\n");
			if(i==0) printf("\nNo se encuentra dicho libro. \n");
			else printf("Se encontro %d coincidencias. \n",j);
				break;
				default: printf("Opcion no valida \n");
	}
	fclose(pf);
}
//FIN FUNCION CONSULTA INDIVIDUAL

void modificar_libros()
{
	FILE*pf;
	libro c;
//	int i;
//	int longitud;
//	int x=0;
		
		printf("\nNuevo nombre de libro: ");
		gets(c.titulo);
		
		printf("Nuevo autor de libro: ");
		gets(c.autor);
		
		printf("Nuevo ISBN: ");
		gets(c.isbn);
		
		printf("Nueva editorial: ");
		gets(c.editorial);
		
		printf("Nueva fecha publicacion: ");
		gets(c.fechapublicacion);
		
		printf("Nueva fecha compra: ");
		gets(c.fechacompra);
		
		pf=fopen("libros.txt","a");
		
		fprintf(pf, "%s ",c.titulo);
		fprintf(pf, "%s ",c.autor);
		fprintf(pf, "%s ",c.isbn);
		fprintf(pf, "%s ",c.editorial);
		fprintf(pf, "%s ",c.fechapublicacion);
		fprintf(pf, "%s \n",c.fechacompra);
		
		fclose(pf);
}
//FIN FUNCION MODIFICAR LIBRO
