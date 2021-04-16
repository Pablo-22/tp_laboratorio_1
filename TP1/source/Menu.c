/*
 * Menu.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "Operations.h"
#include "Validations.h"
#include "Menu.h"
#include "Show.h"


int mainMenu(int primerOperando, int segundoOperando, int flagOperacionesCalculadas)
{
	int opcion;
	opcion = 0;

	printf("1. Ingresar 1er operando (A = %d) \n", primerOperando);
	printf("2. Ingresar 2do operando (B = %d) \n", segundoOperando);

	if (flagOperacionesCalculadas == 0)
	{
		printf("3. Calcular todas las operaciones \n");
		printf("      a) Calcular la suma (%d+%d) \n", primerOperando, segundoOperando);
		printf("      b) Calcular la resta (%d-%d) \n", primerOperando, segundoOperando);
		printf("      c) Calcular la division (%d/%d) \n", primerOperando, segundoOperando);
		printf("      d) Calcular la multiplicacion (%d*%d) \n", primerOperando, segundoOperando);
		printf("      e) Calcular el factorial (%d! y %d!) \n", primerOperando, segundoOperando);
	}
	else
	{
		printf("Ya se han calculado las operaciones para los valores ingresados \n");
	}

	printf("4. Informar resultados \n");
	printf("5. Salir \n");

	printf("\n Elija una opción: ");
	scanf("%d", &opcion);

	return opcion;
}


void cleanConsole()
{
	/* El símbolo _WIN32 está definido solamente en Windows
	 * y con la construcción utilizada el compilador verá,
	 * por ejemplo, la instrucción #include<windows.h> solo si
	 * es Windows. En una compilación para linux, es como si
	 * esa línea del fuente no existiera.*/

	#ifdef _WIN32
    	system("cls");
	#else
    	system("clear");
	#endif
}
