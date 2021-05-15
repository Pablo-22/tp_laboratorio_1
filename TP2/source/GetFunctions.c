#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "TerminalFunctions.h"
#include "GetFunctions.h"
#include "Menu.h"



/********** UTN GET ***********************************
 ********** UTN GET ***********************************
 ********** UTN GET **********************************/
int getInt(char mensaje[], char mensajeDeError[], int minimo, int maximo, int realizarValidaciones)
{
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	if (realizarValidaciones == TRUE)
	{
		printf("\n");
		while(numeroIngresado < minimo || numeroIngresado > maximo)
		{
			printf("%s", mensajeDeError);
			printf("\n");
			printf("%s", mensaje);
			scanf("%d", &numeroIngresado);
		}
	}
	return numeroIngresado;
}

float getFloat(char mensaje[], char mensajeDeError[], float minimo, int maximo, int realizarValidaciones)
{
	float numeroIngresado;

	printf("%s",mensaje);
	scanf("%f", &numeroIngresado);

	if (realizarValidaciones == TRUE)
	{
		printf("\n");
		while(numeroIngresado < minimo || numeroIngresado > maximo)
		{
			printf("%s", mensajeDeError);
			printf("\n");
			printf("%s", mensaje);
			scanf("%f", &numeroIngresado);
		}
	}

	return numeroIngresado;
}

char getChar(char mensaje[], char mensajeDeError[], char opcion1, char opcion2, int realizarValidaciones)
{
	char caracterIngresado;

	CleanBuffer();
	printf("%s", mensaje);
	scanf("%c", &caracterIngresado);

	if (realizarValidaciones == TRUE)
	{
		printf("\n");
		while(caracterIngresado != opcion1 && caracterIngresado != opcion2)
		{
			printf("%s", mensajeDeError);
			printf("\n");
			CleanBuffer();
			printf("%s", mensaje);
			scanf("%c", &caracterIngresado);
		}
	}

	return caracterIngresado;
}

void getString(char mensaje[], char cadenaDeSalida[])
{
	CleanBuffer();
	printf("%s", mensaje);
	scanf("%[^\n]", cadenaDeSalida);
}



/********** UTN GET ***********************************
 ********** UTN GET ***********************************
 ********** UTN GET **********************************/

void indexValidation(int index)
{
	if (index == -1)
	{
		CleanConsole();
		printf("No se ha encontrado esa ID \nIntente nuevamente: \n\n");
	}
}


void inicializarVector(int vector[], int extensionVector, int valorDeInicio)
{
	int i;

	for (i = 0; i < extensionVector; i++)
	{
		vector[i] = valorDeInicio;
	}
}
